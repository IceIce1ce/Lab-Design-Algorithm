#include<iostream>
#include<fstream>
using namespace std;

void longestSeqSum(float a[], int n){
	float max_sum = 0, cur_sum = 0;
	int start_idx = 0, end_idx = 0, continue_idx = 0; 
	for(int i = 0; i < n; i++){
		int j = i;
		cur_sum += a[i];
		if(max_sum < cur_sum){
			max_sum = cur_sum;
			start_idx = continue_idx;
			end_idx = j;
		}
		else if(cur_sum < 0){
			cur_sum = 0;
			continue_idx = j + 1;
		}
	}
	for(int i = start_idx; i <= end_idx; i++) cout << a[i] << " ";
	cout << endl << max_sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_2.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int n;
	fin >> n;
	float *arr = new float[n];
	for(int i = 0; i < n; i++) fin >> arr[i];
	fin.close();
	longestSeqSum(arr, n);
	delete[] arr;
	return 0;
}