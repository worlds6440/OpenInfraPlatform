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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcConstraint.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcConstraint;
		class IfcLogicalOperatorEnum;
		class IfcObjectiveEnum;
		class IfcLabel;
		//ENTITY
		class IfcObjective : public IfcConstraint
		{
		public:
			IfcObjective();
			IfcObjective( int id );
			~IfcObjective();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcObjective"; }


			// IfcConstraint -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;
			//  shared_ptr<IfcText>							m_Description;				//optional
			//  shared_ptr<IfcConstraintEnum>				m_ConstraintGrade;
			//  shared_ptr<IfcLabel>							m_ConstraintSource;			//optional
			//  shared_ptr<IfcActorSelect>					m_CreatingActor;			//optional
			//  shared_ptr<IfcDateTime>						m_CreationTime;				//optional
			//  shared_ptr<IfcLabel>							m_UserDefinedGrade;			//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;
			//  std::vector<weak_ptr<IfcResourceConstraintRelationship> >	m_PropertiesForConstraint_inverse;

			// IfcObjective -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcConstraint> >		m_BenchmarkValues;			//optional
			shared_ptr<IfcLogicalOperatorEnum>			m_LogicalAggregator;		//optional
			shared_ptr<IfcObjectiveEnum>					m_ObjectiveQualifier;
			shared_ptr<IfcLabel>							m_UserDefinedQualifier;		//optional
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

