// Maximilian Bolling  ID: xh9447
// mbolling@horizon.csueastbay.edu
#include <iostream>
#include <fstream>  //used to read from file
using namespace std;
//===================================Class Declarations========================================
class card{
private:
    string suit, ranking;
    int sInt=0,rInt=0;

public:
    void printCard(){cout<<suit<<ranking;}
    void printCardInt(){cout<<sInt<<rInt<<endl;}

    //Constructors
    card(string s,string r){
        setSuit(s);
        setRank(r);
        convert(s,r);
    }

    card(){
        setSuit("NULL");
        setRank("NULL");
    }

    //Returns True if card this is called from is greater than parameter card c
    bool ComparedTo(card c){
        //if array rank > hand rank
        if(c.getRInt()>getRInt()){
            return false;
            //if array rank < hand rank
        }else if(c.getRInt()<getRInt()){
           return true;
            //if array rank == hand rank
        }else if(c.getRInt() == getRInt()){

            if(c.getSInt()>getSInt()){
                return false;
            }else{
                return true;
                }
            }
        }

    //Returns True if card this is equal to parameter card c
    bool EqualTo(card c){
       if(c.getRInt() == getRInt()){
            if(c.getSInt()==getSInt()){
                return true;
            }else{
                return false;
                }
            }
            return false;
        }

     //Converts string values of Suit and Ranking into int values SInt and RInt
    void convert(string s,string r){
        //Suit If
        if(getSInt() == 0)
            if(s =="C")  setSInt(1);
            else if (s == "D") setSInt(2);
            else if (s == "H") setSInt(3);
            else if (s == "S") setSInt(4);

        //Rank If
            if(r=="2") setRInt(2);
            else if(r=="3") setRInt(3);
            else if(r=="4") setRInt(4);
            else if(r=="5") setRInt(5);
            else if(r=="6") setRInt(6);
            else if(r=="7") setRInt(7);
            else if(r=="8") setRInt(8);
            else if(r=="9") setRInt(9);
            else if(r=="10") setRInt(10);
            else if(r=="J") setRInt(11);
            else if(r=="Q") setRInt(12);
            else if(r=="K") setRInt(13);
            else if(r=="A") setRInt(14);
    }

    //Getter's and Setter's
    void setSuit(string s){suit = s;}
    string getSuit(){return suit;}

    void setRank(string r){ranking = r;}
    string getRank(){return ranking;}

    void setSInt(int s){sInt = s;}
    int getSInt(){return sInt;}

    void setRInt(int r){rInt = r;}
    int getRInt(){return rInt;}

};

//===================================Prototypes================================================
void putItem(card d[], card c, int &length); //insert card into deck in ascending order
void deleteItem(card d[], card c, int &length); //delete card from deck
void getItem(card d[], card c, int length); //test if card is in deck
void printDeck(card d[],int length);   //print all cards in deck


//==================================Main Loop==================================================
int main()
{
    //================================Variables================================================
    card* deck;
    deck = new card[20];
    card* holdDeck;
    holdDeck = new card[20];
    string data,line, cardinfo, suit, ranks;
    int it1 = 0, it2 = 0;
    int length = 0;
    string name = "DataFile.txt";
    //===================================Input=================================================
    //input data file into one string
    ifstream myfile (name.c_str());
    if(myfile.is_open()){
        while(getline(myfile,line)){
            line = (line+"\n");
            data += line ;
            }
            myfile.close();
    }else{
        cout<<"cant find"<<endl;
        }

    //Input initial 20 items
    for(int i = 0; i<20; i++){
        cardinfo = "";
        suit = "";
        ranks = "";
        //Find first ,
        while(data.c_str()[it2]!=','){
            it2++;
        }

        //Grab Entire Card
        cardinfo = data.substr(it1,it2-it1);
        //Set Suit
        suit = data.substr(it1,1);

        ranks = data.substr(it1+1,it2-(it1+1));

        holdDeck[i].setSuit(suit);
        holdDeck[i].setRank(ranks);
        holdDeck[i].convert(suit,ranks);
        putItem(deck,holdDeck[i],length);

        it2++;
        it1 = it2;
    }
    printDeck(deck,length);

    //Move to next Line
    while(data.c_str()[it2]!='\n'){
            it2++;
        }
        it2++;
        it1 = it2;
        //start of 2nd line
        /*
        while(data.c_str()[it2]!='\n'){
            while(data.c_str()[it2]!=','){
                it2++;
            }
            //Grab Entire Card
            cardinfo = data.substr(it1,it2-it1);
            //Set Suit
            suit = data.substr(it1,1);

            ranks = data.substr(it1+1,it2-(it1+1));
            /*
            card c(suit,ranks);
            c.convert(suit,ranks);

            deleteItem(deck,c,length);

        //cout<<cardinfo<<endl;
            it2++;
            it1 = it2;
        }
        it2++;
        it1 = it2;
*/
        //Hard Coding Cards
        card a ("H","4");
        card b ("D","5");
        card c ("H","K");
        card d ("D","2");

        //Proving Delete function works
        deleteItem(deck,a,length);
        deleteItem(deck,b,length);
        deleteItem(deck,c,length);
        deleteItem(deck,d,length);

        printDeck(deck,length);

        //Hard Coding put more items
        card e ("S","7");
        card f ("H","K");
        card g ("D","10");

        putItem(deck,e,length);
        putItem(deck,f,length);
        putItem(deck,g,length);

        printDeck(deck,length);

        //Hard coded Cards
        card h("C","9");

        card i("C","10");

        //Proof Get Item function works
        getItem(deck,h,length);
        cout<<",";
        getItem(deck,i,length);


    //========================!!!!!!!!!!END OF FUNTION!!!!!!!!=================================
    return 0;
}
//===================================Function Definitions======================================

//Length is not being saved globally
void putItem(card d[], card c, int &length){
    bool moreToSearch;
    int pos = 0;

    moreToSearch = (pos<length);
        while(moreToSearch){
            //card is larger than the one in the deck
            if(c.ComparedTo(d[pos])){
                pos++;
                moreToSearch = (pos<length);
            }else{
                //else is never being called
               moreToSearch = false;
            }
        }
        for(int index = length; index > pos; index--)
            d[index] = d[index-1];
        d[pos] = c;
        length++;
}

void deleteItem(card d[], card c, int &length){
    int pos = 0;

    while(!c.EqualTo(d[pos]))
        pos++;

    if(c.EqualTo(d[pos])){
        for(int index = pos + 1; length > index;index++)
            d[index -1] = d[index];
        length--;
    }
}

void getItem(card d[], card c, int length){
    int pos = 0;
    bool moreToSearch = (pos<length);
    while(moreToSearch){
        if(c.EqualTo(d[pos])){
            cout<<c.getSuit()<<c.getRank()<<" YES";
            return;
        }
        pos++;
        moreToSearch = (pos<length);

    }

        cout<<c.getSuit()<<c.getRank()<<" NO";
}

void printDeck(card d[],int length){
    for(int it = 0; it<length; it++){
        d[it].printCard();
        if(it<length-1)
            cout<<",";
    }
    cout<<endl;
}
