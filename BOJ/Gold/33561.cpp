// 임스의 땅따먹기 - G3 -2025.04.23
// n by n을 숫자를 늘려가면서 filter를 sliding window 해야 할듯? 그렇게 brute force 하면 풀릴거같음
// 시간초과 -> retry해봐야함.. 로직은 맞는듯
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,k;
int arr[501][501];
int vis[501][501];
vector<int>v;
vector<int>answer;
int main(){
    cin>>n;
    int cnt = 0;
    int ttmp = 0;
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n ; j++){
            cin>>arr[i][j];
            ttmp+=arr[i][j];
            if(arr[i][j] == 0) cnt++;
        }
    }
    cin>>k;
    for(int i=0; i<k ; i++){int t; cin>>t; v.push_back(t);}
    if(cnt == 0){
        cout<<ttmp<<endl;exit(0);
    }
    sort(v.begin(), v.end(), greater<int>());

    int mx = -1;
    for(int i=1; i<=n ;i++)
        for(int j=1; j<=n ; j++)
            mx = max(mx,arr[i][j]);        
    answer.push_back(mx);
    int f = 2; // filter size
    int tmp1=0;
    int tmp2=0;
    int ans =0;
    int num_zero = 0;
    bool flag =0;
    while(f<=n){
        for(int i=1+tmp1 ; i<=f+tmp1; i++){
            if(i==n+1){flag=1;break;}
            for(int j=1+tmp2 ; j<=f+tmp2; j++){
                if(arr[i][j]==0)num_zero++;
                vis[i][j]=1;
                ans+=arr[i][j];
            }
        }
        if(flag) break;
        if(num_zero > k){
            tmp2++;ans=0; num_zero = 0;
            if(f + tmp2 >n){
                tmp2 = 0; tmp1++; continue;
            }
            if(f+tmp1 > n){
                tmp1 = 0; f++; continue;
            }
            continue;
        }
        if(num_zero == k){
            for(auto &e : v) ans +=e;
            answer.push_back(ans);
            ans=0;num_zero = 0;
            tmp2++; 
            if(vis[n][n]==1){
                f++; tmp1=0; tmp2=0; 
                for(int i=1; i<=n ;i++)
                    for(int j=1; j<=n ; j++)
                        vis[i][j]=0;
                continue;
            }
            if(f + tmp2 >n){
                tmp2 = 0; tmp1++; continue;
            }
            if(f+tmp1 > n){
                tmp1 = 0; f++; continue;
            }
            continue;
        }
        if(num_zero < k){
            for(int i=0 ;i<num_zero ; i++) ans += v[i];
            answer.push_back(ans);
            ans=0;num_zero = 0;
            tmp2++; 
            if(vis[n][n]==1){
                f++; tmp1=0; tmp2=0; 
                for(int i=1; i<=n ;i++)
                    for(int j=1; j<=n ; j++)
                        vis[i][j]=0;
                continue;
            }
            if(f + tmp2 >n){
                tmp2 = 0; tmp1++; continue;
            }
            if(f+tmp1 > n){
                tmp1 = 0; f++; continue;
            }
            continue;
        }
        // if(f + tmp2 >n){
        //     tmp2 = 0; tmp1++; continue;
        // }
        // if(f+tmp1 > n){
        //     tmp1 = 0; f++; continue;
        // }
        //f++;
    }
    // int f = 2; // filter size
    // int tmp1 =0;
    // int num_zero = 0;
    // int ans =0;
    // int tmp2=0;
    // bool flag2 = 0;
    // while(f<=n){
    //     //int tmp2=0;
    //     ans=0; num_zero=0;
   
    //     for(int i=1+tmp1 ; i<=f+tmp1 ; i++){
    //         //int tmp = 0;
    //         if(flag2){break;}
    //         if(f+tmp1 > n){ tmp1 = 0; break;}
    //         //int ans = 0;
    //         //int num_zero = 0;
    //         for(int j=1+tmp2; j<=f+tmp2 ; j++){
    //             if(f+tmp2 > n) {
    //                 tmp2=0; tmp1++;break;
    //             }
    //             if(arr[i][j]==0) num_zero++;
    //             ans += arr[i][j];
    //             //cout<< i <<" "<< j <<" "<<ans << " 뀨잉 " << num_zero<<endl;
    //         }
    //     }
     
    //     if(num_zero >k){
    //         tmp2++; continue;
    //     }
    //     if(num_zero == k){
    //         for(auto &e : v) ans +=e;
    //         answer.push_back(ans);
    //         tmp2++; continue;
    //     }
    //     if(num_zero<k){
    //         for(int i=0 ;i<num_zero ; i++) ans += v[i];
    //         answer.push_back(ans);
    //         tmp2++; continue;
    //     }
    //     tmp1++;f++;
    // }

    sort(answer.begin(), answer.end(), greater<int>());
    if(v[0] >= answer[0]) cout<<v[0]<<endl;
    else cout<<answer[0]<<endl;
    // for(int i=0 ; i<answer.size() ; i++){
    //     cout<<answer[i]<<" ";
    // }
}