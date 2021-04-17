#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
#define ll long long

int getNumDigit(ll val){
	int cnt = 0;
	while(val != 0){
		cnt++;
		val /= 10;
	}
	return cnt;
}

ll karatsuba(ll x, ll y){
	//compute size of the numbers
	int m = max(getNumDigit(x), getNumDigit(y));
	if(m < 10) return x * y;
	int m2 = floor(m / 2);
	//split the digit sequences in the middle
	ll high1 = x / pow(10, m2);
	ll low1 = x - (high1 * pow(10, m2));
	ll high2 = y / pow(10, m2);
	ll low2 = y - (high2 * m2);
	//3 calls made to numbers approximately half the size
	ll z0 = karatsuba(low1, low2);
	ll z1 = karatsuba(low1 + high1, low2 + high2);
	ll z2 = karatsuba(high1, high2);
	return (z0 + ((z1 - z0 - z2) * m2) + (z2 * pow(10, 2 * m2)));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("input_1.txt");
	if(!fin.is_open()){
		cout << "File not found";
		exit(0);
	}
	ll x, y;
	fin >> x;
	fin >> y;
	fin.close();
	cout << karatsuba(x, y);
	return 0;
}