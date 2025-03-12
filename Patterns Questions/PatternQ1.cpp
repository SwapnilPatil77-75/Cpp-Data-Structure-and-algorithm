#include<iostream>
using namespace std;

int main(){
int n;
bool value = true;
cout<<" Enter the number "<< endl;
cin>>n;

for(int i = 1; i<=n; i++){
  for(int j = 1; j<=i; j++){
    cout<<value;
    value =  !value;
  }
  cout<<endl;
}


    return 0;
}