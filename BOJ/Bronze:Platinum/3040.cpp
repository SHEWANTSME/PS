//백설 공주와 일곱 난쟁이 - b2 - 2024.05.29
//조합을 이용하여 9명중 2명을 뽑아서 합이 100이 되는 경우를 찾는다.
#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>>v;
vector<pair<int,int>>vv;
int x,y;
void combinations(int n, int r,int tot) {
    vector<int> vec(n);  
    iota(vec.begin(), vec.end(), 0);  
    vector<bool> select(n); 
    fill(select.end() - r, select.end(), true); 

    do {
        vector<int>tmp;
        for (int i = 0; i < n; ++i) {
            if (select[i]) {
                tmp.push_back(vec[i]);
                //ans.push_back(i);
                //std::cout << vec[i] << " ";
            }
        }
        //cout<<v[tmp[0]].first<< " "<<v[tmp[1]].first<<endl;
        if(v[tmp[0]].first + v[tmp[1]].first==tot){
            x = v[tmp[0]].first;
            y = v[tmp[1]].first;
            //x=tmp[0];y=tmp[1]; 
            //cout<<x<< " "<<y<<endl;
            return;
        }
        tmp.clear();
    } while (next_permutation(select.begin(), select.end()));
}
int main(){
    int total=0;
    for(int i=0; i<9;i++){
        int n;cin>>n;
        total+=n;
        v.push_back({n,i});
        vv.push_back({i,n});
    }
    total-=100;
    //cout<< "TOT "<<total<<endl;
    sort(v.begin(),v.end());
    combinations(9,2,total);

    for(int i=0;i<9;i++){
        if(x == vv[i].second or y==vv[i].second)continue;
        else cout<<vv[i].second<<endl;
    }
}

//저렇게 굳이 이것저것 해서 하는것 보단
// 이렇게 하는게 훨씬 더 깔끔..
#include <bits/stdc++.h>
using namespace std;
int arr[9];
bool check[9];
int main() {
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (sum - (arr[i] + arr[j]) == 100) {
                check[i] =1;
                check[j] =1;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (check[i] == 1) continue;
        cout << arr[i] << endl;
    }
}