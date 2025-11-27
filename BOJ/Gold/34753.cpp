//백준 빙고 스피드러너 - G3 - 2025.11.24
// 완료 -> 누적합이랑 line_selected로 따져줘야함
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define ll long long
using namespace std;
int n;
ll arr[1503][1503];
ll visited[1503][1503];
bool line_selected[1503*2+5];
ll selected_count = 0;
ll sum_vertical[1503];
ll sum_horizontal[1503];
ll sum_diagonal =0;
ll sum_rev_diagonal=0;

int main(){
    fastio;
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>arr[i][j];
    
    // 누적합
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sum_horizontal[i] += arr[i][j];
            sum_vertical[j] += arr[i][j];
            if(i==j) sum_diagonal += arr[i][j];
            if(i+j==n+1) sum_rev_diagonal += arr[i][j];
        }
    }

    ll tmp = 0;
    while (selected_count < 2*n+2) {
        vector<pair<ll,ll>> bingo; // {id, cost}
        for(int i=1; i<=n; i++){ //horizontal
            if (not line_selected[i]) bingo.push_back({i, sum_horizontal[i]});
        }
        for(int j=1; j<=n; j++) { //vertical
            if (not line_selected[n + j]) bingo.push_back({n + j, sum_vertical[j]});
        }
        // diagonal, reverse diagonal
        if (not line_selected[2*n+1]) bingo.push_back({2*n+1 ,sum_diagonal});
        if (not line_selected[2*n+2]) bingo.push_back({2*n+2, sum_rev_diagonal});
        if (bingo.empty()) break;

        sort(bingo.begin(), bingo.end(),
            [](const pair<ll,ll>& a, const pair<ll,ll>& b) {
                if(a.second != b.second) return a.second < b.second;// cost 기준 오름차순
                return a.first < b.first;// cost가 같으면 id 기준 오름차순
            });

        auto [id, cost] = bingo[0];
        tmp += cost;
        cout<<tmp<<endl;
        line_selected[id] = 1;
        selected_count++;
        if (id >= 1 and id <= n) {// horizontal
            int r = id;
            for (int c=1; c<=n; c++) {
                if (not visited[r][c]) {
                    visited[r][c] = 1;
                    ll v = arr[r][c];
                    sum_horizontal[r] -= v;
                    sum_vertical[c] -= v;
                    if (r == c) sum_diagonal -= v;
                    if (r+c == n+1) sum_rev_diagonal -= v;
                }
            }
        }
        else if (id>n and id<=2*n) {// vertical
            int c = id-n;
            for (int r = 1; r <= n; r++) {
                if (not visited[r][c]) {
                    visited[r][c] = 1;
                    ll v = arr[r][c];
                    sum_horizontal[r] -= v;
                    sum_vertical[c] -= v;
                    if (r == c) sum_diagonal -= v;
                    if (r+c == n+1) sum_rev_diagonal -= v;
                }
            }
        }
        else if (id == 2*n +1) {// main diagonal
            for (int i = 1; i <= n; i++) {
                int r = i;
                int c = i;
                if (not visited[r][c]) {
                    visited[r][c] = 1;
                    ll v = arr[r][c];
                    sum_horizontal[r] -= v;
                    sum_vertical[c] -= v;
                    sum_diagonal -= v;
                    if (r+c == n+1) sum_rev_diagonal -= v;
                }
            }
        }
        else if (id == 2*n+2) {//reverse diagonal
            for (int i = 1; i <= n; i++) {
                int r = i;
                int c = n-i+1;
                if (not visited[r][c]) {
                    visited[r][c] = 1;
                    ll v = arr[r][c];
                    sum_horizontal[r] -= v;
                    sum_vertical[c] -= v;
                    sum_rev_diagonal -= v;
                    if (r == c) sum_diagonal -= v;
                }
            }
        }
        else break;
    }

}