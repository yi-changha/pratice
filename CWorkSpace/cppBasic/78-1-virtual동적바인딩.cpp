// 가상 함수와 동적 바인딩

#include <iostream>

using namespace std;

class Weapon {
public:
	Weapon(int power) : power(power) {
		cout << "Weapon(int)" << endl;
	}

	virtual void Use() {	// 가상 함수
		cout << "Weapon::Use()" << endl;
	}

protected:
	int power;
};

class Sword : public Weapon {
public :
	Sword(int power) : Weapon(power) {
		cout << "Sword(int)" << endl;
	}

	void Use() {
		cout << "Sword::Use()" << endl;
		Swing();
	}

private:
	void Swing() {
		cout << "Swing sword" << endl;
	}
};

class Magic : public Weapon {
public:
	Magic(int power, int manaCost) : Weapon(power), manaCost(manaCost) {
		cout << "Magic(int, int)" << endl;
	}

	void Use() {
		cout << "Magic::Use()" << endl;
		Cast();
	}

private:
	void Cast() {
		cout << "Cast magic" << endl;
	}
	int manaCost;
};

int main() {
	Sword mySword(10);
	Magic myMagic(15, 7);

	mySword.Use();
	myMagic.Use();

	Weapon *currentWeapon;
	currentWeapon = &mySword;
	currentWeapon->Use();
	currentWeapon = &myMagic;
	currentWeapon->Use();
}