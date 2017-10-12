#include <iostream>

using namespace std;
int test[100];
int compareTo(int t[],int j);
int compareTo(int t[],string j);
void addToArray(int t[], int j);
bool doesExist(int t[],int j);
int main()
{
    test[0]=1;
    test[1]=2;
    test[2]=4;
    test[3]=6;
    cout<<compareTo(test,7)<<endl;
    cout<<doesExist(test,2)<<endl;
    cout<<doesExist(test,3)<<endl;
    return 0;
}
//Not complete
void addToArray(int t[], int j){
    int length = 0;
    int pos = compareTo(t,j);
    if(pos==0) t[pos] = j;
}
//Returns position of the same  item;
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
}


