#include<bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int chk=0;
    for(auto &e : truck_weights) chk+=e;
    if(truck_weights.size()<=bridge_length and chk<=weight)return bridge_length+truck_weights.size();
    
    queue<int>bridge;
    for(int i=0; i<bridge_length; i++)bridge.push(0);
    
    int idx=0; int now_weight=0; int time=0;
    
    while(idx<truck_weights.size()){
        now_weight-=bridge.front();
        bridge.pop();
        if(now_weight+truck_weights[idx]<=weight){
            bridge.push(truck_weights[idx]);
            now_weight +=truck_weights[idx];
            idx++;
        }
        else bridge.push(0);
        time++;
    }
    time+=bridge_length;
    return time;
}