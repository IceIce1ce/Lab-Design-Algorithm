#include<iostream>
#include<fstream>
using namespace std;

void maxSequenceSum(int a[], int n){
	int max_sum = 0, cur_sum = 0, start_idx = 0, end_idx = 0, continue_idx = 0;
	for(int i = 0; i < n; i++){
		int j = i;
		cur_sum += a[i];
		if(max_sum < cur_sum){
			max_sum = cur_sum;
			start_idx = continue_idx;
			end_idx = i;
		}
		else if(cur_sum < 0){
			cur_sum = 0;
			continue_idx = j + 1;
		}
	}
	for(int i = start_idx; i <= end_idx; i++) cout << a[i] << " ";
	cout << endl << start_idx << " " << end_idx << endl;
	cout << max_sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_3.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int n;
	fin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++) fin >> a[i];
	fin.close();
	maxSequenceSum(a, n);
	delete[] a;
	return 0;
}