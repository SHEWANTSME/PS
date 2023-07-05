// 로또- S2 - 2023/07/05
// 하라는 대로 하면 됨 + 그림을 그려보면 쉬움
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int vis[51];
void Rec(int idx, int cnt ,int n){
    if(idx==-1) {Rec(0,0,n);return;}//return 없으면 안됨.. 끝마쳐야하니까
    if(cnt==6){// 6개를 다 뽑았으면 출력
        for(int i=0 ; i<n ; i++){
            if(vis[i]==1)cout<<v[i]<<" ";
        }cout<<endl;
        return;
    }
    vis[idx]=1;// idx번째를 뽑았다고 표시
    cnt++;// 뽑은 개수 증가
    if(idx+1<=n)Rec(idx+1,cnt,n);// 다음 idx를 뽑는 경우
    cnt--;// 뽑은 개수 감소
    vis[idx]=0;// idx번째를 뽑지 않았다고 표시
    if(idx+1<=n)Rec(idx+1,cnt,n);// 다음 idx를 뽑지 않는 경우
    return;
}
// 참고로 next_permutation 사용방법은 다음과 같음
// next_permutation은 “오름차순의 배열”을 기준으로 순열을 구성함
// prev_permuation은 “내림차순의 배열”을 기준으로 순열을 구성함
int arr[6]={1,2,3,4,5,6};
void Permutation(){
    do{
        for(int i=0;i<6;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }while(next_permutation(arr,arr+6));
}
//https://ansohxxn.github.io/algorithm/combination/
// 위의 링크가서 자세히 보면 더 이해가 쉬움
int main(){
    Permutation();
    while(1){
        int n;cin>>n;
        if(n==0)break;
        for(int i=0;i<n;i++){
            int t;cin>>t;v.push_back(t);
        }
        Rec(-1,0,n);// idx,cnt,n
        v.clear();// 다음 입력을 위해 초기화
        cout<<endl;// 출력형식을 맞추기 위해
    }
}
/*
        Rec(4,5,7)
        /         \ 
Rec(5,6,7)->출력 Rec(5,5,7)
                   /      \   
        Rec(6,6,7)->출력  Rec(6,5,7)
                            /
                        Rec(7,6,7)->출력
이런식임
*/
