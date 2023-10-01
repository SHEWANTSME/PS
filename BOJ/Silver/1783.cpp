//병든 나이트 - S3 - 2023/10/01
// N에 따라 조건 분기해야하는 Greedy
#include<iostream>
#include<algorithm>
#define P "\n" //endl 좀 길어서 
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    if(n==1)cout<<1<<P;// 높이가 1이면 1밖에 안됨
    else if(n==2){// 높이가 2이면 
        if(m>7)cout<<4<<P;// 가로가 7보다 크면 무조건 4
        // 길게 지그재그만 가능한데 맥시멈이 4개니까 
        else cout<<(m+1)/2<<P;// 7보다 작으면 3,2,1개 일텐데, m이 홀수인 경우도 생각해줘야 하니까
    }
    // 4가지 경우를 다 쓰면서 최소의 m은 7이므로
    // 7보다 작은 애들은 4가지 경우를 다 못쓰면서 m만큼 움직일 수 있지만,
    // m<=4가 아닌이상 m의 길이만큼 움직일 수는 없으므로
    else if(m<7)cout<<min(4,m)<<P;// 이렇게 되는거고
    else cout<<m-2<<P;// n>=3 , m>=7인 경우에는 그림을 보면 알겠지만 m-2만 됨
}