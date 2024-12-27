// 저울 - G4 - 2024/12/27
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;
int n, m;
int main(){
    cin>>n>>m;
    vector<vector<int>> cost(n+1, vector<int>(n+1,1e9));// cost[i][j] = i에서 j로 가는데 필요한 최소 비용
    for(int i=0; i<m; i++){
        int s,e;
        cin>>s>>e;
        cost[s][e]=0;// s에서 e로 가는데 필요한 비용은 0
    }
    for(int i=1;i<=n;i++) cost[i][i]=0;// 자기 자신으로 가는 비용은 0

    for(int k=1;k<=n;k++){// k는 거쳐가는 노드
        for(int i=1;i<=n;i++){// i는 출발 노드
            for(int j=1;j<=n;j++){// j는 도착 노드
                // for문의 순서를 거쳐가는 노드 -> 출발 노드 -> 도착 노드 순으로 해야함
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);// i에서 j로 가는데 필요한 비용은 i에서 k로 가는데 필요한 비용 + k에서 j로 가는데 필요한 비용
            }
        }
    }
    for(int i=1;i<=n;i++){
        int ans = n;// i번째 추의 맥시멈 n에서 부터 
        for(int j=1;j<=n;j++){// i번째 추와 j번째 추에 대해 비교
            if(cost[i][j]!=1e9 or cost[j][i]!=1e9){// i번째 추와 j번째 추가 서로 비교 가능하다면
                ans--;
            }
        }
        cout<<ans<<endl;
    }
}