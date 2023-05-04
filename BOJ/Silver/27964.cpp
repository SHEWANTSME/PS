// 콰트로치즈피자 - S5 - 2023/05/05 어린이날
#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
int n;
map<string,int>mp;
bool flag= 0;
int main(){
    cin>>n;
    while(n--){    
        string s; cin>>s;
        mp[s]++;
    }
    int cnt =0;
    if(mp.size()<4){
        cout<<"sad"<<endl;
        exit(0);
    }
    for(auto &e : mp){
        cout<<e.first<<" "<<e.second<<endl;
        string temp = "";
        if(e.first.size()<6)continue;
        for(int i = e.first.size()-1; i>=e.first.size()-6; i--){
            if(i<0)break;
            cout<<i<<endl;
            temp.push_back(e.first[i]);
            if(temp == "eseehC"){cnt++;break;}
        }   
        if(cnt==4){flag=1;break;}
    }
    if(flag==1) cout<<"yummy"<<endl;
    else cout<<"sad"<<endl;
}
// 위의 풀이가 어디가 틀린진 전혀 못찾겠으니
/*
7
ACheese ACheese BCheese CCheese CheeseDD CheeseEE Kk

7
ACheese ACheese BCheese CCheese DCheese ECheese Kk 

7
AACheese CheeseBurger Cheese cheese KKCheese PPCheeseEE Kk

*/
// 그냥 substr쓰자.. 반례는 정신건강에 해롭다.. 
// 왜 편한길로 안가려고 하니?
#include<iostream>
#include<string>
#include<map>
using namespace std;
int n;
map<string,int>mp;
int main(){
    cin>>n;
    while(n--){
        string s;cin>>s;
        if(s.size()<6)continue;
        auto temp = s.substr(s.size()-6);//s.size()-6 인덱스부터 끝까지
        if(temp=="Cheese")mp[s]++;
    }
    if(mp.size()>=4)cout<<"yummy"<<endl;
    else cout<<"sad"<<endl;
}

