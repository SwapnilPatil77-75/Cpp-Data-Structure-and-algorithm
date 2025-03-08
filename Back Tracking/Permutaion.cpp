#include<iostream>
using namespace std;

void permutaion(string str, string ans){
    int n = str.size();
    if(n == 0){
        cout<<ans<<"\n";
        return;
    }

    for(int i = 0; i<n; i++){
        char ch = str[i];
        string nextStr = str.substr(0,i) + str.substr(i+1, n-i-1);
        permutaion(nextStr,ans+ch);
    }
}

int main(){
string str="abcd";
string ans= "";

permutaion(str,ans);



    return 0;
}