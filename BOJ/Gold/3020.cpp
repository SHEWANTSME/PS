// 개똥벌레- G5 - 2023/08/09
#include<iostream>
using namespace std;
int n, h;
int seok[500001];// 석순
int jong[500001];// 종유석
int main(){
    cin>>n>>h;
    for(int i=1;i<=n; i++){
        int t; cin>>t;
        if(i%2) seok[t]++;// 홀수번째는 석순
        else jong[t]++;// 짝수번째는 종유석
    }
    for(int i=h-1; i>=1;i--){//누적 합
//지금 높이일때의 total갯수는 지금보다 한단계 높았을때의 total갯수에서 지금 높이에서 꼭대기에 있는 경우를 더해줌
        seok[i]+=seok[i+1];
        jong[i]+=jong[i+1];
    } 
    // 종유석을 다르게 하려다가 또 꼬였는데 그냥 이렇게 하는게 맞았음
    int ans = 1e9;
    int cnt=0;
    for(int i=1; i<=h ; i++){
        //cout<<seok[i]<<" "<<jong[h-i+1]<<endl;// 
        int t = seok[i]+jong[h-i+1];// i는 석순의 높이, h-i+1은 종유석의 높이
        ans = (ans>t)?t:ans;// 최소값 갱신
    }
    for(int i=1; i<=h ; i++){
        int t = seok[i]+jong[h-i+1];
        if(t==ans)cnt++;
    }
    cout<<ans<<" "<<cnt<<endl;

}