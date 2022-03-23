// OpenCASCADE Ʃ�丮�� by ��â��
// 22.03.23

// Geom package�� ���� �, ǥ�� ���� ���� ���(geometric entities) ���� �� ��ȯ
// OpenCASCADE���� �����ϴ� ��ġ ������ ���� ��� ���� ���

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

	// 4������ ������ ������ � ����
	// ������ � : �������� ������ �����ϰ� �������� ���� ��� ����� ���. (���� ���� ��� ���Ե��� ����)

	// ������ ����
	TColgp_Array1OfPnt controlPoints(1, 4);

	controlPoints.SetValue(1, gp_Pnt(0.0, 0.0, 0.0));		// ������
	controlPoints.SetValue(2, gp_Pnt(1.0, 0.0, 1.0 / 3.0));	// ������1
	controlPoints.SetValue(3, gp_Pnt(1.0, 1.0, 2.0 / 3.0));	// ������2
	controlPoints.SetValue(4, gp_Pnt(1.0, 1.0, 1.0));		// ����

	Handle_Geom_Curve bezierCurve = new Geom_BezierCurve(controlPoints);	// �����Ҵ� ������ �(��� ������)

	GeometryWriter::writeGeomEntityToStepFile(bezierCurve, "bezierInitial.stp");	// stp���Ϸ�����(���, �����̸�)

	// ������ ������ ��� Geom_Geometry�κ��� ��� �ޱ� ������ ��� �������� ��ȯ ���� ����.

	// 180�� ȸ��
	Handle_Geom_Geometry rotated = bezierCurve->Rotated(gp::OZ(), M_PI); // (0,0,1)�� ���Ϳ� ���Ͽ� 180�� ȸ��

	// Handle�� ����� ����� DownCast�� ���� ����� ��ȯ ����
	Handle_Geom_Curve rotatedCurve = Handle_Geom_Curve::DownCast(rotated);
	GeometryWriter::writeGeomEntityToStepFile(rotatedCurve, "rotatedBezier.stp");

	// Handle�� DownCast�� ���� ũ�� ����
	Handle_Geom_Curve scaledCurve = Handle_Geom_Curve::DownCast(bezierCurve->Scaled(gp::Origin(), 2.0));

	// ������ ��� �Ű����� ��� ã��
	Standard_Real firstParameter = bezierCurve->FirstParameter();
	Standard_Real lastParameter = bezierCurve->LastParameter();

	cout << "������ ��� �Ű� ���� - " << "���� : " << firstParameter << ",\t���� :" << lastParameter << endl;

	// �־��� �Ű��������� ��� �����ϱ� ���� "Value" �Լ� �̿�
	gp_Pnt pointOnCurve = bezierCurve->Value(0.0);
	cout << "Point at u = 0.0: " << "(" << pointOnCurve.X() << "," << pointOnCurve.Y() << "," << pointOnCurve.Z() << ")" << endl;

	pointOnCurve = bezierCurve->Value(0.5);
	cout << "Point at u = 0.5: " << "(" << pointOnCurve.X() << "," << pointOnCurve.Y() << "," << pointOnCurve.Z() << ")" << endl;

	pointOnCurve = bezierCurve->Value(1.0);
	cout << "Point at u = 1.0: " << "(" << pointOnCurve.X() << "," << pointOnCurve.Y() << "," << pointOnCurve.Z() << ")" << endl;

	// ���� ���͸� ���ϱ� ���� �Լ� "D1". 
	gp_Vec tangentVector;
	bezierCurve->D1(0.0, pointOnCurve, tangentVector);
	cout << "Magnitude of tangent at 0.0: " << tangentVector.Magnitude() << endl;
	bezierCurve->D1(0.5, pointOnCurve, tangentVector);
	cout << "Magnitude of tangent at 0.5: " << tangentVector.Magnitude() << endl;
	bezierCurve->D1(1.0, pointOnCurve, tangentVector);
	cout << "Magnitude of tangent at 1.0: " << tangentVector.Magnitude() << endl;

	// ��� ���� ���� ������ ũ�⸦ �����ϸ� ���̸� ���� �� ����.
	// OpenCASCADE�� math_GaussSingleIntegration�̶�� ��ġ ���� ��ƾ�� ���� ���� ������ �� �� ����.
	// ��� : math_Function���� Ŭ������ ��ӹް�, "Value"�Լ��� ����. �� �Լ��� �־��� X���� ���� ������ ũ�⸦ ��ȯ��.

	TangentMagnitude functionToBeIntegrated(bezierCurve);
	math_GaussSingleIntegration integrator(functionToBeIntegrated, firstParameter, lastParameter, 5);
	// �Ű� ���� �Ѱ��� ���Ѱ� ���� ���� ���� ������ �Լ��� ����(�Լ�, ����, ����, order)
	// order�� 61���� �۰ų� ���� �ڿ���. order�� ���� �ٲ�� �̼��ϰ� ���� ���̰� ����.

	if (integrator.IsDone())
	{
		cout << "�뷫���� ��� ���� : " << integrator.Value() << endl;
	}

	// ȸ���� ��� ũ�� ������ ��� ���� ����

	// ȸ���� �
	functionToBeIntegrated.setCurve(rotatedCurve);
	math_GaussSingleIntegration rotatedIntegrator(functionToBeIntegrated, firstParameter, lastParameter, 5);
	double rotatedLength = rotatedIntegrator.Value();

	// 2��� ũ�Ⱑ ������ �
	functionToBeIntegrated.setCurve(scaledCurve);
	math_GaussSingleIntegration scaledIntegrator(functionToBeIntegrated, firstParameter, lastParameter, 5);
	double scaledLength = scaledIntegrator.Value();

	cout << "ȸ���� � ���� : " << rotatedLength << endl;
	cout << "2��� ũ�� ������ � ���� : " << scaledLength << endl;

	// Rigid Transformation(��ü ��ȯ) :  ȸ����, �����̵����� ����ϴ� ��ȯ, ��ǥ�� �������� ����.
	// ȸ���� ��ü ��ȯ�̱� ������ ����� ���̰� �״��������, ��ô�� ���̰� �����.

	return 0;
}