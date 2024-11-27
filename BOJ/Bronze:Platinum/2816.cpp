//디지털티비 - B1 - 2024/11/27
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int idx_1,idx_2;
vector<int>v;
string ans;
int main(){
    cin>>n;
    while(n--){
        string s;cin>>s;
        if(s=="KBS1"){v.push_back(-1);idx_1=v.size()-1;}
        else if(s=="KBS2"){v.push_back(-2);idx_2 = v.size()-1;}
        else v.push_back(1);
    }
    if(idx_1<idx_2){
        for(int i=0;i<idx_1;i++) ans.push_back('1');
        for(int i=1;i<=(idx_2-idx_1);i++) ans.push_back('4');
        for(int i=1;i<=idx_2;i++) ans.push_back('1');
        for(int i=1;i<idx_2;i++) ans.push_back('4');
    } // a가 먼저 b가 나중
    if(idx_1>idx_2){
        for(int i=0;i<idx_2;i++) ans.push_back('3');
        for(int i=1;i<=(idx_1-idx_2);i++) ans.push_back('1');
        for(int i=1;i<=idx_1;i++) ans.push_back('4');
        for(int i=1;i<=idx_2;i++) ans.push_back('1');
        for(int i=2;i<=idx_2;i++) ans.push_back('4');
    } // b가 먼저 a가 나중
    cout<<ans<<endl;
}