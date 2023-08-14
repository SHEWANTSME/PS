// 숫자고르기 - G5 - 2023/08/13
// 오예 한방에 품
// DFS로 지금 숫자가 다음엔 어떻게 갈지? 생각하고 거기서 cycle이 생기는지 확인하면 됨
#include<iostream>
#include<vector>
#include<algorithm> // sort 때문에
#include<map> 
#include<string.h>//memset 때문에
#define endl "\n"
using namespace std;
int n;
int arr[101];//arr[i] = i번째 수가 가리키는 수
int visited[101];//visited[i] = i번째 수가 방문했는지 여부
vector<int>b_v;//black_vector
vector<int>r_v;//red_vector
vector<int>ans_2;
int ans_1=0;
map<int,int>b_m;//black_map
map<int,int>r_m;//red_map

/*
1 3 2 4
3 2 4 1 -> 이러면 같은 집합임

how would you define as a same group?
*/
int Func(int x){
    if(visited[x]){//이미 방문했던 곳이라면
        for(auto &e : b_v){//b_v에 있는 모든 원소들을
            b_m[e]=1;//b_m에 넣어준다
        }
        //cout<<"b_v.first "<<b_v.front()<<endl; 
        return b_v.size();//b_v의 크기를 리턴
    }
    visited[x]=1;//방문했다고 표시
    b_v.push_back(x);//b_v에 x를 넣어준다
    int nxt = arr[x];//다음으로 갈 곳
    r_v.push_back(nxt);//r_v에 nxt를 넣어준다
    if(r_m[nxt]){//이미 방문했던 곳이라면
        return -1;//-1을 리턴
    }
    r_m[nxt]=1;//방문했다고 표시
    return Func(nxt);//다음으로 갈 곳을 리턴
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    for(int i=1; i<=n;i++){
        if(b_m[i])continue;
        int temp = Func(i);
        if(temp!=-1){
            for(auto &e : b_v){
                ans_2.push_back(e);
            }
                ans_1+=temp;
           // ans_2.push_back(i);
        }
        memset(visited,0,sizeof(visited));
        b_v.clear();
        r_v.clear();
        r_m.clear();
    }
    cout<<ans_1<<endl;
    sort(ans_2.begin(),ans_2.end());
    for(auto &e : ans_2)
        cout<<e<<endl;
}