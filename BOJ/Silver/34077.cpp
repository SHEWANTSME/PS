//폴카의 수학 공부 - S2 - 2025.08.08
// '-'붙은 수 다음 결과가 다 0이면 YES
#include<iostream>
#include<string>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl "\n"
using namespace std;
int tc;
int main(){
    fastio;
    cin>>tc;
    while(tc--){
        int t;cin>>t;
        string s; cin>>s;
        if(s.size()==3){cout<<"YES"<<endl;continue;}
        bool chk=0;int tmp=0;
        for(int i=1; i<s.size()-2;i+=2){
            if(s[i]=='-'){ chk=1;tmp=i;break;}
        }
        if(chk==1){
            bool chk2=0;
            for(int i=s.size()-1; i>=tmp+3;i-=2){
                if(s[i]!='0'){chk2=1;break;}
            }
            if(chk2==1 and chk==1)cout<<"NO"<<endl;
            if(chk2==0 and chk==1)cout<<"YES"<<endl;
        }
        if(chk==0)cout<<"YES"<<endl;        
    }
}