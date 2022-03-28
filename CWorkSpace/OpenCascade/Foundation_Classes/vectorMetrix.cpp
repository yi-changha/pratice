/*
Open CASCADE Ʃ�丮�� by ��â��
2022.03.25
vector and matrix
*/

// OCC
#include "occ.h"


int main(int argc, char** argv)
{
#if 1
	// aVec1�� aVec2�� �����; aVec1�� ������ aVec2�� ������ ���� ����
	math_Vector aVec1(0, 2), aVec2(1, 3);
	aVec2 = aVec1;
#endif
#if 0
	// ���� �� ��Ʈ���� ���� ���� �Ǵ� ��Ʈ���� ���� ���� ���� �ִ� index�� ����Ͽ� �ʱ�ȭ�ؾ���.
	math_Vector bVec(1, 3);
	math_Matrix bMat(1, 3, 1, 3);
	Standard_Real bValue;

	bVec(2) = 1.0;
	bValue = bVec(1);
	bMat(1, 3) = 1.0;
	bValue = bMat(2, 2);
#endif
#if 0
	// ����, ��Ʈ���� ����
	// Standard_DimensionError : � ���꿡 ���õ� �� ����̳� ���Ͱ� ȣȯ���� ���� ��� �߻�.
	// Standard_RangeError : ���� �Ǵ� ��Ʈ������ ���� �ܿ� �׼����� �õ��� ��� �߻�.

	math_Vector cVec1(1, 3), cVec2(1, 2), cVec3(0, 2);
	cVec1 = cVec2; // ����: Standard_DimensionError �߻�; �� ���Ͱ� ȣȯ���� ����
	cVec1 = cVec3; // OK: ������ �������� ������ ġ���� ȣȯ ����
	cVec1(0) = 2.0; // ����: Standard_RangeError �߻�; ���� ��
#endif
	
	return 0;
}