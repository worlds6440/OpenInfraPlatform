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
#include "IfcSegmentIndexSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcLineIndex = LIST [2:?] OF IfcPositiveInteger;
		class IfcLineIndex : public IfcSegmentIndexSelect, public Ifc4Type
		{
		public:
			IfcLineIndex();
			~IfcLineIndex();
			virtual const char* classname() const { return "IfcLineIndex"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLineIndex> readStepData( std::string& arg );
			std::vector<int> m_vec;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

