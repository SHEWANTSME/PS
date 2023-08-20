// // 텀 프로젝트 - G3 - 2023/08/15
// // 기존 코드가 vector와 map의 남용으로 인해 시간초과가 발생했다고 판단함.
// // + 투머치 memset도 한 몫한듯

// // 기존 코드 (실패)
// // 텀 프로젝트 - G3 - 2023/08/15
// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<map>
// #include<string.h>
// #define endl "\n"
// using namespace std;
// int tc, n;
// int arr[100001];
// int visited[100001];
// vector<int>b_v;//black_vector
// vector<int>r_v;//red_vector
// int ans = 0;
// map<int, int>b_m;//black_map
// map<int, int>r_m;//red_map
// int Func(int x) {
//     if (visited[x]) {
//         for (auto& e : b_v) 
//             b_m[e] = 1;
//         return b_v.size();
//     }
//     visited[x] = 1;
//     b_v.push_back(x);
//     int nxt = arr[x];
//     r_v.push_back(nxt);
//     if (r_m[nxt]) return -1;
//     r_m[nxt] = 1;
//     return Func(nxt);
// }

// int main() {
//     cin >> tc;
//     while (tc--) {
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//             cin >> arr[i];
//         for (int i = 1; i <= n; i++) {
//             if (b_m[i])continue;
//             int temp = Func(i);
//             if (temp != -1) {
//                 ans += temp;
//             }
//             memset(visited, 0, sizeof(visited));
//             b_v.clear();
//             r_v.clear();
//             r_m.clear();
//         }
//        // cout << n << " " << ans << endl;
//         cout << n-ans << endl;
//         b_m.clear();
//         ans = 0;
//         for (int i = 1; i <= n; i++)
//             arr[i] = 0;
//     }
// }

// 새로운 코드 (성공)
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#define endl "\n"
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0) // much faster time taken
using namespace std;
int tc, n;
int arr[100001];
int visited[100001];
int done[100001];// 방문 했다고 다 끝난건 아니기 때문에, cycle 판별여부까지 끝난 상태의 node면 done[x]=1로 둔다.
int cnt = 0;// cycle이루는 node의 개수를 count

// 그림이랑 node의 상태를 확인해보면서 코드를 짜면 잘 알 수있음
void Func(int node){
    visited[node]=1;// 현재 node 방문표시
    int nxt = arr[node]; // 다음 방문할놈 
    if(not visited[nxt])Func(nxt); // 다음 방문할놈이 visited되지 않았다면 -> Recursion돌자
    else if(not done[nxt]){ // 다음 방문할놈이 visited되었고, 다음 방문할놈이 done된 상태가 아니면
    // cycle이 발생할 조건이라서 for문을 돈다.
        for(int i=nxt;i!=node;i=arr[i]){// cycle내 노드 탐색-> 이런 for문이 cycle 탐색할때 유용한 형태임
            cnt++;// cnt up 해주고
        }
        cnt++; // 지 자신도 cycle에 포함되니까 cnt 한번 더 up 해주고
    }
    done[node]=1;// 여기까지 왔으면 해당 node에 대한 cycle 판별 여부가 끝났으니 done=1로 해야지
}

int main() {
    fastio;
    cin >> tc;
    while(tc--){
        cin>>n;
        for(int i=1; i<=n ; i++)
            cin>>arr[i];
        // 모든 tc 경우에 초기화되어야함
        memset(visited,0,sizeof(visited));
        memset(done,0,sizeof(done));
        cnt=0;
        for(int i=1; i<=n; i++){
            if(not visited[i])Func(i);
        }
        cout<<n-cnt<<endl;
    }
}