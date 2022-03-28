/*
Open CASCADE Ʃ�丮�� by ��â��
2022.03.28
������ ���

���� ���� ���� ���� ������ ����� �����Ѵ�.
*/

#include <iostream>
using namespace std;

// OCC
#include "occ.h"

int main(int argc, char** argv)
{
    Viewer vout(50, 50, 500, 500);

    // ������ - �迭 ����
    TColgp_Array2OfPnt P(1, 5, 1, 3); // (�� �ּ�, �� �ִ�, �� �ּ�, �� �ִ�)

    // 1��
    P(1, 1) = gp_Pnt(0., 0., 0.);
    P(2, 1) = gp_Pnt(1., 0., 0.);
    P(3, 1) = gp_Pnt(2., 0., 0.);
    P(4, 1) = gp_Pnt(3., 0., 0.);
    P(5, 1) = gp_Pnt(4., 0., 0.);

    // 2��
    P(1, 2) = gp_Pnt(0., 2., 0.);
    P(2, 2) = gp_Pnt(1., 2., 4.);
    P(3, 2) = gp_Pnt(2., 2., 4.);
    P(4, 2) = gp_Pnt(3., 2., 4.);
    P(5, 2) = gp_Pnt(4., 2., 0.);

    // 3��
    P(1, 3) = gp_Pnt(0., 4., 0.);
    P(2, 3) = gp_Pnt(1., 4., 0.);
    P(3, 3) = gp_Pnt(2., 4., 0.);
    P(4, 3) = gp_Pnt(3., 4., 0.);
    P(5, 3) = gp_Pnt(4., 4., 0.);


    // ������ ����� �������� ������ ������ �ڵ� ����
    Handle(Geom_BezierSurface) BezierGeo = new Geom_BezierSurface(P);

    // BRepBuilderAPI_MakeFace�� ���� ������ ����� ������ ������ �Է��Ͽ� �� ����
    TopoDS_Face BezierFace = BRepBuilderAPI_MakeFace(BezierGeo, 0); // (��� ������ ������ ��� �ڵ�, ���� ��밪)

    // �������� �����κ��� �������� ǥ���� ��������, �Ű� ���� �Ѱ踦 �����Ѵ�.
    Handle(Geom_Surface) BezierGeo_bis = BRep_Tool::Surface(BezierFace);
    double u_lower, u_upper, v_lower, v_upper;
    BezierGeo_bis->Bounds(u_lower, u_upper, v_lower, v_upper);

    cout << u_lower << "\t" << u_upper << "\t" << v_lower << "\t" << v_upper << endl;

    vout << BezierFace;

    vout.StartMessageLoop();
    return 0;
}