/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcSystemFurnitureElementTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcSystemFurnitureElementTypeEnum 
		IfcSystemFurnitureElementTypeEnum::IfcSystemFurnitureElementTypeEnum() {}
		IfcSystemFurnitureElementTypeEnum::~IfcSystemFurnitureElementTypeEnum() {}
		void IfcSystemFurnitureElementTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSYSTEMFURNITUREELEMENTTYPEENUM("; }
			if( m_enum == ENUM_PANEL )
			{
				stream << ".PANEL.";
			}
			else if( m_enum == ENUM_WORKSURFACE )
			{
				stream << ".WORKSURFACE.";
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
		shared_ptr<IfcSystemFurnitureElementTypeEnum> IfcSystemFurnitureElementTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSystemFurnitureElementTypeEnum>(); }
			shared_ptr<IfcSystemFurnitureElementTypeEnum> type_object( new IfcSystemFurnitureElementTypeEnum() );
			if( _stricmp( arg.c_str(), ".PANEL." ) == 0 )
			{
				type_object->m_enum = IfcSystemFurnitureElementTypeEnum::ENUM_PANEL;
			}
			else if( _stricmp( arg.c_str(), ".WORKSURFACE." ) == 0 )
			{
				type_object->m_enum = IfcSystemFurnitureElementTypeEnum::ENUM_WORKSURFACE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSystemFurnitureElementTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSystemFurnitureElementTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
