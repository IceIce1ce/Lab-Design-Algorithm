#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int n;
int** readFileToMatrix(int **matrix = NULL){
	ifstream fin("input_1.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	vector<vector<int>> tmp;
	if(fin.is_open()){
		fin >> n;
		matrix = new int*[n];
		for(int i = 0; i < n; i++) matrix[i] = new int[n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++) matrix[i][j] = 0;
		}
		string line;
		while(getline(fin, line)){
			istringstream ss(line);
			tmp.emplace_back(istream_iterator<int>(ss), istream_iterator<int>());
		}
	}
	fin.close();
	for(int i = 1; i < n; i++){
		while(tmp[i].size() != n){
			tmp[i].push_back(0);
			if(tmp[i].size() == n) break;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) matrix[i][j] = tmp[i + 1][j];
	}
	return matrix;
	delete[] matrix;
}

int **new_matrix = readFileToMatrix();
vector<int> list_cost;

void maxPathTriangle(){
	int max = INT_MIN, i = 0, *result = new int[n];
	while(i >= 0){
		for(int j = 0; j < n; j++){
			if(new_matrix[i][j] > max) max = new_matrix[i][j];
		}
		result[i] = max;
		max = 0;
		i++;
		if(i == n) break;
	}
	for(int i = 0; i < n; i++) list_cost.push_back(result[i]);
	delete[] result;
}

int maxPathDp(int k = n - 1){
	for(int i = k - 1; i >= 0; i--){
		for(int j = 0; j <= i; j++) new_matrix[i][j] += max(new_matrix[i + 1][j], new_matrix[i + 1][j + 1]);
	}
	return new_matrix[0][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	maxPathTriangle();
	cout << maxPathDp() << endl;
	for(int i = 0; i < list_cost.size(); i++) cout << list_cost[i] << " ";
	for(int i = 0; i < n; i++) delete[] new_matrix[i];
	delete[] new_matrix;
	return 0;
}