#include<iostream>
#include<fstream>
using namespace std;
#define MAX 100

int path_x[8] = {2, 1, -1, -2, -2, -1,  1,  2};
int path_y[8] = {1, 2,  2,  1, -1, -2, -2, -1};

bool isValidCell(int x, int y, int sol[][MAX], int N){
	return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == 0);
}

void printByCoordinate(int sol[][MAX], int N){
	int count = 1;
	while(count < N * N){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(sol[i][j] == count){
					cout << "(" << i << ", " << j << ")" << " ";
					count++;
				}
			}
		}
	}
}

bool knightTour(int sol[][MAX], int row, int col, int total_step, int N){
	if(total_step == N * N) return true;
	for(int idx = 0; idx < N; idx++){
		int new_row = row + path_x[idx];
		int new_col = col + path_y[idx];
		if(isValidCell(new_row, new_col, sol, N)){
			total_step++;
			sol[new_row][new_col] = total_step;
			if(knightTour(sol, new_row, new_col, total_step, N)) return true;
			total_step--;
			sol[new_row][new_col] = 0;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_2.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int N;
	fin >> N;
	fin.close();
	int sol[MAX][MAX];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++) sol[i][j] = 0;
	}
	sol[0][0] = 1;
	if(knightTour(sol, 0, 0, 1, N)){
		cout << "1" << endl;
		printByCoordinate(sol, N);
	}
	else cout << "0";
	return 0;
}