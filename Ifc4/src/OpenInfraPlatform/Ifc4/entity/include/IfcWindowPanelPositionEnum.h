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
		// TYPE IfcWindowPanelPositionEnum = ENUMERATION OF	(LEFT	,MIDDLE	,RIGHT	,BOTTOM	,TOP	,NOTDEFINED);
		class IfcWindowPanelPositionEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcWindowPanelPositionEnumEnum
			{
				ENUM_LEFT,
				ENUM_MIDDLE,
				ENUM_RIGHT,
				ENUM_BOTTOM,
				ENUM_TOP,
				ENUM_NOTDEFINED
			};

			IfcWindowPanelPositionEnum();
			IfcWindowPanelPositionEnum( IfcWindowPanelPositionEnumEnum e ) { m_enum = e; }
			~IfcWindowPanelPositionEnum();
			virtual const char* classname() const { return "IfcWindowPanelPositionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWindowPanelPositionEnum> readStepData( std::string& arg );
			IfcWindowPanelPositionEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

