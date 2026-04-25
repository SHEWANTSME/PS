// 단어의 개수 - B2 - 2026.04.25
#include<iostream>
#include<string>
using namespace std;
bool flag=0;
int cnt=0;
int main(){
    string s;     
    getline(cin, s);
    for(int i=0; i<s.size() ; i++){
        if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){flag=1;}
        if(s[i]==' ' and flag==1){cnt++;flag=0;}
    }
    if(s[s.size()-1]!=' ')cnt++;
    cout<<cnt<<endl;
}