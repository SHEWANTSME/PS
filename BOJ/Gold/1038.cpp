//감소하는 수 - G5 - 2025/01/02

// 1번 풀이
#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n;
int main(){
    cin>>n;
    if(n<=10){cout<<n<<endl;exit(0);}
    if(n>=1023){cout<<-1<<endl;exit(0);}
    vector<string> v;
    for(int i=0;i<=9;i++) v.push_back(to_string(i));
    for(int i=1;i<=1022;i++){
        for(int j=0;j<=9;j++){
            if(v[i-1][0]-'0'>j){
                v.push_back(to_string(j)+v[i-1]);
                cout<<"v[i-1] : "<<v[i-1]<<" v[i-1][0] : "<<v[i-1][0]<<" j : "<<j<<" v.back() : "<<v.back()<<endl;
                //cout<<v.back()<<endl;
            }
        }
    }
    //v[n] reverse 시켜보자
    reverse(v[n].begin(),v[n].end());
    cout<<"Final : "<<v[n]<<endl;
}

//2번 풀이(Recursion)

//3번풀이(brute force) -> 시간초과
#include <iostream>
using namespace std;
int n;
bool dec(int n){
    int prev = 10;
    while(n>0){
        int cur = n%10;
        if(cur>=prev)return 0;
        prev=cur;
        n/=10;
    }
    return 1;
}
int main(){
    cin>>n;
    if(n>1023){cout<<-1<<endl;exit(0);}
    int cnt = -1;
    for(int i=0;i<=9876543210;i++){
        if(dec(i))cnt++;
        if(cnt==n){cout<<i<<endl;exit(0);}
    }
}