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
#include "IfcSimpleValue.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcTime = STRING;
		class IfcTime : public IfcSimpleValue, public IfcRoadType
		{
		public:
			IfcTime();
			IfcTime( std::string value );
			~IfcTime();
			virtual const char* classname() const { return "IfcTime"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTime> readStepData( std::string& arg );
			std::string m_value;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

