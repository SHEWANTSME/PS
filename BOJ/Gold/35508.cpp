//Good Bye, 토마토! - G4 - 2026.04.28(백준 서버 종료날)
// 이건 시간초과가 나는 코드 -> O(n^2)
#include <iostream>
#include <vector>
#include<algorithm>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n,t;
vector<int>a;
vector<int>b;
vector<int>c;
int ans=0;
int main(){
    fastio;
    cin>>n>>t;
    for(int i=0; i<n; i++){
        int aa,bb,cc;
        cin>>aa>>bb>>cc;
        a.push_back(aa);b.push_back(bb);c.push_back(cc);
    }
    for(int i=0; i<n; i++){
        if(a[i]<=t) ans=max(ans,b[i]+c[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++){
            if(i==j)continue;
            if(a[i]+a[j]<=t) ans = max(ans,b[i]+c[j]);
        }
    }
    cout<<ans<<endl;    
}

// 정답 코드
// 정렬 + prefix max 쓰면 O(n logn)가능
// 먼저 (a, c) 기준으로 정렬하고
// c의 prefix max 배열 만들고
// 각 i에 대해 t-a[i]이하인 j를 binary search로 찾고 해당 범위에서 max c 찾으면 됨

#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl "\n"
using namespace std;

int n,t;
vector<int>a;
vector<int>b;
vector<int>c;

int main(){
    fastio;
    cin>>n>>t;
    for(int i=0; i<n; i++){
        int aa,bb,cc;
        cin>>aa>>bb>>cc;
        a.push_back(aa);
        b.push_back(bb);
        c.push_back(cc);
    }
    
    int ans=0;
    for(int i=0; i<n; i++){
        if(a[i]<=t) ans=max(ans,b[i]+c[i]);
    }
    vector<pair<int,int>> vc;
    for(int i=0; i<n; i++) vc.push_back({a[i], c[i]});// (a, c) 정렬용 vec
    sort(vc.begin(), vc.end());
    vector<int> prefix(n); // prefix max
    prefix[0]=vc[0].second;
    for(int i=1; i<n; i++) prefix[i]=max(prefix[i-1], vc[i].second);

    for(int i=0; i<n; i++){
        if(a[i]>t) continue;
        int remain = t-a[i];

        int l=0, r=n-1, pos=-1;
        while(l<=r){// checking the upper bound
            int mid=(l+r)/2;
            if(vc[mid].first <= remain){
                pos=mid;
                l=mid+1;
            }else r=mid-1;
        }
        if(pos!=-1) ans = max(ans, b[i]+prefix[pos]);
    }
    cout<<ans<<endl;
}