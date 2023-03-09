// DFS 스페셜저지 - G3 - 2023/03/07
// find how DFS's visiting way is valid or not
// 실패. 다른사람의 풀이를 보고 할 수 있었음 -> 나중에 reset되고나서 다시 해보자.
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;
// 왜 생각이 안나지

int n; // 노드 갯수
vector<int>v[100001];// 연결리스트 make
vector<int>chk;
vector<int>temp; // 필요없음
bool ans = 0;
int test_idx =0;
int visited[100001];
void DFS(int now){
    // I think pre and now should be considered -> 라고 생각하긴했는데 글쎼?
    /*
    chk = 1 3 2 4
    1 2
    1 3
    2 4
    */
   // 해당 문제는 n>=2이고 무조건 처음 노드의 숫자는 1임 그래서 DFS(1)이라 한거고
    visited[now]=1; // DFS들어가자마자 방문체크
    int param =0; // 이 밑의 while문이 어떻게 실행되는지 아는게 매우 중요. 
    while(param<v[now].size()){ // 왜 while문으로 했냐면, param이 default로 증가하는게 아니고
    // 조건에 따라 증가하거나 reset되기 때문임 + 현재 노드의 연결리스트의 사이즈가 0보단 커야 while문 들어감
        int nxt = v[now][param];// 현재 연결리스트에서 다음 노드
        if(not visited[nxt] and nxt == chk[test_idx+1]){
            // 다음노드가 방문하지 않았고 다음노드가 예상결과의 위치와 같으면
            test_idx++; // 테스트인덱스++
            // 테스트인덱스는 전역변수라서 DFS가 얼마나 깊게 들어갔든 루프마다의 값이 변하는건 아니며
            // 따라서 테스트인덱스가 특정 값이 되면 (마지막까지 순탄하게 가면) -> 맞는 예상결과를 가지고 있었다는 얘기고
            // 그 뜻은 ans 값을 1로 하고 리턴해줘도 된다는 뜻
            DFS(nxt);
            if(test_idx >=chk.size()-1){
                ans =1; return;
            }
            param =0; // 일단 순서를 바꾸면 안되니까 다시 처음부터 봐보는거임
        }
        else param++;
    }
    
}

int main(){
    cin>>n;
    for(int i=1 ; i<n ; i++){
        int a,b; cin>>a>>b;
        v[a].push_back(b);
       // v[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        int t;cin>>t;chk.push_back(t);
    } // 여기서 나오는 예상 결과를 바탕으로 어떤 노드부터 방문할지 볼 수 있음! 이게 이 문제의 핵심
   
   DFS(1);
   cout<<ans<<endl;
}
// 이런식으로 풀면 가능할듯..!