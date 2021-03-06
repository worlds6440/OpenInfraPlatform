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
		// TYPE IfcDistributionSystemEnum = ENUMERATION OF	(AIRCONDITIONING	,AUDIOVISUAL	,CHEMICAL	,CHILLEDWATER	,COMMUNICATION	,COMPRESSEDAIR	,CONDENSERWATER	,CONTROL	,CONVEYING	,DATA	,DISPOSAL	,DOMESTICCOLDWATER	,DOMESTICHOTWATER	,DRAINAGE	,EARTHING	,ELECTRICAL	,ELECTROACOUSTIC	,EXHAUST	,FIREPROTECTION	,FUEL	,GAS	,HAZARDOUS	,HEATING	,LIGHTING	,LIGHTNINGPROTECTION	,MUNICIPALSOLIDWASTE	,OIL	,OPERATIONAL	,POWERGENERATION	,RAINWATER	,REFRIGERATION	,SECURITY	,SEWAGE	,SIGNAL	,STORMWATER	,TELEPHONE	,TV	,VACUUM	,VENT	,VENTILATION	,WASTEWATER	,WATERSUPPLY	,USERDEFINED	,NOTDEFINED);
		class IfcDistributionSystemEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcDistributionSystemEnumEnum
			{
				ENUM_AIRCONDITIONING,
				ENUM_AUDIOVISUAL,
				ENUM_CHEMICAL,
				ENUM_CHILLEDWATER,
				ENUM_COMMUNICATION,
				ENUM_COMPRESSEDAIR,
				ENUM_CONDENSERWATER,
				ENUM_CONTROL,
				ENUM_CONVEYING,
				ENUM_DATA,
				ENUM_DISPOSAL,
				ENUM_DOMESTICCOLDWATER,
				ENUM_DOMESTICHOTWATER,
				ENUM_DRAINAGE,
				ENUM_EARTHING,
				ENUM_ELECTRICAL,
				ENUM_ELECTROACOUSTIC,
				ENUM_EXHAUST,
				ENUM_FIREPROTECTION,
				ENUM_FUEL,
				ENUM_GAS,
				ENUM_HAZARDOUS,
				ENUM_HEATING,
				ENUM_LIGHTING,
				ENUM_LIGHTNINGPROTECTION,
				ENUM_MUNICIPALSOLIDWASTE,
				ENUM_OIL,
				ENUM_OPERATIONAL,
				ENUM_POWERGENERATION,
				ENUM_RAINWATER,
				ENUM_REFRIGERATION,
				ENUM_SECURITY,
				ENUM_SEWAGE,
				ENUM_SIGNAL,
				ENUM_STORMWATER,
				ENUM_TELEPHONE,
				ENUM_TV,
				ENUM_VACUUM,
				ENUM_VENT,
				ENUM_VENTILATION,
				ENUM_WASTEWATER,
				ENUM_WATERSUPPLY,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDistributionSystemEnum();
			IfcDistributionSystemEnum( IfcDistributionSystemEnumEnum e ) { m_enum = e; }
			~IfcDistributionSystemEnum();
			virtual const char* classname() const { return "IfcDistributionSystemEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDistributionSystemEnum> readStepData( std::string& arg );
			IfcDistributionSystemEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

