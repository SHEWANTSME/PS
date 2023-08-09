// 끝말잇기 - S5 - 2023/08/09
// n==1, n==맨마지막일 경우일 때 잘 나누면 됨
// 나머진 걍 하라는대로 하면 됨
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int n,m;
vector<string>v;// 단어들
map<string ,int>mp;//중복 체크
int main(){
    cin>>n;// 단어 개수
    char pre_last = '1';//마지막 글자
    char next_fir= '.';//첫 글자
    bool flag=0;
    bool frog=0;
    bool frag=0;
    for(int i=1; i<=n ; i++){
        string t;cin>>t;
        mp[t]=1;//중복 체크
        v.push_back(t);
    }
    if(n==1){//단어가 하나일 경우 -> 이경우 안하면 98퍼틀 나옴
        cin>>m;//m도 어차피 1이므로
        string k; cin>>k;cout<<k<<endl;exit(0);// k가 답이고 끝내버리면 됨
    }
    for(int i=0 ; i<v.size() ;i++){
        if(flag==1 or frog==1 or frag==1)continue;
        if(v[i]=="?"){
            if(i==0){
                next_fir=v[i+1][0]; flag=1;
            }
            else if(i==v.size()-1){
                pre_last=v[i-1][v[i-1].size()-1];
                frag=1;
            }
            else{
                next_fir=v[i+1][0];
                pre_last=v[i-1][v[i-1].size()-1];
                frog=1;
            }
        }
    }
    cin>>m;
    string ans = "";
    for(int i=1; i<=m ; i++){
        string t; cin>>t;
        if(mp[t]==1)continue;
        if(frog==1 and flag==0 and frag==0){
            if(t[0]==pre_last and t[t.size()-1]==next_fir) ans=t;
        }
        if(frog==0 and flag==1 and frag== 0){
            if(t[t.size()-1]==next_fir)ans=t;
        }        
        if(frog==0 and flag==0 and frag== 1){
            if(t[0]==pre_last)ans=t;
        }
    }
    cout<<ans<<endl;
}