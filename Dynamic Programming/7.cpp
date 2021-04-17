#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

void knapSack(int W, int *w, int *v, int n){
	//v: values, w: weights, n: number of distinct items, W: knapsack capacity
	int row = n + 1, col = W + 1, **value = new int*[row], j;
	for(int i = 0; i < row; i++) value[i] = new int[col];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++) value[i][j] = -1;
	}
	for(int i = 0; i <= n; i++){
		for(j = 0; j <= W; j++){
			if(i == 0 || j <= 0) value[i][j] = 0;
			else if(w[i] > j) value[i][j] = value[i - 1][j];
			else if(w[i - 1] <= j) value[i][j] = max(v[i - 1] + value[i - 1][j - w[i - 1]], value[i - 1][j]);
		}
	}
	int val = value[n][W];
	vector<int> items;
	j = W;
	if(value[n][W] > 0){
		for(int i = n; i > 0; i--){
			if(value[n][W] != value[i - 1][j]){
				items.push_back(i);
				value[n][W] -= v[i - 1];
				j -= w[i - 1];
			}
			else continue;
		}
	}
	sort(items.begin(), items.end());
	for(int i = 0; i < items.size(); i++){
		items[i]--;
		cout << items[i] << " ";
	}
	cout << endl << val;
	for(int i = 0; i < row; i++) delete[] value[i];
	delete[] value;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_7.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int W, n, *w = NULL, *v = NULL;
	if(fin.is_open()){
		fin >> W;
		fin >> n;
		w = new int[n];
		v = new int[n];
		for(int i = 0; i < n; i++) fin >> w[i] >> v[i];
	}
	knapSack(W, w, v, n);
	delete[] w;
	delete[] v;
	return 0;
}