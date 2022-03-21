#include <iostream>
#include <iomanip>
using namespace std;

// Open CASCADE
#include "BRepPrimAPI_MakeCylinder.hxx"
#include "BRepPrimAPI_MakeBox.hxx"
#include "BRepAlgoAPI_Cut.hxx"
#include "BRepGProp.hxx"
#include "STEPControl_Writer.hxx"
#include "GProp_GProps.hxx"

int main(int argc, char* argv[]) 
{
	cout << "----- OpenCASCADE 튜토리얼 by 이창하 -----" << endl
		<< "----- Chapter 0 : Demonstrative example	-----" << endl;

	// 중심점 기준으로 한 지점을 설정하고, 100x100x50 상자 생성
	gp_Pnt pnt1(-50.0, -50.0, 0.0);
	BRepPrimAPI_MakeBox boxMaker(pnt1, 100, 100, 50); // (기준점, x, y, z)
	TopoDS_Shape box = boxMaker.Shape();


	// 중심점 기준으로 직경 25, 높이 50인 실린더 생성
	BRepPrimAPI_MakeCylinder cylinderMaker(25.0, 50.0);
	TopoDS_Shape cylinder = cylinderMaker.Shape();

	// 박스로부터 실린더만큼을 자름
	BRepAlgoAPI_Cut cutMaker(box, cylinder);
	TopoDS_Shape cuttedBox = cutMaker.Shape();

	// 결과물을 파일에 작성함.
	STEPControl_Writer writer;
	writer.Transfer(cuttedBox, STEPControl_AsIs); // STEP모델로 변환(형상, 모델 타입)
	writer.Write("cuttedBox.stp");

	cout << "관통된 박스가 cuttedBox.stp 파일로 저장되었습니다." << endl;

	// 생성된 형상의 체적 특성 계산
	GProp_GProps volumeProperties; // 기하학적 객체, 3D공간에서 기하학적 전역 특성을 계산하기 위해 쓰임.
	BRepGProp::VolumeProperties(cuttedBox, volumeProperties); // 기하학적 특성 계산(형상, GProp_GProps

	// 모델 부피 출력
	cout << setprecision(14) << "모델의 부피는 " << volumeProperties.Mass() << endl;

	// 무게중심 출력
	cout << "무게 중심은 " << volumeProperties.CentreOfMass().X() << " "
		<< volumeProperties.CentreOfMass().Y()<< volumeProperties.CentreOfMass().Z() << endl;

	// matrix of inertia(관성 행렬) 출력
	gp_Mat inertiaMatrix = volumeProperties.MatrixOfInertia();
	cout << "matrix of inertia(관성 행렬) : " << endl;
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cout << inertiaMatrix(i, j) << "\t\t";
		}
		cout << endl;
	}
	return 0;
}