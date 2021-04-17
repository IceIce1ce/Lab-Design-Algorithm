#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int moneyChange(int a[], int n, int money){
	for(int i = 0; i < n; i++){
		if(a[i] == money) return 1;
	}
	int minCoins = money;
	for(int i = 0; i < n; i++){
		if(money > a[i]){
			int tmpSum = 1 + moneyChange(a, n, money - a[i]);
			if(tmpSum < minCoins) minCoins = tmpSum;
		}
	}
	return minCoins;
}

int main(){
	//int a[] = {25, 10, 5, 1};
	//int n = sizeof(a) / sizeof(a[0]);
	//int money = 72;
	ios::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_5.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int n;
	fin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++) fin >> a[i];
	int money;
	fin >> money;
	fin.close();
	sort(a, a + n, greater<int>());
	int minCoinDivide = moneyChange(a, n, money);
	vector<int> tmp, vec;
	for(int i = 0; i < n; i++) tmp.push_back(a[i]);
	sort(tmp.begin(), tmp.end(), greater<int>());
	for(int i = 0; i < tmp.size(); i++){
		while(money >= tmp[i] && minCoinDivide > 0){
			money -= tmp[i];
			vec.push_back(tmp[i]);
			minCoinDivide--;
			if(minCoinDivide == 0) break;
		}
	}
	vector<int> tmpCount;
	for(int i = 0; i < n; i++) tmpCount.push_back(count(vec.begin(), vec.end(), a[i]));
	for(int i = 0; i < n; i++) cout << a[i] << ": " << tmpCount[i] << endl;
	return 0;
}