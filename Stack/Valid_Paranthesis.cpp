#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack{
public:
    vector<T> stack;

    void push(T val){
        stack.push_back(val);
    }
    void pop(){
        stack.pop_back();
    }

    T top(){
        return stack.back();
    }


    bool validParanthesis(string str){

        int i = 0;
        while(!(str.empty())){
            if(str[i] == '{' || str[i] == '(' || str[i] == '['){
                push(str[i]);
                i++;
            }
            if( str[i] == '}' || str[i] == ')' || str[i] == ']' ){
                T temp = top();
                if(temp == str[i]){
                    pop();
                    i++;
                }else{
                    return -1;
                }
            }
        }

        return 1;
    }


};

int main(){

    string str = "{([]}";
    Stack<char> S;
    cout<<S.validParanthesis(str);
}