/*
Open CASCADE Ʃ�丮�� by ��â��
2022.03.29
B-Spline, Bezier-Spline 2

NURBS (Non-uniform rational B-spline)
������ ������ ������ ������ ��꿡 ���� ��� ���ϰ�, �� ��� Ȯ���Ų 3������ ����� ���ϴ� ���. 

���� ���� ���� �����Ͽ� face ���� �����Ѵ�.
*/
#include <iostream>
using namespace std;

// OCC
#include "occ.h"

int main(int argc, char** argv)
{
    Viewer vout(50, 50, 500, 500);

    // ������ - �迭 ����
    TColgp_Array1OfPnt P(1, 10); // (�ּ�, �ִ�)
    P(1) = gp_Pnt(0, 0, 0);
    P(2) = gp_Pnt(1, 1, 0);
    P(3) = gp_Pnt(2, -3, 0);
    P(4) = gp_Pnt(3, -5, 0);
    P(5) = gp_Pnt(4, 0, 0);
    P(6) = gp_Pnt(5, 2, 0);
    P(7) = gp_Pnt(6, 5, 0);
    P(8) = gp_Pnt(4, -2, 0);
    P(9) = gp_Pnt(2, -2, 0);
    P(10) = gp_Pnt(0, -5, 0);


    // 0���� �������� ���� �ľ�
    Standard_Integer length = P.Length() - 1;

    // �⺻ ���׽�(basis polynomials)�� ���� ����
    // ����(Linear) : p = 1, 2��(Quadratic) : p = 2, 3��(Cubic) : p = 3
    // p = n : n����, ex) x,y,z 3�����̴� p = 3���� ����
    Standard_Integer p = 3;

    // knot : ��Ʈ�� ����Ʈ�� ������ ���� �� 1�� �� ������ ���(0���� �����ϱ� ����)
    // ��� ������ [0 to x]�� ����, x�� �ŵ� ����, ���� ����(knot vector)�� ���� ������.
    // Ŀ���� �Ķ���ʹ� �� ���� Ŀ�� �� �ּҶ�� �� �� ����.
    // Poles.Length() == Sum(Mults(i)) - Degree - 1 >= 2
    // N + 1 = length - p + 2
    Standard_Integer N = length - p + 2 - 1;
    TColStd_Array1OfReal U_values(0, N);
    TColStd_Array1OfInteger U_mults(0, N);

    for (int i = 0; i <= N; ++i) {
        // ���� �� ���� (i��° ���� i/N)
        U_values(i) = double(i) / double(N);

        // ���� ��� ����
        if (i == 0 || i == N) { U_mults(i) = p + 1; }
        else { U_mults(i) = 1; }
    }

    // B-Spline�� geometry�� topology ����
    Handle(Geom_BSplineCurve) BSplineGeo = new Geom_BSplineCurve(P, U_values, U_mults, p);  // geometry�� �����Ͽ� �ڵ鿡 ����
    TopoDS_Edge BSplineEdge = BRepBuilderAPI_MakeEdge(BSplineGeo);  // BRepBuilderAPI_MakeEdge�� geometry�� �̿��Ͽ� topology ����
 
    // B-Spline�� �������� ������ �����ϴ� Edge�� �����.
    Standard_Integer numOfPoles = BSplineGeo->NbPoles();
    gp_Pnt P_start = BSplineGeo->Pole(1);       // ������
    gp_Pnt P_end = BSplineGeo->Pole(numOfPoles);// ����
    TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(P_start, P_end);

    // B-Spline�� Edge�� ���� ���� Edge�� ���ؼ� Wire�� �����Ѵ�.
    BRepBuilderAPI_MakeWire makeWire;
    makeWire.Add(BSplineEdge);
    makeWire.Add(edge);
    TopoDS_Wire wire = makeWire.Wire(); // �߰��� edge���� ���� Wire�� ����

    // wire�� ������� face ����
    TopoDS_Face face = BRepBuilderAPI_MakeFace(wire);


    vout << face;

    vout.StartMessageLoop();
    return 0;
}