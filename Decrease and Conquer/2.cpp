#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

void josephus(int n){
	vector<int> last_human;
	for(int i = 1; i <= n; i++) last_human.push_back(i);
	int idx = 0;
	while(last_human.size() > 1){
		idx++;
		if(idx >= last_human.size()) idx %= last_human.size();
		cout << last_human[idx] << " ";
		auto it = last_human.begin() + idx;
	    last_human.erase(it);
	}
	cout << endl << last_human[last_human.size() - 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_2.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int n;
	if(fin.is_open()) fin >> n;
	fin.close();
	josephus(n);
	return 0;
}