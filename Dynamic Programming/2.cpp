#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int changeCoinsDP(int d[], int k, int money, int tmp[]){
	int *C = new int[money];
	C[0] = 0;
	for(int cents = 1; cents <= money; cents++){
		C[cents] = INT_MAX;
		for(int i = 0; i < k; i++){
			if(d[i] > cents) continue;
			if(C[cents - d[i]] + 1 < C[cents]){
				C[cents] = C[cents - d[i]] + 1;
				tmp[cents] = i;
			}
		}
	}
	return C[money];
	delete[] C;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_2.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	vector<int> tmpArr;
	int deno;
	while(fin >> deno) tmpArr.push_back(deno);
	fin.close();
	int n = tmpArr.size() - 1, *d = new int[n], money = tmpArr[n], *tmp = new int[money + 1];
	for(int i = 0; i < tmpArr.size() - 1; i++) d[i] = tmpArr[i];
	changeCoinsDP(d, n, money, tmp);
	int k = money;
	vector<int> list_coins;
    while(k){
		list_coins.push_back(d[tmp[k]]);
		k -= d[tmp[k]];
    }
	vector<int> tmpCount;
	for(int i = 0; i < n; i++) tmpCount.push_back(count(list_coins.begin(), list_coins.end(), d[i]));
	for(int i = 0; i < n; i++) cout << d[i] << ": " << tmpCount[i] << endl;
	delete[] d;
	delete[] tmp;
    return 0;
}