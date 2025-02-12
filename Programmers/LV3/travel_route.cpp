// 여행경로 - LV3 - 2025.02.12

// 처음 풀이
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string>ans;
int vis[10002];
bool chk=0;
void DFS(string now, vector<vector<string>> tickets , int cnt){
    if(cnt == tickets.size())chk=1;
    ans.push_back(now);
    for(int i=0; i<tickets.size();i++){
        if(not vis[i] and tickets[i][0]==now){
            vis[i]=1;
            DFS(tickets[i][1],tickets,cnt+1);
            if(not chk){
                ans.pop_back();
                vis[i]=0;
            }
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets, 0);
    return ans;
}

// 두번째 풀이
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, vector<string>> graph;
vector<string> ans;
bool chk = 0;

void DFS(string now, int cnt, int totalTickets) {
    ans.push_back(now);
    if (cnt == totalTickets) {
        chk = 1; return;
    }
    vector<string>& destinations = graph[now];
    for (int i = 0; i < destinations.size(); i++) {
        string next = destinations[i];
        destinations.erase(destinations.begin() + i); // 방문 처리
        DFS(next, cnt + 1, totalTickets);
        if(chk) return;  // 경로 찾았으면 즉시 종료
        destinations.insert(destinations.begin() + i, next); // 방문 취소
    }
    ans.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    for (auto& ticket : tickets) 
        graph[ticket[0]].push_back(ticket[1]);    
    for (auto& entry : graph)
        sort(entry.second.begin(), entry.second.end()); // 사전순 정렬
    DFS("ICN", 0, tickets.size());
    return ans;
}
