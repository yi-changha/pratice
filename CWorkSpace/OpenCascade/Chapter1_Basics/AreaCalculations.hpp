// Open CASCADE 튜토리얼 by 이창하
// 2022.03.22
#ifndef AREACALCULATIONS_HPP
#define AREACALCULATIONS_HPP 

#include "TColgp_HArray1OfPnt.hxx"
#include "math_Matrix.hxx"

namespace AreaCalculations
{
	double calculateTriangleArea(const Handle_TColgp_HArray1OfPnt triangleCorners) {
		math_Matrix matrixForAreaCalculation(0, 2, 0, 2); // 3x3 행렬 생성 (3점의 x, y, z좌표를 각각 저장하기 위함)

		// 점1
		matrixForAreaCalculation(0, 0) = triangleCorners->Value(1).X();
		matrixForAreaCalculation(0, 1) = triangleCorners->Value(1).Y();
		matrixForAreaCalculation(0, 2) = 1.0;	// Z 좌표, 곱했을 떄 0이 나오지 않게 1을 대입

		// 점2
		matrixForAreaCalculation(1, 0) = triangleCorners->Value(2).X();
		matrixForAreaCalculation(1, 1) = triangleCorners->Value(2).Y();
		matrixForAreaCalculation(1, 2) = 1.0;

		// 점3
		matrixForAreaCalculation(2, 0) = triangleCorners->Value(3).X();
		matrixForAreaCalculation(2, 1) = triangleCorners->Value(3).Y();
		matrixForAreaCalculation(2, 2) = 1.0;

		double area = 0.5 * matrixForAreaCalculation.Determinant(); // 행렬의 면적을 구하고, 삼각형이기 때문에 값에 0.5를 곱함.
		return area;
	}
}
#endif