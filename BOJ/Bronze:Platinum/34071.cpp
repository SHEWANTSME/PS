//첫 번째 문제는 정말 쉬운 문제일까? - B4 - 2025.07.26
#include<iostream>
#include<algorithm>
using namespace std;
int n; int minn = 1001; int maxx =-1;
int main(){
    cin>>n; int chk=0;
    for(int i=1; i<=n;i++){
        int t; cin>>t;
        if(i==1)chk=t;
        minn = min(t,minn);
        maxx = max(t,maxx);
    }
    if(chk==minn){cout<<"ez"<<endl; exit(0);}
    if(chk==maxx){cout<<"hard"<<endl;exit(0);}
    cout<<"?"<<endl;
}