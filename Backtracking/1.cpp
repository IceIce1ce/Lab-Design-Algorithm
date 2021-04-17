#include<iostream>
#include<fstream>
using namespace std;
#define MAX 100

int cnt = 0;

void printByCoordinate(int board[][MAX], int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(board[i][j] == 1) cout << "(" << i << ", " << j << ")" << " ";
		}
	}
}

bool isPromissing(int board[][MAX], int row, int col, int N){
	for(int i = 0; i < col; i++){
		if(board[row][i]) return false; //check row
	}
	for(int i = 0; i < row; i++){
		if(board[i][col]) return false; //check col
	}
	int _i = row, _j = col;
	while(_i >= 0 && _j < N){
		if(board[_i][_j]) return false; //check top right diagonals
		_i--; _j++;
	}
	_i = row, _j = col;
	while(_i >= 0 && _j >= 0){
		if(board[_i][_j]) return false; //check top left diagonals
		_i--; _j--;
	}
	return true;
}

bool solve(int board[][MAX], int col, int N){
	if(col == N) cnt++;
	if(col >= N) return true;
	for(int i = 0; i < N; i++){
		if(isPromissing(board, i, col, N)){
			board[i][col] = 1; //change to 1 after placing
			if(solve(board, col + 1, N)) return true;
			board[i][col] = 0; //empty cell can place
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_1.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int N;
	fin >> N;
	fin.close();
	int board[MAX][MAX];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++) board[i][j] = 0; //init board
	}
	if(solve(board, 0, N) == false) return 0;
	cout << cnt << endl;
	printByCoordinate(board, N);
	return 0;
}