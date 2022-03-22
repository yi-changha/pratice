/*
OpenCASCADE 튜토리얼 by 이창하
2022.03.22
원 그리기
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

	gp_Pnt centerPoint(5.0, 5.0, 0.0);	// 중심점, xy 평면
	gp_Dir zDirection(0.0, 0.0, 1.0);	// normal direction (면의 반향)
	gp_Dir xDirection(1.0, 0.0, 0.0);	
	gp_Ax2 axis(centerPoint, zDirection, xDirection);	// z축이 중심축인 좌표계

	// 원 생성
	gp_Circ circle(axis, 5);

	// 원의 기하학적 특성
	cout << "원1의 면적 : " << circle.Area() << endl;
	cout << "원1의 둘레 : " << circle.Length() << endl;

	// 원래의 원에 2배인 원 생성.
	gp_Circ circle2 = circle.Scaled(gp_Pnt(5.0, 5.0, 0.0), 2.0);	// 확대축소(중심점, 배율)
	cout << "원2의 면적 : " << circle2.Area() << endl;
	cout << "원2의 둘레 : " << circle2.Length() << endl;
	cout << endl;

	// ELClib packge = Elementary Curve opretations
	
	// 원주를 20등분으로 나누고 점을 찍음.
	Standard_Integer numberOfSamplePoints = 20;
	double deltaU = 2 * M_PI / (numberOfSamplePoints - 1);

	for (Standard_Integer i = 0; i < numberOfSamplePoints; i++) {
		gp_Pnt pointOnCircle = ElCLib::Value(i * deltaU, circle);
		cout << pointOnCircle.X() << ", " << pointOnCircle.Y() << ", " << pointOnCircle.Z() << endl;
	}
	cout << endl << "" << endl;
	
	// D1을 이용해 tangent vector(접선 벡터) 구하기
	for (Standard_Integer i = 0; i < numberOfSamplePoints; i++) {
		gp_Pnt pointOnCircle;
		gp_Vec tangentVector;
		ElCLib::D1(i * deltaU, circle2, pointOnCircle, tangentVector);
		cout << pointOnCircle.X() << ", " << pointOnCircle.Y() << ", " << pointOnCircle.Z() << "\t\t"
			<< tangentVector.X() << ", " << tangentVector.Y() << ", " << tangentVector.Z() << endl;
	}

	return 0;
}