//팔 - S1 - 2025.12.03
#include<iostream>
#include<string>
using namespace std;
string s1,s2;
int cnt=0;
int main(){
    cin>>s1>>s2;
    if(s1.size() != s2.size()){cout<<0<<endl; exit(0);}
    for(int i=0; i<s1.size(); i++){
        if(s1[i]==s2[i]){
            if(s1[i]=='8')cnt++;
        } 
        else break;
    }
    cout<<cnt<<endl;
}
//문자열의 처음 '8' cnt 해주면 됨. -> 몇개 찾다보면 규칙나옴