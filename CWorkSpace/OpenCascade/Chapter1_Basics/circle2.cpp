// OpenCASCADE by ��â��
// 2022.03.22
// ��

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

// Open CASCADE
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Circ.hxx>
#include <ElCLib.hxx>
#include <gce_MakeCirc.hxx>

int main(int argc, char* argv[1]) {
	gp_Pnt centerPoint1(0.0, 0.0, 0.0);		
	gp_Dir zDirection(0.0, 0.0, 1.0);	
	gp_Dir xDirection(1.0, 0.0, 0.0);
	gp_Dir yDirection(0.0, 1.0, 0.0);
	gp_Ax2 axis(centerPoint1, zDirection, xDirection);	// z���� �߽����� ��ǥ��

	/*
	gce_MakeCirc MC(axis, 5);
	const gp_Circ& C = MC.Value();
	*/

	// �Ÿ� ����
	gp_Circ circle(axis, 5);
	cout << circle.Distance(centerPoint1) << endl;
	cout << circle.SquareDistance(centerPoint1) << endl;

	// ��ġ ����
	gp_Pnt centerPoint2(5.0, 0.0, 0.0);
	circle.SetLocation(centerPoint2);

	// ��ġ ���� �� ����
	cout << circle.Distance(centerPoint1) << endl;
	cout << circle.SquareDistance(centerPoint1) << endl;

	// ���ָ� 20������� ������ ���� ����.
	Standard_Integer numberOfSamplePoints = 20;
	double deltaU = 2 * M_PI / (numberOfSamplePoints - 1);

	for (Standard_Integer i = 0; i < numberOfSamplePoints; i++) {
		gp_Pnt pointOnCircle = ElCLib::Value(i * deltaU, circle);
		cout << pointOnCircle.X() << ", " << pointOnCircle.Y() << ", " << pointOnCircle.Z() << endl;
	}
	cout << endl << "" << endl;

	// Y�� ��Ī
	gp_Ax1 axis2(centerPoint1, yDirection);
	gp_Circ circle2 = circle.Mirrored(axis2);
	for (Standard_Integer i = 0; i < numberOfSamplePoints; i++) {
		gp_Pnt pointOnCircle = ElCLib::Value(i * deltaU, circle2);
		cout << pointOnCircle.X() << ", " << pointOnCircle.Y() << ", " << pointOnCircle.Z() << endl;
	}
	cout << endl << "" << endl;

}