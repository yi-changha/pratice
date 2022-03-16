#include "Viewer.h"

// OCC
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepTools.hxx>

int main(int argc, char** argv)
{
	Viewer vout(50, 50, 500, 500);
	TopoDS_Shape sh;

	if (argc > 1) {
		BRep_Builder bbuilder;


		if (BRepTools::Read(sh, argv[1], bbuilder)) {
			return 1;
		}
	}

	/*
	// Make shape.
	BRepPrimAPI_MakeBox mkBox(10, 20, 30);
	mkBox.Build();
	//
	if (!mkBox.IsDone())
		return 1;
	//
	const TopoDS_Shape& shape = mkBox.Shape();

	// Visualize.
	vout << shape;
	*/
	vout << BRepPrimAPI_MakeBox(10, 20, 30)
		<< sh;

	vout.StartMessageLoop();
	return 0;
}