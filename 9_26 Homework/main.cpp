// Maximilian Bolling  ID: xh9447
// mbolling@horizon.csueastbay.edu
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//===================================Prototypes========================================
double avg(int col[]);
int high(int col[]);
void conversion(string s, int c1[],int c2[],string inv[]);
void readInvalid(string s[]);
bool stringCheck(string s);
int main()
{
    //================================Variables=========================================
    string name,data,line;
    int col1[10],col2;
    string invalid[10];
    double avg1;
    bool correctname = false;
    int currentInt = 0, highest2 =0, rows = 0, divisor = 0;

    //=================================TEST ARRAYS======================================
    int test [] = {7,8000,99999,11,100000};
    string tests[] = {"asdasd", "blah", "goods"};
    //How I can make dynamic arrays at runtime if i know the total
    int* my_dynamic_array;

    int size;
    std::cin >> size;

    my_dynamic_array = new int[size];

    //===================================Input=================================================
    //While name is not correct
    while(!correctname){
        cout << "Please input the filename:" << endl;
        cin>> name;

        ifstream myfile (name.c_str());
        if(myfile.is_open()){

            while(getline(myfile,line)){
                line = (line+"\n");
                data += line ;
                rows++;
            }
            myfile.close();
            correctname = true;
        }else{
            cout<<"cant find"<<endl;
            }
    }
    //All of the data is now in the string Data

    //if name is correct loop through rows of data
    //if first col data is an int add to col1, add to avg1 and divisor++
    //else add to invalid

    //2nd col if int add to col2,
    //if currentInt > highest2, highest2 = currentInt
    //else add to invalid

    //===================================Output=================================================
    cout<<data<<endl;
    //Avg C1
    cout<<std::fixed;
    cout<<"The average value of all numbers in the first column: "<<std::setprecision(4)<<avg(test)<<endl;;
    //High C2
    cout<<"The largest value of all numbers in the second column: "<<high(test)<<endl;
    //Total Rows in file
    cout<<"The total number of rows in the file is: "<<rows<<endl;
    //Invalid numbers
    readInvalid(tests);

    cout<<stringCheck("12334512312")<<endl;
    cout<<stringCheck("123345123i2")<<endl;

    return 0;
}

//===================================Function Definitions========================================

//Potentially references to all arrays
void conversion(string s,int c1[],int c2[],string inv[]){
//while not at the end of string s
//while(s)
//grab first section up to ','
//call stringCheck if true convert to int add to c1 else add to inv

//grab next set of string to '/n'
//Call stringCheck and if its true convert to int add to c2 else add to inv
}

//Average array of ints and returns double
double avg(int col[]){
    double sum = 0;
    double avger;
    for(int i = 0; i<=
     sizeof(col);i++){
        sum += col[i];
    }
    avger = sum/sizeof(col);
    return avger;
}

//Choose the high number from an array of ints
int high(int col[]){
int test = 0, cur = 0;
    for(int i = 0;i<=sizeof(col);i++){
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
