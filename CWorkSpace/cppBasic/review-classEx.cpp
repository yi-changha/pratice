/*
1. �Ʒ��� GameWindow Ŭ������ �ڵ忡�� â �ʺ�� ���̸� �Ű������� �޴� ResizeWindow �Լ��� �߰��Ͽ�
���� ���ǰ� ���� width�� height�� ���� �ٲ� �� �ֵ��� �ϼ���.
	- ���� �Ű������� ���� ��ġ�ϵ��� â ũ�⸦ ������ ��.
	- �ʺ� 800���� �۰ų� ���̰� 600���� ���� ���� ���� 800, 600���� ������ ��.
	
2. GameWindow::GameWindow(int w, int h) �����ڵ� ���������� 2���� ������ �����ϵ��� �����ϼ���.

3. �ۼ��� �ڵ忡�� ���ȭ�� ������ �κ��� ��� ���ȭ�ϼ���.
*/

#include <iostream>

using namespace std;

class GameWindow {
public:
	GameWindow();
	GameWindow(const int,const int);
	
	int GetW() const;
	int GetH() const;

private:
	int width;
	int height;
};

GameWindow::GameWindow() : width(800), height(600) {}
GameWindow::GameWindow(const int w, const int h) : width(w), height(h) {
	if (w < 800) width = 800;
	else width = w;

	if (h < 600) height = 600;
	else height = h;
}

int GameWindow::GetW() const { return width; }
int GameWindow::GetH() const { return height; }


int main() {
	GameWindow mainWindow(1366, 468);
	cout << mainWindow.GetW() << "x" << mainWindow.GetH() << endl;
}
