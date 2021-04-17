#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

void changeMaking(int a[], int n, int total_coin){
	vector<int> tmp;
	for(int i = 0; i < n; i++) tmp.push_back(a[i]);
	sort(tmp.begin(), tmp.end(), greater<int>());
	vector<int> vec;
	for(int i = 0; i < tmp.size(); i++){
		while(total_coin >= tmp[i]){
			total_coin -= tmp[i];
			vec.push_back(tmp[i]);
		}
	}
	vector<int> tmpCount;
	for(int i = 0; i < n; i++) tmpCount.push_back(count(vec.begin(), vec.end(), a[i]));
	for(int i = 0; i < n; i++) cout << a[i] << ": " << tmpCount[i] << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_3.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int n;
	fin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++) fin >> arr[i];
	int total_coin;
	fin >> total_coin;
	fin.close();
	changeMaking(arr, n, total_coin);
	return 0;
}