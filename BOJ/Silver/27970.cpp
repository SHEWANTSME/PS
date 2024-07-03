// OX - S1 - 2024/07/03
// XOX 경우를 잘못생각했었네..
#include<iostream>
#include<algorithm>
#include<string>
#define ll unsigned long long
using namespace std;
int main(){
    string s;
    cin>>s;
    ll tmp = 1;
    ll ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='X'){
            if(i==0) continue;
            tmp*=2;
            tmp%=1000000007;
        }
        else{
            if(i==0){ans+=tmp;continue;}
            tmp*=2;
            tmp%=1000000007;
            ans+=tmp;
            ans%=1000000007;
        }
    }
    cout<<ans<<endl;
}
/*
기존코드
#include<iostream>
#include<algorithm>
#include<string>
#define ll unsigned long long
using namespace std;
int main(){
    string s;
    cin>>s;
    ll tmp = 1;
    ll ans=0;
    for(int i=0;i<s.size();i++){
        tmp%=1000000007;
        tmp*=2;
        tmp%=1000000007;
        if(s[i]=='X'){continue;}
        else{
            if(i==0)tmp/=2;
            ans%=1000000007;
            ans+=tmp;
            ans%=1000000007;
        }
    }
    cout<<ans<<endl;
}
-> XOX같은 경우를 처리를 제대로 하지 못함
*/