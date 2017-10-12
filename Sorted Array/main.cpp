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
    void printCard(){cout<<suit<<ranking<<endl;}
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
        if(c.getRInt()>getRInt()){
            return false;
        }else if(c.getRInt()<getRInt()){
           return true;
        }else if(c.getRInt() == getRInt()){
            if(c.getSInt()>getSInt()){
                return false;
            }else{
                return true;
                }
            }
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
void putItem(card d[], card c, int length); //insert card into deck in ascending order
void deleteItem(card d[], card c, int length); //delete card from deck
void getItem(card d[], card c, int length); //test if card is in deck
void printDeck(card d[]);   //print all cards in deck


//==================================Main Loop==================================================
int main()
{
    //================================Variables================================================
    card* deck;
    deck = new card[20];
    string data,line;
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

    //1st 20 items = inputCards1 ;
    for(int i = 0;i<20;i++){
            //if(){
          //  }
    }
    // Go to nextline = delete cards
    // go to next line = inputcards2
    //go to next line = testCards;

    //================================TESTING AREA=============================================
    deck[0]= card("H","2");
    deck[1]= card("D","8");
    deck[2]= card("S","A");
    deck[3]= card("C","7");
    deck[4]= card("D","J");
    printDeck(deck);
    cout<<"Print Deck Test^^^^^"<<endl<<endl;

    card g("H","10");

    card a("C","2");
    card t("C","10");
    card b("S","10");
    card c("D","A");
    g.printCard();
    g.printCardInt();
    cout<<"Should return 1: "<<g.ComparedTo(a)<<endl;
    cout<<"Should return 1: "<<g.ComparedTo(t)<<endl;
    cout<<"Should return 0: "<<g.ComparedTo(b)<<endl;
    cout<<"Should return 0: "<<g.ComparedTo(c)<<endl;

    //========================!!!!!!!!!!END OF FUNTION!!!!!!!!=================================
    return 0;
}
//===================================Function Definitions======================================

void putItem(card d[], card c, int length){
    int l = length;
    int pos = 0;
    while(pos<=l){
        //card is larger than the one in the deck
        if(c.ComparedTo(d[pos])){
            pos++;
        }else{
            //put card at pos move all other objects down one spot starting at bottom
        }
    }
}

void printDeck(card d[]){
    int it = 0;
    while(d[it].getSuit() != "NULL"){
        d[it].printCard();
        it++;
    }
}
//Returns position of the same  item;
/*
int compareTo(int t[],int j){
    int pos = 0;
    if(t[pos]==NULL){
        return pos;
    }
    while(t[pos]<j && t[pos]!= NULL){
        pos++;
    }
    return pos;
}
int compareTo(int t[], string j){

}

bool doesExist(int t[], int j){
    int pos = 0;
    while(t[pos]!= NULL){
        if(t[pos]==j){
            return true;
        }
        pos++;
    } return false;
}*/
