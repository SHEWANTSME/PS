//Good Bye, 설탕 배달! - S2 - 2026.04.28(백준 서버 종료날)
//과거보다 지금 prefix max가 더 중요 -> Greedy
#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl "\n"
#define ll long long
using namespace std;
int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<vector<ll>> arr(n, vector<ll>(4));
        for(int i=0;i<n;i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
        ll x=0,y=0,z=0;
        bool flag=1;

        for(int i=0;i<n;i++){
            x=max(x,arr[i][0]);
            y=max(y,arr[i][1]);
            z=max(z,arr[i][2]);
            if(x+y+z>=arr[i][3]-i){
                flag=0;break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}