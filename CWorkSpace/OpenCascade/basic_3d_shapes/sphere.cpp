/*
Open CASCADE Ʃ�丮�� by ��â��
2022.03.24
sphere ��
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
	// ��(gp_Ax2 �߽���, ������)

	yAxis.SetLocation(gp_Pnt(10.0, 10.0, 0.0));
	TopoDS_Shape sphere2 = BRepPrimAPI_MakeSphere(yAxis, 7.0, 5.0).Shape();
	// spherical wedge : ���� ���ó�� �ڸ� ���� (�߽���, ������, angle)

	yAxis.SetLocation(gp_Pnt(-10.0, -10.0, 0.0));
	TopoDS_Shape sphere3 = BRepPrimAPI_MakeSphere(yAxis, 7.0, 5.0, 6.0).Shape();
	// spherical segment : �׸��� ����� ����(gp_Ax2 �߽���, ������, angle1, angle2)


	vout << sphere1 << sphere2 << sphere3;

	vout.StartMessageLoop();
	return 0;
}