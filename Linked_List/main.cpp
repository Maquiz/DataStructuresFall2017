// Maximilian Bolling  ID: xh9447
// mbolling@horizon.csueastbay.edu
#include <iostream>
#include <fstream>   //used to read from file
#include <stdlib.h>  //Used for atoi
using namespace std;
//===================================Class Definitions========================================
//Create node class
class node{
public:
    //Node constructor with no arguments
    node(){
        next = 0;
    };
    //Node constructor with 2 arguments
    node(int i, node *in = NULL){
        info = i; next = in;
    }
    void setValue(int i){
        info = i;
    }
    int getValue(){
        return info;
    }

    int info;
    node *next;
};

//List class
class LList{
public:
    LList(){
    head = tail = 0;
    length = 0;
    }
    //Debugging functions
    void printHead(){
        cout<<head->getValue()<<endl;
    }

    void printTail(){
        cout<<tail->getValue()<<endl;
    }

    void append(int i){
        node *n = new node(i);
        node *it = head;
        n->next = NULL;
        if(head == NULL){
           head = tail = n;
           length++;
        }else{
            while(it->next)
                it = it->next;

            it->next = n;
            tail = n;
            length++;
        }
    }

    void add(int added, int pos){
        node *n = new node(added);
        node *it = get(pos);
        if(pos == 0){
            head = n;
            n->next = it;
            length++;
        }else if(pos == (length-1)){
            append(added);
        }
        else if(pos<length){
            it = get(pos-1);
            n->next = it->next;
            it->next = n;
            length++;
        }
    }

    void add(int added, string pos){
        if(pos == "END"){
            append(added);
        }
    }

    void deleteNode(int i){
        node *it;
        node *prev;

        it = head;
        while(it){
            if(i == it->getValue()){
                if(it==head){
                    prev = head->next;
                    delete head;
                    head = prev;
                   // cout<<head->getValue()<<endl;

                }else if(it == tail){
                    //Tail deletion is not working
                    prev->next = NULL;
                    delete tail;
                    tail = prev;
                   // cout<<tail->getValue()<<endl;
                }else{
                    prev->next = it->next;
                    delete it;
                }
                break;
            }
            prev = it;
            it = it->next;
        }
    }

    node* get(int i){
        node *it;
        int j = 0;
        it = head;

        while(it){
            if(j == i){
                return it;
            }
            j++;
            it = it->next;
        }
    }

    void printAll(){
        node *it;

        it = head;
        while(it){
            cout<<it->getValue()<<endl;
            it = it->next;
        }
        cout<<endl;
    }

private:
    int length;
    node *head, *tail;
};
void finisher(string s, LList l){
    int it1 = 0,it2 = 0;
    int fit1 = 0, fit2 = 0;
    string stringTest;
    //Append each int into a new node
    while(s.c_str()[it2]!='\n'){
            stringTest == "";
        if(s.c_str()[it2]==','){
            stringTest = s.substr(it1,it2-it1);
            l.append(atoi(stringTest.c_str()));
            it2++;
            it1 = it2;
        }
        else{
            it2++;
        }
    }
    stringTest = s.substr(it1,it2-it1);
    l.append(atoi(stringTest.c_str()));
    it2++;
    it1 = it2;
    l.printAll();
    //Delete numbers given
    while(s.c_str()[it2]!='\n'){
            stringTest == "";
        if(s.c_str()[it2]==','){
            stringTest = s.substr(it1,it2-it1);
            l.deleteNode(atoi(stringTest.c_str()));
            it2++;
            it1 = it2;
        }
        else{
            it2++;
        }
    }
    stringTest = s.substr(it1,it2-it1);
    l.deleteNode(atoi(stringTest.c_str()));
    it2++;
    it1 = it2;
    l.printAll();
    //Adding 2@3
    string added = "",pos ="";
    while(s.c_str()[it2]!=NULL){
            stringTest == "";
        if(s.c_str()[it2]==','){
            stringTest = s.substr(it1,it2-it1);
            while(stringTest.c_str()[fit2]!=NULL){
                if(stringTest.c_str()[fit2]=='@'){
                    added = stringTest.substr(fit1,fit2 - fit1);
                    fit2++;
                    fit1 = fit2;
                    fit2++;
                }else
                    fit2++;
            }
            pos = stringTest.substr(fit1,fit2 -fit1);
            if(pos =="END"){
                l.add(atoi(added.c_str()),pos);
                pos = "";
                added = "";
            }else{
                l.add(atoi(added.c_str()),atoi(pos.c_str()));
                pos = "";
                added = "";
            }
            it2++;
            it1 = it2;
        }
        else{
            it2++;
        }
    }
    stringTest == "";
        if(s.c_str()[it2]==NULL){
            stringTest = s.substr(it1,it2-it1);
            while(stringTest.c_str()[fit2]!=NULL){
                if(stringTest.c_str()[fit2]=='@'){
                    added = stringTest.substr(fit1,fit2 - fit1);
                    fit2++;
                    fit1 = fit2;
                    fit2++;
                }else
                    fit2++;
            }
            pos = stringTest.substr(fit1,fit2 -fit1);
            if(pos =="END"){
                l.add(atoi(added.c_str()),pos);
                pos = "";
                added = "";
            }else{
                l.add(atoi(added.c_str()),atoi(pos.c_str()));
                pos = "";
                added = "";
            }
            it2++;
            it1 = it2;
        }
        else{
            it2++;
        }
        l.printAll();
}
int main()
{
    //================================Variables=========================================
    string data,line;
    string name = "DataFile.txt";
    //===================================Input=================================================
        //input data file into one string
        ifstream myfile (name.c_str());
        if(myfile.is_open()){

            while(getline(myfile,line)){
                line = (line+"\n");
                data += line ;

            }
           // cout<<data<<endl;
            myfile.close();
        }else{
            cout<<"cant find"<<endl;
            }

    LList linked;
    finisher(data,linked);

}
