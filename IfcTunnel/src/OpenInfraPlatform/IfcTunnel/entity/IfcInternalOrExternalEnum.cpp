/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../model/IfcTunnelException.h"
#include "include/IfcInternalOrExternalEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcInternalOrExternalEnum 
		IfcInternalOrExternalEnum::IfcInternalOrExternalEnum() {}
		IfcInternalOrExternalEnum::~IfcInternalOrExternalEnum() {}
		void IfcInternalOrExternalEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCINTERNALOREXTERNALENUM("; }
			if( m_enum == ENUM_INTERNAL )
			{
				stream << ".INTERNAL.";
			}
			else if( m_enum == ENUM_EXTERNAL )
			{
				stream << ".EXTERNAL.";
			}
			else if( m_enum == ENUM_EXTERNAL_EARTH )
			{
				stream << ".EXTERNAL_EARTH.";
			}
			else if( m_enum == ENUM_EXTERNAL_WATER )
			{
				stream << ".EXTERNAL_WATER.";
			}
			else if( m_enum == ENUM_EXTERNAL_FIRE )
			{
				stream << ".EXTERNAL_FIRE.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcInternalOrExternalEnum> IfcInternalOrExternalEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcInternalOrExternalEnum>(); }
			shared_ptr<IfcInternalOrExternalEnum> type_object( new IfcInternalOrExternalEnum() );
			if( _stricmp( arg.c_str(), ".INTERNAL." ) == 0 )
			{
				type_object->m_enum = IfcInternalOrExternalEnum::ENUM_INTERNAL;
			}
			else if( _stricmp( arg.c_str(), ".EXTERNAL." ) == 0 )
			{
				type_object->m_enum = IfcInternalOrExternalEnum::ENUM_EXTERNAL;
			}
			else if( _stricmp( arg.c_str(), ".EXTERNAL_EARTH." ) == 0 )
			{
				type_object->m_enum = IfcInternalOrExternalEnum::ENUM_EXTERNAL_EARTH;
			}
			else if( _stricmp( arg.c_str(), ".EXTERNAL_WATER." ) == 0 )
			{
				type_object->m_enum = IfcInternalOrExternalEnum::ENUM_EXTERNAL_WATER;
			}
			else if( _stricmp( arg.c_str(), ".EXTERNAL_FIRE." ) == 0 )
			{
				type_object->m_enum = IfcInternalOrExternalEnum::ENUM_EXTERNAL_FIRE;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcInternalOrExternalEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
