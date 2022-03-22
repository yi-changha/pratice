/*
OpenCASCADE Ʃ�丮�� by ��â��
2022.03.22
�� �׸���
*/
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

// Open CASCADE
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Ax2.hxx>
#include <gp_Circ.hxx>
#include <ElCLib.hxx>

int main(int argc, char* argv[1]) {

	gp_Pnt centerPoint(5.0, 5.0, 0.0);	// �߽���, xy ���
	gp_Dir zDirection(0.0, 0.0, 1.0);	// normal direction (���� ����)
	gp_Dir xDirection(1.0, 0.0, 0.0);	
	gp_Ax2 axis(centerPoint, zDirection, xDirection);	// z���� �߽����� ��ǥ��

	// �� ����
	gp_Circ circle(axis, 5);

	// ���� �������� Ư��
	cout << "��1�� ���� : " << circle.Area() << endl;
	cout << "��1�� �ѷ� : " << circle.Length() << endl;

	// ������ ���� 2���� �� ����.
	gp_Circ circle2 = circle.Scaled(gp_Pnt(5.0, 5.0, 0.0), 2.0);	// Ȯ�����(�߽���, ����)
	cout << "��2�� ���� : " << circle2.Area() << endl;
	cout << "��2�� �ѷ� : " << circle2.Length() << endl;
	cout << endl;

	// ELClib packge = Elementary Curve opretations
	
	// ���ָ� 20������� ������ ���� ����.
	Standard_Integer numberOfSamplePoints = 20;
	double deltaU = 2 * M_PI / (numberOfSamplePoints - 1);

	for (Standard_Integer i = 0; i < numberOfSamplePoints; i++) {
		gp_Pnt pointOnCircle = ElCLib::Value(i * deltaU, circle);
		cout << pointOnCircle.X() << ", " << pointOnCircle.Y() << ", " << pointOnCircle.Z() << endl;
	}
	cout << endl << "" << endl;
	
	// D1�� �̿��� tangent vector(���� ����) ���ϱ�
	for (Standard_Integer i = 0; i < numberOfSamplePoints; i++) {
		gp_Pnt pointOnCircle;
		gp_Vec tangentVector;
		ElCLib::D1(i * deltaU, circle2, pointOnCircle, tangentVector);
		cout << pointOnCircle.X() << ", " << pointOnCircle.Y() << ", " << pointOnCircle.Z() << "\t\t"
			<< tangentVector.X() << ", " << tangentVector.Y() << ", " << tangentVector.Z() << endl;
	}

	return 0;
}