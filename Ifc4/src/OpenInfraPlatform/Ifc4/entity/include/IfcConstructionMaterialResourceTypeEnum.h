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
		// TYPE IfcConstructionMaterialResourceTypeEnum = ENUMERATION OF	(AGGREGATES	,CONCRETE	,DRYWALL	,FUEL	,GYPSUM	,MASONRY	,METAL	,PLASTIC	,WOOD	,NOTDEFINED	,USERDEFINED);
		class IfcConstructionMaterialResourceTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcConstructionMaterialResourceTypeEnumEnum
			{
				ENUM_AGGREGATES,
				ENUM_CONCRETE,
				ENUM_DRYWALL,
				ENUM_FUEL,
				ENUM_GYPSUM,
				ENUM_MASONRY,
				ENUM_METAL,
				ENUM_PLASTIC,
				ENUM_WOOD,
				ENUM_NOTDEFINED,
				ENUM_USERDEFINED
			};

			IfcConstructionMaterialResourceTypeEnum();
			IfcConstructionMaterialResourceTypeEnum( IfcConstructionMaterialResourceTypeEnumEnum e ) { m_enum = e; }
			~IfcConstructionMaterialResourceTypeEnum();
			virtual const char* classname() const { return "IfcConstructionMaterialResourceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcConstructionMaterialResourceTypeEnum> readStepData( std::string& arg );
			IfcConstructionMaterialResourceTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

