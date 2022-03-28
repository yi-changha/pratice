/*
Open CASCADE Ʃ�丮�� by ��â��
2022.03.28
FACE

�������� Ư���� ���� �����Ѵ�.
*/

#include <iostream>
using namespace std;

// OCC
#include "occ.h"


static TopoDS_Face makeDisk(gp_Pnt centerPoint, gp_Dir dir, Standard_Real radius)
{
	gp_Ax2 axis(centerPoint, dir);// �� ����

	Handle(Geom_Circle) circle = GC_MakeCircle(axis, radius);	// �������� ���� ����
	TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(circle);			// ������ ���� edge ����
	TopoDS_Wire wire = BRepBuilderAPI_MakeWire(edge);			// edge�κ��� wire(edge�� ����ü) ����
	TopoDS_Face disk = BRepBuilderAPI_MakeFace(wire);			// wire�� ���� face(��)�� disk ����
	return disk;
}

int main(int argc, char** argv)
{
	gp_Pnt centerPoint(5.0, 5.0, 0.0);	// �߽���, xy ���
	gp_Dir zDirection(0.0, 0.0, 1.0);	// normal direction (���� ����)
	gp_Dir xDirection(1.0, 0.0, 0.0);

	TopoDS_Face F = makeDisk(centerPoint, zDirection, 5); // (�߽���, z��, ������)
	
	gp_Dir direc(0, 0, 1);
	Standard_Real l = 10;


	return 0;
}