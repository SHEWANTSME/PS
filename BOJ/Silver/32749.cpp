// 타노수 - S5 - 2024/12/02
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n,t;
string s;
int main() {
    cin>>n>>t>>s;
    int power=(1<<n);//2^n
    int digits=(1 << (n-t));//2^(n-t)
    string ans= "";

    for (int i=0; i<power; i+=digits) {//slicing
        string cur = s.substr(i, digits);
        ans=max(ans, cur);
    }

    cout<<ans<<endl;
}
