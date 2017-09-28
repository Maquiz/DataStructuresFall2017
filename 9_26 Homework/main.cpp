// Maximilian Bolling
// mbolling@horizon.csueastbay.edu
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

double avg(int col[]);
int high(int col[]);
void conversion(string s, int c1[],int c2[],string inv[]);
void readInvalid(string s[]);
int main()
{
    string name,data;
    int col1[10],col2;
    int test [] = {7,8000,99999,11,100000};
    string tests[] = {"asdasd", "blah", "goods"};
    string invalid[10];
    string line,tester;
    double avg1;
    int currentInt = 0, highest2 =0, rows = 0, divisor = 0;

    //===================================Input=================================================
    //While name is not correct
    cout << "Please input the filename:" << endl;
    cin>> name;

    ifstream myfile ("DataFile.txt");
    if(myfile.is_open()){
            while(getline(myfile,line)){
                line = (line+"\n");
                tester += line ;
                //cout<<line<<endl;
            }
            myfile.close();
    }else{

         cout<<"cantfind"<<endl;
        }


    //once we have the correct file we pull all data into one string if possible
    //if name is correct loop through rows of data
    //if first col data is an int add to col1, add to avg1 and divisor++
    //else add to invalid
    //2nd col if int add to col2,
    //if currentInt > highest2, highest2 = currentInt
    //else add to invalid
    //rows++

    //===================================Output=================================================
    cout<<tester<<endl;
    //Avg C1
    cout<<std::fixed;
    cout<<"The average value of all numbers in the first column: "<<std::setprecision(4)<<avg(test)<<endl;;
    //High C2
    cout<<"The largest value of all numbers in the second column: "<<high(test)<<endl;
    //Total Rows in file
    cout<<"The total number of rows in the file is: "<<rows<<endl;
    //Invalid numbers
    readInvalid(tests);

    return 0;
}

//Average array of ints and turn into double
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

//Potentially references to all arrays
void conversion(string s,int c1[],int c2[],string inv[]){
//grab first section up to ','

//test if it is an int or string
//if its an int add to c1 else add to inv
//grab next set of string to '/n'
//test if it is an int or string
//if its an int add to c2 else add to inv
}

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
