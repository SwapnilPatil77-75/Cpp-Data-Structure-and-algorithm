#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack{
    vector<T> stack;
public:
    void push(T val){
        stack.push_back(val);
    }

    void pop(){
        stack.pop_back();
    }

    T top(){
        return stack.back();
    }

    void printStack(){
        T data = top();
        while(!(stack.empty())){
            T data = top();
            cout<<data<<" ";
            pop();

        }
        cout<<endl;
    }

    void reverse(Stack<T> &s){
        if(stack.empty()){
            return;
        }

        T temp = top();
        pop();

        reverse(s);
        pushAtBottom(s,temp);

    }
    void pushAtBottom(Stack<T> &s ,T val){
        if(stack.empty()){
            push(val);
            return;
        }

        T temp = top();
        pop();

        pushAtBottom(s, val);

        push(temp);
    }
};

int main(){

    Stack<int> s;   // Object Syntax for template class

    s.push(20);
    s.push(60);
    s.pop();
    //cout<<s.top()<<endl;
    s.printStack();
    Stack<char> S;
    S.push('N');
    S.push('I');
    S.push('V');
    S.push('O');
    S.reverse(S);
    S.printStack();
    
}