#include<iostream>
#include<unordered_map>
using namespace std;


bool isValid(string str1, string str2){

    unordered_map<char,int> map;

    for(int i = 0; i<str1.size(); i++){
        if(map.count(str1[i])){
            map[str1[i]]++;
        }else{                            // to store frequncy of a character 
            map[str1[i]] = 1;
        }
    }

    for(int i = 0;i<str2.size(); i++){
       if(map.count(str2[i])){
            map[str2[i]]--;
            if(map[str2[i]] == 0){
                map.erase(str2[i]);
            }
       }
       else{
        return false;
       }
    }

    if(map.size() == 0){
        return true;
    }
}

int main(){


    string s = "race";
    string t = "cere";

    cout<<isValid(s,t)<<endl;
    return 0;
}