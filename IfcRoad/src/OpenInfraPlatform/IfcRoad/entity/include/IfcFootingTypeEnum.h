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
		// TYPE IfcFootingTypeEnum = ENUMERATION OF	(CAISSON_FOUNDATION	,FOOTING_BEAM	,PAD_FOOTING	,PILE_CAP	,STRIP_FOOTING	,USERDEFINED	,NOTDEFINED);
		class IfcFootingTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcFootingTypeEnumEnum
			{
				ENUM_CAISSON_FOUNDATION,
				ENUM_FOOTING_BEAM,
				ENUM_PAD_FOOTING,
				ENUM_PILE_CAP,
				ENUM_STRIP_FOOTING,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcFootingTypeEnum();
			IfcFootingTypeEnum( IfcFootingTypeEnumEnum e ) { m_enum = e; }
			~IfcFootingTypeEnum();
			virtual const char* classname() const { return "IfcFootingTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFootingTypeEnum> readStepData( std::string& arg );
			IfcFootingTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

