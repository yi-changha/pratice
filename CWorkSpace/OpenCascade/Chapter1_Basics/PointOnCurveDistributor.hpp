// Open CASCADE 튜토리얼 by 이창하
// 2022.03.22
#ifndef POINTONCURVEDISTRIBUTOR_HPP
#define POINTONCURVEDISTRIBUTOR_HPP 

#include "Standard_Integer.hxx"
#include "TColgp_Array1OfPnt.hxx"
#include "ElCLib.hxx"

namespace PointOnCurveDistribution
{
	template<typename CurveType>
	void distributePointsOnCurve(const CurveType& curve, TColgp_Array1OfPnt& pointArray, double lowerLimit, double upperLimit, Standard_Integer resolution)
	{
		double deltaU = (upperLimit - lowerLimit) / (resolution - 1);
		for (Standard_Integer i = 0; i < resolution; i++)
		{
			gp_Pnt pointOnCurve = ElCLib::Value(i * deltaU, curve);
			pointArray.SetValue(i + 1, pointOnCurve);
		}
	}
}
#endif