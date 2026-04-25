// 스택 - S4 - 2026.04.25
#include<iostream>
#include<vector>
#define endl "\n"
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n;
vector<int>v;
int main(){
    fastio;
    cin>>n;
    while(n--){
        int t;cin>>t;
        if(t==1){
            int x; cin>>x;v.push_back(x);continue;
        }
        if(t==2){
            if(v.empty())cout<<-1<<endl;
            else{
                cout<<v.back()<<endl;
                v.pop_back();
            }
        }
        if(t==3){
            cout<<v.size()<<endl;
        }
        if(t==4){
            if(v.empty())cout<<1<<endl;
            else cout<<0<<endl;
        }
        if(t==5){
            if(v.empty())cout<<-1<<endl;
            else{
                cout<<v.back()<<endl;
            }
        }
    }
}