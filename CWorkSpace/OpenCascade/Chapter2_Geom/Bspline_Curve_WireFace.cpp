/*
Open CASCADE 튜토리얼 by 이창하
2022.03.29
B-Spline, Bezier-Spline 2

NURBS (Non-uniform rational B-spline)
일정한 점들을 연결한 직선서 계산에 의한 곡선을 구하고, 그 곡선을 확장시킨 3차원의 곡면을 구하는 방식. 

위에 구한 선을 연결하여 face 면을 도출한다.
*/
#include <iostream>
using namespace std;

// OCC
#include "occ.h"

int main(int argc, char** argv)
{
    Viewer vout(50, 50, 500, 500);

    // 제어점 - 배열 정의
    TColgp_Array1OfPnt P(1, 10); // (최소, 최대)
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


    // 0부터 제어점의 갯수 파악
    Standard_Integer length = P.Length() - 1;

    // 기본 다항식(basis polynomials)의 순서 정의
    // 선형(Linear) : p = 1, 2차(Quadratic) : p = 2, 3차(Cubic) : p = 3
    // p = n : n차원, ex) x,y,z 3차원이니 p = 3으로 설정
    Standard_Integer p = 3;

    // knot : 컨트롤 포인트의 개수를 더한 뒤 1을 뺀 수들의 목록(0부터 시작하기 때문)
    // 곡선은 도메인 [0 to x]를 갖고, x는 매듭 벡터, 절점 벡터(knot vector)에 의해 정해짐.
    // 커브의 파라미터는 한 점의 커브 위 주소라고 할 수 있음.
    // Poles.Length() == Sum(Mults(i)) - Degree - 1 >= 2
    // N + 1 = length - p + 2
    Standard_Integer N = length - p + 2 - 1;
    TColStd_Array1OfReal U_values(0, N);
    TColStd_Array1OfInteger U_mults(0, N);

    for (int i = 0; i <= N; ++i) {
        // 절점 값 설정 (i번째 값은 i/N)
        U_values(i) = double(i) / double(N);

        // 절점 배수 설정
        if (i == 0 || i == N) { U_mults(i) = p + 1; }
        else { U_mults(i) = 1; }
    }

    // B-Spline의 geometry와 topology 정의
    Handle(Geom_BSplineCurve) BSplineGeo = new Geom_BSplineCurve(P, U_values, U_mults, p);  // geometry를 생성하여 핸들에 대입
    TopoDS_Edge BSplineEdge = BRepBuilderAPI_MakeEdge(BSplineGeo);  // BRepBuilderAPI_MakeEdge과 geometry를 이용하여 topology 정의
 
    // B-Spline의 시작점과 끝점을 연결하는 Edge을 만든다.
    Standard_Integer numOfPoles = BSplineGeo->NbPoles();
    gp_Pnt P_start = BSplineGeo->Pole(1);       // 시작점
    gp_Pnt P_end = BSplineGeo->Pole(numOfPoles);// 끝점
    TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(P_start, P_end);

    // B-Spline의 Edge와 새로 만든 Edge를 합해서 Wire를 생성한다.
    BRepBuilderAPI_MakeWire makeWire;
    makeWire.Add(BSplineEdge);
    makeWire.Add(edge);
    TopoDS_Wire wire = makeWire.Wire(); // 추가한 edge들을 합쳐 Wire로 생성

    // wire를 기반으로 face 생성
    TopoDS_Face face = BRepBuilderAPI_MakeFace(wire);


    vout << face;

    vout.StartMessageLoop();
    return 0;
}