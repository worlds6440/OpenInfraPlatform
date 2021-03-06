/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/IfcBridgeException.h"
#include "include/IfcCableCarrierSegmentTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcCableCarrierSegmentTypeEnum 
		IfcCableCarrierSegmentTypeEnum::IfcCableCarrierSegmentTypeEnum() {}
		IfcCableCarrierSegmentTypeEnum::~IfcCableCarrierSegmentTypeEnum() {}
		void IfcCableCarrierSegmentTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCABLECARRIERSEGMENTTYPEENUM("; }
			if( m_enum == ENUM_CABLELADDERSEGMENT )
			{
				stream << ".CABLELADDERSEGMENT.";
			}
			else if( m_enum == ENUM_CABLETRAYSEGMENT )
			{
				stream << ".CABLETRAYSEGMENT.";
			}
			else if( m_enum == ENUM_CABLETRUNKINGSEGMENT )
			{
				stream << ".CABLETRUNKINGSEGMENT.";
			}
			else if( m_enum == ENUM_CONDUITSEGMENT )
			{
				stream << ".CONDUITSEGMENT.";
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
		shared_ptr<IfcCableCarrierSegmentTypeEnum> IfcCableCarrierSegmentTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCableCarrierSegmentTypeEnum>(); }
			shared_ptr<IfcCableCarrierSegmentTypeEnum> type_object( new IfcCableCarrierSegmentTypeEnum() );
			if( _stricmp( arg.c_str(), ".CABLELADDERSEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierSegmentTypeEnum::ENUM_CABLELADDERSEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".CABLETRAYSEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierSegmentTypeEnum::ENUM_CABLETRAYSEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".CABLETRUNKINGSEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierSegmentTypeEnum::ENUM_CABLETRUNKINGSEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".CONDUITSEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierSegmentTypeEnum::ENUM_CONDUITSEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierSegmentTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierSegmentTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
