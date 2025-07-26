// 3대 512 - B3 - 2025.05.25
#include<iostream>
#include<queue>
using namespace std;
int n;
priority_queue <int, vector<int>, greater<int> > pq;
int main(){
    cin>>n;
    while(n--){
        int a,b,c;cin>>a>>b>>c;
        if(a+b+c-512<0)continue;
        else{
            pq.push(a+b+c);
        }
    }
    if(not pq.empty()) cout<<pq.top()<<endl;
    else cout<<-1<<endl;
}