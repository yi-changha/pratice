# include <iostream>

using namespace std;

int inventory[64] = { 0 };
int score = 0;

void getItem(int itemID, int cnt = 1, int sc = 0) {
	inventory[itemID] += cnt;
	score += sc;
}

int main() {
	getItem(6, 5);
	getItem(6, 15);
	getItem(3);
	getItem(11, 34, 7000);

	cout << score << endl;
	for (int i = 0; i < 16; i++) {
		cout << inventory[i] << ' ';
	}
	cout << endl;
}