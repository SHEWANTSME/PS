#include <string>
#include <vector>
#include<algorithm> // sort 때매
#include<set> // set 때매
#include<cmath>// sqrt때매
using namespace std;

// 문자열 numbers로 만들 수 있는 "모든 숫자 조합"을 구하는 함수
// 반환 타입을 set<int>로 한 이유: 중복 숫자(예: "011")가 있어도
// 같은 숫자가 여러 경로로 만들어질 수 있는데, set이 자동으로 중복 제거 + 정렬까지 해줌
set<int> make_num(string n){
    // next_permutation은 "현재 상태 이후의 순열"만 만들어주기 때문에,
    // 모든 순열을 빠짐없이 돌려면 반드시 오름차순 정렬한 상태에서 시작해야 함
    sort(n.begin(), n.end());

    set<int> cands; // 만들어질 수 있는 모든 숫자 후보를 저장할 집합

    // do-while을 쓰는 이유: 정렬 직후의 최초 상태도 "하나의 순열"이므로
    // 조건 검사 전에 먼저 한 번은 실행되어야 함 (while로 쓰면 최초 상태를 놓침)
    do{
        // 현재 순열(n)에서 길이 1자리부터 전체 길이까지 앞부분(prefix)을 잘라서
        // 전부 숫자로 변환 -> 이렇게 하면 "몇 자리를 뽑을지 + 어떤 순서로 배치할지"가
        // 순열 자체에서 다 커버됨
        for(int i=1; i<=n.size() ; i++){
            cands.insert(stoi(n.substr(0,i))); // substr(0,i): 0번 인덱스부터 i개 문자
            // stoi가 "007" 같은 문자열도 앞자리 0을 무시하고 7로 자동 변환해줌
        }
    }while(next_permutation(n.begin(),n.end())); 
    // next_permutation은 "다음 순열로 바꾸는 데 성공했는지"를 bool로 리턴
    // 다시 오름차순 최초 상태로 돌아오면 false를 리턴하면서 루프 종료

    return cands; // 후보 숫자들의 집합을 그대로 반환
}

// cands 안의 숫자들 중 소수가 몇 개인지 세는 함수
int chk_prime(set<int> cands){
    int cnt=0; // 소수 개수 누적
    for(auto &e : cands){ // set의 모든 원소를 하나씩 확인
        if(e<=1)continue; // 0, 1은 소수가 아니므로 바로 스킵 (사실 0은 make_num에서 안 나오지만 방어적으로 처리)

        bool x = 0; // 합성수(소수가 아님) 여부 플래그. false로 초기화

        // 소수 판별: 2부터 sqrt(e)까지만 나누어봐도 충분함
        // (e의 약수는 항상 sqrt(e)를 기준으로 쌍을 이루기 때문에, 그 이상은 검사할 필요 없음)
        for(int i=2; i<=sqrt(e); i++){
            if(e%i==0){x=1;break;} // 나누어떨어지는 수를 찾으면 소수가 아니므로 바로 탈출
        }

        if(!x)cnt++; // 끝까지 나누어떨어지는 수가 없었다면(x==0) 소수이므로 카운트
    }
    return cnt;
}

int solution(string numbers) {
    set<int> st = make_num(numbers); // 1단계: 만들 수 있는 모든 숫자 후보 구하기
    int ans = chk_prime(st);         // 2단계: 그 후보들 중 소수 개수 세기
    return ans;
}