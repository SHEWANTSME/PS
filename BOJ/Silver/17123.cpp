//배열놀이 - S2 - 2025.02.14
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tc;
int main() {
    cin>>tc;
    while(tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> grid(n+2, vector<int>(n+2, 0));
        
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=n;j++) 
                cin>>grid[i][j];
        vector<vector<int>> v(n+2, vector<int>(n+2, 0));
        for (int i=0; i<m; i++) {
            int a,b,c,d,e;
            cin>>a>>b>>c>>d>>e;
            v[a][b]+=e;
            v[a][d+1]-=e;// 왜 d+1이지? => d까지 포함해서 빼야하니까
            v[c+1][b]-=e;// 왜 c+1이지? => c까지 포함해서 빼야하니까
            v[c+1][d+1]+=e;// 왜 c+1이지? => c까지 포함해서 더해야하니까

            // for(int i=1; i<=n; i++){
            //     for(int j=1; j<=n; j++){
            //         cout<<v[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
        }
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=n; j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                v[i][j]+=(v[i-1][j] + v[i][j-1]-v[i-1][j-1]);

        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=n; j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                grid[i][j]+=v[i][j];

        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=n; j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        vector<int>row_sums(n+1,0);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                row_sums[i] += grid[i][j];
                
        vector<int> col_sums(n+1,0);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                col_sums[i] += grid[j][i];
                
        for(int i=1; i<=n;i++) cout<<row_sums[i]<<" ";
        cout<<endl;
        for(int i=1; i<=n;i++) cout<<col_sums[i]<<" ";
        cout<<endl;
    }
}