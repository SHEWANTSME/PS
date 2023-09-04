//알파빌과 베타빌 - S5 - 2023/09/04
// greedy
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<int>v;
int cnt=0;
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int t; cin>>t;
        v.push_back(t);
    }
    for(int i=0; i<m;i++){
        int t; cin>>t;
        for(int j=0; j<m; j++){
            if(v[j]==t)cnt++;
        }
    }
    cout<<m-cnt<<endl;
    /* 참고로 이렇게 풀면 틀림
    for(int i=0; i<m;i++){
        int t; cin>>t;
        w.push_back(t);
    }
    int ans=0;
    for(int i=0 ;i<m; i++){
        for(int j=0 ;j<n; j++){
            if(w[i]==v[j] and i==j)ans++;
        }
    }
    cout<<w.size()-ans<<endl;
    */
}