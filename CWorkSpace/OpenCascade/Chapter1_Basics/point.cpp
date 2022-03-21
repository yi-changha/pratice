/*
OpenCASCADE 튜토리얼 by 이창하
2022.03.21
3D 공간에서의 두 점 pnt1, pnt2
*/

#include <iostream>
using namespace std;

// Open CASCADE
#include "gp_Pnt.hxx"
#include "gp_Ax1.hxx"
#include "gp_Trsf.hxx"

int main(int argc, char* argv[1]) {

	// 점 객체 두 개 생성 (x, y, z)
	gp_Pnt	pnt1(0.0, 0.0, 0.0), 
			pnt2(1.0, 1.0, 1.0);

	// 좌표표현
	cout << "pnt1: " << pnt1.X() << ", " << pnt1.Y() << ", " << pnt1.Z() << endl;
	cout << "pnt2: " << pnt2.X() << ", " << pnt2.Y() << ", " << pnt2.Z() << endl;
	cout << "두 점의 거리 : " << pnt1.Distance(pnt2) << endl;

	// pnt1을 pnt기준으로 90도 회전
	gp_Trsf rotation;	// 비영구적인 대칭, 회전, 배율을 위한 객체 생성
	gp_Ax1 rotationAxis(gp_Pnt(1.0, 0.0, 1.0), gp_Dir(-1.0, 0.0, -1.0));
	rotation.SetRotation(rotationAxis, 3.1415926 / 2.0); // 개체에 회전 값 설정(회전시킬 축, 회전 각도)
	pnt2.Transform(rotation); // 변환 적용(대상 개체)
	cout << "90도 회전 후 pnt2의 좌표 : " << pnt2.X() << ", " << pnt2.Y() << ", " << pnt2.Z() << endl;

	// pnt1에 대해서 Y축으로 미러링(대칭) 
	gp_Ax1 axisY(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(0.0, 1.0, 0.0));
	gp_Pnt pnt3 = pnt1.Mirrored(axisY), pnt4 = pnt2.Mirrored(axisY);
	cout << "Y축 대칭시킨 pnt1의 좌표 : " << pnt3.X() << ", " << pnt3.Y() << ", " << pnt3.Z() << endl;
	cout << "Y축 대칭시킨 pnt2의 좌표 : " << pnt4.X() << ", " << pnt4.Y() << ", " << pnt4.Z() << endl;

	return 0;
}