/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcAirTerminalBoxTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcAirTerminalBoxTypeEnum 
		IfcAirTerminalBoxTypeEnum::IfcAirTerminalBoxTypeEnum() {}
		IfcAirTerminalBoxTypeEnum::~IfcAirTerminalBoxTypeEnum() {}
		void IfcAirTerminalBoxTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCAIRTERMINALBOXTYPEENUM("; }
			if( m_enum == ENUM_CONSTANTFLOW )
			{
				stream << ".CONSTANTFLOW.";
			}
			else if( m_enum == ENUM_VARIABLEFLOWPRESSUREDEPENDANT )
			{
				stream << ".VARIABLEFLOWPRESSUREDEPENDANT.";
			}
			else if( m_enum == ENUM_VARIABLEFLOWPRESSUREINDEPENDANT )
			{
				stream << ".VARIABLEFLOWPRESSUREINDEPENDANT.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcAirTerminalBoxTypeEnum> IfcAirTerminalBoxTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcAirTerminalBoxTypeEnum>(); }
			shared_ptr<IfcAirTerminalBoxTypeEnum> type_object( new IfcAirTerminalBoxTypeEnum() );
			if( _stricmp( arg.c_str(), ".CONSTANTFLOW." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalBoxTypeEnum::ENUM_CONSTANTFLOW;
			}
			else if( _stricmp( arg.c_str(), ".VARIABLEFLOWPRESSUREDEPENDANT." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalBoxTypeEnum::ENUM_VARIABLEFLOWPRESSUREDEPENDANT;
			}
			else if( _stricmp( arg.c_str(), ".VARIABLEFLOWPRESSUREINDEPENDANT." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalBoxTypeEnum::ENUM_VARIABLEFLOWPRESSUREINDEPENDANT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalBoxTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAirTerminalBoxTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
