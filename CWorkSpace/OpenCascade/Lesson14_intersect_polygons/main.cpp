// Exercise includes
#include "Viewer.h"

#include <Intf_InterferencePolygon2d.hxx>
#include <Intf_Polygon2d.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <Geom_Plane.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>

//---------------------------------------------------------

class SimplePolygon : public Intf_Polygon2d {
public:
	static Handle(Geom_Plane) PLANE;

public:

	SimplePolygon(const std::initializer_list<std::pair<double, double >>& poles) {
		for (const auto& pole : poles)
		{
			gp_Pnt2d P(pole.first, pole.second);
			m_poles.push_back(P);

			myBox.Add(P);
		}
	}

public:
	//! Returns the tolerance of the polygon.
	virtual double DeflectionOverEstimation() const {
		return Precision::Confusion();
	}

	//! Returns the number of Segments in the polyline.
	virtual int NbSegments() const {
		return int(m_poles.size()) - 1;
	}

	//! Returns the points of the segment <Index> in the Polygon.
	virtual void Segment(const int index, gp_Pnt2d& beg, gp_Pnt2d& end) const {
		beg = m_poles[index - 1];
		end = m_poles[index];
	}

public:
	operator TopoDS_Shape()
	{
		BRepBuilderAPI_MakePolygon mkPoly;
		//
		for (const auto& P2d : m_poles)
		{
			mkPoly.Add(PLANE->Value(P2d.X(), P2d.Y()));
		}

		return mkPoly.Shape();
	}

protected:
	std::vector<gp_Pnt2d> m_poles;
};

Handle(Geom_Plane) SimplePolygon::PLANE;

//---------------------------------------------------------


int main(int argc, char** argv)
{
	Viewer vout(50, 50, 500, 500);

	SimplePolygon::PLANE = new Geom_Plane(gp::XOY());

	SimplePolygon	poly0({ {0.0, 0.0}, {1.0, 0.0}, {0.25, 0.75} }),
					poly1({ {0.5, 1.2}, {0.5, -1.0}, {1.0, 3.0} });

	vout << poly0 << poly1;

	Intf_InterferencePolygon2d algo(poly0, poly1);
	const int numPts = algo.NbSectionPoints();

	for (int isol = 1; isol <= numPts; ++isol){
		gp_Pnt2d	sol2d = algo.Pnt2dValue(isol);
		gp_Pnt		sol3d = SimplePolygon::PLANE->Value(sol2d.X(), sol2d.Y());

		vout << BRepBuilderAPI_MakeVertex(sol3d);
	}

	std::cout << "Num. of intersection points: " << numPts << std::endl;

	vout.StartMessageLoop();

	return 0;
}