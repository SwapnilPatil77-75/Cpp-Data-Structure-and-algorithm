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

    void printStack(){
        T data = top();
        while(!(stack.empty())){
            T data = top();
            cout<<data<<" ";
            pop();

        }
        cout<<endl;
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
    S.push('O');
    S.push('V');
    S.push('I');
    S.push('N');
    S.pushAtBottom(S,'L');
    S.pushAtBottom(S,'O');
    S.pushAtBottom(S,'V');
    S.pushAtBottom(S,'E');
    S.printStack();
   
    // S.pushAtBottom(S,'L');
    // S.pushAtBottom(S,'O');
    // S.pushAtBottom(S,'V');
    // S.pushAtBottom(S,'E');
    // S.printStack();
    
}