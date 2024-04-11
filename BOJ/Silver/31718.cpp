// Double Up - S3 - 2024/04/11
// 처음 풀이 - 겁나 난잡하게 풀었음
#include <iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
priority_queue<int,vector<int>,greater<int>>pq2;
map<int,int>mp;
int arr[200001];
map<int,int>mp2;
int ans=-1;
int main(){
    int n;cin>>n;
    for(int i=1; i<=n ; i++){
        int t; cin>>t;pq2.push(t);
        arr[i]=1;
        mp[t]++;
    }
    
    while(not pq2.empty()){
        int fr = pq2.top();
        if(mp2[fr]!=0){
            pq2.pop();
            continue;
        }
        mp2[fr]=1;
        pq2.pop();
        if(mp[fr*2]!=0){
            mp[fr*2]+=mp[fr];
            ans = max(ans,mp[fr*2]);
        }
    }
    cout<<ans<<endl;
}
// 23% 틀렸다고 나오는데, 뭔지 잘 모르겠어서 패스

// 두 번째 풀이 - 훨씬 간결하게 품
#include <iostream>
#include<algorithm>
#include<unordered_map>// map보다 빠르고 메모리 효율이 좋음
using namespace std;
unordered_map<int,int>mp;
int arr[200001];
int ans=-1;

int main(){
    int n;cin>>n;
    for(int i=1; i<=n ; i++) cin>>arr[i];
    for(int i=1; i<=n;i++){
        int now = arr[i];
        while(now%2==0) now/=2;// 이게 핵심 -> 2로 나누어 떨어지는 수를 찾아서 그 수의 개수를 세면 되는거임. 
        // 아까처럼 2를 곱해가면서 찾는게 아니라 
        if(mp.contains(now)) mp[now]++;// contains함수는 해당 key값이 있는지 확인하는 함수인데, cpp20부터 있음
        else mp[now]=1;
    }
    for(auto &e : mp) ans = max(ans, e.second);
    cout<<ans<<endl;
}
// *max_element 쓸때는 -> vector에선 arr.begin() 이렇게 하고 일반 배열에선 begin(arr) 하면 됨
// 일반 배열 할때는 *max_element(begin(arr),end(arr));
// vector 할때는 *max_element(arr.begin(),arr.end());