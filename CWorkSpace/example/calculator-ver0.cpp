//����
#include <iostream>
using namespace std;

class Calculator  {
public:
	Calculator(double Num1, double Num2) : Num1(Num1), Num2(Num2) {}
	double add() {
		return res = Num1 + Num2;
	}
	double sub() {
		return res = Num1 - Num2;
	}
	double mul() {
		return res = Num1 * Num2;
	}
	double div() {
		return res = Num1 / Num2;
	}

	void Print() {
		cout << res << endl;
	}

private:
	double Num1, Num2, res;
};


int main(){
	double n1, n2;
	cout << "���� �� ���� �Է����ּ���" << endl;
	cin >> n1 >> n2;

	Calculator cal(n1, n2);

	int ope;
	makeOpe:
		cout << "���� ���� ����" << endl << "����(1)" << endl << "����(2)" << endl
			<< "����(3)" << endl << "������(4)" << endl;
		cin >> ope;
		switch (ope) {
		case 1:
			cal.add();
			cal.Print();
			break;
		case 2:
			cal.sub();
			cal.Print();
			break;
		case 3:
			cal.mul();
			cal.Print();
			break;
		case 4:
			cal.div();
			cal.Print();	
			break;
		default:
			cin.clear();
			cout << "����. 1~4�� ������ �Է����ּ���." << endl;
			goto makeOpe;
			break;
		}
}