#include<iostream>
using namespace std;

class Sample{

public:
int age; 
int het;

Sample(int age ,int het){
    this-> age = age;
    this-> het = het;
}
};


void print(){
    Sample* acc;

    cout<<acc->age<<" "<<acc->het;
}

int main(){

//Sample(26,23);
Sample obj = Sample(26,23);
cout<<obj.age;
Sample* sam;
sam = &obj;
cout<<sam->het;


}