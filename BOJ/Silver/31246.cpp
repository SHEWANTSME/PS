//모바일 광고 입찰 - S5 - 2024/02/29
#include<iostream>
#include<algorithm>
#include<queue>
#define fastio cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
using namespace std;
int n,k;
priority_queue<int>pq;
int main(){
    fastio;
    cin>>n>>k;
    while(n--){
        int a,b;
        cin>>a>>b;
        pq.push(a-b);
    }
    int cnt=0;
    int nn = pq.size(); // 이거때문에 시간 잡아먹었네..
    for(int i=0; i<nn;i++){
        if(pq.top()>=0){
            pq.pop();// pq가 pop될 수도 있으니까 for문ㅇ안에서 pq.size()를 쓰면 안된다.
            cnt++;
        }    
    }
    cnt=k-cnt;
    if(cnt<=0) cout<<0<<"\n";
    else{
        for(int i=1;i<cnt;i++){
            pq.pop();
        }
        cout<<-pq.top()<<"\n";
    }
}