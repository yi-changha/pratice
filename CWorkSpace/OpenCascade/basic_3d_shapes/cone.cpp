/*
Open CASCADE 튜토리얼 by 이창하
2022.03.24
Cone 원뿔
*/
#define _USE_MATH_DEFINES_

#include "Viewer.h"

#include <cmath>
// OCC
#include <gp_Ax2.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepTools.hxx>


int main(int argc, char** argv)
{
	Viewer vout(50, 50, 500, 500);

	gp_Ax2 yAxis;

	// Cone(gp_Ax2 중심축, 아래 반지름, 위 반지름, 높이)
	yAxis.SetLocation(gp_Pnt(10.0, 10.0, 0.0));
	TopoDS_Shape cone1 = BRepPrimAPI_MakeCone(yAxis, 5.0, 1.0, 10.0).Shape();
	
	// 잘라진 Cone(gp_Ax2 중심축, 아래 반지름, 위 반지름, 높이, 구현할 각도)
	yAxis.SetLocation(gp_Pnt(-10.0, -10.0, 0.0));
	TopoDS_Shape cone2 = BRepPrimAPI_MakeCone(yAxis, 5.0, 1.0, 10.0, M_PI/2).Shape();

	vout << cone1 << cone2;

	vout.StartMessageLoop();
	return 0;
}
