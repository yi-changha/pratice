/*
����
�Ѽ��� ���� (x, y)�� �ִ�. 
���簢���� �� ���� ��ǥ�࿡ �����ϰ�, ���� �Ʒ� �������� (0, 0), ������ �� �������� (w, h)�� �ִ�. 
���簢���� ��輱���� ���� �Ÿ��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� x, y, w, h�� �־�����.

���
ù° �ٿ� ������ ������ ����Ѵ�.

����
1 �� w, h �� 1,000
1 �� x �� w-1
1 �� y �� h-1
x, y, w, h�� ����
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