/*
Open CASCADE Ʃ�丮�� by ��â��
2022.03.24
Torus �� ���
*/
#define _USE_MATH_DEFINES_

#include "Viewer.h"

#include <cmath>

// OCC
#include <gp_Ax2.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepTools.hxx>


int main(int argc, char** argv)
{
	Viewer vout(50, 50, 500, 500);

	gp_Ax2 yAxis;

	// Torus(gp_Ax2 �߽���, �߽����κ��� ������ �߽� ������, �������� ������)
	yAxis.SetLocation(gp_Pnt(10.0, 10.0, 0.0));
	TopoDS_Shape Torus1 = BRepPrimAPI_MakeTorus(yAxis, 3.0, 1.0).Shape();

	// Torus�� angle1 �������� �ڸ� ��ŭ ǥ��
	yAxis.SetLocation(gp_Pnt(-10.0, 10.0, 0.0));
	TopoDS_Shape Torus2 = BRepPrimAPI_MakeTorus(yAxis, 5.0, 1.0, M_PI/2).Shape();

	// angle1, angle2�� �ڸ� ��ŭ ǥ��, ������ �����ϳ� �Ʒ����� �����ϳ� ����.
	// torus�� angle1�� angle2�� ���Ե� ����ŭ ������ �߶��ֱ� ������ �ȿ��� ������ ä������ ������ ����
	// angle1 <= angle2
	yAxis.SetLocation(gp_Pnt(10.0, -10.0, 0.0));
	TopoDS_Shape Torus3 = BRepPrimAPI_MakeTorus(yAxis, 7.0, 1.0, 0, M_PI).Shape();
	
	// angle1 angle2 : �������� �ڸ��� ǥ���� ���� / angle3: �������� �ڸ��� ǥ���� ����
	yAxis.SetLocation(gp_Pnt(-10.0, -10.0, 0.0));
	TopoDS_Shape Torus4 = BRepPrimAPI_MakeTorus(yAxis, 9.0, 1.0, 0, M_PI*0.1, M_PI).Shape();
	

	//vout << Torus1 << Torus2 << Torus3 << Torus4;

	vout << Torus3;

	vout.StartMessageLoop();
	return 0;
}