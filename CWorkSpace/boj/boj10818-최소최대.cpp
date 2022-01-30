/*
����
N���� ������ �־�����. 
�̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 1,000,000)�� �־�����. 
��° �ٿ��� N���� ������ �������� �����ؼ� �־�����. 
��� ������ -1,000,000���� ũ�ų� ����, 1,000,000���� �۰ų� ���� �����̴�.

���
ù° �ٿ� �־��� ���� N���� �ּڰ��� �ִ��� �������� ������ ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main() {
	int n, max, min;
	int *arr;
	cout << "�Է��� ������ ������ �Է��ϼ���.  (1 �� N �� 1,000,000)" << endl;
	cin >> n;
	if (n < 1 || n > 1000000) exit(-1);

	arr = (int *)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > 1000000) exit(-1);
		else if (i == 0){
			min = arr[i];
			max = arr[i];
		}
		else if (arr[i] > max) max = arr[i];
		else if (arr[i] < min) min = arr[i];
	}
	cout << "max : " << max << endl << "min : " << min;
	free(arr);
}