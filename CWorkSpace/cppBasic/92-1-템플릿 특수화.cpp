#include <iostream>
#include <string>

using namespace std;

template<typename T>
T getArraySum(const T arr[], int n) {
	cout << "���ø�" << endl;
	T sum = arr[0];
	for (int i = 1; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

// ���ø� Ư��ȭ
template<>
string getArraySum<string>(const string arr[], int n) {
	cout << "Ư��ȭ" << endl;
	string sum = arr[0];
	for (int i = 1; i < n; i++) {
		sum += ' ' + arr[i];
	}
	return sum;
}

int main() {
	string sarr[3] = { "hello", "world", "lee" };
	string ssum = getArraySum(sarr, 3);
	cout << ssum << endl;
	
	int iarr[5] = { 3, 1, 4, 1, 5 };
	int isum = getArraySum(iarr, 5);
	cout << isum << endl;
}