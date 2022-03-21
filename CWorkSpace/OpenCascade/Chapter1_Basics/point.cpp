/*
OpenCASCADE Ʃ�丮�� by ��â��
2022.03.21
3D ���������� �� �� pnt1, pnt2
*/

#include <iostream>
using namespace std;

// Open CASCADE
#include "gp_Pnt.hxx"
#include "gp_Ax1.hxx"
#include "gp_Trsf.hxx"

int main(int argc, char* argv[1]) {

	// �� ��ü �� �� ���� (x, y, z)
	gp_Pnt	pnt1(0.0, 0.0, 0.0), 
			pnt2(1.0, 1.0, 1.0);

	// ��ǥǥ��
	cout << "pnt1: " << pnt1.X() << ", " << pnt1.Y() << ", " << pnt1.Z() << endl;
	cout << "pnt2: " << pnt2.X() << ", " << pnt2.Y() << ", " << pnt2.Z() << endl;
	cout << "�� ���� �Ÿ� : " << pnt1.Distance(pnt2) << endl;

	// pnt1�� pnt�������� 90�� ȸ��
	gp_Trsf rotation;	// �񿵱����� ��Ī, ȸ��, ������ ���� ��ü ����
	gp_Ax1 rotationAxis(gp_Pnt(1.0, 0.0, 1.0), gp_Dir(-1.0, 0.0, -1.0));
	rotation.SetRotation(rotationAxis, 3.1415926 / 2.0); // ��ü�� ȸ�� �� ����(ȸ����ų ��, ȸ�� ����)
	pnt2.Transform(rotation); // ��ȯ ����(��� ��ü)
	cout << "90�� ȸ�� �� pnt2�� ��ǥ : " << pnt2.X() << ", " << pnt2.Y() << ", " << pnt2.Z() << endl;

	// pnt1�� ���ؼ� Y������ �̷���(��Ī) 
	gp_Ax1 axisY(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(0.0, 1.0, 0.0));
	gp_Pnt pnt3 = pnt1.Mirrored(axisY), pnt4 = pnt2.Mirrored(axisY);
	cout << "Y�� ��Ī��Ų pnt1�� ��ǥ : " << pnt3.X() << ", " << pnt3.Y() << ", " << pnt3.Z() << endl;
	cout << "Y�� ��Ī��Ų pnt2�� ��ǥ : " << pnt4.X() << ", " << pnt4.Y() << ", " << pnt4.Z() << endl;

	return 0;
}