// Maximilian Bolling  ID: xh9447
// mbolling@horizon.csueastbay.edu
#include <iostream>
#include <fstream>
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
        //TEST
        //cout<<length<<endl;
        //printHead();
        //printTail();
        //END TEST
    }

private:
    int length;
    node *head, *tail;
};

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
            cout<<data<<endl;
            myfile.close();
        }else{
            cout<<"cant find"<<endl;
            }
    //Create new node
    node *p = new node(10);
    p->next = new node(11);
    //cout<<p->next->getValue()<<endl;
    LList linked;
    linked.append(100);
    linked.append(110);
    linked.append(120);
    linked.append(130);
    linked.append(140);
    linked.append(150);
    linked.append(160);
    linked.printAll();
    linked.deleteNode(110);
    linked.deleteNode(100);
    linked.deleteNode(160);
    linked.add(1000,0);
    linked.add(999,3);
    linked.add(1234,"END");
    //linked.add(444,100);
    //===================================Output=================================================
    linked.printAll();
}
