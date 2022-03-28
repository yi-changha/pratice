/*
Open CASCADE 튜토리얼 by 이창하
2022.03.25
vector and matrix
*/

// OCC
#include "occ.h"


int main(int argc, char** argv)
{
#if 1
	// aVec1이 aVec2로 복사됨; aVec1의 수정은 aVec2에 영향을 주지 않음
	math_Vector aVec1(0, 2), aVec2(1, 3);
	aVec2 = aVec1;
#endif
#if 0
	// 벡터 및 매트릭스 값은 벡터 또는 매트릭스 범위 정의 내에 있는 index를 사용하여 초기화해야함.
	math_Vector bVec(1, 3);
	math_Matrix bMat(1, 3, 1, 3);
	Standard_Real bValue;

	bVec(2) = 1.0;
	bValue = bVec(1);
	bMat(1, 3) = 1.0;
	bValue = bMat(2, 2);
#endif
#if 0
	// 벡터, 매트릭스 오류
	// Standard_DimensionError : 어떤 연산에 관련된 두 행렬이나 벡터가 호환되지 않을 경우 발생.
	// Standard_RangeError : 벡터 또는 매트릭스의 범위 외에 액세스를 시도할 경우 발생.

	math_Vector cVec1(1, 3), cVec2(1, 2), cVec3(0, 2);
	cVec1 = cVec2; // 오류: Standard_DimensionError 발생; 두 벡터가 호환되지 않음
	cVec1 = cVec3; // OK: 범위는 동일하지 않지만 치수는 호환 가능
	cVec1(0) = 2.0; // 오류: Standard_RangeError 발생; 범위 밖
#endif
	
	return 0;
}