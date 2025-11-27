//백준 빙고 스피드러너 - G3 - 2025.11.24
// 시간초과 -> chk함수 최적화 필요
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define ll long long
using namespace std;
int n;
ll arr[1503][1503];
ll fin=0;
ll visited[1503][1503];

ll chk_vertical(int y, ll pre){ // k는 k번째 빙고가 될 수 있는 minimum 값
    ll sum = 0;
    for(int i=1; i<=n; i++){
        if(visited[i][y]==0) sum += arr[i][y];
    }
    if(sum==0) return -1;
    else return pre+sum;
}
ll chk_horizontal(int x, ll pre){
    ll sum = 0;
    for(int j=1; j<=n; j++){
        if(visited[x][j]==0) sum += arr[x][j];
    }
    if(sum==0) return -1;
    else return pre+sum;
}
ll chk_diagonal(ll pre){
    ll sum = 0;
    for(int i=1; i<=n; i++){
        if(visited[i][i]==0) sum += arr[i][i];
    }
    if(sum==0) return -1;
    else return pre+sum;

}
ll chk_rev_diagonal(ll pre){
    ll sum = 0;
    for(int i=1; i<=n; i++){
        if(visited[i][n-i+1]==0) sum += arr[i][n-i+1];
    }
    if(sum==0) return -1;
    else return pre+sum;
}

int main(){
    fastio;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
            fin+=arr[i][j];
        }
    }
    ll tmp = 0;
    while(1){
        vector<pair<ll,ll>> bingo;
        for(int i=1;i<=n;i++){
            ll hh = chk_horizontal(i,tmp);
            if(hh != -1) {bingo.push_back({i,hh});}
        }
        for(int i=1;i<=n;i++){
            ll vv = chk_vertical(i,tmp);
            if(vv != -1) {bingo.push_back({n+i,vv});}
        }
        ll dd = chk_diagonal(tmp); 
        if(dd!=-1) bingo.push_back({2*n+1, dd});
        ll rdd = chk_rev_diagonal(tmp); 
        if(rdd!=-1) bingo.push_back({2*n+2, rdd});
        
        sort(bingo.begin(), bingo.end(),
            [](const pair<ll,ll>& a, const pair<ll,ll>& b) {
                return a.second < b.second;   // second 기준 오름차순
            });
        bool flag= 0;
        //cout<<"bingo bingo : "<<bingo[0].second<<endl;
        if(bingo.empty()) break;
        if(bingo[0].first>=1 and bingo[0].first<=n){//horizontal
            ll row = bingo[0].first;
            for(int j=1; j<=n; j++){
                visited[row][j]=1;
            }
        }
        else if(bingo[0].first>n and bingo[0].first<=2*n){//vertical
            ll col = bingo[0].first - n;
            for(int i=1; i<=n; i++){
                visited[i][col]=1;
            }
        }
        else if(bingo[0].first == 2*n+1){//diagonal
            for(int i=1; i<=n; i++){
                visited[i][i]=1;
            }
        }
        else if(bingo[0].first == 2*n+2){//reverse diagonal
            for(int i=1; i<=n; i++){
                visited[i][n-i+1]=1;
            }
        }
        else{
            flag=1;break;
        }
        if(flag) break;
        tmp = bingo[0].second;
        cout<<tmp<<endl;
    }
    cout<<fin<<endl;
}