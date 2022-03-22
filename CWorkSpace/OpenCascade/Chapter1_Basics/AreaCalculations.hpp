// Open CASCADE Ʃ�丮�� by ��â��
// 2022.03.22
#ifndef AREACALCULATIONS_HPP
#define AREACALCULATIONS_HPP 

#include "TColgp_HArray1OfPnt.hxx"
#include "math_Matrix.hxx"

namespace AreaCalculations
{
	double calculateTriangleArea(const Handle_TColgp_HArray1OfPnt triangleCorners) {
		math_Matrix matrixForAreaCalculation(0, 2, 0, 2); // 3x3 ��� ���� (3���� x, y, z��ǥ�� ���� �����ϱ� ����)

		// ��1
		matrixForAreaCalculation(0, 0) = triangleCorners->Value(1).X();
		matrixForAreaCalculation(0, 1) = triangleCorners->Value(1).Y();
		matrixForAreaCalculation(0, 2) = 1.0;	// Z ��ǥ, ������ �� 0�� ������ �ʰ� 1�� ����

		// ��2
		matrixForAreaCalculation(1, 0) = triangleCorners->Value(2).X();
		matrixForAreaCalculation(1, 1) = triangleCorners->Value(2).Y();
		matrixForAreaCalculation(1, 2) = 1.0;

		// ��3
		matrixForAreaCalculation(2, 0) = triangleCorners->Value(3).X();
		matrixForAreaCalculation(2, 1) = triangleCorners->Value(3).Y();
		matrixForAreaCalculation(2, 2) = 1.0;

		double area = 0.5 * matrixForAreaCalculation.Determinant(); // ����� ������ ���ϰ�, �ﰢ���̱� ������ ���� 0.5�� ����.
		return area;
	}
}
#endif