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

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcTimeSeriesDataTypeEnum = ENUMERATION OF	(CONTINUOUS	,DISCRETE	,DISCRETEBINARY	,PIECEWISEBINARY	,PIECEWISECONSTANT	,PIECEWISECONTINUOUS	,NOTDEFINED);
		class IfcTimeSeriesDataTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcTimeSeriesDataTypeEnumEnum
			{
				ENUM_CONTINUOUS,
				ENUM_DISCRETE,
				ENUM_DISCRETEBINARY,
				ENUM_PIECEWISEBINARY,
				ENUM_PIECEWISECONSTANT,
				ENUM_PIECEWISECONTINUOUS,
				ENUM_NOTDEFINED
			};

			IfcTimeSeriesDataTypeEnum();
			IfcTimeSeriesDataTypeEnum( IfcTimeSeriesDataTypeEnumEnum e ) { m_enum = e; }
			~IfcTimeSeriesDataTypeEnum();
			virtual const char* classname() const { return "IfcTimeSeriesDataTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTimeSeriesDataTypeEnum> readStepData( std::string& arg );
			IfcTimeSeriesDataTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

