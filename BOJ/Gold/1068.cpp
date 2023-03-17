// 트리 - G5 - 2023/03/16
// 리프노드의 정의를 제대로 하지 않아서 존나 너무 헤맸음..
// what is a leaf node? - one child & child ==rem_parent일때 parent가 leaf가 되지
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>v[52];
int n,rem_parent,root;
int visited[52];
int cnt =0;
void DFS_1(int parent , int code){ // code==0 : 부모가 rem_parent
    if(visited[parent]==1 or visited[parent]==-1 )return;
    if(code==0){
        visited[parent]=-1;
        cout<<"지울부모 : "<<parent<<endl;
        for(auto &child:v[parent]){
            DFS_1(child,0);
        }
        return;
    }
    visited[parent]=1;
    cout<<"부모: "<<parent<<endl;
    // if(v[parent].empty()){
    //     cout<<"leaf"<<endl;
    //     //cnt++;
    //     return;
    // }

    for(auto &child: v[parent]){
        if(child == rem_parent){
            DFS_1(child,0);
        }else{
            DFS_1(child,1);
        }
    }

}
void DFS_2(int parent, int code){
    if(visited[parent]==1 or visited[parent]==-1 )return;
    visited[parent]=1;
    cout<<"부모: "<<parent<<endl;
    if(v[parent].empty()){
        cout<<"leaf"<<endl;
        cnt++;
        return;
    }

    for(auto &child: v[parent]){
        if(child == rem_parent){
            continue;
        }else{
            DFS_2(child,1);
        }
    }
    cnt++;
}
// void DFS(int parent,int code){
//     if(visited[parent] == -1){
//         return;
//     }
//     if(visited[parent]==1)return;
//     if(code==0){
//         visited[parent]=-1; return;
//     }
//    // if(visited[parent]==-1)return;
//     //if(code==1)visited[parent]=1;
//     //if(code==0){visited[parent]=-1;return;}
    
//     cout<<"부모 : "<<parent<<endl;
//     if(v[parent].empty()){
//         cnt++;
//         cout<<"leaf"<<endl;
//     }
//     for(auto&child : v[parent]){
//         if(child == rem_parent){
//             visited[child]=-1;
//             DFS(child,0);
//             cnt++;
//             cout<<"leaf"<<endl;
//         }
//         else DFS(child,1);
//         //if(child == rem_parent)continue;
//         //DFS(child);
//     }
//     // if(v[parent].empty()){
//     //     cnt++;
//     //     cout<<"leaf"<<endl;
//     // }
// //    cout<<parent<<endl;
// }
// void DFS(int pre, int now){
// // (0,1) , (1,1),(2,1), (3,1), (4,1)
//     //if()
//     if(visited[pre])return;
//     visited[pre]=1;
//     //cout<<"pre: "<<pre << "now: "<<now<<endl;
//     for(auto &e : v[pre]){
//         DFS(e,now);
//     }
//     cout<<"pre: "<<pre<<endl;
// }
int main(){
    cin>>n;
    for(int child=0 ; child<n ; child++){
        int parent;
        cin>>parent;
        if(parent==-1){
            root = child;
            v[51].push_back(root);
        }
        else v[parent].push_back(child);
    }
    cin>>rem_parent;
    if(rem_parent == root){
        cout<<0<<endl; exit(0);
    }
    DFS_1(root,1);
    for(int i=0 ; i<51;i++){
        if(visited[i]==1)visited[i]=0;
        else continue;
    }
    DFS_2(root,1);
    cout<<cnt<<endl;
   // DFS(0,rem);
    // for(int i=0 ; i<n ; i++){
    //     DFS(i ,rem);
    // }
    /*
    -> -1 0 0 1 1
        0
      1     2
    3   4
    v[0].push_back(1)
    v[0].push_back(2)
    v[1].push_back(3)
    v[1].push_back(4)
    

            9
        8       7
    6     5    3   2
  1   0   11
13 16  

    
    */
}