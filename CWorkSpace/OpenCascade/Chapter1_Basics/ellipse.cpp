/*
OpenCASCADE Ʃ�丮�� by ��â��
2022.03.22
Ÿ���� �׸���
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

	gp_Pnt centerPoint(0.0, 0.0, 0.0);	// �߽���
	gp_Dir xDirection(1.0, 0.0, 0.0);
	gp_Dir zDirection(0.0, 0.0, 1.0);
	gp_Ax2 axis(centerPoint, zDirection, xDirection); // (�߽���, normal direction(��� ����), x��)

	gp_Elips ellipse(axis, 10.0, 5.0);

	Standard_Integer numberOfSamplePoints = 20;
	double deltaU = 2 * M_PI / (numberOfSamplePoints - 1);

	for (Standard_Integer i = 0; i < numberOfSamplePoints; i++) {
		gp_Pnt pointOnEllipse;
		gp_Vec tangentVector;
		ElCLib::D1(i * deltaU, ellipse, pointOnEllipse, tangentVector);
		tangentVector.Rotate(gp_Ax1(pointOnEllipse, zDirection), -M_PI / 2);
		tangentVector.Divide(tangentVector.Magnitude()); // magnitude : ������ ũ�� ���
		cout << pointOnEllipse.X() << ",\t" << pointOnEllipse.Y() << ",\t" << pointOnEllipse.Z() << "\t\t\t\t"
			<< tangentVector.X() << ",\t" << tangentVector.Y() << ",\t" << tangentVector.Z() << endl;
	}

	return 0;
}