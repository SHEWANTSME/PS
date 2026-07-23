#include <string>
#include <vector>
using namespace std;

int cnt = 1;                          // 지금까지 방문한 노드 개수 (A가 1번째)
char vowels[5] = {'A','E','I','O','U'}; // 모음 사전 순서

// 현재 모음 c의 "다음 모음"을 반환 (U는 호출되지 않는다고 가정)
char nxtvowel(char c){
    for(int i=0; i<5; i++){
        if(vowels[i]==c) return vowels[i+1];
    }
}

int DFS(string s, string word){
    if(s==word) return cnt;           // 목표 단어에 도달 -> 현재 순번 반환

    if(s.size()<5){
        // 아직 자식이 있는 노드 -> 항상 첫 번째 자식('A')으로 내려간다
        s.push_back('A');
        cnt++;                        // 새 노드 방문 -> 순번 증가
        return DFS(s,word);
    }

    if(s.size()==5){
        // leaf 노드 -> 더 못 내려가니 형제/부모 쪽으로 이동해야 함
        if(s.back()!='U'){
            // 마지막 글자가 U가 아니면 -> 바로 다음 형제로 교체
            char tmp = s.back();
            s.pop_back();
            s.push_back(nxtvowel(tmp));
            cnt++;
            return DFS(s,word);
        }
        else{
            // 마지막 글자가 U -> 이 노드는 "막내 자식"이었으므로
            // U인 동안 계속 부모로 거슬러 올라간다
            while(s.back()=='U'){
                s.pop_back();
            }
            // U가 아닌 글자를 만나면, 거기서 다음 형제로 교체
            char tmp = s.back();
            s.pop_back();
            s.push_back(nxtvowel(tmp));
            cnt++;
            return DFS(s,word);
        }
    }
}

int solution(string word){
    return DFS("A", word);            // 트리의 루트 'A'에서 탐색 시작
}