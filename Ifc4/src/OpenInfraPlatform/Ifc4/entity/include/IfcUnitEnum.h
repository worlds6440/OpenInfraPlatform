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
		// TYPE IfcUnitEnum = ENUMERATION OF	(ABSORBEDDOSEUNIT	,AMOUNTOFSUBSTANCEUNIT	,AREAUNIT	,DOSEEQUIVALENTUNIT	,ELECTRICCAPACITANCEUNIT	,ELECTRICCHARGEUNIT	,ELECTRICCONDUCTANCEUNIT	,ELECTRICCURRENTUNIT	,ELECTRICRESISTANCEUNIT	,ELECTRICVOLTAGEUNIT	,ENERGYUNIT	,FORCEUNIT	,FREQUENCYUNIT	,ILLUMINANCEUNIT	,INDUCTANCEUNIT	,LENGTHUNIT	,LUMINOUSFLUXUNIT	,LUMINOUSINTENSITYUNIT	,MAGNETICFLUXDENSITYUNIT	,MAGNETICFLUXUNIT	,MASSUNIT	,PLANEANGLEUNIT	,POWERUNIT	,PRESSUREUNIT	,RADIOACTIVITYUNIT	,SOLIDANGLEUNIT	,THERMODYNAMICTEMPERATUREUNIT	,TIMEUNIT	,VOLUMEUNIT	,USERDEFINED);
		class IfcUnitEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcUnitEnumEnum
			{
				ENUM_ABSORBEDDOSEUNIT,
				ENUM_AMOUNTOFSUBSTANCEUNIT,
				ENUM_AREAUNIT,
				ENUM_DOSEEQUIVALENTUNIT,
				ENUM_ELECTRICCAPACITANCEUNIT,
				ENUM_ELECTRICCHARGEUNIT,
				ENUM_ELECTRICCONDUCTANCEUNIT,
				ENUM_ELECTRICCURRENTUNIT,
				ENUM_ELECTRICRESISTANCEUNIT,
				ENUM_ELECTRICVOLTAGEUNIT,
				ENUM_ENERGYUNIT,
				ENUM_FORCEUNIT,
				ENUM_FREQUENCYUNIT,
				ENUM_ILLUMINANCEUNIT,
				ENUM_INDUCTANCEUNIT,
				ENUM_LENGTHUNIT,
				ENUM_LUMINOUSFLUXUNIT,
				ENUM_LUMINOUSINTENSITYUNIT,
				ENUM_MAGNETICFLUXDENSITYUNIT,
				ENUM_MAGNETICFLUXUNIT,
				ENUM_MASSUNIT,
				ENUM_PLANEANGLEUNIT,
				ENUM_POWERUNIT,
				ENUM_PRESSUREUNIT,
				ENUM_RADIOACTIVITYUNIT,
				ENUM_SOLIDANGLEUNIT,
				ENUM_THERMODYNAMICTEMPERATUREUNIT,
				ENUM_TIMEUNIT,
				ENUM_VOLUMEUNIT,
				ENUM_USERDEFINED
			};

			IfcUnitEnum();
			IfcUnitEnum( IfcUnitEnumEnum e ) { m_enum = e; }
			~IfcUnitEnum();
			virtual const char* classname() const { return "IfcUnitEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcUnitEnum> readStepData( std::string& arg );
			IfcUnitEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

