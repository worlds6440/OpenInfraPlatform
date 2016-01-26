/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"
#include "IfcConnectionPointGeometry.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcLengthMeasure;
		//ENTITY
		class IfcConnectionPointEccentricity : public IfcConnectionPointGeometry
		{
		public:
			IfcConnectionPointEccentricity();
			IfcConnectionPointEccentricity( int id );
			~IfcConnectionPointEccentricity();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcConnectionPointEccentricity"; }


			// IfcConnectionGeometry -----------------------------------------------------------

			// IfcConnectionPointGeometry -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcPointOrVertexPoint>			m_PointOnRelatingElement;
			//  shared_ptr<IfcPointOrVertexPoint>			m_PointOnRelatedElement;	//optional

			// IfcConnectionPointEccentricity -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLengthMeasure>					m_EccentricityInX;			//optional
			shared_ptr<IfcLengthMeasure>					m_EccentricityInY;			//optional
			shared_ptr<IfcLengthMeasure>					m_EccentricityInZ;			//optional
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
