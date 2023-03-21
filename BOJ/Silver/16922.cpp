// 로마 숫자 만들기 - S3 - 2023/03/21
// 백트래킹이 어떻게 돌아가는지 알면 된다. 처음엔 시간초과가 걸렸으나 visited를 만든 후 다시 제출하니 통과
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int arr[4]={1,5,10,50};
int vis[20][3000];
vector<int>v;
vector<int>res;
// 전체적인 백트래킹의 구조를 눈에 익히자!
void Back(int now){ 
    if(vis[v.size()][now]==1)return;
    if(v.size() == n){
        int temp =0;
        for(auto &e : v)
            temp+=e;
        bool flag=0;
        for(auto &e : res){
            if(temp==e){flag=1;break;}
        }
        if(flag==1)return;
        else {res.push_back(temp); return;}
    }
    vis[v.size()][now]=1;
    for(int i=0 ; i<4 ; i++){
        int cur = arr[i];
        v.push_back(cur);
        Back(now+cur);
        v.pop_back();
        vis[v.size()][cur+now]=0;
    }
}
int main(){    
    cin>>n;
    
    Back(1);
    cout<<res.size()<<endl;
    // for(auto &e : res){
    //     cout << e << endl;
    // }
}