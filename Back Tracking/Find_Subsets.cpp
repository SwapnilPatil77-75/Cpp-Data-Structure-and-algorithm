#include<iostream>
using namespace std;



void Substring(string str , string subset){
    if(str.size() == 0){
        cout<<subset<<endl;
        return;
    }
    int n = str.size();

    char ch = str[0];
    Substring(str.substr(1,n-1), subset + ch);  // Ch is in subset 
    Substring(str.substr(1,n-1),subset);        // ch is not in subset 
}
int main(){

string str = "NIVO";
string subset = "";
Substring(str,subset);



    return 0;
}