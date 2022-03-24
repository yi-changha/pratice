/*
OpenCASCADE 튜토리얼 by 이창하
2022.03.22
삼각형 그리기
*/

#define _USE_MATH_DEFINES_
#include <iostream>
#include <cmath>
using namespace std;

// Open CASCADE를 활용해서 만든 헤더파일
#include "PointOnCurveDistributor.hpp"
#include "WriteCoordinatesToFile.hpp"
#include "AreaCalculations.hpp"


int main(int argc, char* argv[1]) {

	// 원 생성
	gp_Pnt centerPoint(5.0, 5.0, 0.0);	// 중심점
	gp_Dir xDirection(1.0, 0.0, 0.0);
	gp_Dir zDirection(0.0, 0.0, 1.0);
	gp_Ax2 axis(centerPoint, zDirection, xDirection); // (중심점, normal direction(평면 방향), x축)
	gp_Circ circle(axis, 5);
	Standard_Integer resolution = 20;

	// 500의 요소와 함께 할당됨. index는 0~499가 아닌 1~500.
	TColgp_Array1OfPnt pointsOnCircle(1, resolution);

	// 점들을 분산하여 파일에 기입
	PointOnCurveDistribution::distributePointsOnCurve(circle, pointsOnCircle, 0.0, 2.0 * M_PI, resolution);
	WriteCoordinatesToFile::writeCoordinatesToFile("triangle.txt", pointsOnCircle);
	
	// 작은 삼각형들의 면적을 합산하여 대략적인 면적 구함.
	// for문으로 원주 및 원의 중심, 두 모서리를 세 점으로 가진 삼각형을 생성.
	double totalArea = 0.0;
	for (Standard_Integer i = 1; i <= resolution; i++) {
		gp_Pnt firstPntOfTriangle = pointsOnCircle.Value(i);
		gp_Pnt secondPntofTriangle;
		if (i != resolution) {
			secondPntofTriangle = pointsOnCircle.Value(i + 1);
		}
		else	// 끝에 도달하면 첫 번째 점을 값을 가져가게끔 처리
		{
			secondPntofTriangle = pointsOnCircle.Value(1);
		}
		gp_Pnt thirdPntOfTriangle = centerPoint;

		// 핸들(스마트 포인터 같은)이 포인트 배열에 구축되어 있음.
		Handle_TColgp_HArray1OfPnt trianglePointsArray = new TColgp_HArray1OfPnt(1, 3);
		trianglePointsArray->ChangeValue(1) = firstPntOfTriangle;
		trianglePointsArray->ChangeValue(2) = secondPntofTriangle;
		trianglePointsArray->ChangeValue(3) = thirdPntOfTriangle;
		totalArea += AreaCalculations::calculateTriangleArea(trianglePointsArray);
	}

	cout << "삼각형으로 계산한 원의 면적 : " << totalArea << endl;
	cout << "원래 원의 면적 : " << circle.Area() << endl;
	cout << "차이나는 면적 : " << fabs(totalArea - circle.Area()) << endl;
	cout << "정확도 : " << 1 - (fabs(totalArea - circle.Area()) / circle.Area()) << endl;
	

	return 0;
}
