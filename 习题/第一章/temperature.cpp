#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    float f;
    cin>>f;
    cout<<fixed<<setprecision(3)<<5*(f-32)/9;
    return 0;
}