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
#include "IfcPreDefinedProperties.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcLengthMeasure;
		class IfcReinforcingBarRoleEnum;
		class IfcSectionProperties;
		class IfcReinforcementBarProperties;
		//ENTITY
		class IfcSectionReinforcementProperties : public IfcPreDefinedProperties
		{
		public:
			IfcSectionReinforcementProperties();
			IfcSectionReinforcementProperties( int id );
			~IfcSectionReinforcementProperties();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSectionReinforcementProperties"; }


			// IfcPropertyAbstraction -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;

			// IfcPreDefinedProperties -----------------------------------------------------------

			// IfcSectionReinforcementProperties -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLengthMeasure>								m_LongitudinalStartPosition;
			shared_ptr<IfcLengthMeasure>								m_LongitudinalEndPosition;
			shared_ptr<IfcLengthMeasure>								m_TransversePosition;		//optional
			shared_ptr<IfcReinforcingBarRoleEnum>					m_ReinforcementRole;
			shared_ptr<IfcSectionProperties>							m_SectionDefinition;
			std::vector<shared_ptr<IfcReinforcementBarProperties> >	m_CrossSectionReinforcementDefinitions;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

