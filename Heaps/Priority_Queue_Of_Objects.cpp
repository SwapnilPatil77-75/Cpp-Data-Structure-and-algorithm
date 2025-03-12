#include<iostream>
#include<queue>
using namespace std;


class Student{

public:
    string name;
    int marks;


    Student(string name , int marks){
        this->name = name;
        this->marks = marks;
    }
    
     // Comparison for max-Heap which is deafult 
    // bool operator <(const Student &obj)const{
    //     return this->marks < obj.marks;
    // }
        // Comparison for min-Heap 
     bool operator <(const Student &obj)const{
        return this->marks < obj.marks;
    }
};




int main(){
    priority_queue<Student> pq;

    pq.push(Student("Swapnil",96));
    pq.push(Student("Nivo",80));
    pq.push(Student("Aman",76));


    while(!pq.empty()){
        cout<<pq.top().name<<" "<<pq.top().marks<<"\n";
        pq.pop();
    }

return 0;
}