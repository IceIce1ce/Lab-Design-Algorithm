#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;

void print(bool **V, int a[], int i, int k, queue<int> &q){
	queue<int> p = q;
	if(i == 0){
		bool exc1 = V[0][k];
		if(k != 0){
			if(exc1 == 1){
				q.push(a[i - 1]);
				while(!q.empty()){
				cout << q.front() << " ";
				q.pop();
				}
			}
		}
		else{
			cout << endl;
			while(!q.empty()){
				cout << q.front() << " ";
				q.pop();
			}
		}
	}
	else{
		bool exc2 = V[i - 1][k];
		if(exc2 == 1) print(V, a, i - 1, k, p);
		if(k >= a[i - 1]){
			bool exc3 = V[i - 1][k - a[i - 1]];
			if(exc3 == 1){
				q.push(a[i - 1]);
				print(V, a, i - 1, k - a[i - 1], q);
			}
		}
	}
}

void SubsetSumsDP(int a[], int n, int k, queue<int> p){
	bool **V = new bool*[n + 1];
	for(int i = 0; i < n + 1; i++) V[i] = new bool[k + 1];
	for(int i = 0; i <= n; i++) V[i][0] = 1;
	for(int i = 1; i <= k; i++) V[0][i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++) V[i][j] = j >= a[i - 1] ? V[i - 1][j] || V[i - 1][j - a[i - 1]] : V[i - 1][j];
	}
	print(V, a, n, k, p);
	for(int i = 0; i < n + 1; i++) delete[] V[i];
	delete[] V;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_6.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int n, k;
	fin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++) fin >> a[i];
	fin >> k;
	fin.close();
	queue<int> p;
	SubsetSumsDP(a, n, k, p);
	return 0;
}