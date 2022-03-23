// OpenCASCADE 튜토리얼 by 이창하
// 22.03.23

// Geom package를 통해 곡선, 표면 등의 형상 요소(geometric entities) 생성 및 변환
// OpenCASCADE에서 제공하는 수치 적분을 통해 곡선의 길이 계산

#define _USE_MATH_DEFINES
#include <cmath>

#include "GeometryWriter.hpp"
#include "TangentMagnitude.hpp"

#include "TColgp_Array1OfPnt.hxx"
#include "Geom_BezierCurve.hxx"
#include "math_GaussSingleIntegration.hxx"
using namespace std;

int main(void)
{

	// 4점으로 구성된 베지어 곡선 생성
	// 베지어 곡선 : 시작점과 끝점을 지정하고 제어점을 통해 곡선을 만드는 방법. (제어 점은 곡선에 포함되지 않음)

	// 제어점 생성
	TColgp_Array1OfPnt controlPoints(1, 4);

	controlPoints.SetValue(1, gp_Pnt(0.0, 0.0, 0.0));		// 시작점
	controlPoints.SetValue(2, gp_Pnt(1.0, 0.0, 1.0 / 3.0));	// 제어점1
	controlPoints.SetValue(3, gp_Pnt(1.0, 1.0, 2.0 / 3.0));	// 제어점2
	controlPoints.SetValue(4, gp_Pnt(1.0, 1.0, 1.0));		// 끝점

	Handle_Geom_Curve bezierCurve = new Geom_BezierCurve(controlPoints);	// 동적할당 베지어 곡선(원곡선 제어점)

	GeometryWriter::writeGeomEntityToStepFile(bezierCurve, "bezierInitial.stp");	// stp파일로저장(대상, 파일이름)

	// 생성된 베지어 곡선은 Geom_Geometry로부터 상속 받기 때문에 모든 기하학적 변환 적용 가능.

	// 180도 회전
	Handle_Geom_Geometry rotated = bezierCurve->Rotated(gp::OZ(), M_PI); // (0,0,1)인 벡터에 대하여 180도 회전

	// Handle의 내장된 기능인 DownCast를 통해 곡선으로 변환 가능
	Handle_Geom_Curve rotatedCurve = Handle_Geom_Curve::DownCast(rotated);
	GeometryWriter::writeGeomEntityToStepFile(rotatedCurve, "rotatedBezier.stp");

	// Handle의 DownCast를 통해 크기 조정
	Handle_Geom_Curve scaledCurve = Handle_Geom_Curve::DownCast(bezierCurve->Scaled(gp::Origin(), 2.0));

	// 생성된 곡선의 매개변수 경계 찾기
	Standard_Real firstParameter = bezierCurve->FirstParameter();
	Standard_Real lastParameter = bezierCurve->LastParameter();

	cout << "생성된 곡선의 매개 변수 - " << "하한 : " << firstParameter << ",\t상한 :" << lastParameter << endl;

	// 주어진 매개변수에서 곡선을 측정하기 위해 "Value" 함수 이용
	gp_Pnt pointOnCurve = bezierCurve->Value(0.0);
	cout << "Point at u = 0.0: " << "(" << pointOnCurve.X() << "," << pointOnCurve.Y() << "," << pointOnCurve.Z() << ")" << endl;

	pointOnCurve = bezierCurve->Value(0.5);
	cout << "Point at u = 0.5: " << "(" << pointOnCurve.X() << "," << pointOnCurve.Y() << "," << pointOnCurve.Z() << ")" << endl;

	pointOnCurve = bezierCurve->Value(1.0);
	cout << "Point at u = 1.0: " << "(" << pointOnCurve.X() << "," << pointOnCurve.Y() << "," << pointOnCurve.Z() << ")" << endl;

	// 접선 벡터를 평가하기 위한 함수 "D1". 
	gp_Vec tangentVector;
	bezierCurve->D1(0.0, pointOnCurve, tangentVector);
	cout << "Magnitude of tangent at 0.0: " << tangentVector.Magnitude() << endl;
	bezierCurve->D1(0.5, pointOnCurve, tangentVector);
	cout << "Magnitude of tangent at 0.5: " << tangentVector.Magnitude() << endl;
	bezierCurve->D1(1.0, pointOnCurve, tangentVector);
	cout << "Magnitude of tangent at 1.0: " << tangentVector.Magnitude() << endl;

	// 곡선을 따라 접선 벡터의 크기를 적분하면 길이를 얻을 수 있음.
	// OpenCASCADE의 math_GaussSingleIntegration이라는 수치 통합 루틴을 통해 위의 과정을 할 수 있음.
	// 방법 : math_Function에서 클래스를 상속받고, "Value"함수를 실행. 이 함수는 주어진 X값에 대해 접선의 크기를 반환함.

	TangentMagnitude functionToBeIntegrated(bezierCurve);
	math_GaussSingleIntegration integrator(functionToBeIntegrated, firstParameter, lastParameter, 5);
	// 매개 변수 한계의 하한과 상한 간에 단일 변수의 함수를 통합(함수, 하한, 상한, order)
	// order은 61보다 작거나 같은 자연수. order의 값이 바뀌면 미세하게 값의 차이가 있음.

	if (integrator.IsDone())
	{
		cout << "대략적인 곡선의 길이 : " << integrator.Value() << endl;
	}

	// 회전된 곡선과 크기 조정된 곡선의 길이 측정

	// 회전된 곡선
	functionToBeIntegrated.setCurve(rotatedCurve);
	math_GaussSingleIntegration rotatedIntegrator(functionToBeIntegrated, firstParameter, lastParameter, 5);
	double rotatedLength = rotatedIntegrator.Value();

	// 2배로 크기가 조정된 곡선
	functionToBeIntegrated.setCurve(scaledCurve);
	math_GaussSingleIntegration scaledIntegrator(functionToBeIntegrated, firstParameter, lastParameter, 5);
	double scaledLength = scaledIntegrator.Value();

	cout << "회전된 곡선 길이 : " << rotatedLength << endl;
	cout << "2배로 크기 조정된 곡선 길이 : " << scaledLength << endl;

	// Rigid Transformation(강체 변환) :  회전과, 평행이동만을 허용하는 변환, 좌표는 보존되지 않음.
	// 회전은 강체 변환이기 때문에 원곡선의 길이가 그대로이지만, 축척은 길이가 변경됨.

	return 0;
}