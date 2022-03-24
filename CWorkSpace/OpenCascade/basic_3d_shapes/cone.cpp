/*
Open CASCADE Ʃ�丮��
Cone ����
*/
#include "Viewer.h"

// OCC
#include <gp_Ax2.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepTools.hxx>


int main(int argc, char** argv)
{
	Viewer vout(50, 50, 500, 500);

	gp_Ax2 yAxis;
	yAxis.SetLocation(gp_Pnt(10.0, 10.0, 0.0));

	TopoDS_Shape cone = BRepPrimAPI_MakeCone(yAxis, 5.0, 1.0, 10.0).Shape();
	// Cone(gp_Ax2 �߽���, �Ʒ� ������, �� ������, ����)


	vout << cone;

	vout.StartMessageLoop();
	return 0;
}