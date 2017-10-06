// Maximilian Bolling  ID: xh9447
// mbolling@horizon.csueastbay.edu
#include <iostream>
#include <iomanip>  //Used for decimal precision
#include <fstream>  //used to read from file
#include <stdlib.h>  //Used for atoi
using namespace std;
//===================================Prototypes================================================
void conversion(string s,int& invc,int& c1c,int& c2c);
void finisher(string s, int invc,int c1c, int c2c,int r);
double avg(int col[],int length);
int high(int col[],int length);
void readInvalid(string s[]);
bool stringCheck(string s);
//==================================Main Loop==================================================
int main()
{
    //================================Variables================================================
    string name,data,line;
    bool correctname = false;
    int  rows = 0, invcount = 0, c1count = 0, c2count = 0;
    //===================================Input=================================================
    while(!correctname){
        cout << "Please input the filename:" << endl;
        cin>> name;
        //If user does not add txt filename
        if(name.c_str()[name.length()-4] != '.'){
                name +=".txt";
        }
        ifstream myfile (name.c_str());

        if(myfile.is_open()){
            while(getline(myfile,line)){
                line = (line+"\n");
                data += line ;
                rows++;
            }
            myfile.close();
            correctname = true;
        }
    }
    //===================================Output================================================
    conversion(data,invcount,c1count, c2count);
    finisher(data, invcount, c1count, c2count,rows);
    return 0;
}

//===================================Function Definitions======================================

//count amount of ints for each column and invalid ints to create array in finisher
void conversion(string s,int& invc,int& c1c,int& c2c){//,int c1[],int c2[],string inv[]){
    int it1 = 0,it2 = 0;
    string stringTest;
    bool test;
    while(s.c_str()[it2]!=NULL){
            stringTest == "";
        if(s.c_str()[it2]==','){
            stringTest = s.substr(it1,it2-it1);
            test = stringCheck(stringTest);
            if(test){
                c1c++;
            }else{
                invc++;
            }
            it2++;
            it1 = it2;
        }else if(s.c_str()[it2]=='\n'){
            stringTest = s.substr(it1,it2-it1);
            test = stringCheck(stringTest);
            if(test){
                c2c++;
            }else{
                invc++;
            }
            it2++;
            it1 = it2;
        }
        else{
            it2++;
        }
    }
}

//Create arrays, fill with correct contents and display
void finisher(string s, int invc,int c1c, int c2c,int r){
    int* col1;
    int* col2;
    col1 = new int[c1c];
    col2 = new int[c2c];
    string* inv;
    inv = new string[invc];
    int nc1c = 0;
    int nc2c = 0;
    int ninvc = 0;
    int it1 = 0,it2 = 0;
    string stringTest;
    bool test;
    while(s.c_str()[it2]!=NULL){
            stringTest == "";
        if(s.c_str()[it2]==','){
            stringTest = s.substr(it1,it2-it1);
            test = stringCheck(stringTest);
            if(test){
                col1[nc1c] = atoi(stringTest.c_str());
                nc1c++;
            }else{
                inv[ninvc] = stringTest;
                ninvc++;
            }
            it2++;
            it1 = it2;
        }else if(s.c_str()[it2]=='\n'){
            stringTest = s.substr(it1,it2-it1);
            test = stringCheck(stringTest);
            if(test){
                col2[nc2c] = atoi(stringTest.c_str());
                nc2c++;
            }else{
                inv[ninvc] = stringTest;
                ninvc++;
            }
            it2++;
            it1 = it2;
        }
        else{
            it2++;
        }
    }
    //Avg c1
    cout<<std::fixed;
    cout<<"The average value of all numbers in the first column: "<<std::setprecision(4)<<avg(col1,c1c)<<endl;
    //High C2
    cout<<"The largest value of all numbers in the second column: "<<high(col2,c2c)<<endl;\
    //Total Rows in file
    cout<<"The total number of rows in the file is: "<<r<<endl;
    //Display Invalid numbers
    readInvalid(inv);
}

//Average array of ints and returns double
double avg(int col[], int length){
    double sum = 0;
    double avger;
    for(int i = 0; i<length;i++){
        sum += col[i];
    }
    avger = sum/length;
    return avger;
}

//Choose the high number from an array of ints
int high(int col[], int length){
int test = 0, cur = 0;
    for(int i = 0;i<length;i++){
        cur = col[i];
        if(cur> test){
            test = cur;
        }
    }
    return test;
}

//Couts entire array of strings of invalid numbers
void readInvalid(string s[]){
    string output;
    //Why do i need this magic number?
    for(int i = 0;i<sizeof(s)-1;i++){
        output.append(s[i]);
        output.append(", ");
    }
    //clear last 2 characters
    output.erase(output.end()-2);
    cout<<"The invalid numbers are: "<<output<<endl;
}

//Check if all characters are integers
bool stringCheck(string s){
    //loop through chars
    for (int i = 0; i < s.length(); i++){
        char c = s.c_str()[i];
        //Any chars arent ints return false
        if(c != '0' && c != '1' &&c != '2' &&c != '3' && c != '4' &&c != '5'
        &&c != '6' &&c != '7' &&c != '8' &&c != '9'){
            return false;
        }
    }
    return true;
}

