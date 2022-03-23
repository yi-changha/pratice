// OpenCASCADE 튜토리얼 by 이창하
// 22.03.23

#include "LinePlaneIntersection.hpp"

#include "math_FunctionWithDerivative.hxx"
#include "math_FunctionRoot.hxx"
#include "math_DirectPolynomialRoots.hxx"
#include "ElCLib.hxx"

LinePlaneIntersection::LinePlaneIntersection() {
	// TODO Auto-generated constructor stub

}

LinePlaneIntersection::~LinePlaneIntersection() {
	// TODO Auto-generated destructor stub
}

LinePlaneIntersection::LinePlaneIntersectionSolution LinePlaneIntersection::intersectLineWithPlane 
(const gp_Lin& line,const gp_Pln& plane) 
{   
	Standard_Real A, B, C, D;
	plane.Coefficients(A, B, C, D);	// 평면의 계수 도출.

	gp_Pnt lineBasePoint = line.Location();		// 선의 원점
	gp_Dir lineDirection = line.Direction();	// 선의 방향

	Standard_Real X = A * lineDirection.X() + B * lineDirection.Y() + C * lineDirection.Z();
	Standard_Real Y = A * lineBasePoint.X() + lineBasePoint.Y() + lineBasePoint.Z() + D;

	math_DirectPolynomialRoots rootFinder(X, Y); // Xx+Y(ax+b)의 실제 경로 계산.
	rootFinder.Dump(std::cout);

	LinePlaneIntersectionSolution result;

	if (rootFinder.InfiniteRoots())			// 해가 무한인 경우
	{
		result.state = LinePlaneIntersectionSolution::InfiniteSolutions;
	}
	else if (rootFinder.NbSolutions() == 0)	// 해가 없는 경우
	{
		result.state = LinePlaneIntersectionSolution::NoSolution;
	}
	else									// 한 개의 해를 갖는 경우
	{
		result.state = LinePlaneIntersectionSolution::OneSolution;
		result.intersectionPoint = ElCLib::Value(rootFinder.Value(1), line);
	}

	return result;

}