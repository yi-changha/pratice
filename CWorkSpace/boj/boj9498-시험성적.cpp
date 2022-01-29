/*
문제
시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 시험 점수가 주어진다. 시험 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
시험 성적을 출력한다
*/

#include <iostream>
using namespace std;

int main() {
	int score;
	cout << "시험 점수를 입력하세요" << endl;
	cin >> score;

	if (score > 100)	cout << "ERROR, 시험은 100점 만점입니다!" << endl;
	else if (score >= 90) cout << score << "점, A" << endl;
	else if (score >= 80) cout << score << "점, B" << endl;
	else if (score >= 70) cout << score << "점, C" << endl;
	else if (score >= 60) cout << score << "점, D" << endl;
	else if (score >= 0) cout << score << "점, F" << endl;
	else cout << "ERROR, 점수가 음수(-)일 수는 없어요!" << endl;
}