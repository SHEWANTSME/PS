#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++){
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    int answer = 0;
    
    while(!q.empty()){   
        auto cur = q.front();
        q.pop();
        
        int priority = cur.first;
        int idx = cur.second;
        if(priority < pq.top()) q.push(cur);
        else{
            pq.pop();
            answer++;
            if(idx == location) return answer;
        }
    }
    return answer;
}
/*
[abcd] [2132]
a(2<=3)
[bcda]
b(1<=3)
[cdab]
c (3=3)
[dab]
d(2=2)
[ab]
a (2=2)
[b]
b
*/