// Open CASCADE 튜토리얼 by 이창하
// 2022.03.22
#ifndef WRITECOORDINATESTOFILE_HPP
#define WRITECOORDINATESTOFILE_HPP 

#include "TColgp_Array1OfPnt.hxx"
#include <fstream>
#include <string>

namespace WriteCoordinatesToFile
{
	void writeCoordinatesToFile(std::string fileName, const TColgp_Array1OfPnt& points) {
		std::ofstream file;
		file.open(fileName.c_str());
		for (Standard_Integer i = points.Lower(); i <= points.Upper(); i++)
		{
			file << points.Value(i).X() << " " << points.Value(i).Y() << " " << points.Value(i).Z() << std::endl;
		}
	}
}
#endif