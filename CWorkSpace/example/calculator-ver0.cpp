//°è»ê±â
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
	cout << "¼ýÀÚ µÎ °³¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä" << endl;
	cin >> n1 >> n2;

	Calculator cal(n1, n2);

	int ope;
	makeOpe:
		cout << "¿¬»ê Á¾·ù ¼±ÅÃ" << endl << "µ¡¼À(1)" << endl << "»¬¼À(2)" << endl
			<< "°ö¼À(3)" << endl << "³ª´°¼À(4)" << endl;
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
			cout << "¿À·ù. 1~4ÀÇ Á¤¼ö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä." << endl;
			goto makeOpe;
			break;
		}
}