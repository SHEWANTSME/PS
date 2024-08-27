// 변수명 - B1 - 2024/08/27
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n;
string s;
vector<int>v;
int main(){
    cin>>n;cin>>s;
    if(n==1){
        cout<<s<<endl;
        string tmp="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' and s[i]<='z') tmp.push_back(s[i]);
            else{
                tmp.push_back('_');
                tmp.push_back(s[i]+32);
            }
        }
        cout<<tmp<<endl;
        cout<<char(s[0]-32)<<s.substr(1)<<endl;exit(0);
    }
    if(n==2){
        string tmp="";bool flag = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='_'){flag=1;continue;}
            if(s[i]>='a' and s[i]<='z'){
                if(flag) {tmp.push_back(s[i]-32);flag=0;continue;}
                else {tmp.push_back(s[i]);continue;}
            }
        }
        cout<<tmp<<endl;
        cout<<s<<endl;
        cout<<char(tmp[0]-32);cout<<tmp.substr(1)<<endl;
        exit(0);
    }
    else{
        cout<<char(s[0]+32)<<s.substr(1)<<endl;
        bool flag=0;
        string tmp = "";
        for(int i=0; i<s.size();i++){
            if(s[i]>='A' and s[i]<='Z'){
                v.push_back(i);
            }
        }
        for(int i=0;i<v.size()-1;i++){
            for(int j=v[i]; j<v[i+1];j++){
                //cout<<j<<endl;
                if(j==v[i]) cout<<char(s[j]+32);
                else cout<<char(s[j]);
            }cout<<'_';
            //0 3 5 10  14 
        }
        //cout<<v[v.size()-1]<<endl;
        cout<<char(s[v[v.size()-1]]+32);
        for(int i=v[v.size()-1]+1;i<s.size();i++)cout<<s[i];
        cout<<endl;
        cout<<s<<endl;
    }
}