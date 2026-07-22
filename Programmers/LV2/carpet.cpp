#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;
multimap<int,int> mp;
vector<int> solution(int brown, int yellow) {
    int xy = brown+yellow;
    int x_plus_y = (brown+4)/2;
    int ansx=0;int ansy=0;
    bool chk=0;
    for(int i=x_plus_y; i>=1; i--){
        if(chk==1)break;
        int x = i;
        int y = x_plus_y-i;
        if(x<y)break;
        if(x*y == xy and x+y==x_plus_y and x>=y){
            ansx=x;ansy=y;
            chk=1;break;
        }
    }
    vector<int> answer;
    answer.push_back(ansx);
    answer.push_back(ansy);
    return answer;
}