/*
문제
세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.

입력
세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

출력
직사각형의 네 번째 점의 좌표를 출력한다.
*/

#include <iostream>
using namespace std;

struct Point {int x, y;};

int comp(int n1, int n2, int n3) {
	if (n1 == n2) return n3;
	else if (n2 == n3) return n1;
	else return n2;
}

int main() {
	Point p1, p2, p3, p4;

	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;

	p4.x = comp(p1.x, p2.x, p3.x);
	p4.y = comp(p1.y, p2.y, p3.y);

	cout << p4.x << " " << p4.y << endl;
}