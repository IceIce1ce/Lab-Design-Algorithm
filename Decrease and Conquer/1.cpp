#include<iostream>
#include<vector>
using namespace std;
#define num_courses 5

void topoSort(int a[num_courses][num_courses]){
	vector<int> tmp(num_courses, 0), visit(num_courses, 0), topo;
	int cnt = 0;
	for(int i = 0; i < tmp.size(); i++){
		for(int j = 0; j < tmp.size(); j++) tmp[i] += a[j][i];
	}
	while(cnt >= 0){
		for(int i = 0; i < tmp.size(); i++){
			if(tmp[i] == 0 && visit[i] == 0){
				topo.push_back(i);
				visit[i] = 1;
			}
			else{
				for(int j = 0; j < tmp.size(); j++){
					if(a[j][i] == 1) tmp[i]--;
				}
			}
		}
		cnt++;
		if(cnt == tmp.size()) break;
	}
	for(int i = 0; i < topo.size(); i++){
		topo[i]++;
		cout << topo[i] << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//3 1 2 -> a[1][3] = a[2][3] = 1
	//4 3 -> a[3][4] = 1
	//5 3 4 -> a[3][5] = a[4][5] = 1
	int a[5][5] = {{0, 0, 1, 0, 0},
				   {0, 0, 1, 0, 0},
				   {0, 0, 0, 1, 1},
				   {0, 0, 0, 0, 1},
		           {0, 0, 0, 0, 0}};
	topoSort(a);
	return 0;
}