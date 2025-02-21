// 2048(Easy) - G1 - 2025/02/20
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int ans =0;
void move(vector<vector<int>>& arr, int dir) {
    // 0 : Left , 1 : Right , 2: Up, 3: Down
     if (dir == 0) {// Left
        for (int i=0; i<n; i++) {// 세로
            int idx=0;// idx는 move되고 나서 들어갈 위치의 index
            for (int j=0; j<n; j++) {//가로
                if (arr[i][j] != 0) {// arr가 0이면 고려할 필요가 없음
                    int temp = arr[i][j];// temp가 잠시 현재 값을 저장해두고
                    arr[i][j] = 0; // 현재 값을 0으로 만들어줌 -> 이렇게 해야 합쳐지고 나서든 그냥 stack되던
                    // 빈 공간이 생겨야 하니까 0으로 해줘야함
                    if (arr[i][idx] == 0) arr[i][idx] = temp; 
                    // 기본적으로 해당 알고리즘에서 생각해야 할거는, idx가 껴있는 arr는 새로운 값이 update되는 arr이고
                    // j가 속한 arr는 원래 arr임
                    // 1. arr[i][idx]=0인 0으로 만들어준 값을 기존 위치에 다시 temp값 넣기
                    else if(arr[i][idx] == temp) { arr[i][idx]*=2; idx++;} // 2. 합체될때 -> idx를 증가시켜줘야함
                    else{ idx++; arr[i][idx] = temp;} // 3. 합체되지 않고 그냥 밀렸을때
                }
            }
        }
    }
    if(dir == 1){// Right
        for (int i=0; i<n; i++) {
            int idx = n-1;
            for (int j=n-1; j>=0; j--) {
                if (arr[i][j] != 0) {
                    int temp = arr[i][j];
                    arr[i][j] = 0;
                    if(arr[i][idx]==0) arr[i][idx]=temp;
                    else if (arr[i][idx] == temp) {arr[i][idx] *= 2; idx--;} 
                    else {idx--; arr[i][idx] = temp;}
                }
            }
        }
    }
    if(dir == 2){// Up
        for (int i=0; i<n; i++) {
            int idx = 0;
            for (int j=0; j<n; j++) {   
                if (arr[j][i] != 0) {
                    int temp = arr[j][i];
                    arr[j][i] = 0;
                    if(arr[idx][i]==0) arr[idx][i]=temp;
                    else if (arr[idx][i] == temp) {arr[idx][i] *= 2; idx++;} 
                    else {idx++; arr[idx][i] = temp;}
                }
            }
        }
    }
    if(dir == 3){// Down
        for (int i=0; i<n; i++) {
            int idx = n - 1;
            for (int j=n-1; j>=0; j--) {
                if (arr[j][i] != 0) {
                    int temp = arr[j][i];
                    arr[j][i] = 0;
                    if(arr[idx][i]==0) arr[idx][i]=temp;
                    else if (arr[idx][i] == temp) {arr[idx][i] *= 2; idx--;} 
                    else {idx--; arr[idx][i] = temp;}
                }
            }
        }
    }
}

void Func(vector<vector<int>> &arr, int depth) {
    if (depth == 5) {
        for (int i=0;i<n;i++) 
            for (int j=0; j<n; j++) 
                ans = max(ans,arr[i][j]);
        return;
    }
    for(int i=0;i<4; i++){
        vector<vector<int>> newarr = arr;
        // copy를 하는 이유? -> move함수에서 arr를 직접적으로 수정하면 안되기 때문
        move(newarr,i);
        Func(newarr,depth+1);
    }

    
}

int main() {
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin>>board[i][j];
    Func(board, 0);
    cout<<ans<<endl;
}