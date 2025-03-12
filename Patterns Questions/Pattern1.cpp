#include<iostream>
using namespace std;

int main(){

int n ;
cout<< " Enter the number ";
cin >> n;
// 1 1 1 1 
// 2 2 2 2
// 3 3 3 3
// 5 5 5 5

for( int i = 1; i<= n; i++ ){
    for(int j = 1 ; j<=4; j++){
        cout<<i<<" ";
    }
    cout<<endl;
}

//*
// **
// ***
// ****
// *****
for(int i =1  ; i<=n; i++){ 
    for(int j = 1; j<=i ; j++){
        cout<<"*";
    }
    cout<<endl;
}

// ******
// *    *
// *    *
// *    *
// ******
for(int i = 1; i<=n ; i++)
{
cout<<"*";
for(int j= 1; j<=n-1; j++){
    if(i == 1 || i == n){
        cout<<"*";
    }else{
        cout<<" ";
    }
}


cout<<"*"<<endl;
}


for(int i  =1 ; i<=n; i++){
    for(int j = 1; j<= n-i ; j++){
        cout<<" ";
    }

    for(int j = 1 ; j<=i ; j++){
        cout<<"*";
    }
    cout<<endl;
}
  int num = 1;
for(int i =1; i<=n; i++){
    //int num = 1;
    for(int j=1; j<= i ; j++){
        cout<<num<<" ";
        num++;
    }
cout<<endl;
}


    return 0;
}