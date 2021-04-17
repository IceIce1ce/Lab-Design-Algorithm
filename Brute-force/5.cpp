#include<iostream>
#include<vector>
#include<fstream>
#include<climits>
using namespace std;

int n_cities;
 
int** readFileToMatrix(int **matrix = NULL){
	ifstream fin("input_5.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	vector<int> tmpCity1, tmpCity2, tmpCost;
	int city1, city2, cost;
	if(fin.is_open()){
		fin >> n_cities;
		matrix = new int*[n_cities];
		for(int i = 0; i < n_cities; i++) matrix[i] = new int[n_cities];
		for(int i = 0; i < n_cities; i++) {
			fin >> city1 >> city2 >> cost;
			tmpCity1.push_back(city1);
			tmpCity2.push_back(city2);
			tmpCost.push_back(cost);
		}
	}
	fin.close();
	for(int i = 0; i < n_cities; i++){
		for(int j = 0; j < n_cities; j++){
			matrix[i][j] = 0; 
		}
	}
	int cnt = 0;
	while(cnt < n_cities){
		matrix[tmpCity1[cnt] - 1][tmpCity2[cnt] - 1] = tmpCost[cnt];
		matrix[tmpCity2[cnt] - 1][tmpCity1[cnt] - 1] = tmpCost[cnt];
		cnt++;
		if(cnt == n_cities) break;
	}
	return matrix;
	for(int i = 0; i < n_cities; i++) delete[] matrix[i];
	delete[] matrix;
}

int **newMatrix = readFileToMatrix(), *visited = new int[n_cities];
vector<int> tmpPath, tmpCost;

int init(int S){
	int cMin = INT_MAX, min = INT_MAX;
	for(int i = 0; i < n_cities; i++){
		if(newMatrix[S][i] != 0 && visited[i] != 1){
			if(newMatrix[S][i] + newMatrix[i][S] < min){
				min = newMatrix[S][i] + newMatrix[i][0];
				cMin = i;
			}
		}
	}
	return cMin;
}

void TSP(int S = 0){
	visited[S] = 1;
	cout << S + 1 << " ";
	tmpPath.push_back(S + 1);
	int n_cities = init(S);
	if(n_cities != INT_MAX) TSP(n_cities);
	else n_cities = 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	TSP();
	int cnt = 0, total_cost = 0;
	while(cnt < n_cities - 1){
		tmpCost.push_back(newMatrix[tmpPath[cnt] - 1][tmpPath[cnt + 1] - 1]);
		cnt++;
		if(cnt == n_cities) break;
	}
	tmpCost.push_back(newMatrix[tmpPath[tmpPath.size() - 2]][tmpPath[0] - 1]);
	for(int i = 0; i < tmpCost.size(); i++) total_cost += tmpCost[i];
	cout << "\n" << total_cost;
	delete[] visited;
	for(int i = 0; i < n_cities; i++) delete[] newMatrix[i];
	delete[] newMatrix;
	return 0;
}