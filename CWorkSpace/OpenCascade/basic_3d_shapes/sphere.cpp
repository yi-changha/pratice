/*
Open CASCADE 튜토리얼 by 이창하
2022.03.24
sphere 구
*/
#include "Viewer.h"

// OCC
#include <gp_Ax2.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepTools.hxx>


int main(int argc, char** argv)
{
	Viewer vout(50, 50, 500, 500);

	gp_Ax2 yAxis;
	yAxis.SetLocation(gp_Pnt(10.0, -10.0, 0.0));
	TopoDS_Shape sphere1 = BRepPrimAPI_MakeSphere(yAxis, 7.0).Shape();
	// 구(gp_Ax2 중심축, 반지름)

	yAxis.SetLocation(gp_Pnt(10.0, 10.0, 0.0));
	TopoDS_Shape sphere2 = BRepPrimAPI_MakeSphere(yAxis, 7.0, 5.0).Shape();
	// spherical wedge : 구를 사과처럼 자른 형상 (중심축, 반지름, angle)

	yAxis.SetLocation(gp_Pnt(-10.0, -10.0, 0.0));
	TopoDS_Shape sphere3 = BRepPrimAPI_MakeSphere(yAxis, 7.0, 5.0, 6.0).Shape();
	// spherical segment : 그릇과 비슷한 형상(gp_Ax2 중심축, 반지름, angle1, angle2)


	vout << sphere1 << sphere2 << sphere3;

	vout.StartMessageLoop();
	return 0;
}