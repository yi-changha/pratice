/*
문제
"OOXXOXXOOO"와 같은 OX퀴즈의 결과가 있다. O는 문제를 맞은 것이고, X는 문제를 틀린 것이다.
문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다.
예를 들어, 10번 문제의 점수는 3이 된다.
"OOXXOXXOOO"의 점수는 1+2+0+0+1+0+0+1+2+3 = 10점이다.
OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있고, 길이가 0보다 크고 80보다 작은 문자열이 주어진다.
문자열은 O와 X만으로 이루어져 있다.

출력
각 테스트 케이스마다 점수를 출력한다.
*/

#include <iostream>
using namespace std;

int main() {
	char strArr[90] = {};
	int t;
	cout << "테스트할 문자열의 개수를 입력하세요." << endl;
	cin >> t;

	for (int i = 0, score, alpha, len; i < t; i++) {
		score = 0, alpha = 0, len = 0;
		cout << "Test " << i+1 << ": O와 X로 이루어진 문자열을 입력하세요" << endl;
		cin >> strArr;
		while (strArr[len] != '\0')
			len++;

		for (int j = 0; j < len; j++) {
			if (strArr[j] == 'O')
			{
				alpha++;
				score += alpha;
			}
			else
				alpha = 0;
		}
		cout << "Test "<< i+1 <<"의 점수는 " << score << "점 입니다." << endl << endl;
	}
}