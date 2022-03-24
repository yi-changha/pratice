/*
Open CASCADE 튜토리얼 by 이창하
2022.03.24
Cylinder 원통
*/
#include "Viewer.h"

// OCC
#include <gp_Ax2.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepTools.hxx>


int main(int argc, char** argv)
{
	Viewer vout(50, 50, 500, 500);

	gp_Ax2 yAxis;
	yAxis.SetLocation(gp_Pnt(10.0, 10.0, 0.0));

	TopoDS_Shape Cylinder = BRepPrimAPI_MakeCylinder(yAxis, 10.0, 5.0).Shape();
	// 원통(gp_Ax2 중심축, 반지름, 높이)


	vout << Cylinder;

	vout.StartMessageLoop();
	return 0;
}