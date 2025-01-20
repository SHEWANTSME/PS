// 스도쿠 - 2580번, 2239번 - G4 - 2025/01/20
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// pair를 두번써서 조잡하지만 일단 이렇게 둠
vector<pair<pair<int, int>, int>>v;
int arr[10][10];
// 처음엔 체크함수를 int로 했었는데 생각해보니 bool로 해도 될거같아서 bool로 변경
// 이 체크함수에 인자를 벡터를 처음에 넣었었는데 그러니까 시간초과걸려서 빼버렸더니 통과

bool check( int nn) {
	int fir = v[nn].first.first; // X
	int sec = v[nn].first.second; // Y
	int place = v[nn].second; // 미니스퀘어 PLACENUM
	for (int i = 1; i <= 9; i++) {
		if (arr[fir][i] == arr[fir][sec] and i != sec) return 0;// 가로 검사 
        // FOR돌면서 I랑 SEC가 다르면서 정작 원소값 같으면 그냥 0리턴
		if (arr[i][sec] == arr[fir][sec] and i != fir) return 0;
        // 얘는 세로검사  마찬가지
	}
	if (place == 1) // 여기까지 온거면 이미 위에애들이 1이란 얘기(가로세로가 )
		{ // 여기서부터는 1~9까지 범위별로 미니스퀘어 검사하는거임
			for (int i = 1; i <= 3; i++){
				for (int j = 1; j <= 3; j++){
					if (arr[i][j] == arr[fir][sec]){ // 미니스퀘어에서 값이 같으면서 , 정작 X,Y가 I,J가 아니면
						if (i != fir and j != sec) return 0; // 당근 0리턴이겟지							
					}
				}
			}
			return 1; // 이 모든 검사를 통과하면 1을 받을 자격 충만
		}
		
	else if (place == 2) // 같은거라 생략
    	{
			for (int i = 1; i <= 3; i++){
				for (int j = 4; j <= 6; j++){
					if (arr[i][j] == arr[fir][sec]){
						if (i != fir and j != sec) return 0;
					}
				}
			}
			return 1;
		}
		
	else if (place == 3){
		for (int i = 1; i <= 3; i++){
			for (int j = 7; j <= 9; j++){
				if (arr[i][j] == arr[fir][sec]){
					if (i != fir and j != sec) return 0;
				}
			}
		}
		return 1;
	}
		
	else if (place == 4){
		for (int i = 4; i <= 6; i++){
			for (int j = 1; j <= 3; j++){
				if (arr[i][j] == arr[fir][sec]){
					if (i != fir and j != sec) return 0;
				}
			}
		}
		return 1;
	}

	else if (place == 5){
		for (int i = 4; i <= 6; i++){
			for (int j = 4; j <= 6; j++){
				if (arr[i][j] == arr[fir][sec]){
					if (i != fir and j != sec) return 0;
				}
			}
		}
		return 1;
	}

	else if (place == 6){
		for (int i = 4; i <= 6; i++){
			for (int j = 7; j <= 9; j++){
				if (arr[i][j] == arr[fir][sec]){
					if (i != fir and j != sec) return 0;
				}
			}
		}
		return 1;
	}
		
	else if (place == 7){
		for (int i = 7; i <= 9; i++){
			for (int j = 1; j <= 3; j++){
				if (arr[i][j] == arr[fir][sec]){
					if (i != fir and j != sec) return 0;
				}
			}
		}
		return 1;
	}
	else if (place == 8){
		for (int i = 7; i <= 9; i++){
			for (int j = 4; j <= 6; j++){
				if (arr[i][j] == arr[fir][sec]){
					if (i != fir and j != sec) return 0;
				}
			}
		}
		return 1;
	}
		
	else if (place == 9){
		for (int i = 7; i <= 9; i++){
			for (int j = 7; j <= 9; j++){
				if (arr[i][j] == arr[fir][sec]){
					if (i != fir and j != sec) return 0;
				}
			}
		}
		return 1;
	}	
}
void Sudoku(int n) {
    // n-queen도 그렇고 이게 가장 중요한 함수 틀임.
    // 어떤 숫자에 도달했을때 끝마치는 백트래킹의 기본 형태. 계속 까먹는데 외워두자!
	if (n == v.size()) { // V의 사이즈 와 같을때
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << arr[i][j];
			}cout << endl;
		} // 출력
		exit(0); // 이거 안하니까 런타임뜨더라고 왜그런진 잘 모르겠당
	}
	for (int i = 1; i <= 9; i++) {// 처음엔 싹다 인자로 받고 재귀로 했던것도 또 돌리고 이러니까 시간초과
        // 그냥 이렇게 숫자는 1부터 9까지니까 
		arr[v[n].first.first][v[n].first.second] = i;
        // N+1번째 벡터의 ARR의 (X,Y)를 1부터 차근차근 증가시킴
		if (check(n))Sudoku(n + 1); // CHECK가 1이면 N을 1증가하고 재귀
	}
	arr[v[n].first.first][v[n].first.second] = 0; // 백트래킹할때는 이렇게
    // 쭉 재귀타다가 막혀서 돌아와야할때 이렇게 조건 초기화를 해줘야함
    // 안하면 난장판됨.. 암튼 이렇게 해줘야 다음번에 다른위치에서 재귀를 타서 이 위치로 돌아올때 값의 영향이 없지
	return;
}
int main() {
    fastio;
	for (int i = 1; i <= 9; i++) {
        string s; cin>>s;
		for (int j = 1; j <= 9; j++) {
			arr[i][j] = s[j - 1] - '0'; // arr안에 string을 int로 변환해서 넣어줌
			if (arr[i][j] == 0) {
                // arr가 0일때 v에 (x,y)와 minisquare에서의 placenum을 붙여줬다.
				if (i <= 3 and j <= 3)v.push_back({ { i,j },1 });
				if (i <= 3 and j <= 6 and j > 3)v.push_back({ {i,j},2 });
				if (i <= 3 and j > 6 and j <= 9)v.push_back({ {i,j},3 });
				if (i > 3 and i <= 6 and j <= 3)v.push_back({ {i,j},4 });
				if (i > 3 and i <= 6 and j > 3 and j <= 6)v.push_back({ {i,j},5 });
				if (i > 3 and i <= 6 and j > 6 and j <= 9)v.push_back({ {i,j},6 });
				if (i > 6 and i <= 9 and j <= 3)v.push_back({ {i,j},7 });
				if (i > 6 and i <= 9 and j > 3 and j <= 6)v.push_back({ {i,j},8 });
				if (i > 6 and i <= 9 and j > 6 and j <= 9)v.push_back({ {i,j},9 });
		}
			
	}
}
	Sudoku(0); // v는 지금 zero-indexed니까 0으로 해야지
	return 0;
}