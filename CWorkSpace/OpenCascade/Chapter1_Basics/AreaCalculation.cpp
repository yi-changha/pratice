/*
OpenCASCADE Ʃ�丮�� by ��â��
2022.03.22
�ﰢ�� �׸���
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

// Open CASCADE�� Ȱ���ؼ� ���� �������
#include "PointOnCurveDistributor.hpp"
#include "WriteCoordinatesToFile.hpp"
#include "AreaCalculations.hpp"


int main(int argc, char* argv[1]) {

	// �� ����
	gp_Pnt centerPoint(5.0, 5.0, 0.0);	// �߽���
	gp_Dir xDirection(1.0, 0.0, 0.0);
	gp_Dir zDirection(0.0, 0.0, 1.0);
	gp_Ax2 axis(centerPoint, zDirection, xDirection); // (�߽���, normal direction(��� ����), x��)
	gp_Circ circle(axis, 5);
	Standard_Integer resolution = 20;

	// 500�� ��ҿ� �Բ� �Ҵ��. index�� 0~499�� �ƴ� 1~500.
	TColgp_Array1OfPnt pointsOnCircle(1, resolution);

	// ������ �л��Ͽ� ���Ͽ� ����
	PointOnCurveDistribution::distributePointsOnCurve(circle, pointsOnCircle, 0.0, 2.0 * M_PI, resolution);
	WriteCoordinatesToFile::writeCoordinatesToFile("triangle.txt", pointsOnCircle);
	
	// ���� �ﰢ������ ������ �ջ��Ͽ� �뷫���� ���� ����.
	// for������ ���� �� ���� �߽�, �� �𼭸��� �� ������ ���� �ﰢ���� ����.
	double totalArea = 0.0;
	for (Standard_Integer i = 1; i <= resolution; i++) {
		gp_Pnt firstPntOfTriangle = pointsOnCircle.Value(i);
		gp_Pnt secondPntofTriangle;
		if (i != resolution) {
			secondPntofTriangle = pointsOnCircle.Value(i + 1);
		}
		else	// ���� �����ϸ� ù ��° ���� ���� �������Բ� ó��
		{
			secondPntofTriangle = pointsOnCircle.Value(1);
		}
		gp_Pnt thirdPntOfTriangle = centerPoint;

		// �ڵ�(����Ʈ ������ ����)�� ����Ʈ �迭�� ����Ǿ� ����.
		Handle_TColgp_HArray1OfPnt trianglePointsArray = new TColgp_HArray1OfPnt(1, 3);
		trianglePointsArray->ChangeValue(1) = firstPntOfTriangle;
		trianglePointsArray->ChangeValue(2) = secondPntofTriangle;
		trianglePointsArray->ChangeValue(3) = thirdPntOfTriangle;
		totalArea += AreaCalculations::calculateTriangleArea(trianglePointsArray);
	}

	cout << "�ﰢ������ ����� ���� ���� : " << totalArea << endl;
	cout << "���� ���� ���� : " << circle.Area() << endl;
	cout << "���̳��� ���� : " << fabs(totalArea - circle.Area()) << endl;
	cout << "��Ȯ�� : " << 1 - (fabs(totalArea - circle.Area()) / circle.Area()) << endl;
	

	return 0;
}