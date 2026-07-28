#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
/*
- 0ms 시점에 3ms가 소요되는 0번 작업 요청 
  -> 작업소요시간은 3ms, 작업 요청시간은 0ms, 작업 번호 0
- 1ms 시점에 9ms가 소요되는 1번 작업 요청
  -> 작업소요시간은 9ms, 작업 요청시간은 1ms, 작업 번호 1
- 3ms 시점에 5ms가 소요되는 2번 작업 요청
  -> 작업소요시간은 5ms, 작업 요청시간은 3ms, 작업 번호 2

우선순위가 작업소요시간 -> 작업요청시각 -> 작업번호 순서니까

*/

int checktime(vector<vector<int>>jobs){
    priority_queue<pp,vector<pp>,greater<>> pq; // (쇼요시간, 요청시간)
    sort(jobs.begin(), jobs.end());
    int time=0,idx=0,sum=0,cnt=0;
    //time : 현재 시각 , idx : 아직 pq에 넣지 않은 다음 작업의 인덱스
    // sum : 모든 작업의 (종료시간 - 요청시간)의 총합
    // cnt : 완료한 작업 개수
    while(cnt<jobs.size()){
        while(idx<jobs.size() and jobs[idx][0]<=time){
            pq.push({jobs[idx][1],jobs[idx][0]});
            idx++;
        }
        if(pq.empty()){time=jobs[idx][0];continue;}
        auto cur=pq.top();pq.pop();
        sum+=(time+cur.first-cur.second);
        time+=cur.first;cnt++;
    }
    return sum;
}
int solution(vector<vector<int>> jobs) {
    int ans=checktime(jobs);
    return ans/jobs.size();
}