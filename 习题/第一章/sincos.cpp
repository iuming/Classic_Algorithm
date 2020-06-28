#include<iostream>
#include<cmath>
#define PI 3.14159265350
using namespace std;
int main(){
    double n;
    cin>>n;
    n=n/180*PI;
    cout<<sin(n)<<endl<<cos(n)<<endl;
    getchar();
    return 0;
}