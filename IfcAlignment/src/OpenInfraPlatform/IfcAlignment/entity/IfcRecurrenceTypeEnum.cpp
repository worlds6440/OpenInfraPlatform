/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcRecurrenceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcRecurrenceTypeEnum 
		IfcRecurrenceTypeEnum::IfcRecurrenceTypeEnum() {}
		IfcRecurrenceTypeEnum::~IfcRecurrenceTypeEnum() {}
		void IfcRecurrenceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCRECURRENCETYPEENUM("; }
			if( m_enum == ENUM_DAILY )
			{
				stream << ".DAILY.";
			}
			else if( m_enum == ENUM_WEEKLY )
			{
				stream << ".WEEKLY.";
			}
			else if( m_enum == ENUM_MONTHLY_BY_DAY_OF_MONTH )
			{
				stream << ".MONTHLY_BY_DAY_OF_MONTH.";
			}
			else if( m_enum == ENUM_MONTHLY_BY_POSITION )
			{
				stream << ".MONTHLY_BY_POSITION.";
			}
			else if( m_enum == ENUM_BY_DAY_COUNT )
			{
				stream << ".BY_DAY_COUNT.";
			}
			else if( m_enum == ENUM_BY_WEEKDAY_COUNT )
			{
				stream << ".BY_WEEKDAY_COUNT.";
			}
			else if( m_enum == ENUM_YEARLY_BY_DAY_OF_MONTH )
			{
				stream << ".YEARLY_BY_DAY_OF_MONTH.";
			}
			else if( m_enum == ENUM_YEARLY_BY_POSITION )
			{
				stream << ".YEARLY_BY_POSITION.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcRecurrenceTypeEnum> IfcRecurrenceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcRecurrenceTypeEnum>(); }
			shared_ptr<IfcRecurrenceTypeEnum> type_object( new IfcRecurrenceTypeEnum() );
			if( _stricmp( arg.c_str(), ".DAILY." ) == 0 )
			{
				type_object->m_enum = IfcRecurrenceTypeEnum::ENUM_DAILY;
			}
			else if( _stricmp( arg.c_str(), ".WEEKLY." ) == 0 )
			{
				type_object->m_enum = IfcRecurrenceTypeEnum::ENUM_WEEKLY;
			}
			else if( _stricmp( arg.c_str(), ".MONTHLY_BY_DAY_OF_MONTH." ) == 0 )
			{
				type_object->m_enum = IfcRecurrenceTypeEnum::ENUM_MONTHLY_BY_DAY_OF_MONTH;
			}
			else if( _stricmp( arg.c_str(), ".MONTHLY_BY_POSITION." ) == 0 )
			{
				type_object->m_enum = IfcRecurrenceTypeEnum::ENUM_MONTHLY_BY_POSITION;
			}
			else if( _stricmp( arg.c_str(), ".BY_DAY_COUNT." ) == 0 )
			{
				type_object->m_enum = IfcRecurrenceTypeEnum::ENUM_BY_DAY_COUNT;
			}
			else if( _stricmp( arg.c_str(), ".BY_WEEKDAY_COUNT." ) == 0 )
			{
				type_object->m_enum = IfcRecurrenceTypeEnum::ENUM_BY_WEEKDAY_COUNT;
			}
			else if( _stricmp( arg.c_str(), ".YEARLY_BY_DAY_OF_MONTH." ) == 0 )
			{
				type_object->m_enum = IfcRecurrenceTypeEnum::ENUM_YEARLY_BY_DAY_OF_MONTH;
			}
			else if( _stricmp( arg.c_str(), ".YEARLY_BY_POSITION." ) == 0 )
			{
				type_object->m_enum = IfcRecurrenceTypeEnum::ENUM_YEARLY_BY_POSITION;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
