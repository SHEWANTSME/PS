//수상한 문자열 - G2 - 2025.12.09
#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0)
#define endl "\n"
using namespace std;
int n,m;
vector<int> parent; // x의 부모 노드 번호
vector<int> dist; // x와 parent[x] 사이의 관계 (0: 같음, 1: 다름)

int find(int x) { // 경로 압축 + relation update
    if (parent[x] == x) return x; // 자신이 root면 그냥 자신 반환
    int root = find(parent[x]); // find real root recursively

    dist[x] = dist[x] ^ dist[parent[x]];
    /* 재귀가 풀리면서 돌아올 때 관계 갱신
    내 부모가 root와 맺고 있는 관계(dist[parent[x]])와 내가 부모와 맺고 있는 관계(dist[x])를 XOR 연산 하면
    나와 root가 맺고 있는 관계가 됨
    */
    parent[x] = root; // 부모를 root로 갱신 -> 경로 압축
    return root; // find 함수를 호출하는 것만으로도 경로 압축이 되기 때문에 return root가 없이 함수 호출만 해도 경로압축이 됨
}

bool merge(int a, int b, int w) { // Union함수 : 두개의 집합 합치기
    int rootA = find(a); // a의 root 찾기
    int rootB = find(b);// b의 root 찾기

    if (rootA != rootB) { // 둘이 root가 다르면
        // 병합을 해줘야함 -> rootA를 rootB의 자식으로 붙여두기
        // 경로: rootA -> ... -> a --(w)--> b -> ... -> rootB
        // dist[a] ^ w ^ dist[b] : rootA와 rootB가 맺는 관계 
        //(여기서 rootA는 원래 루트였으므로 갱신 전 dist[rootA]는 의미가 없고, 새로 연결될 때의 관계값을 계산해서 넣는 것)
        parent[rootA] = rootB;
        dist[rootA] = dist[a] ^ w ^ dist[b];
        return 1;
    } else {
        // 이미 같은 집합에 속해 있다면 모순 검사
        // a와 b가 현재 맺고 있는 관계(dist[a] ^ dist[b])가 w와 같은지 확인(w : 새 힌트 a와 b의 관계는 w (0: 같음, 1: 다름))
        if ((dist[a] ^ dist[b]) != w) return 0;
        return 1;
    }
}

int main() {
    fastio;
    cin>>n>>m;
    
    parent.resize(n+1);
    for(int i=0; i<=n; i++) parent[i]=i;
    dist.resize(n+1);
    for(int i=0; i<=n; i++) dist[i]=0;

    for(int i=0; i<m; i++){
        int num; cin>>num;
        if(num==1){
            int l,r;
            cin>>l>>r;
            while(l<r){
                // l과 r은 같아야 함 (w = 0)
                if(merge(l,r,0)==0){
                    cout<<"No"<<endl; exit(0);
                }
                l++;r--;
            }
        }
        else{
            int x,y; cin>>x>>y;
            if(merge(x,y,1)==0){
                // x와 y는 달라야 함 (w = 1)
                cout<<"No"<<endl; exit(0);
            }
        }
    }
    cout<<"Yes"<<endl;

    // 문자열 복원
    // 일단 root를 A로 고정하고 시작
    vector<char> result(n+1);
    for(int i=1; i<=n; i++){
        find(i);
        if(dist[i]==0) result[i]='A';
        else result[i]='B';
    }
    for(int i=1; i<=n; i++){cout<<result[i];}
    cout<<endl;
}
