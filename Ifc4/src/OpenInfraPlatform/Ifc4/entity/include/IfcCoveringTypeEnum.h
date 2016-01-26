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
		// TYPE IfcCoveringTypeEnum = ENUMERATION OF	(CEILING	,FLOORING	,CLADDING	,ROOFING	,MOLDING	,SKIRTINGBOARD	,INSULATION	,MEMBRANE	,SLEEVING	,WRAPPING	,USERDEFINED	,NOTDEFINED);
		class IfcCoveringTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcCoveringTypeEnumEnum
			{
				ENUM_CEILING,
				ENUM_FLOORING,
				ENUM_CLADDING,
				ENUM_ROOFING,
				ENUM_MOLDING,
				ENUM_SKIRTINGBOARD,
				ENUM_INSULATION,
				ENUM_MEMBRANE,
				ENUM_SLEEVING,
				ENUM_WRAPPING,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCoveringTypeEnum();
			IfcCoveringTypeEnum( IfcCoveringTypeEnumEnum e ) { m_enum = e; }
			~IfcCoveringTypeEnum();
			virtual const char* classname() const { return "IfcCoveringTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCoveringTypeEnum> readStepData( std::string& arg );
			IfcCoveringTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

