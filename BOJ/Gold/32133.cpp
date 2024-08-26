// 가위바위보 - G5 - 2024/08/26
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
int N, M, K;
vector<string>arr;
int main(){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        string s;cin>>s;
        arr.push_back(s);
    }
    for(int i=0;i<M;i++){
        map<string,int>mp;//string을 key로 가지고 int를 value로 가지는 map
        for(int j=0;j<N;j++){
            string s=arr[j].substr(0,i+1);
            mp[s]++;
            //cout<<s << " "<< mp[s]<<endl;
        }
        for(auto it:mp){
            if(it.second<=K){ // K번 이하로 나온 문자열 중에서 길이가 길어야 라운드가 그만큼 줄어들어서 최소가 되니까
            // 그 중에서 지는 가위바위보 문자열을 만들면 됨
                cout<<it.first.size()<<endl;
                for(auto &e : it.first){
                    if(e=='S')cout<<'P';
                    else if(e=='P')cout<<'R';
                    else cout<<'S';
                }
                cout<<endl;
                exit(0);
            }
        }
    }
    cout<<-1<<endl;
}