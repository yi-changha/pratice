// const�� ���ӻ�
// 1. �Ű������� ���ȭ (��� �Լ�)
// 2. �޼����� ���ȭ (��� �޼���)

// �޼����� ���ȭ
// : �� �޼��� �ȿ��� �ڱⰡ ���� �ٸ� Ŭ������ ��� ������ �ǵ帱 �� ���� ����.


#include <iostream>

using namespace std;

class Account {
public:
	Account() : money(0) {}
	Account(int money) : money(money) {}

	void Deposit(const int d) {	// �Էµ� d�� �����Ҽ� ���� ��.
		//d = money;			//����, d���� �����ؼ� �� ������ ����.
		money += d;
		cout << d << "���� �����߽��ϴ�." << endl;
	}
	void Draw(int d) {
		if (money >= d) {
			money -= d;
			cout << d << "���� �����߽��ϴ�." << endl;
		}
	}

	int ViewMoney() const {
		//money++;				// ����, �ܰ� Ȯ�� �ø��� 1���� �����ϰ� ��.
		return money;
	}

	//const int ViewMoney() {} 
	// �Լ��� �տ� const�� ���� �� ������, ����� �޼���� �ƴ�.
	// ��κ��� ��� �ǹ̰� ������, ��Ȥ ����.

private:
	int money;
};

int main() {
	Account lee(200);
	
	lee.Deposit(100);
	lee.Draw(20);

	cout << "���� �ܰ� : " <<lee.ViewMoney() << "��" << endl;
}