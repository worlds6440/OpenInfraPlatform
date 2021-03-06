/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcExternalSpatialElementTypeEnum = ENUMERATION OF	(EXTERNAL	,EXTERNAL_EARTH	,EXTERNAL_WATER	,EXTERNAL_FIRE	,USERDEFINED	,NOTDEFIEND);
		class IfcExternalSpatialElementTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcExternalSpatialElementTypeEnumEnum
			{
				ENUM_EXTERNAL,
				ENUM_EXTERNAL_EARTH,
				ENUM_EXTERNAL_WATER,
				ENUM_EXTERNAL_FIRE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFIEND
			};

			IfcExternalSpatialElementTypeEnum();
			IfcExternalSpatialElementTypeEnum( IfcExternalSpatialElementTypeEnumEnum e ) { m_enum = e; }
			~IfcExternalSpatialElementTypeEnum();
			virtual const char* classname() const { return "IfcExternalSpatialElementTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcExternalSpatialElementTypeEnum> readStepData( std::string& arg );
			IfcExternalSpatialElementTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

