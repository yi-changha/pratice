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
	cout << "----- OpenCASCADE Ʃ�丮�� by ��â�� -----" << endl
		<< "----- Chapter 0 : Demonstrative example	-----" << endl;

	// �߽��� �������� �� ������ �����ϰ�, 100x100x50 ���� ����
	gp_Pnt pnt1(-50.0, -50.0, 0.0);
	BRepPrimAPI_MakeBox boxMaker(pnt1, 100, 100, 50); // (������, x, y, z)
	TopoDS_Shape box = boxMaker.Shape();


	// �߽��� �������� ���� 25, ���� 50�� �Ǹ��� ����
	BRepPrimAPI_MakeCylinder cylinderMaker(25.0, 50.0);
	TopoDS_Shape cylinder = cylinderMaker.Shape();

	// �ڽ��κ��� �Ǹ�����ŭ�� �ڸ�
	BRepAlgoAPI_Cut cutMaker(box, cylinder);
	TopoDS_Shape cuttedBox = cutMaker.Shape();

	// ������� ���Ͽ� �ۼ���.
	STEPControl_Writer writer;
	writer.Transfer(cuttedBox, STEPControl_AsIs); // STEP�𵨷� ��ȯ(����, �� Ÿ��)
	writer.Write("cuttedBox.stp");

	cout << "����� �ڽ��� cuttedBox.stp ���Ϸ� ����Ǿ����ϴ�." << endl;

	// ������ ������ ü�� Ư�� ���
	GProp_GProps volumeProperties; // �������� ��ü, 3D�������� �������� ���� Ư���� ����ϱ� ���� ����.
	BRepGProp::VolumeProperties(cuttedBox, volumeProperties); // �������� Ư�� ���(����, GProp_GProps

	// �� ���� ���
	cout << setprecision(14) << "���� ���Ǵ� " << volumeProperties.Mass() << endl;

	// �����߽� ���
	cout << "���� �߽��� " << volumeProperties.CentreOfMass().X() << " "
		<< volumeProperties.CentreOfMass().Y()<< volumeProperties.CentreOfMass().Z() << endl;

	// matrix of inertia(���� ���) ���
	gp_Mat inertiaMatrix = volumeProperties.MatrixOfInertia();
	cout << "matrix of inertia(���� ���) : " << endl;
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cout << inertiaMatrix(i, j) << "\t\t";
		}
		cout << endl;
	}
	return 0;
}