/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcAirToAirHeatRecoveryTypeEnum = ENUMERATION OF	(FIXEDPLATECOUNTERFLOWEXCHANGER	,FIXEDPLATECROSSFLOWEXCHANGER	,FIXEDPLATEPARALLELFLOWEXCHANGER	,ROTARYWHEEL	,RUNAROUNDCOILLOOP	,HEATPIPE	,TWINTOWERENTHALPYRECOVERYLOOPS	,THERMOSIPHONSEALEDTUBEHEATEXCHANGERS	,THERMOSIPHONCOILTYPEHEATEXCHANGERS	,USERDEFINED	,NOTDEFINED);
		class IfcAirToAirHeatRecoveryTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcAirToAirHeatRecoveryTypeEnumEnum
			{
				ENUM_FIXEDPLATECOUNTERFLOWEXCHANGER,
				ENUM_FIXEDPLATECROSSFLOWEXCHANGER,
				ENUM_FIXEDPLATEPARALLELFLOWEXCHANGER,
				ENUM_ROTARYWHEEL,
				ENUM_RUNAROUNDCOILLOOP,
				ENUM_HEATPIPE,
				ENUM_TWINTOWERENTHALPYRECOVERYLOOPS,
				ENUM_THERMOSIPHONSEALEDTUBEHEATEXCHANGERS,
				ENUM_THERMOSIPHONCOILTYPEHEATEXCHANGERS,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcAirToAirHeatRecoveryTypeEnum();
			IfcAirToAirHeatRecoveryTypeEnum( IfcAirToAirHeatRecoveryTypeEnumEnum e ) { m_enum = e; }
			~IfcAirToAirHeatRecoveryTypeEnum();
			virtual const char* classname() const { return "IfcAirToAirHeatRecoveryTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAirToAirHeatRecoveryTypeEnum> readStepData( std::string& arg );
			IfcAirToAirHeatRecoveryTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

