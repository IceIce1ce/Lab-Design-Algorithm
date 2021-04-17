#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void shakerSort(float a[], int n){
	int left = 0, right = n - 1, k = 0, i;
	while(left < right){
		for(i = left; i < right; i++){
			if(a[i] > a[i+1]) {
				swap(a[i], a[i+1]);
				k = i;
			}
		}
		right = k;
		for(i = right; i > left; i--){
			if(a[i] < a[i - 1]){
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		left = k;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_1.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int n;
	fin >> n;
	float *arr = new float[n];
	for(int i = 0; i < n; i++) fin >> arr[i];
	fin.close();
	shakerSort(arr, n);
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	delete[] arr;
	return 0;
}