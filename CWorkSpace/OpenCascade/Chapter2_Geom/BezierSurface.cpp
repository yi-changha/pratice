/*
Open CASCADE 튜토리얼 by 이창하
2022.03.28
베지어 곡면

여러 제어 점을 가진 베지어 곡면을 구현한다.
*/

#include <iostream>
using namespace std;

// OCC
#include "occ.h"

int main(int argc, char** argv)
{
    Viewer vout(50, 50, 500, 500);

    // 제어점 - 배열 정의
    TColgp_Array2OfPnt P(1, 5, 1, 3); // (행 최소, 행 최대, 열 최소, 열 최대)

    // 1행
    P(1, 1) = gp_Pnt(0., 0., 0.);
    P(2, 1) = gp_Pnt(1., 0., 0.);
    P(3, 1) = gp_Pnt(2., 0., 0.);
    P(4, 1) = gp_Pnt(3., 0., 0.);
    P(5, 1) = gp_Pnt(4., 0., 0.);

    // 2행
    P(1, 2) = gp_Pnt(0., 2., 0.);
    P(2, 2) = gp_Pnt(1., 2., 4.);
    P(3, 2) = gp_Pnt(2., 2., 4.);
    P(4, 2) = gp_Pnt(3., 2., 4.);
    P(5, 2) = gp_Pnt(4., 2., 0.);

    // 3행
    P(1, 3) = gp_Pnt(0., 4., 0.);
    P(2, 3) = gp_Pnt(1., 4., 0.);
    P(3, 3) = gp_Pnt(2., 4., 0.);
    P(4, 3) = gp_Pnt(3., 4., 0.);
    P(5, 3) = gp_Pnt(4., 4., 0.);


    // 베지어 곡면의 기하학적 정보를 저장할 핸들 정의
    Handle(Geom_BezierSurface) BezierGeo = new Geom_BezierSurface(P);

    // BRepBuilderAPI_MakeFace을 통해 베지어 곡면의 위상적 정보를 입력하여 면 생성
    TopoDS_Face BezierFace = BRepBuilderAPI_MakeFace(BezierGeo, 0); // (곡면 기하학 정보가 담긴 핸들, 공차 허용값)

    // 위상학적 면으로부터 기하학적 표면을 가져오고, 매개 변수 한계를 도출한다.
    Handle(Geom_Surface) BezierGeo_bis = BRep_Tool::Surface(BezierFace);
    double u_lower, u_upper, v_lower, v_upper;
    BezierGeo_bis->Bounds(u_lower, u_upper, v_lower, v_upper);

    cout << u_lower << "\t" << u_upper << "\t" << v_lower << "\t" << v_upper << endl;

    vout << BezierFace;

    vout.StartMessageLoop();
    return 0;
}