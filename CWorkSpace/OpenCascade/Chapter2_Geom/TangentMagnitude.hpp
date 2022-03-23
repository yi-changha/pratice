#ifndef _TANGENTMAGNITUDE_HPP_
#define _TANGENTMAGNITUDE_HPP_ 

#include "math_Function.hxx"
#include "Geom_Curve.hxx"

class TangentMagnitude : public math_Function
{
public:
	TangentMagnitude(Handle_Geom_Curve curve);
	virtual ~TangentMagnitude();
	Standard_Boolean Value(Standard_Real X, Standard_Real& F);

	const Handle_Geom_Curve getCurve() const;
	void setCurve(Handle_Geom_Curve curve);


private:
	Handle_Geom_Curve myCurve;
};
#endif