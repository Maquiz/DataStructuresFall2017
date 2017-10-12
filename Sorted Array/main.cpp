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
    card(string s,string r){
    setSuit(s);
    setRank(r);
    convert(s,r);
}
    card(){
    setSuit("NULL");
    }

    void setSuit(string s){suit = s;}
    string getSuit(){return suit;}

    void setRank(string r){ranking = r;}
    string getRank(){return ranking;}

    void setSInt(int s){sInt = s;}
    int getSInt(){return sInt;}

    void setRInt(int r){rInt = r;}
    int getRInt(){return rInt;}

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

};
//===================================Prototypes================================================
void putItem(card d[], card c); //insert card into deck in ascending order
void deleteItem(card d[], card c); //delete card from deck
void getItem(card d[], card c); //test if card is in deck
void printDeck(card d[]);   //print all cards in deck


//==================================Main Loop==================================================
int main()
{
    //================================Variables================================================
    card* deck;
    deck = new card[20];
    string data,line;
    int it1 = 0, it2 = 0;
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

    deck[0]= card("H","7");

    card g("H","10");
    g.printCard();
    g.printCardInt();

    card f("S","A");

    f.printCard();
    f.printCardInt();
    return 0;
}
//===================================Function Definitions======================================

//Not complete
/*
void addToArray(int t[], int j){
    int length = 0;
    int pos = compareTo(t,j);
    if(pos==0) t[pos] = j;
}*/
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
