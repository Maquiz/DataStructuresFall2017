// Maximilian Bolling  ID: xh9447
// mbolling@horizon.csueastbay.edu
#include <iostream>
#include <fstream>  //data stream
#include <stdlib.h> //Atoi convert from c-string to int

using namespace std;

//===================================Class Definitions========================================
class node{
public:
    //Node constructor with no arguments
    node(){
        next = prev  = 0;
    };
    //Node constructor with 1 arguments
    node(char i){
        info = i;
        next = prev = NULL;
    }
    void setValue(char c){
        info = c;
    }
    char getValue(){
        return info;
    }

    char info;
    node *next;
    node *prev;
};

//Circular Doubly Linked List class
class CDLList{
public:
    CDLList(){
    head = tail = 0;
    length = 0;
    last = 0;
    }
    //Debugging functions
    void printHead(){
        cout<<head->getValue()<<endl;
    }

    void printTail(){
        cout<<tail->getValue()<<endl;
    }

    void append(char i){
        node *n = new node(i);
        //The first item
        if(head == NULL){
           head = tail = n;
           last = head;
           length++;
        }else{
            tail->next = n;
            n->prev = tail;
            n->next = NULL;
            tail = n;
            length++;
        }
    }

    //Need to make this relative to the last letter found
    char get(int j){
        //negative number
        if(j < 0){
            for(int i = 0;i>j;i--){
                last = last->prev;
            }
            return last->getValue();

        } else{
            for(int i = 0;i<j;i++){
                last = last->next;
            }
            return last->getValue();
        }
    }

    void printAll(){
        node *it;
        it = head;
        for(int i = 0; i< length; i++){
            cout<<it->getValue()<<endl;
            it = it->next;
        }
        cout<<endl;
    }

private:
    int length;
    node *head, *tail, *last;
};

int main()
{
    string data ,line;
    CDLList List;

    //Input Letters and Create Linked List
    ifstream myfile ("Letters.txt");
    if(myfile.is_open()){
        while(getline(myfile,line)){
            //create new node with line as char
            List.append(line.c_str()[0]);
            data += line;
            }
        myfile.close();
        }

    //Input data for sequence of characters
    ifstream seqfile("Sequence.txt");
    if(seqfile.is_open()){
        while(getline(seqfile,line)){
            //save sequence as line string
            data += line;
            }
        seqfile.close();
        }

    int it1 = 0, it2 = 0;
    string tester, finalWord;
    //decompose the line string into sequence parts
    while(line.c_str()[it2]!= NULL){
        if(line.c_str()[it2]!= ',' ){
            it2++;
        } else{
            tester = line.substr(it1,it2-it1);
            // findLetter on tester and list
            finalWord += List.get(atoi(tester.c_str()));
            //Clear string
            tester ="";
            it2++;
            it1 = it2;
        }
    }

    //Last sequence
     if(line.c_str()[it2]!= NULL ){
            it2++;
        } else{
            tester = line.substr(it1,it2-it1);
            // findLetter on tester and list
            finalWord += List.get(atoi(tester.c_str()));
            //Clear string
            tester ="";
            it2++;
            it1 = it2;
        }

    cout<<finalWord<<endl;
    return 0;
}
