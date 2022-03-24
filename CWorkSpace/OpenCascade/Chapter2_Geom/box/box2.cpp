#include "Viewer.h"

// OCC

#include "Viewer.h"

// OCC
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepTools.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <STEPControl_Writer.hxx>
#include <StlAPI_Writer.hxx>
#include <VrmlAPI_Writer.hxx>


int main(int argc, char** argv)
{
	Viewer vout(50, 50, 500, 500);
	TopoDS_Shape Box = BRepPrimAPI_MakeBox(3.0, 4.0, 5.0).Shape();
	TopoDS_Shape Box2 = BRepPrimAPI_MakeBox(-3.0, -4.0, -5.0).Shape();
	BRepMesh_IncrementalMesh(Box, 1.0, Standard_True);

	vout << Box << Box2;

	vout.StartMessageLoop();

	StlAPI_Writer StlWriter;
	StlWriter.Write(Box, "Box.stl");
	StlWriter.Write(Box2, "Box2.stl");
	VrmlAPI_Writer VrmlWriter;
	VrmlWriter.Write(Box, "Box.wrl");
	VrmlWriter.Write(Box2, "Box2.wrl");
	STEPControl_Writer StepWriter;
	StepWriter.Transfer(Box, STEPControl_AsIs);
	StepWriter.Write("Box.stp");
	StepWriter.Transfer(Box2, STEPControl_AsIs);
	StepWriter.Write("Box2.stp");

	return 0;
}