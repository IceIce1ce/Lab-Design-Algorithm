#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void lis_DP(int a[], int n){
	vector<int> *L = new vector<int>[n];
	L[0].push_back(a[0]);
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[j] < a[i] && L[j].size() > L[i].size()) L[i] = L[j];
		}
		L[i].push_back(a[i]);
	}
	int max = INT_MIN;
	for(int i = 0; i < n; i++){
		if(L[max].size() < L[i].size()) max = i;
	}
	vector<int> res;
	for(auto it: L[max]) res.push_back(it);
	for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
	cout << endl << res.size();
	delete[] L;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_4.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int n;
	fin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++) fin >> a[i];
	fin.close();
	lis_DP(a, n);
	return 0;
}