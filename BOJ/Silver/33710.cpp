// 비장의 일격(Small) - S4 - 2025/04/11
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set> // unordered -> 중복 허용 하지 않음
#include <string>
using namespace std;
int n,k;
string s;
int ans = 1e9;
unordered_set<string> vis[3]; 

void dfs(string s, int cnt) {
    if (vis[cnt].count(s)) return; 
    vis[cnt].insert(s); 
    if (cnt == k) {
        ans = min(ans,(int)s.size()); // (int)s.size() -> string의 길이를 int로 바꿔줘야함
        return;
    }
    for(int i=0; i<s.size();i++){
        for(int j=i+1 ; j<s.size();j++){
            if(s[i] == s[j] and s[i] !='X'){
                string new_s = s.substr(0,i) + s.substr(j+1); // substr(0,i) -> i까지의 문자열, substr(j+1) -> j+1부터 끝까지의 문자열
                cout<<new_s<<endl;
                dfs(new_s, cnt+1); 
            }
        }
    }
    ans = min(ans,(int)s.size());
}

int main() {
    cin>>n>>k>>s;
    dfs(s,0);
    cout<<ans<<"\n";
}
