/*
Open CASCADE 튜토리얼 by 이창하
2022.03.28
FACE

기하학적 특성인 면을 구현한다.
*/

#include <iostream>
using namespace std;

// OCC
#include "occ.h"


static TopoDS_Face makeDisk(gp_Pnt centerPoint, gp_Dir dir, Standard_Real radius)
{
	gp_Ax2 axis(centerPoint, dir);// 축 정의

	Handle(Geom_Circle) circle = GC_MakeCircle(axis, radius);	// 기하학적 원을 생성
	TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(circle);			// 원으로 부터 edge 생성
	TopoDS_Wire wire = BRepBuilderAPI_MakeWire(edge);			// edge로부터 wire(edge의 결합체) 생성
	TopoDS_Face disk = BRepBuilderAPI_MakeFace(wire);			// wire를 통해 face(면)인 disk 생성
	return disk;
}

int main(int argc, char** argv)
{
	gp_Pnt centerPoint(5.0, 5.0, 0.0);	// 중심점, xy 평면
	gp_Dir zDirection(0.0, 0.0, 1.0);	// normal direction (면의 반향)
	gp_Dir xDirection(1.0, 0.0, 0.0);

	TopoDS_Face F = makeDisk(centerPoint, zDirection, 5); // (중심점, z축, 반지름)
	
	gp_Dir direc(0, 0, 1);
	Standard_Real l = 10;


	return 0;
}