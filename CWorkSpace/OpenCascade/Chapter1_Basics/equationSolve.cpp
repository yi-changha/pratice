// OpenCASCADE Ʃ�丮�� by ��â��
// 22.03.23
// OpenCASCADE�� ����� �̿��Ͽ� �������� Ǯ���Ѵ�.
// ���� ��� ������ ������ ���迡 ���ؼ� ǥ���Ѵ�.


#include <gp_Ax3.hxx>
#include <gp_Dir.hxx>
#include <gp_Lin.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pln.hxx>
#include <StdFail_InfiniteSolutions.hxx>

#include "LinePlaneIntersection.hpp"

#include <iostream>
using namespace std;

void treatIntersectionSolution(
	LinePlaneIntersection::LinePlaneIntersectionSolution solution) {
	switch (solution.state) {

	// ������ ���� �ذ� �����ϴ� ��� (���� ���� ��ġ�ϴ� ���)
	case LinePlaneIntersection::LinePlaneIntersectionSolution::InfiniteSolutions:
		cout << "���� ���� ��ġ�մϴ�. (����)" << endl;
		break;

	// �ذ� ���� ��� (���� ���� ����������, ��ġ���� �ʴ� ���)
	case LinePlaneIntersection::LinePlaneIntersectionSolution::NoSolution:
		cout << "���� ���� �����մϴ�. (��X)" << endl;
		break;

	// ��� ���� �� ������ ������ ���
	case LinePlaneIntersection::LinePlaneIntersectionSolution::OneSolution:
		cout << "������ : " << solution.intersectionPoint.X()
			<< ", " << solution.intersectionPoint.Y() << ", "
			<< solution.intersectionPoint.Z() << endl;
	}
}

int main(int argc, char** argv) {
	// ��� ����
	gp_Dir normalOfPlane(1.0, 0.0, 1.0);
	gp_Dir xDirectionOfPlane(1.0, 0.0, -1.0);
	gp_Pnt pointOnPlane(1.0, 0.0, 0.0);
	gp_Ax3 coordinateSystemOfPlane(pointOnPlane, normalOfPlane,
		xDirectionOfPlane);
	gp_Pln plane(coordinateSystemOfPlane);

	// �� 1 ����, �� 1�� ��� ������ ���� (����)
	gp_Lin line(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(1.0, 0.0, 1.0));
	LinePlaneIntersection::LinePlaneIntersectionSolution intersectionPoint 
		= LinePlaneIntersection::intersectLineWithPlane(line, plane);
	treatIntersectionSolution(intersectionPoint);
	cout << endl;

	// �� 2 ����, �� 2�� ��� ������ ���� (��ġ)
	gp_Lin line2(gp_Pnt(1.0, 0.0, 0.0), gp_Dir(1.0, 0.0, -1.0));
	intersectionPoint = LinePlaneIntersection::intersectLineWithPlane(line2, plane);
	treatIntersectionSolution(intersectionPoint);
	cout << endl;

	// �� 3 ����, �� 3�� ��� ������ ���� (����)
	gp_Lin line3(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(1.0, 0.0, -1.0));
	intersectionPoint = LinePlaneIntersection::intersectLineWithPlane(line3, plane);
	treatIntersectionSolution(intersectionPoint);

	return 0;
}
