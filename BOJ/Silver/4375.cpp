// 1 - S3 - 2023/08/27
// c++로 시간초과 나길래 일단 python으로 풀었는데 
// %n을 하니까 통과됨
#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){// 예전에 틀렸을때는 이렇게 안하고 while(1) {cin>>n; if(cin.eof()) break; }이렇게 했었는데 이렇게 하면 틀림..
    // 아래 주석 봐보셈
        int num=1;
        int ones=1;
        while(1){
            if(ones%n==0) break;
            ones*=10; ones++;
            num++; 
            ones%=n;// 이게 핵심임 ones가 너무 커지면 int 범위를 넘어가서 오버플로우가 발생함
        }
        cout<<num<<endl;
    }
}

/*EOF bit는 마지막 값을 읽었을 때 켜지지 않습니다. 그건 성공이기 때문입니다. 그 다음에 또 읽으려고 했을 때(실패했을 때) 켜집니다.

아래 Code 1에서는, 5까지 쓴 뒤 cin.eof()가 아직 false이므로 while문에 한 번 더 들어가며, 이때는 cin >> n;이 실패하므로 n에 5가 그대로 들어 있어 5가 2번 찍힙니다.

그에 반해 Code 2에서는 5까지 쓴 뒤 6번째로 cin >> n;을 실행했을 때 EOF bit가 켜지면서 while의 조건을 false로 만들어 주기에 while문에 또 들어가지 않습니다.

(수정: 코드에서 '\n'은 ' '으로 생각해주세요)*/

입력: "1 2 3 4 5"

// Code 1-------------
int n;
while (!cin.eof()) {
    cin >> n;
    cout << n << '\n';
}
출력: 1 2 3 4 5 5
//----------------------

// Code 2-------------
int n;
while (cin >> n) {
    cout << n << '\n';
}
출력: 1 2 3 4 5
//-----------------------