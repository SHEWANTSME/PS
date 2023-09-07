//귀여운 라이언 - S1 - 2023/09/07
// sliding window 문제. 근데 나는 2 pointer로 품
// 내 풀이 - 2 pointer
#include<iostream>
#include<queue>
using namespace std;
int n,k;
queue<int>q;// 라이언이 있는 위치를 담는 큐
int minn=1e9;
int endd=-1;// 라이언이 있는 위치 중 가장 마지막 위치
int main(){
    cin>>n>>k;
    bool flag=0;// k==1인지 아닌지
    bool flag2=0;// 라이언이 있는지 없는지
    if(k==1)flag=1;
    for(int i=1; i<=n;i++){
        int t;cin>>t;
        if(flag2==1)continue;
        if(flag==1){
            if(t==1)flag2=1;
        }
        if(t==1){
            if(q.empty()){q.push(i);continue;}// q가 비었을땐 넣고 continue
            else{//q에 뭐라도 있을 땐
                q.push(i);endd=i;// endd 갱신
                if(q.size()==k){// q의 크기가 k일때
                    int tmp=q.front();
                    int len=endd-tmp+1;// 길이
                    minn=(minn<len)?minn:len;// 최소값 갱신
                    q.pop();
                }
            }
        }
    }
    if(flag){// k==1일때
        if(flag2){cout<<1<<endl;exit(0);}
        else {cout<<-1<<endl;exit(0);}
    }
    // 위에서 exit(0)안해주면 아래코드도 실행되는 경우 존재
    if(minn==1e9) cout<<-1<<endl;
    else cout<<minn<<endl;
}















// sliding window 풀이
// 비교해보셈
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int n,k;
int ans=1e9;
int main() {
    cin>>n>>k;
	for (int i = 0; i < n; i++) {
		int x;cin>>x;
        if(x==1)v.push_back(i);// 라이언이 있는 위치를 v에 넣음
	}
    for(int i=k-1;i<v.size();i++)// v.size()가 n보다 작을 수 있음!
        ans=min(ans,v[i]-v[i-k+1]+1);// v[i]는 끝점, v[i-k+1]은 시작점
    cout<<(ans==1e9?-1:ans)<<endl;// ans가 1e9이면 -1, 아니면 ans 출력
}
