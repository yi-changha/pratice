/*
문제
정수 n개가 주어졌을 때, n개의 합을 구하는 함수를 작성하시오.
작성해야 하는 함수는 다음과 같다.

long long sum(std::vector<int> &a);
a: 합을 구해야 하는 정수 n개가 저장되어 있는 배열 (0 ≤ a[i] ≤ 1,000,000, 1 ≤ n ≤ 3,000,000)
리턴값: a에 포함되어 있는 정수 n개의 합
*/

#include <iostream>
using namespace std;

int inspect(const int n, const int min, const int max) {
	if (n < min || n > max) {
		cout << "ERROR, " << min << "보다 크고 " << max << "보다 작은 정수로 입력해야합니다." << endl;
		exit(-1);
	}
}

int longSum(const int n) {
	int sum = 0;
	int *a;
	a = (int *)malloc(sizeof(int)*n);

	cout << n << "개의 정수를 입력해주세요. (단, 1,000,000이하의 음이 아닌 정수)" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		inspect(a[i], 0, 1000000);
		sum += a[i];
	}
	return sum;
}

int main() {
	int n;
	cout << "입력할 정수의 개수를 입력해주세요." << endl;
	cin >> n;
	inspect(n, 1, 3000000);

	cout << longSum(n) << endl;
}