// 임스의 땅따먹기 - G3 -2025.04.23
// n by n을 숫자를 늘려가면서 filter를 sliding window 해야 할듯? 그렇게 brute force 하면 풀릴거같음

// 시간초과 코드
#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl "\n"
using namespace std;

int n, k;
int arr[501][501];        // 원본 격자 배열
int pre[501][501];     // 누적합 배열 (2차원 prefix sum)
int zero[501][501];       // 0의 개수를 저장하는 누적합 배열
vector<int> v;            // 대체할 수 있는 숫자들

// 2차원 누적합을 이용해 (x1, y1) ~ (x2, y2) 구간의 총합을 O(1)로 반환
int get_sum(int x1, int y1, int x2, int y2) {
    return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
}

// 동일 방식으로 해당 구간의 0의 개수를 O(1)로 반환
int get_zero(int x1, int y1, int x2, int y2) {
    return zero[x2][y2] - zero[x1-1][y2] - zero[x2][y1-1] + zero[x1-1][y1-1];
}

int main(){
    fastio;

    // 입력: n x n 배열
    cin >> n;
    int total = 0;        // 전체 배열의 총합
    int num_zero = 0;   // 전체 배열에서 0의 개수

    // 배열 입력 및 누적합/0 개수 배열 초기화
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + arr[i][j];// 2차원 누적합
            if(arr[i][j] == 0) {zero[i][j] = zero[i-1][j] + zero[i][j-1] - zero[i-1][j-1] +1; num_zero++;} 
            else zero[i][j] = zero[i-1][j] + zero[i][j-1] - zero[i-1][j-1]; // 0의 개수 누적합
            total += arr[i][j];               // 전체 합 계산
        }
    }

    // 바꿔 넣을 수 있는 숫자 k개 입력받기
    cin>>k;
    for(int i=0; i<k ; i++){int t; cin>>t; v.push_back(t);}

    // 내림차순 정렬: 큰 값부터 차례대로 대입하기 위함
    sort(v.rbegin() , v.rend());// same as sort(v.begin(), v.end(), greater<int>());

    // 0이 하나도 없으면 그냥 전체 합 출력 후 종료
    if(num_zero == 0){cout << total << endl; exit(0);}

    int answer = 0; // 가능한 최대 점수를 저장

    // 필터 크기 f x f 를 1부터 n까지 늘려가며 확인
    for(int f = 1; f <= n; f++){
        // 시작 좌표 (i, j) 에 대해 전체 탐색
        for(int i = 1; i + f - 1 <= n; i++){
            for(int j = 1; j + f - 1 <= n; j++){
                // 현재 윈도우 좌표: (i,j) ~ (i+f-1, j+f-1)
                int x1 = i, y1 = j;
                int x2 = i + f - 1, y2 = j + f - 1;

                // 이 구간 안의 0의 개수
                int cur_zero = get_zero(x1, y1, x2, y2);

                // 바꿀 수 있는 수보다 0이 많으면 skip
                if(cur_zero > k) continue;

                // 기본 합 (0 포함)
                int cur_sum = get_sum(x1, y1, x2, y2);

                // 0인 칸마다 대체 숫자 넣기 (큰 수부터)
                for(int z = 0; z < cur_zero; z++) {
                    cur_sum += v[z];
                }

                // 현재 점수 갱신
                answer = max(answer, cur_sum);
            }
        }
    }

    // 가능한 점수 중 최대와, 단일 숫자만 넣는 경우 중 큰 값 출력
    cout << max(answer, v[0]) << endl;
}




























// 시간초과난 방법
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



// 정답 코드
#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl "\n"
using namespace std;

int n,k; 
int arr[501][501];
int pre[501][501]; // 2차원 누적합 배열
int zero[501][501]; // 0의 개수를 저장하는 누적합 배열
vector<int>v;

int get_sum(int x_1, int y_1, int x_2, int y_2){ 
    return pre[x_2][y_2] - pre[x_1-1][y_2] - pre[x_2][y_1-1] + pre[x_1-1][y_1-1];
}

int get_zero(int x_1, int y_1, int x_2, int y_2){
    return zero[x_2][y_2] - zero[x_1-1][y_2] - zero[x_2][y_1-1] + zero[x_1-1][y_1-1];
}

int main(){
    fastio;
    cin>>n;
    int tot=0;
    int num_zero = 0;
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=n ; j++){
            cin>>arr[i][j];
            pre[i][j] = pre[i-1][j] +pre[i][j-1] - pre[i-1][j-1] + arr[i][j];
            if(arr[i][j] == 0){zero[i][j] = zero[i-1][j]+zero[i][j-1] - zero[i-1][j-1]+1;num_zero++;}
            else zero[i][j] = zero[i-1][j]+zero[i][j-1] - zero[i-1][j-1];
            tot +=arr[i][j];
        }
    }
    cin>>k;
    for(int i=0; i<k;i++){int t; cin>>t; v.push_back(t);}
    sort(v.rbegin(),v.rend());
    
    vector<int> reward_sum(k+1, 0);
    for (int i = 1; i <= k; i++) reward_sum[i] = reward_sum[i-1] + v[i-1];
    
    if(num_zero ==0){cout<<tot<<endl;exit(0);}
    
    int ans = 0;
    int filter = 1;
    while(filter<=n){
        for(int i=1; i+filter-1 <=n ; i++){
            for(int j=1; j+filter-1<=n ; j++){
                int x_1 = i; int x_2 = i+filter-1;
                int y_1 = j; int y_2 = j+filter-1;
                
                int num_z = get_zero(x_1,y_1,x_2,y_2);
                if(num_z>k)continue;
                
                int num_sum = get_sum(x_1,y_1,x_2,y_2);
                int bonus = reward_sum[num_z]; 
                ans=max(ans,num_sum+bonus);
            }
        } filter++;
    }
    cout<<max(ans,v[0])<<endl;
}