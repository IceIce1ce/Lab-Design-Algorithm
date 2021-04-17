#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

vector<float> readFile(){
	ifstream fin("input_5.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	int n, key;
	float freq;
	fin >> n;
	vector<float> freqArr;
	freqArr.push_back(0);
	for(int i = 0; i < n; i++) {
		fin >> key >> freq;
		freqArr.push_back(freq);
	}
	fin.close();
	return freqArr;
}

vector<float> freq = readFile();
vector<int> tmp;
int n = freq.size() - 1;
float s[100];

float P(int i, int j){ return (float)s[j] - s[i - 1]; }

float OptimalBST(int **R, int i, int j){
	if(i == j) return freq[j];
	else if(i > j) return 0;
	float val = DBL_MAX;
	for(int t = i; t <= j; t++){
		float cur = max(OptimalBST(R, i, t - 1), OptimalBST(R, t + 1, j)) + P(i, j);
		if(cur < val){
			val = cur;
			R[i][j] = t;
		}
	}
	return val;
}

void tree(int **C, int **R, int i, int j){
	int t = R[i][j];
	if(i == j) t = j;
	if(t == 0) return;
	tmp.push_back(t);
	tree(C, R, i, t - 1);
	tree(C, R, t + 1, j);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int **C = new int*[n + 2], **R = new int*[n + 2];
	for(int i = 0; i < n + 2; i++){
		C[i] = new int[n + 2]; R[i] = new int[n + 2];
	}
	for(int i = 0; i < n + 2; i++){
		for(int j = 0; j < n + 2; j++){
			C[i][j] = 0; R[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + freq[i];
    OptimalBST(R, 1, n);
    tree(C, R, 1, n);
	cout << tmp[0] << endl;
	for(int i = 0; i < tmp.size(); i++) cout << tmp[i] << " ";
	delete[] C;
	delete[] R;
    return 0;
}