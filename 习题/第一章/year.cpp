#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%4==0){
        if(n%100==0){
            if(n%400==0){
                cout<<"yes"<<endl;
                return 0;
            }else{
                cout<<"no"<<endl;
                return 0;
            }
        }else{
            cout<<"yes"<<endl;
            return 0;
        }
    }else{
        cout<<"no"<<endl;
        return 0;
    }
}