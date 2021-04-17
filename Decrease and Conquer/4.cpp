#include<iostream>
#include<fstream>
using namespace std;

float interpolationSearch(float a[], int n, float x){
	int left = 0, right = n - 1;
	while(left <= right){
		if(n == 1){
			if(a[0] == x) return left;
			return -1;
		}
		else{
			int pos = left + (((double)(x - a[left]) / (a[right] - a[left])) * (right - left));
			if(a[pos] == x) return pos;
			if(a[pos] > x) right = pos - 1;
			if(a[pos] < x) left = pos + 1;
		}
	}
	return -1; 
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
	float *a = new float[n];
	for(int i = 0; i < n; i++) fin >> a[i];
	float x;
	fin >> x;
	fin.close();
	cout << interpolationSearch(a, n, x);
	delete[] a;
	return 0;
}