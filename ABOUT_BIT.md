## ABOUT BIT  
![Bit](https://github.com/SHEWANTSME/NOVEMBER/assets/91362178/eb034879-2515-4f8b-8601-0dd39f503ff8)
<img width="591" alt="비트연산과로직연산차이" src="https://github.com/SHEWANTSME/NOVEMBER/assets/91362178/7410f975-bc5f-4ea0-873f-8a967cd826fa">

```cpp  
#include <iostream>
#include <bitset>
#include <string>
using namespace std;
// using sublime text without debugging sounds okay..? 
int main() {
	unsigned char items_flag = 0;

	//cout << bitset<8>(items_flag)<<endl; // 8비트 사이즈로 00000000이 찍히겠지?
	// make each bit on flags
	const unsigned char opt0 = 2 << 0; -> 데이터 변경이 필요 없을때 쓰는 안전장치!! -> CONST
	const unsigned char opt1 = 2 << 1;
	const unsigned char opt2 = 2 << 2;
	const unsigned char opt3 = 1 << 3;
	const unsigned char opt4 = 4 << 1;
	// 보면 알겠지만 2<<2랑 1<<3 이랑 4<<1은 값이같음 
	// 조금만 생각해보면 알 수 있음


	cout << bitset<8>(opt0) << endl;
	cout << bitset<8>(opt1) << endl;
	cout << bitset<8>(opt2) << endl;
	cout << bitset<8>(opt3) << endl;
	cout << bitset<8>(opt4) << endl;

	items_flag |= opt0;  --> i_f = i_f | opt0 -> 둘의 범위를 합친 범위가 곧 내 범위다.
	cout << "Item0 obtained" << bitset<8>(items_flag) << endl;
	items_flag |= opt2;
	cout << "Item2 obtained" << bitset<8>(items_flag) << endl;
	items_flag &= ~opt3;  --> 드모르간을 생각해보셈 -> opt3이 아닌부분과 i_f와의  교집합이면 i_f에서 opt3을 뺀 부분
	cout << "Item3 lost" << bitset<8>(items_flag) << endl;

}
```  
---   

#### ~ -> NOT -> 0000 to 1111  

#### & -> AND -> 1111&0101 = 0101(비교한둘이 모두 1일때 1)  

#### | -> OR -> 1111 | 0101 -> 1111 (둘중하나라도 1일때 1)  

#### ^ -> XOR -> 1110 ^ 0100 -> 1010(같으면 거짓이라는 씹변태규칙)  

----  

### i 번째 비트 구하기  

1. x & (1 << i)  
    ex) 0 1 0 1 1 에서 3번째 비트를 구하려면 0 1 0 0 0 과 & 연산자를 취해주면 됨. 단, 이 때는 결과가 0이면 i번째가 0이고 0이 아니면 i번째가 1이구나로 판단  

2. (x >> i) & 1  
    ex) 같은 예제에서 0 1 0 1 1 을 3만큼 right shift 해준 값과 & 연산을 취하면, 0 0 0 0 1 즉, 1과 & 연산을 취하게 된다.

` -> 전체 결과가 1인지 0인지로 판단 가능하다. `  


----- 
### i번째 비트를 0과 1로 설정하기  

1. 1로 설정하기 x | (1 << i)  
    x | (1 << i), 해당 자리에 1과 OR 연산 취해주면 1로 바뀌는 것 이용
    {만약 원래 그 자리가 0 인걸 알고 있다면 x + (1 << i) 를 사용해도 된다.}

2. 0으로 설정하기 x & ~(1 << i)  
    ex) 0 1 0 1 1 에서 3번째를 0으로 바꾸고 싶을 때, 1 0 1 1 1 즉, 해당자리에 0을 주고 & 연산을 취하면 0으로 바뀌게 된다. 그러면 1 0 1 1 1 을 어떻게 찾느냐?
    
    ### -> 해당 자리만 1로 만든 0 1 0 0 0 에서 ~(NOT) 연산을 취한 값이다.
    즉, x & ~(1 << i)
    
    만약 원래 그 자리가 1인걸 알고 있다면, x - (1 << i) 로 사용할 수 있다.

----- 
### 마지막 n 비트 구하기  

1. x & ((1 << n) - 1)  
    ex) 0 1 0 1 1 에서 마지막 3 비트를 구하고 싶다면 0 0 1 1 1 과 &를 취해주면 된다.  

* 0 0 1 1 1 은 무엇이냐?
  -> 0 1 0 0 0 에서 1을 뺀 값이다.
  따라서, x & ((1 << n) - 1)  

------  
### i번째 비트 반전  

* x ^ (1 << i)
    ex) 0 1 0 1 1 에서 3번째 1을 0으로 바꾸고 싶다면 0 1 0 0 0 과 XOR 연산을 취해주면 된다.

