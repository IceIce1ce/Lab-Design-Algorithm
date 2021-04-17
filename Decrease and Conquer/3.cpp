#include<iostream>
#include<set>
#include<vector>
#include<fstream>
using namespace std;

//method 1: decrease and conquer using quicksort
void swapFloat(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

int partition(float a[], int low, int high, int pos){
	int pivot = a[high];
	for(int j = low; j <= high - 1; j++){
		if(a[j] < pivot){
			pos++;
			swapFloat(&a[pos], &a[j]);
		}	
	}
	swapFloat(&a[pos + 1], &a[high]);
	return pos + 1;
}

float selection(float a[], int low, int high, int k){
	int h = low - 1;
	int pos = partition(a, low, high, h);
	if(pos == k - 1) return a[pos];
	if(pos > k - 1) return selection(a, low, pos - 1, k);
	if(pos < k - 1) return selection(a, pos + 1, high, k);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_3.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int n, k;
	fin >> n;
	float *a = new float[n];
	for(int i = 0; i < n; i++) fin >> a[i];
	fin >> k;
	fin.close();
	cout << selection(a, 0, n - 1, k);
	delete[] a;
	return 0;
}

/* method 2: using set
void removeDuplicate(float a[], int n, int k)
{
	vector<float> v;
	set<float> s;
	for(int i = 0; i < n; i++) s.insert(a[i]);
	for(float i: s) v.push_back(i);
	cout << v[k - 1];
}

int main()
{
	float a[] = {1.1, 1.1, 1.1, 2.5, 7.3, 2.5, 4.6, 3.3};
	int n = sizeof(a) / sizeof(a[0]);
	int k = 3;
	removeDuplicate(a, n, k);
	return 0;
}
*/