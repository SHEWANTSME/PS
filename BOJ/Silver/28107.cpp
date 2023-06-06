//회전초밥 - S1 - 2023/06/06
// 아이패드 그려진거 보고 다시 봐방 금방 나올듯..!
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int sonnim[100001];
//int customer[100001];
//vector<int>customer[100001];
vector<pair<int,int>>customer[100001];
queue<int>q;
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0 ; i<n;i++){
        int t;cin>>t;
        for(int j=0; j<t;j++){
            int k;cin>>k;
            customer[i].push_back({k,0});
        }
    }
    /*
    예시를 보면
    q : <3 2 1 4 5>
    customer[0] {(1,0) , (6,0)}
    customer[1] {(2,0), (3,0), (5,0)}
    customer[2] {(1,0)}
    */
    for(int i=0;i<m;i++){
        int p;cin>>p;
        q.push(p);
    }
    vector<int>ans(n+1);
    // 보니까 이 풀이가 오래걸리는듯
    while(not q.empty()){
        int fr=q.front();
        q.pop();
        bool flag=0;
        for(int i=0; i<n ; i++){
            for(auto &e : customer[i]){
                if(e.second==1 or e.first !=fr)continue;
                if(e.first == fr){
                    e.second =1;
                    ans[i]++;
                    flag=1;break;
                }
            }
            if(flag==1)break;
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<endl;
    }    


}