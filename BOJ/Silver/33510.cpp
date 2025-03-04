// 이상한 나누기 - S2 - 2025/03/04
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n,ans=0;
string s;
int main(){
    cin>>n>>s;
    reverse(s.begin(),s.end());
    s.pop_back();
    bool flag= 0;
    for(auto &e : s){
        if(e=='1' and flag==0){
            ans=1;flag=1;
        }
        if(e!='1' and flag==1)ans++;
    }
    cout<<ans<<endl;   
}
