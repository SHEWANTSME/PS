// 빗물- G5 - 2023/04/07
// 문제 자체는 되게 직관적이고 쉬워보임.
// 문제대로 보면 구현하기 귀찮으니까 비가 뒤집어서 온다고 생각하자.
// 왜 G5인지 모르겠음. S2정도 되는 난이도같은데?
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int h,w;
int arr[503][503];
int temp[503];
vector<int>v[503];
vector<int>ans;
int main(){
    cin>>h>>w;
    //for(int i=0 ; i<=w;i++) // 이부분은 어차피 코드에 영향을 안줘서 빼도 될듯
    //    arr[0][i]=-1;
    for(int i=1;i<=h;i++)
        arr[i][w]=0;
    for(int i=0;i<w;i++)
        cin>>temp[i];
    for(int i=0 ; i<w ; i++)
        for(int j=0;j<temp[i];j++)
            arr[j+1][i]=1;
    for(int i=1; i<=h ; i++){
        for(int j=0 ; j<=w ; j++){
            if(arr[i][j]==1)v[i].push_back(j);
        }
    }
    
    for(int i=1; i<=h; i++){
        if(v[i].size()<=1)continue;
        int pre = 0;
        for(int j=1 ; j<v[i].size() ; j++){
            int ppre = v[i][pre];
           // cout<<"ppre : "<<ppre<<" v[i][j]: "<<v[i][j]<<endl;
            if(v[i][j]-ppre!=1){
                ans.push_back(v[i][j]-ppre-1);
                pre++;
            }
            else{
                pre++;continue;
            }
        }
    }
    int realans=0;
    for(auto &e : ans){
     //   cout<<e<<endl;
        realans+=e;
    }
    cout<<realans<<endl;
    // for(int i=0 ; i<=h ; i++){
    //     for(int j=0 ; j<=w ; j++){
    //         cout<<arr[i][j]<<" ";
    //     }cout<<endl;
    // }
}