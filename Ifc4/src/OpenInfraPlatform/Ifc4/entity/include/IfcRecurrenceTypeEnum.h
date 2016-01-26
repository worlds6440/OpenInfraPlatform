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

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcRecurrenceTypeEnum = ENUMERATION OF	(DAILY	,WEEKLY	,MONTHLY_BY_DAY_OF_MONTH	,MONTHLY_BY_POSITION	,BY_DAY_COUNT	,BY_WEEKDAY_COUNT	,YEARLY_BY_DAY_OF_MONTH	,YEARLY_BY_POSITION);
		class IfcRecurrenceTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcRecurrenceTypeEnumEnum
			{
				ENUM_DAILY,
				ENUM_WEEKLY,
				ENUM_MONTHLY_BY_DAY_OF_MONTH,
				ENUM_MONTHLY_BY_POSITION,
				ENUM_BY_DAY_COUNT,
				ENUM_BY_WEEKDAY_COUNT,
				ENUM_YEARLY_BY_DAY_OF_MONTH,
				ENUM_YEARLY_BY_POSITION
			};

			IfcRecurrenceTypeEnum();
			IfcRecurrenceTypeEnum( IfcRecurrenceTypeEnumEnum e ) { m_enum = e; }
			~IfcRecurrenceTypeEnum();
			virtual const char* classname() const { return "IfcRecurrenceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRecurrenceTypeEnum> readStepData( std::string& arg );
			IfcRecurrenceTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

