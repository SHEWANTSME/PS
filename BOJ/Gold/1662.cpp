// 압축- G5 - 2023/06/28
// 내가 생각했던 ))3)(2) 같은 예제는 없는 것 같음.. 왜 없지?
// 33(562(71(9))) -> 19 
// 1()66(5) -> 7
#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
string s;
int vis[51];
// always try to think recursively.. -> which could make your thinking sense much better.
int ans = 0;
stack<char>stk;
// 33(562(71(9))) -> 19 
int func(int idx){
    int cnt =0;
    for(int i=idx; i<s.size() ; i++){
        char now = s[i];
        if(now == '(' and not vis[i]){
            vis[i]=1;
            cnt--;
            cnt+=(s[i-1]-'0')*func(i+1);
        }
        if(now==')' and not vis[i]){
            vis[i]=1;
            return cnt;
        }
        if((now !=')' and now!='(' ) and not vis[i]){
            vis[i]=1;cnt++;
        }
    }
    return cnt;
}

int main(){
    cin>>s;
    cout<<func(0)<<endl;
}
// 