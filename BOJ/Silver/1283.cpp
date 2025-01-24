//단축키 지정 - S1- 2025/01/24

#include<iostream>
#include<algorithm>
#include<string>
using namespace std; 
int n; 
int Alpha[26];
int chk[6];
vector<char>ans;
int main(){
    cin>>n;
    cin.ignore();// 버퍼비우기 -> 이거 안하면 개행문자가 들어가서 입력이 제대로 안됨
    int cnt =0;
    while(n--){
        string s;
        getline(cin,s);// 띄어쓰기 포함해서 입력받기 -> 여기서는 ignore 안해도됨 -> getline은 버퍼를 비워줌
        string tmp = "";
        vector<string>v;
        //cout<<"뀨?  : "<<s<<endl;
        for(int i=0; i<s.size();i++){
            if(s[i]==' '){
                v.push_back(tmp);
                tmp="";
            }
            else{
                tmp.push_back(s[i]);
            }
        }
        v.push_back(tmp);

        // for(auto &e : v){
        //     cout<<"fslkjsdf"<<e<<endl;
        //     cout<<e[0]<<endl;
        // }

        bool flag= 0;
        for(int i=0; i<v.size();i++){
            if(v[i][0]>='a' and v[i][0]<='z'){
                if(Alpha[v[i][0]-'a']!=1){Alpha[v[i][0]-'a']=1;flag=1;ans.push_back(v[i][0]);break;}
            }
            if(v[i][0]>='A' and v[i][0]<='Z'){
                if(Alpha[v[i][0]-'A']!=1){Alpha[v[i][0]-'A']=1;flag=1;ans.push_back(v[i][0]);break;}
            }
        }
        if(flag==0){
            bool fflag=0;
            for(int i=0; i<v.size();i++){
                for(auto &e : v[i]){
                    if(e>='a' and e<='z'){
                        if(Alpha[e-'a']==1)continue;
                        else {Alpha[e-'a']=1;fflag=1;ans.push_back(e);break;}
                    }
                    if(e>='A' and e<='Z'){
                        if(Alpha[e-'A']==1)continue;
                        else {Alpha[e-'A']=1;fflag=1;ans.push_back(e);break;}
                    }
                }
            }
            if(fflag==0){
                ans.push_back('-');
            }
        }

        // string realans="";
        // bool flagg=0;
        // for(int i=0; i<s.size();i++){
        //     if(s[i] == ans[cnt]){
        //         realans.push_back('[');
        //         realans.push_back(s[i]);
        //         realans.push_back(']');
        //         flagg=1;
        //     }
        //     else realans.push_back(s[i]);
        // }
        // cout<<realans<<endl;
        // cnt++;
        string realans="";
        bool flagg=0;
        for(int i=0; i<v.size();i++){
            for(int j=0; j<v[i].size(); j++){
                //cout<<v[i][j]<< " "<<ans[cnt]<<" " <<flagg<<" "<<chk[i]<<endl;
                if(v[i][j]==ans[cnt] and flagg==0 and chk[i]==0){
                    realans.push_back('[');
                    realans.push_back(v[i][j]);
                    realans.push_back(']');
                    flagg=1;chk[i]=1;
                }
                else realans.push_back(v[i][j]);
            }
            realans.push_back(' ');
        }
        cout<<realans<<endl;cnt++;
    }
    // for(auto &e : ans){
    //     cout<<e<<endl;
    // }

}