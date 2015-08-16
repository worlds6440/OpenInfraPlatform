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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcLengthMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcNonNegativeLengthMeasure = IfcLengthMeasure;
		class IfcNonNegativeLengthMeasure : public IfcLengthMeasure
		{
		public:
			IfcNonNegativeLengthMeasure();
			~IfcNonNegativeLengthMeasure();
			virtual const char* classname() const { return "IfcNonNegativeLengthMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcNonNegativeLengthMeasure> readStepData( std::string& arg );
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
