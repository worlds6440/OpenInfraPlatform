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
		// TYPE IfcProjectedOrTrueLengthEnum = ENUMERATION OF	(PROJECTED_LENGTH	,TRUE_LENGTH);
		class IfcProjectedOrTrueLengthEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcProjectedOrTrueLengthEnumEnum
			{
				ENUM_PROJECTED_LENGTH,
				ENUM_TRUE_LENGTH
			};

			IfcProjectedOrTrueLengthEnum();
			IfcProjectedOrTrueLengthEnum( IfcProjectedOrTrueLengthEnumEnum e ) { m_enum = e; }
			~IfcProjectedOrTrueLengthEnum();
			virtual const char* classname() const { return "IfcProjectedOrTrueLengthEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProjectedOrTrueLengthEnum> readStepData( std::string& arg );
			IfcProjectedOrTrueLengthEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

