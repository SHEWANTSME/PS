// //컴소인의 크리스마스 - G5 - 2024/12/04

// 이전코드 -> arr[1e9]를 하면 메모리 낭비라서 터짐 
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<deque>
// using namespace std;
// int num_zero,tot_sum;
// int n;
// int arr[200001];
// int maxx = -1;
// deque<int>dq[200001];
// int main(){
//     cin>>n;
//     for(int i=1; i<=n;i++){
//         cin>>arr[i];
//         if(arr[i]==0){
//             num_zero++;
//         }
//         maxx = max(maxx,arr[i]);
//         tot_sum+=arr[i];
//         dq[arr[i]].push_back(i);
//     }
//     // if(num_zero != maxx){
//     //     cout<<-1<<endl;exit(0);
//     // }
//     if(tot_sum >=n){
//         cout<<-1<<endl;exit(0);
//     }
//     cout<<dq[0].front()<<" 0 "<<endl;
//     dq[0].pop_front();
//     // if(maxx-1 != dq[0].size()){
//     //     cout<<-1<<endl;exit(0);
//     // }
//     for(auto &e : dq[1]){
//         for(int i=0;i<2;i++){
//             cout<<e<<" 1 "<<endl;
//         }
//     }
//     if(not dq[1].empty()){
//         dq[1].clear();
//     }
//     for(int i=2; i<=200000;i++){
//         if(dq[i].empty())continue;
//         else{
//             for(auto &e : dq[i]){
//                 for(int j=0;j<i-1;j++){
//                     cout<<e<<" 2 "<<endl;
//                     cout<<dq[0].front()<<" 3 "<<endl;
//                     dq[0].pop_front();
//                 }
//                 for(int k=0;k<2;k++){
//                     cout<<e<<" 4 "<<endl;
//                 }
//             }
//             //i 0 i i 
//         }
//     }

// }

// 통과 코드
#include <iostream>
#include <unordered_map>
#include <deque>
#define endl "\n"
#define ll long long
using namespace std;

int num_zero;
int num_x;
ll tot_sum;
int n;
ll arr[200001];
unordered_map<int, deque<int>> q; // 지금처럼 sparse하고 빠른 정렬필요없고 중복X일땐 이렇게
// deque말고 걍 vector로 하는게 더 빠름(왜 deque로 했지?)

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        tot_sum += arr[i];
        q[arr[i]].push_front(i); //이렇게 sparse한 경우엔 unordered_map을 써줘야함
        // #include<map> -> map은 정렬O + 중복x , multimap은 정렬O + 중복 key 허락, 
        // #include<unordered_map> -> unordered_map은 정렬 X 중복 X , unordered_multimap -> 정렬X ,중복 keyO
    }
    if (tot_sum+1 != n) {// 이걸 안하면 30퍼쯤에서 틀리더라
        //x 개수 = O 개수+1 이여야만 함! 즉, 내가 구현한 대로 보면 tot_sum+1 = n이 아닐땐 무조건 -1임
        cout << -1 << endl;
        exit(0);
    }

    if (!q[0].empty()) {
        cout << q[0].front() << endl;
        q[0].pop_front();
    } else {
        cout << -1 << endl;
        exit(0);
    }

    for (auto &e : q[1]) {
        for (int i = 0; i < 2; i++) {
            cout << e << endl;
        }
    }
    q[1].clear();

    for (int i = 2; i <= 200000; i++) {
        if (q[i].empty()) continue;
        for (auto &e : q[i]) {
            for (int j = 0; j < i - 1; j++) {
                cout<<e<<endl;
                if (!q[0].empty()) {
                    cout << q[0].front() << endl;
                    q[0].pop_front();
                } else {
                    cout << -1 << endl;
                    exit(0);
                }
            }
            for (int k = 0; k < 2; k++) {
                cout << e << endl;
            }
        }
    }
}
