// 타노스는 요세푸스가 밉다 - S2 - 2023/05/26
// 딱보면 queue쓰는 문제인건 감이 왔는데 문제 이해를 제대로 못했음 첨에.. 국어를 못하는듯..
/*
시작은 1번 청설모를 첫 번째 청설모로 한다. 타노스가 손을 튕기면 첫 번째 청설모부터 시계 방향으로 k마리의 청설모가 선택된다. 
이후 첫 번째 청설모를 제외한 2번째...k번째 청설모가 번호가 증가하는 순서대로 제거되고 첫 번째 청설모만 살아남는다. 
단, 남아 있는 청설모가 k마리보다 적으면 첫 번째 청설모를 제외한 모든 청설모가 제거된다. 제거된 후 남아있는 청설모가 
2마리 이상일 경우 첫 번째 청설모의 오른쪽 청설모가 첫 번째 청설모가 되고, 제거하는 과정을 다시 진행한다. 이 과정은 청설모가 
1마리 남을 때까지 계속된다.
*/
#include <iostream>
#include <queue>
using namespace std;
int n,k;
queue<int>q;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) q.push(i);
    while(1){
        if(q.size()==1)break;
        int fr=q.front();
        q.pop();
        for(int i=0;i<k-1;i++){
            if(not q.empty()){
                q.pop();
            }
            else break;
        }
        q.push(fr);
    }
    cout<<q.front()<<endl;
}