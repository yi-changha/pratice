/*
����
�� ���� �־����� ��, �࿡ ������ ���簢���� ����� ���ؼ� �ʿ��� �� ��° ���� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�� ���� ��ǥ�� �� �ٿ� �ϳ��� �־�����. ��ǥ�� 1���� ũ�ų� ����, 1000���� �۰ų� ���� �����̴�.

���
���簢���� �� ��° ���� ��ǥ�� ����Ѵ�.
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