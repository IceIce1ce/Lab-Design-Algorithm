#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Point
{
	public: int x, y;
};

int direction(Point p1, Point p2, Point p3)
{
	int dir = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
	if(dir == 0) return 0; //colinear
	return (dir > 0)? 1: 2; //1: clockwise, 2: counter clockwise
}

void convex_hull(Point points[], int n)
{
	if(n < 3) return; //return if point array just has 3 points
	stack<Point> s;
	int leftmost = 0, ymin = points[0].y;
	for(int i = 1; i < n; i++){
		int y_coord = points[i].y;
		//p0 be the point in Q with the minimum y-coordinate or the leftmost such point in case of a tie
		if(y_coord < ymin || (y_coord == ymin && points[i].x < points[leftmost].x)){
			ymin = points[i].y;
			leftmost = i;
		}
	}
	int p0 = leftmost, q; //init p = left most with min x_coordinate, q is point triplet point is counter clockwise order around p0
	//brute-force until we reach to the first point
	do {
		s.push(points[p0]); //add each cur point to an empty stack
		q = (p0 + 1) % n;
		for(int i = 0; i < n; i++){
			if(direction(points[p0], points[i], points[q]) == 2) q = i;
		}
		p0 = q;
	} while(p0 != leftmost);
	vector<int> result;
	if(s.empty()) return;
	while(!s.empty()){
		Point ans = s.top();
		cout << "(" << ans.x << ", " << ans.y << ")" << " ";
		s.pop();
	}
}

int main() 
{ 
	ios::sync_with_stdio(false);
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
	convex_hull(p, n);
    return 0; 
} 