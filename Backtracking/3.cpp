#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

//solution 1
void subsetSum(int a[], int n, vector<int> res, int sum){
	if(sum == 0){ //if sum = 0, subset found
		for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
		return;
	}
	if(n < 0 || sum < 0) return; //empty array or negative sum
	subsetSum(a, n - 1, res, sum); //include last element
	res.push_back(a[n - 1]);
	sort(res.begin(), res.end());
	subsetSum(a, n - 1, res, sum - a[n - 1]); //exclude last element
}

//solution 2
vector<int> vec;
void subsetSum2(int a[], int n, int sum){
	for(int i = 0; i < n; i++){
		int cur_sum = a[i];
		for(int j = i + 1; j < n; j++){
			if(cur_sum == sum) {
				vec.push_back(i);
				vec.push_back(j);
			}
			if(j == n){
				cout << "No solution";
				break;
			}
			cur_sum += a[j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_3.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int k, t;
	fin >> k;
	int *a = new int[k];
	for(int i = 0; i < k; i++) fin >> a[i];
	fin >> t;
	fin.close();
	vector<int> res;
	cout << "Solution 1: ";
	subsetSum(a, k, res, t);
	cout << endl << "Solution 2: ";
	subsetSum2(a, k, t); 
    for(int i = vec[0]; i <= vec[1] - 1; i++) cout << a[i] << " ";
	delete[] a;
	return 0;
}