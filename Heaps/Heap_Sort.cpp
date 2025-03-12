#include<iostream>
#include<vector>
using namespace std;


void heapify(int i , vector<int> &vec, int n){
    int left = i*2+1;
    int right = i*2+2;
    int maxInx = i;

    if(left < n && vec[left] < vec[maxInx]){   // " < " will sort the array in descending 
        maxInx = left;                         // order 
    } 
    if(right < n && vec[right] < vec[maxInx]){
        maxInx = right;
    } 


    if(maxInx != i){
        swap(vec[i],vec[maxInx]);
        heapify(maxInx, vec, n);
    }



}
void heapSort(vector<int> &vec){
    int n = vec.size();
// Step 1 make the given array into maxHeap 
    for(int i = (n/2)-1; i>= 0; i--){
        heapify(i,vec,n);  // fix the heap only for the parent nodes not for the leaf nodes
    }
    int i =1;
    while(i!=n){
        swap(vec[0],vec[n-i]);

        heapify(0,vec,n-i);
        i++;
        
    }
    //step 2 swap the max- heap root to the the end node
    // this will make the array in ascending order 


    // for(int i = n-1; i>=0; i--){
    //     swap(vec[0],vec[i]);
    //     heapify(0,vec,i);
    // }
}

int main(){


    vector<int> vec ={1,4,2,5,3};

    heapSort(vec);
    for(int i = 0; i<vec.size(); i++){
        cout<<vec[i]<<" ";

    }
    cout<<endl;
}