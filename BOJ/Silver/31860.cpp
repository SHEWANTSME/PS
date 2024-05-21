// 열심히 일하는 중 - S1 - 2024.05.21
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int>pq;// 맨처음 pq에 넣고(max heap)
priority_queue<int>pq2;// 두번째 pq에 k보다 클때 넣고 아닐땐 break(이것도 max heap)
int n,m,k;
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        pq.push(t);
    }
    while(1){
        int top = pq.top();
        if(top<=k)break;// k보다 작으면 break
        pq2.push(top);
        pq.pop();
        top-=m;// m만큼 빼주고 다시 넣어줌
        pq.push(top);
    }
    cout<<pq2.size()<<endl;
    // while(not pq2.empty()){
    //     cout<<pq2.top()<<" ";
    //     pq2.pop();
    // }
    int pre =0;
    while(not pq2.empty()){
        if(pre ==0){// 처음엔 그냥 출력
            pre = pq2.top();
            cout<<pre<<endl;
            pq2.pop();
        }
        else{// 그 다음부터는 이전값과 top값을 더해서 출력
         int top = pq2.top();
        pre /=2;
        cout<<top+pre<<endl;
        pre +=top;//pre 갱신
        pq2.pop();   
        }
    }
}