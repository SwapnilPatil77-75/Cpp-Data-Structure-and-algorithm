#include<iostream>
#include<vector>
using namespace std;
// Max Heap Implementaion 

class Heap{
    vector<int> vec;

public:
        void push(int val){
            // Step 1 add value to end 
            vec.push_back(val);
            // fix the Heap 

            int x = vec.size()-1;
            int parent = (x-1)/2;

            while(x>= 0 && vec[x] > vec[parent]){
                swap(vec[x],vec[parent]);
                x = parent;
                parent = (x-1)/2;
            }
        }

        void heapify(int i){

            if(i >= vec.size()){
                return;
            }

            // calculate left and right child 
            int l = (2*i)+1;
            int r = (2*i)+2;
            int maxInx = i;

            // find the largest child among 2 
            if( l < vec.size() && vec[maxInx] > vec[l]){
                maxInx = l;
            }

            if( r < vec.size() && vec[maxInx] > vec[r]){
                maxInx = r;
            }

            // swap with largest child 
            swap(vec[maxInx],vec[i]);
            if(vec[maxInx] != vec[i]){
                // call for swapped child 
                heapify(maxInx);
            }

            
        }

        void  pop(){

            //step 1 
            // swap root and last Node 

            swap(vec[0],vec[vec.size()-1]);

            // step 2
            //delete last node
            vec.pop_back();

            // step 3
            // fix the heap 

            heapify(0);
        }

        int top(){
            return vec[0];
        }      

        bool isempty(){
            return vec.size()== 0;
        }
};

int main(){

    Heap heap;
    heap.push(56);
    heap.push(20);
    heap.push(80);

   while(!(heap.isempty())){
        cout<<heap.top()<<" ";
        heap.pop();
   }
   cout<<endl;

    return 0;
}