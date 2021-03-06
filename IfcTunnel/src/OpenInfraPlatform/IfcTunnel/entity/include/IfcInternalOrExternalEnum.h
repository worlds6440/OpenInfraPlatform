/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcInternalOrExternalEnum = ENUMERATION OF	(INTERNAL	,EXTERNAL	,EXTERNAL_EARTH	,EXTERNAL_WATER	,EXTERNAL_FIRE	,NOTDEFINED);
		class IfcInternalOrExternalEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcInternalOrExternalEnumEnum
			{
				ENUM_INTERNAL,
				ENUM_EXTERNAL,
				ENUM_EXTERNAL_EARTH,
				ENUM_EXTERNAL_WATER,
				ENUM_EXTERNAL_FIRE,
				ENUM_NOTDEFINED
			};

			IfcInternalOrExternalEnum();
			IfcInternalOrExternalEnum( IfcInternalOrExternalEnumEnum e ) { m_enum = e; }
			~IfcInternalOrExternalEnum();
			virtual const char* classname() const { return "IfcInternalOrExternalEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcInternalOrExternalEnum> readStepData( std::string& arg );
			IfcInternalOrExternalEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

