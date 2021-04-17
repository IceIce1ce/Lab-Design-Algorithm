#include<iostream>
#include<fstream>
using namespace std;
#define MAX 100

string LCS(int dp[][MAX], string S, string T, int m, int n){
    if(m == 0 || n == 0) return "";
    else if(S[m - 1] == T[n - 1]) return LCS(dp, S, T, m - 1, n - 1) + S[m - 1];
    else return dp[m - 1][n] > dp[m][n - 1] ? LCS(dp, S, T, m - 1, n):LCS(dp, S, T, m, n - 1);
}

void LCS_Dyn(int dp[][MAX], string S, string T, int m, int n){
    if(m <= 0 || n <= 0) return;
    else{
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(S[i - 1] == T[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    int dp[MAX][MAX];
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++) dp[i][j] = 0;
    }
	ifstream fin("input_3.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
    string S, T;
    fin >> S;
    fin >> T;
    int m = S.length(), n = T.length();
    LCS_Dyn(dp, S, T, m, n);
    cout << LCS(dp, S, T, m, n);
    return 0;
}