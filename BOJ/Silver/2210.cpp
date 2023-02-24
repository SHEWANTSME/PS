// 숫자판 점프 - S2 - 2023/02/23
// 숫자판의 크기도 작고 충분히 DFS로 풀릴것 같고 시간 제한도 2초
// 기존 backtracking처럼 visited 함수를 하지 않아도 되는게 어차피 왔던곳을 다시 컴백해도 되니까
// 굳이 visited로 체크할 필요가 없음
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
//#include<string.h> // for using memset(0 or -1)로 초기화 할때 사용 
// 지금은 visited를 초기화 할 필요가 없으니 사용 x
using namespace std;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int arr[5][5];
string temp="";
vector<string>v; // 값어치 있는 temp만 담는 vector
set<string>st;
//backtracking 내 방식대로 짜보자
void DFS(int x, int y){ // void 형태의 backtracking 외에도 다른 자료형 형태의 backtracking도 생각해보자
    if(temp.size()==6){ // 다른 사람들은 그냥 set을 사용하더라 -> set이 중복허용이 안되니까 그냥 set 사용한듯
        // bool flag=0;
        // for(auto &e : v){
        //     if(e==temp)flag=1;
        // }
        // if(flag==1){ return;}
        // else{v.push_back(temp);return;} 

        // 이번엔 set 을 사용해서 해보자
        st.insert(temp);
        return;
    }
    for(int i=0 ; i<4 ; i++){
        int nx = dx[i]+x;
        int ny= dy[i]+y;
        if(nx<0 or ny<0 or nx>=5 or ny>=5)continue;
        temp.push_back(arr[nx][ny]+48);
        DFS(nx,ny);
        temp.pop_back();
    }
}
int main(){
    for(int i=0 ; i<5 ; i++)
        for(int j=0 ; j<5 ; j++)
            cin>>arr[i][j];
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<5 ; j++){
            temp.push_back(arr[i][j]+48);
            DFS(i,j);
            temp="";
        }
    }
    //cout<<v.size()<<endl;
    // for(auto &e : st){
    //     cout<<e<<endl;
    // }
    cout<<st.size()<<endl;
}