// 미세먼지 안녕! - G4 - 2025/01/21
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int R,C,T;
int arr[51][51];
int new_arr[51][51];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
// 1. Diffuse -> 2. Move
int air_x,ans;
int Activate_1(int x, int y){
    // 1. -> , up , <- , down  (0,1) , (-1,0) , (0,-1), (1,0)
    int cnt=0;
    int tmp=0;
    for(int i= air_x-2; i>=1; i--){
        cnt++;
        tmp+=new_arr[i][1];
        if(cnt==1)return tmp;
    }
    for(int i=2; i<=C;i++){
        cnt++;
        tmp+=new_arr[1][i];
        if(cnt==1)return tmp;
    }
    for(int i=2;i<=air_x-1;i++){
        cnt++;
        tmp+=new_arr[i][C];
        if(cnt==1)return tmp;
    }
    for(int i=C-1; i>=2;i--){
        cnt++;
        tmp+=new_arr[air_x-1][i];
        if(cnt==1)return tmp;
    }
    return tmp;
}
int Activate_2(int x, int y){
    int cnt=0;
    int tmp=0;
    for(int i= air_x+1; i<=R; i++){
        cnt++;
        tmp+=new_arr[i][1];
        if(cnt==1)return tmp;
    }
    for(int i=2; i<=C;i++){
        cnt++;
        tmp+=new_arr[R][i];
        if(cnt==1)return tmp;
    }
    for(int i=R-1;i>=air_x;i++){
        cnt++;
        tmp+=new_arr[i][C];
        if(cnt==1)return tmp;
    }
    for(int i=C-1; i>=2;i--){
        cnt++;
        tmp+=new_arr[air_x][i];
        if(cnt==1)return tmp;
    }
    return tmp;
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

    // 1. Diffuse

    for(int k=1 ; k<=T ; k++){
        for(int i=1; i<=R;i++){
            for(int j=1; j<=C;j++){
                if(arr[i][j]==-1 or arr[i][j]==0)continue;
                Diffuse(i,j);
            }
        }
        // for(int i=1; i<=R;i++)
        //     for(int j=1; j<=C;j++)
        //         ans+=new_arr[i][j];
        new_arr[air_x][1]=-1;
        new_arr[air_x-1][1]=-1;

        for(int i=2 ; i<air_x-1; i++)
            for(int j=2 ; j<=C-1; j++)
                ans+=new_arr[i][j];
        for(int i= air_x+1;i<=R-1;i++)
            for(int j=2; j<=C-1;j++)
                ans+=new_arr[i][j];

        int q = Activate_1(air_x-1,1);
        int w = Activate_2(air_x,1);
        ans -=(q+w);
        for(int i=1; i<=R;i++){
            for(int j=1; j<=C;j++){
                arr[i][j] = new_arr[i][j];
            }
        }
        // cout<<aans<<endl;
        // cout<<Activate_1(air_x-1,1)<<endl;
        // cout<<Activate_2(air_x,1)<<endl;
    }
    cout<<ans<<endl;


    // for(int i=1; i<=R;i++){
    //     for(int j=1; j<=C;j++){
    //         cout<<new_arr[i][j]<<" ";
    //     }cout<<endl;
    // }
    // 2. purifier activate -> T초동안

    // ans = aans - (Activate_1(air_x-1,1) + Activate_2(air_x,1));
    // cout<<ans<<endl;


    // for(int i=2 ; i<air_x-1; i++)
    //     for(j=2 ; j<=C-1; j++)
    //         ans+=new_arr[i][j];
    // for(int i= air_x+1;i<=R-1;i++)
    //     for(int j=2; j<=C-1;j++)
    //         ans+=new_arr[i][j];
    
    //Activate_1(arix-1,1);// 위쪽 cycle
    //Activate_2(airx,1);// 아래쪽 cycle

}