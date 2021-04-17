#include<iostream>
#include<algorithm>
#include<fstream>
#include<float.h>
#include<math.h>
#include<vector>
using namespace std;

class Point{
	public: float x, y;
};

Point pair1, pair2;
float minDist = DBL_MAX;

bool compare_x(Point p1, Point p2){
    return p1.x < p2.x;
}

float calculate_distance(Point p1, Point p2){
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void mergeSort(Point *a, Point *buf, int low, int mid, int high){
	int k = 0, i = low, j = mid + 1;
	a = new Point[high - low + 1];
	while(i <= mid && j <= high){
		if(a[i].y < a[j].y) a[k++] = buf[i++];
		else a[k++] = buf[j++];
	}
	while(i <= mid) a[k++] = buf[i++];
	while(j <= high) a[k++] = buf[j++];
	for(int i = 0; i < k; i++) buf[low++] = a[i];
	delete[] a;
}

float closest_pair(Point *p1, Point *p2, Point *a, int low, int high){
    if(high <= low) return DBL_MAX;
	int mid = (low + high) / 2;
    float dl = closest_pair(p1, p2, a, low, mid);
    float dr = closest_pair(p1, p2, a, mid + 1, high);
	float d = min(dl, dr);
    mergeSort(p2, a, low, mid, high);
    int k = 0;
    for(int i = low; i <= high; i++){
		if(abs(p2[i].x - p1[mid].x) < d) a[k++] = p2[i];
	}
    for(int i = 0; i < k; i++){
        for(int j = i + 1; j < k && (a[j].y - a[i].y < d); j++){
            if(calculate_distance(a[i], a[j]) < d){
                d = calculate_distance(a[i], a[j]);
                if(d < minDist){
                    minDist = d;
					pair1.x = a[i].x, pair1.y = a[i].y;
					pair2.x = a[j].x, pair2.y = a[j].y;
                }
            }
        }
    }
    return d;
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
	Point *p = NULL;
	if(fin.is_open()){
		fin >> n;
		p = new Point[n];
		for(int i = 0; i < n; i++) fin >> p[i].x >> p[i].y;
	}
	fin.close();
	sort(p, p + n, compare_x);
	Point *p2 = new Point[n], *a = new Point[n];
	for(int i = 0; i < n; i++) p2[i] = p[i];
	closest_pair(p, p2, a, 0, n - 1);
	cout << "(" << pair1.x << "," << pair1.y << ")" << " " << "(" << pair2.x << "," << pair2.y << ")" << endl;
	//print all pair point same minDist
	vector<float> tmp_idx;
	for(int cnt = 1; cnt <= ceil(float(n)/2); cnt++){
		Point *new_p = new Point[n - cnt];
		for(int i = 0; i < n - cnt; i++) new_p[i] = p[i + cnt];
		Point *new_p2 = new Point[n - cnt], *new_a = new Point[n - cnt];
		for(int i = 0; i < n - cnt; i++) new_p2[i] = new_p[i];
		tmp_idx.push_back(closest_pair(new_p, new_p2, new_a, 0, n - (cnt + 1)));
		delete[] new_p;
		delete[] new_p2;
		delete[] new_a;
	}
	for(int i = 0; i < tmp_idx.size(); i++){
		if(tmp_idx[i] == minDist) cout << "(" << p[i + 1].x << "," << p[1].y << ")" << " " << "(" << p[i + 2].x << "," << p[i + 2].y << ")" << endl; 		
	}
	delete[] p;
	delete[] p2;
	delete[] a;
	return 0;
}