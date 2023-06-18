// 단어 변환 - LV3 - 2023/06/18
#include<iostream>
#include<algorithm>
#include <string>
#include <vector>
using namespace std;
int ans=1e9;
int visited[52];
// 다시 해보기 -> 빠르게
/*
재귀를 항상 풀때는 '이 함수가 어떻게 넘어가겠구나' 만 틀을 만들고
문제를 푸는 시간엔 자세히 어떻게 돌아가나를 확인할 필요는 없음. 그냥 믿고 만들어보면 됨
*/
vector<string>sss = {"hot","dot","dog","lot","log","cog"};
void Rec(string beg,string tar, vector<string>words,int depth){
    if(ans<=depth)return;// 최소값 구하는거니까
    if(beg == tar){ans=min(ans,depth);return;} // ans 갱신하고 리턴
    for(int i=0 ; i<words.size() ; i++){
        int chkchk = 0;
        for(int j=0; j<beg.size() ; j++){
            if(beg[j]!=words[i][j])chkchk++;
        }// 딱 한개만 달라야 하니까
        if(chkchk==1 and not visited[i]){// 딱 하나만 다른 상태 + 방문 아직 안함
            visited[i]=1;// 방문처리하고
            Rec(words[i] , tar , words, depth+1);// 그 자리에서부터 재귀 돌려
            visited[i]=0;// 재귀에서 나오면 방문해제처리하고
        }
    }
    return;
}
int solution(string beg, string tar, vector<string> words) {
    Rec(beg,tar,words,0);
    if(ans==1e9)return 0;
    else return ans;
}
int main(){
    cout<<solution("hit" , "cog" , sss)<<endl;
}