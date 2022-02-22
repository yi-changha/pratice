/*
문제
한수는 지금 (x, y)에 있다. 
직사각형은 각 변이 좌표축에 평행하고, 왼쪽 아래 꼭짓점은 (0, 0), 오른쪽 위 꼭짓점은 (w, h)에 있다. 
직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 x, y, w, h가 주어진다.

출력
첫째 줄에 문제의 정답을 출력한다.

제한
1 ≤ w, h ≤ 1,000
1 ≤ x ≤ w-1
1 ≤ y ≤ h-1
x, y, w, h는 정수
*/

#include <iostream>
using namespace std;

int main() {
	int x, y, w, h, min, tempW, tempH;
	cin >> x >> y >> w >> h;

	if (1 > w | 1 > h | 1 > x | 1 > y | 1000 < w | 1000 < h | ((w - 1) < x) | ((h - 1) < y)) exit(-1);

	if ((x*x) > ((x-w)*(x-w))) tempW = x-w;
	else tempW = x;
	if ((y*y) > ((y - h)*(y - h))) tempH = y - h;
	else tempH = y;

	if ((tempW*tempW) > (tempH*tempH)) min = tempH;
	else min = tempW;

	if (min < 0) cout << -min << endl;
	else cout << min << endl;
}