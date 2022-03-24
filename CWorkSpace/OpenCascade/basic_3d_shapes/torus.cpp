/*
Open CASCADE 튜토리얼 by 이창하
2022.03.24
Torus 링 모양
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

	// Torus(gp_Ax2 중심축, 중심으로부터 파이프 중심 반지름, 파이프의 반지름)
	yAxis.SetLocation(gp_Pnt(10.0, 10.0, 0.0));
	TopoDS_Shape Torus1 = BRepPrimAPI_MakeTorus(yAxis, 3.0, 1.0).Shape();

	// Torus의 angle1 수직으로 자른 만큼 표현
	yAxis.SetLocation(gp_Pnt(-10.0, 10.0, 0.0));
	TopoDS_Shape Torus2 = BRepPrimAPI_MakeTorus(yAxis, 5.0, 1.0, M_PI/2).Shape();

	// angle1, angle2로 자른 만큼 표현, 위에서 시작하냐 아래에서 시작하냐 차이.
	// torus는 angle1과 angle2에 대입된 값만큼 면으로 잘라주기 때문에 안에가 면으로 채워지는 현상이 있음
	// angle1 <= angle2
	yAxis.SetLocation(gp_Pnt(10.0, -10.0, 0.0));
	TopoDS_Shape Torus3 = BRepPrimAPI_MakeTorus(yAxis, 7.0, 1.0, 0, M_PI).Shape();
	
	// angle1 angle2 : 수평으로 자르는 표현에 쓰임 / angle3: 수직으로 자르는 표현에 쓰임
	yAxis.SetLocation(gp_Pnt(-10.0, -10.0, 0.0));
	TopoDS_Shape Torus4 = BRepPrimAPI_MakeTorus(yAxis, 9.0, 1.0, 0, M_PI*0.1, M_PI).Shape();
	

	//vout << Torus1 << Torus2 << Torus3 << Torus4;

	vout << Torus3;

	vout.StartMessageLoop();
	return 0;
}