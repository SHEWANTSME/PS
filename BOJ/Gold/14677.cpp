// 병약한 윤호 - G5 - 2024/11/21
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
int arr[1504];
int dp[1504][1504][4];
string s;
int recur(int s, int e, int pre){//s는 시작점 e는 끝점 pre는 이전에 먹은 약
    if(s==e){//끝점에 도달했을때
        if(arr[s]==pre) return dp[s][e][pre]=1;//만약 먹을수 있다면 1을 리턴
        else return dp[s][e][pre]=0;//먹을수 없다면 0을 리턴
    }
    if(s<0 or e>3*n-1) return dp[s][e][pre]=0;
    if(arr[s]!=pre and arr[e] != pre) return dp[s][e][pre]=0;
    if(dp[s][e][pre]!=-1) return dp[s][e][pre];
    int xx,x,y;//xx는 다음에 먹을수 있는 약 x는 끝점을 먹었을때의 값 y는 시작점을 먹었을때의 값
    if(pre == 3) xx = pre-2;//만약 이전에 저녁을 먹었다면 아침을 먹을수 있다
    if(pre !=3) xx = pre+1;//만약 이전에 저녁을 먹지 않았다면 다음에 먹을수 있는 약은 이전에 먹은 약+1
    if(arr[e]==pre)x = recur(s,e-1,xx);
    if(arr[e]!=pre) x = -1;
    if(arr[s]==pre) y = recur(s+1,e,xx);
    if(arr[s]!=pre) y = -1;
    return dp[s][e][pre]=max(x,y)+1;
}

int main(){
    cin>>n >>s;
    // B : 아침 , L : 점심 , D : 저녁
    for(int i=0; i<s.size();i++){
        if(s[i]=='B')arr[i]=1;//아침
        if(s[i]=='L')arr[i]=2;//점심
        if(s[i]=='D')arr[i]=3;//저녁
    }
    cout<<s<<endl;
    memset(dp,-1,sizeof(dp));// dp -1로 초기화
    cout<<recur(0,3*n -1 ,1)<<endl;
}
