/*
OpenCASCADE 튜토리얼 by 이창하
2022.03.22
타원형 그리기
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

	gp_Pnt centerPoint(0.0, 0.0, 0.0);	// 중심점
	gp_Dir xDirection(1.0, 0.0, 0.0);
	gp_Dir zDirection(0.0, 0.0, 1.0);
	gp_Ax2 axis(centerPoint, zDirection, xDirection); // (중심점, normal direction(평면 방향), x축)

	gp_Elips ellipse(axis, 10.0, 5.0);

	Standard_Integer numberOfSamplePoints = 20;
	double deltaU = 2 * M_PI / (numberOfSamplePoints - 1);

	for (Standard_Integer i = 0; i < numberOfSamplePoints; i++) {
		gp_Pnt pointOnEllipse;
		gp_Vec tangentVector;
		ElCLib::D1(i * deltaU, ellipse, pointOnEllipse, tangentVector);
		tangentVector.Rotate(gp_Ax1(pointOnEllipse, zDirection), -M_PI / 2);
		tangentVector.Divide(tangentVector.Magnitude()); // magnitude : 벡터의 크기 계산
		cout << pointOnEllipse.X() << ",\t" << pointOnEllipse.Y() << ",\t" << pointOnEllipse.Z() << "\t\t\t\t"
			<< tangentVector.X() << ",\t" << tangentVector.Y() << ",\t" << tangentVector.Z() << endl;
	}

	return 0;
}