/*
문제
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 
당신은 그들에게 슬픈 진실을 알려줘야 한다.

입력
첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 
점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.
*/

#include <iostream>
using namespace std;

int main() {
	int t;
	double *scoArr;

	cout << "시험의 개수를 입력하세요." << endl;
	cin >> t;

	for (int j = 1, n, cnt; j < t+1; j++) {
		double avg = 0, ptg = 0, sum = 0;
		cnt = 0;
		cout << j << "번 과목 학생의 수를 입력해주세요." << endl;
		cin >> n;
		scoArr = (double *)malloc(sizeof(double)*n);
		if (n > 1000 || n < 1) {
			cout << "ERROR, 학생의 수는 1~1000입니다." << endl;
			exit(-1);
		}
		cout << j << "번 과목에 대해 학생 " << n << "명의 점수를 입력하세요." << endl;
		for (int i = 0; i < n; i++) {
			cin >> scoArr[i];
			sum += scoArr[i];
			if (scoArr[i] > 100 || scoArr[i] < 0) {
				cout << "ERROR, 점수는 0~100점 입니다." << endl;
				exit(-2);
			}
		}
		avg = sum / n;

		for (int i = 0; i < n; i++) {
			if (scoArr[i] > avg) cnt++;
		}
		ptg = (double)cnt * 100 / (double)n;

		cout << fixed;
		cout.precision(3);
		cout << j << "번 과목 평균을 넘는 학생 비율 : "<< ptg << "%"<< endl << endl;
	}
}