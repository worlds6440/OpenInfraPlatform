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
		// TYPE IfcDuctSilencerTypeEnum = ENUMERATION OF	(FLATOVAL	,RECTANGULAR	,ROUND	,USERDEFINED	,NOTDEFINED);
		class IfcDuctSilencerTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcDuctSilencerTypeEnumEnum
			{
				ENUM_FLATOVAL,
				ENUM_RECTANGULAR,
				ENUM_ROUND,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDuctSilencerTypeEnum();
			IfcDuctSilencerTypeEnum( IfcDuctSilencerTypeEnumEnum e ) { m_enum = e; }
			~IfcDuctSilencerTypeEnum();
			virtual const char* classname() const { return "IfcDuctSilencerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDuctSilencerTypeEnum> readStepData( std::string& arg );
			IfcDuctSilencerTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

