// 미세먼지 안녕! - G4 - 2025/01/21
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int R,C,T;
int arr[51][51];
int new_arr[51][51];
int tmp[51][51];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
// 1. Diffuse -> 2. Move
int air_x,ans;
void Move_1(int x,int y){
    for(int i=2; i<=C-1;i++){
        tmp[air_x-1][i+1] = new_arr[air_x-1][i];
    }
    for(int i=air_x-1; i>=2; i--){
        tmp[i-1][C] = new_arr[i][C];
    }
    for(int i= C;i>=2; i--){
        tmp[1][i-1]=new_arr[1][i];
    }
    for(int i=1;i<=air_x-2;i++){
        tmp[i+1][1]= new_arr[i][1];
    }
    if(tmp[air_x-1][1]>0)tmp[air_x-1][1]=0;
}
void Move_2(int x, int y){
    for(int i=2; i<=C-1;i++){
        tmp[air_x][i+1] = new_arr[air_x][i];
    }
    for(int i=air_x; i<=R-1;i++){
        tmp[i+1][C] = new_arr[i][C];
    }
    for(int i=C; i>=2;i--){
        tmp[R][i-1] = new_arr[R][i];
    }
    for(int i=R; i>=air_x+1;i--){
        tmp[i-1][1] = new_arr[i][1];
    }
    if(tmp[air_x][1]>0)tmp[air_x][1]=0;
}

void Diffuse(int x, int y){
    int now = arr[x][y];
    vector<int>tmp;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<1 or ny<1 or nx>R or ny>C)continue;
        if(arr[nx][ny]==-1)continue;
        tmp.push_back(i);
    }
    int temp = now/5;
    for(int i=0; i<tmp.size();i++){
        int xx = x + dx[tmp[i]];
        int yy = y + dy[tmp[i]];
        new_arr[xx][yy] += temp;
    }
    new_arr[x][y] += now - (temp*tmp.size());

}
int main(){
    cin>>R>>C>>T;
    for(int i=1 ; i<=R; i++){
        for(int j=1; j<=C;j++){
            cin>>arr[i][j];
            if(arr[i][j]==-1) air_x = i;
        }
    }
    // 공기청정기의 좌표는 -> (airx, 1) , (airx-1 ,1)가 되겠군

    for(int k=1 ; k<=T ; k++){
        // 1. Diffuse
        memset(new_arr, 0, sizeof(new_arr));
        memset(tmp, 0, sizeof(tmp));
        for(int i=1; i<=R;i++){
            for(int j=1; j<=C;j++){
                if(arr[i][j]==-1 or arr[i][j]==0)continue;
                Diffuse(i,j);
            }
        }

        new_arr[air_x][1]=-1;
        new_arr[air_x-1][1]=-1;

        //Move1
        Move_1(air_x-1,1);
        //Move2
        Move_2(air_x,1);

        for(int i=1;i<=R;i++){
            new_arr[i][1] = tmp[i][1];
            new_arr[i][C]=tmp[i][C];
        }
        for(int i=1; i<=C;i++){
            new_arr[1][i] = tmp[1][i];
            new_arr[R][i] = tmp[R][i];
            new_arr[air_x-1][i]=tmp[air_x-1][i];
            new_arr[air_x][i]=tmp[air_x][i];
        }
        new_arr[air_x][1]=-1;
        new_arr[air_x-1][1]=-1;



        // arr = new_arr 해주고 loop 돌기
        for(int i=1; i<=R;i++){
            for(int j=1; j<=C;j++){
                arr[i][j] = new_arr[i][j];
            }
        }



    }

    for(int i=1; i<=R;i++){
        for(int j=1; j<=C;j++){
            ans +=new_arr[i][j];
        }
    }
    cout<<ans+2<<endl;
}