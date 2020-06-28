#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int a[3];
    for(int i=0;i<3;++i){
        cin>>a[i];
    }
    sort(a,a+3);
    if(!(a[0]+a[1]<a[2]||a[0]<a[2]-a[1])){
        if(sqrt(a[0])+sqrt(a[1])==sqrt(a[2])){
            cout<<"yes"<<endl;
            return 0;
        }else{
            cout<<"no"<<endl;
            return 0;
        }
    }else{
        cout<<"not a triangle"<<endl;
        return 0;
    }
}