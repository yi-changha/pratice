// OpenCASCADE 튜토리얼 by 이창하
// 22.03.23
// OpenCASCADE의 기능을 이용하여 방정식을 풀이한다.
// 선과 평면 사이의 교차점 관계에 대해서 표현한다.


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

	// 무수히 많은 해가 존재하는 경우 (선과 면이 일치하는 경우)
	case LinePlaneIntersection::LinePlaneIntersectionSolution::InfiniteSolutions:
		cout << "선과 면이 일치합니다. (무한)" << endl;
		break;

	// 해가 없는 경우 (선과 면이 평행하지만, 일치하지 않는 경우)
	case LinePlaneIntersection::LinePlaneIntersectionSolution::NoSolution:
		cout << "선과 면이 평행합니다. (해X)" << endl;
		break;

	// 면과 선이 한 점에서 만나는 경우
	case LinePlaneIntersection::LinePlaneIntersectionSolution::OneSolution:
		cout << "교차점 : " << solution.intersectionPoint.X()
			<< ", " << solution.intersectionPoint.Y() << ", "
			<< solution.intersectionPoint.Z() << endl;
	}
}

int main(int argc, char** argv) {
	// 평면 생성
	gp_Dir normalOfPlane(1.0, 0.0, 1.0);
	gp_Dir xDirectionOfPlane(1.0, 0.0, -1.0);
	gp_Pnt pointOnPlane(1.0, 0.0, 0.0);
	gp_Ax3 coordinateSystemOfPlane(pointOnPlane, normalOfPlane,
		xDirectionOfPlane);
	gp_Pln plane(coordinateSystemOfPlane);

	// 선 1 생성, 선 1과 평면 사이의 관계 (교차)
	gp_Lin line(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(1.0, 0.0, 1.0));
	LinePlaneIntersection::LinePlaneIntersectionSolution intersectionPoint 
		= LinePlaneIntersection::intersectLineWithPlane(line, plane);
	treatIntersectionSolution(intersectionPoint);
	cout << endl;

	// 선 2 생성, 선 2과 평면 사이의 관계 (일치)
	gp_Lin line2(gp_Pnt(1.0, 0.0, 0.0), gp_Dir(1.0, 0.0, -1.0));
	intersectionPoint = LinePlaneIntersection::intersectLineWithPlane(line2, plane);
	treatIntersectionSolution(intersectionPoint);
	cout << endl;

	// 선 3 생성, 선 3과 평면 사이의 관계 (평행)
	gp_Lin line3(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(1.0, 0.0, -1.0));
	intersectionPoint = LinePlaneIntersection::intersectLineWithPlane(line3, plane);
	treatIntersectionSolution(intersectionPoint);

	return 0;
}
