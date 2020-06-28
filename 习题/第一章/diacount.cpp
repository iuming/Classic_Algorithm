#include<iostream>
using namespace std;
int main(){
    const int price=95;
    int n;
    cin>>n;
    float count=price*n;
    if(count>=300){
        cout<<0.85*count;
        return 0;
    }else{
        cout<<count;
        return 0;
    }
}