/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universit�t M�nchen
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "SVGExport.h"

void OpenInfraPlatform::Infrastructure::SVGExport::outputToSVG(FILE *fp, buw::HorizontalAlignment2D::Ptr horizontalAlignment)
{
	std::string output = "";
	buw::vector2d start;
	auto he = horizontalAlignment->getAlignmentElementByIndex(0);
	he->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition, &start);
	output += "<g>\n<path d=\"M " + std::to_string(start.x()) + "," + std::to_string(-start.y()) + " ";

	for (int i = 0; i < horizontalAlignment->getAlignmentElementCount(); i++)
	{
		he = horizontalAlignment->getAlignmentElementByIndex(i);

		if (he->getAlignmentType() == buw::eHorizontalAlignmentType::Line)
		{
			buw::vector2d end = he->getEndPosition();
		
			output += "L " + std::to_string(end.x()) + "," + std::to_string(-end.y()) + " ";
		}

		if (he->getAlignmentType() == buw::eHorizontalAlignmentType::Arc)
		{
			buw::vector2d end = he->getEndPosition();
			bool clockwise;
			double radius;

			he->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Clockwise, &clockwise);
			he->genericQuery(OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Radius, &radius);

			output += "A " + std::to_string(radius) + "," + std::to_string(radius) + " 0 0," + std::to_string(clockwise) + " " + std::to_string(end.x()) + "," + std::to_string(-end.y()) + " ";
		}

		if (he->getAlignmentType() == buw::eHorizontalAlignmentType::Clothoid)
		{	
			for (float s = 0.0f; s < 1.0f; s+=0.05f) // use 20 segments to approximate clothoid
			{
				buw::vector2d end = he->getPosition(s);
				output += "L " + std::to_string(end.x()) + "," + std::to_string(-end.y()) + " ";
			}

			buw::vector2d end = he->getEndPosition();

			output += "L " + std::to_string(end.x()) + "," + std::to_string(-end.y()) + " ";
		}
	}

	output += "\">\n</path>\n</g>\n";
	fprintf(fp, output.c_str());
}

void OpenInfraPlatform::Infrastructure::SVGExport::addPath(FILE *fp, const buw::vector2d& a, const buw::vector2d& b, const buw::vector2d& c)
{
	fprintf(fp, "<path d=\"M %f,%f L %f,%f L %f,%f z\"/>\n", a.x(), -a.y(), b.x(), -b.y(), c.x(), -c.y());
}

void OpenInfraPlatform::Infrastructure::SVGExport::convert(
	std::vector<buw::IAlignment3D::Ptr> alignments, 
	OpenInfraPlatform::Infrastructure::DigitalElevationModel::Ptr digitalElevationModel_, 
	const std::string& filename)
{
	FILE *fp = fopen(filename.c_str(), "w");

	if (!fp)
		return;

	fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
	fprintf(fp, "<svg\n");
	fprintf(fp, "xmlns:svg=\"http://www.w3.org/2000/svg\"\n");
	fprintf(fp, "xmlns=\"http://www.w3.org/2000/svg\"\n");
	fprintf(fp, "version=\"1.0\"\n");

	buw::vector3d pmin, pmax, Surfacesmax, Surfacesmin, Alignmentsmin, Alignmentsmax, pnull = { 0, 0, 0 };

	//the following code until the chapter "surfaces" determines the maximal positions of all alignments and surfaces.
	//It is considered if alignments and surfaces were created or not

	if (alignments.size() != 0)
	{
		Alignmentsmin = alignments[0]->getPosition(0);		Alignmentsmax = alignments[0]->getPosition(0);
		for (int i = 0; i < alignments.size(); i++)
		{
			for (double s = alignments[i]->getStartStation(); s < alignments[i]->getEndStation(); s += 1.0)
			{
				auto p = alignments[i]->getPosition(s);
				Alignmentsmin = buw::getMinimizedVector(Alignmentsmin, p);
				Alignmentsmax = buw::getMaximizedVector(Alignmentsmax, p);
			}
		}
	}
	if (digitalElevationModel_->getSurfaceCount() != 0)
	{
		digitalElevationModel_->getSurfacesExtend(Surfacesmin, Surfacesmax);
	}
	if (digitalElevationModel_->getSurfaceCount() != 0 && alignments.size() != 0)
	{
		for (int i = 0; i < 2; i++)
		{
			if (Alignmentsmin[i] < Surfacesmin[i])
			{
				pmin[i] = Alignmentsmin[i];
			}
			else pmin[i] = Surfacesmin[i];
			if (Alignmentsmax[i] > Surfacesmax[i])
			{
				pmax[i] = Alignmentsmax[i];
			}
			else pmax[i] = Surfacesmax[i];
		}
	}
	if (digitalElevationModel_->getSurfaceCount() != 0 && alignments.size() == 0)
	{
		pmin = Surfacesmin;	pmax = Surfacesmax;
	}
	if (digitalElevationModel_->getSurfaceCount() == 0 && alignments.size() != 0)
	{
		pmin = Alignmentsmin;		pmax = Alignmentsmax;
	}
	if (alignments.size() == 0 && digitalElevationModel_->getSurfaceCount() == 0)
	{
		Alignmentsmax = Alignmentsmin = Surfacesmin = Surfacesmax = pnull;
	}
	fprintf(fp, "width=\"1280\" height=\"1024\" viewBox=\" %f %f %f %f \">\n", pmin[0], -pmax[1], abs(pmax[0] - pmin[0]), abs(pmax[1] - pmin[1]));
	fprintf(fp, "<style type=\"text/css\"><![CDATA[.surface{stroke:black;stroke-width:0.001in;fill:orange;}.parcel{stroke:blue;stroke-width:0.01in;fill:none;}.planFeature{stroke:cyan;stroke-width:0.01in;fill:none;}.alignment{stroke:blue;stroke-width:0.02in;fill:none;}.cgpoint{fill:cyan;}.cgpointtext{font-family:'Verdana';font-size:8%;}]]></style>");

	// Surfaces
	for (int i = 0; i < digitalElevationModel_->getSurfaceCount(); i++)
	{
		std::list <int> unsortIDList;
		std::list <int>::const_iterator iter1;
		std::vector <int> missingPointsID;
		fprintf(fp, "<g id=\"Surfaces\">\n");
		fprintf(fp, "<g id=\"SurfaceSet_\" class=\"surface\">\n");
		fprintf(fp, "<g>");
		buw::Surface::Ptr currentSurface = digitalElevationModel_->getSurface(i);
		int x = 0; // first point has always id 0 - old behaviour was differntly from this  //currentSurface.getPoints()[0].id;

		//the following code until "gaps found" searches for gaps in the point ids
		for (int j = 0; j < currentSurface->getTriangeFaces().size(); j++) //create unsortIDList
		{
			for (int f = 0; f < 3; f++)
			{
				unsortIDList.push_back(currentSurface->getTriangeFaces()[j][f]);
			}
		}
		unsortIDList.sort();//sort unsortIDList 
		unsortIDList.unique();//deletes IDs that are more than one time in the list

		//compare every input with a normal numeration and determine by this way the gaps
		for (iter1 = unsortIDList.begin(); iter1 != unsortIDList.end(); iter1++)
		{
			if (*iter1 != x)
			{
				missingPointsID.push_back(x);
				x++;
			}
			x++;
		}//gaps found

		for (int j = 0; j<currentSurface->getTriangeFaces().size(); j++)
		{
			int pointNo1 = currentSurface->getTriangeFaces()[j][0];
			int pointNo2 = currentSurface->getTriangeFaces()[j][1];
			int pointNo3 = currentSurface->getTriangeFaces()[j][2];

			//because of the gap the numeration has been changed, in the following loop this is corrected		
			for (int g = 0; g<missingPointsID.size(); g++)
			{
				if (currentSurface->getTriangeFaces()[j][0] > missingPointsID[g])
				{
					pointNo1--;
				}
				if (currentSurface->getTriangeFaces()[j][1] > missingPointsID[g])
				{
					pointNo2--;
				}
				if (currentSurface->getTriangeFaces()[j][2] > missingPointsID[g])
				{
					pointNo3--;
				}
			}
			buw::vector2d a;
			a.x() = currentSurface->getPoints()[pointNo1][0];
			a.y() = currentSurface->getPoints()[pointNo1][1];
			buw::vector2d b;
			b.x() = currentSurface->getPoints()[pointNo2][0];
			b.y() = currentSurface->getPoints()[pointNo2][1];
			buw::vector2d c;
			c.x() = currentSurface->getPoints()[pointNo3][0];
			c.y() = currentSurface->getPoints()[pointNo3][1];

			addPath(fp, a, b, c);
		}

		fprintf(fp, "</g>\n");
		fprintf(fp, "</g>\n");
		fprintf(fp, "</g>\n");
	}
	
	//Horizontal alignment
	fprintf(fp, "<g id=\"AlignmentSet_\" class=\"alignment\">\n");

	for (int i = 0; i < alignments.size(); i++)
	{
		if (alignments[i]->getType() != buw::e3DAlignmentType::e2DBased)
		{
			continue;
		}

		buw::Alignment2DBased3D::Ptr alignment2D = std::static_pointer_cast<buw::Alignment2DBased3D>(alignments[i]);
		std::string output = "";
		outputToSVG(fp, alignment2D->getHorizontalAlignment());
	}
	fprintf(fp, "</g>\n");
	fprintf(fp, "</svg>\n");

	fclose(fp);
}

OpenInfraPlatform::Infrastructure::SVGExport::SVGExport()
{

}