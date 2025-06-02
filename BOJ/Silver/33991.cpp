//전철 통학 - S5 - 2025.06.02
#include<iostream>
#include<algorithm>
#include<queue>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl "\n"
using namespace std;
int x1,x2,x3,y1,y2,y3,Q;
int main(){
    fastio;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>Q;
    while(Q--){
        int X,Y,t1,t2,t3;
        cin>>X>>Y>>t1>>t2>>t3;
        int tmp1 = abs(X-x1)+abs(Y-y1);
        int tmp2 = abs(X-x2)+abs(Y-y2);
        int tmp3 = abs(X-x3)+abs(Y-y3);
        tmp1 = ((tmp1+t1 -1)/t1) *t1;
        tmp2 = ((tmp2+t2 -1)/t2) *t2;
        tmp3 = ((tmp3+t3 -1)/t3) *t3;
        cout<<min(tmp1,min(tmp2,tmp3))<<endl;
    }
}