// 택배 색칠 - S4 - 2023/08/31
// 개인적으로 S4급은 아닌거 같다. S2~1 정도의 난이도 인것 같다.
#include <iostream>
#include <algorithm>
#define endl "\n"
#define ll long long
using namespace std;
ll arr[1001][1001];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
ll cnt=0;
int n,m;
int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    for(int i=1; i<n-1;i++){// 테두리는 무조건 페인트 칠해지니까 pass
        for(int j=1; j<m-1;j++){
            if(arr[i][j]<=1)continue;//1개면 무조건 페인트 칠해지고(위에서 볼때), 0개면 걍 pass해도 되니까 continue
            ll tmp=arr[i][j]-1;// 위에서 쳐다봤을때 경우 제외하고 나머지 4면중에서 최소
            for(int k=0;k<4; k++)
                tmp=min(arr[i+dx[k]][j+dy[k]],tmp);//여기서는 테두리가 들어가도 상관 없지. 생각해보면 당연하다는걸 알 수 있음
            cnt+=tmp;
        }
    }
	cout<<cnt<<endl;
}