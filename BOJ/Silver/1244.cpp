//스위치 켜고 끄기 - S4 - 2023/08/29
// 그냥 무지성으로 했어도 되는데 bitset을 써보고 싶었음 
#include <iostream>
#include <bitset>
using namespace std;
int n,m;
bitset<101>bit;// 101비트짜리 bitset 선언
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        bool k; cin>>k;
        bit[i]=k;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int gen, num;
        cin >> gen >> num;
        if (gen == 1) {//Male
            for (int j = num; j <= n; j += num) bit.flip(j);
            // 배수만큼 for문 돌면서 flip
        } 
        else {//Female
            auto original = bit[num];
            int ll = num - 1;
            int rr = num + 1;
            while(ll>=1 and rr<=n and bit[ll]==bit[rr]){
                bit.flip(ll); bit.flip(rr);
                ll--; rr++;
            }
            if(original == bit[num])bit.flip(num);
            // 처음 녀석도 flip 해줘야함.. 안하면 4퍼틀 나옴
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout<<bit[i]<<" ";
        if(i%20==0)cout<<endl;
    }
}
/*
BITSET chatgpt 설명

1. 생성자와 초기화:

    std::bitset<N>: N 크기의 비트 집합을 생성합니다. N은 컴파일 타임에 결정되는 정수 값입니다.
    std::bitset<N>(initial_value): 초기 값을 가지고 비트 집합을 생성합니다. initial_value는 정수 또는 이진 문자열로 제공될 수 있습니다.

2. 비트 조작:
    set(pos): pos 위치의 비트를 1로 설정합니다.
    reset(pos): pos 위치의 비트를 0으로 설정합니다.
    flip(pos): pos 위치의 비트를 반전(0은 1로, 1은 0으로)합니다.

3. 비트 확인:
    test(pos): pos 위치의 비트 값을 확인합니다. (0 또는 1을 반환)

4. 비트 연산:
    &, |, ^: 비트 단위 AND, OR, XOR 연산을 수행합니다.
    ~: 비트 단위 NOT 연산을 수행합니다.

5.스트링 변환:
    to_string(): 비트 집합을 이진 문자열로 변환합니다.
    to_ulong(): 비트 집합을 unsigned long 타입의 정수로 변환합니다.

6. 비트 세기:
    count(): 비트 집합 내에서 1인 비트의 개수를 반환합니다.

7. 비트 위치 액세스:
    operator[]: 비트 집합 내 특정 위치의 비트에 접근할 수 있는 배열 형식의 연산자입니다.
*/