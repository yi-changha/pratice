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
	int x, y, w, h;
	int dis[4];
	int min = 1000;
	cin >> x >> y >> w >> h;

	dis[0] = x;
	dis[1] = y;
	dis[2] = w - x;
	dis[3] = h - y;

	for (int i = 0; i < 4; i++)
	{
		if (dis[i] < min)
			min = dis[i];
	}
	cout << min << endl;
}