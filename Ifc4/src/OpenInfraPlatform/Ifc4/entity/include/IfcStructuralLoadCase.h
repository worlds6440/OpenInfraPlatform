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
#include "IfcStructuralLoadGroup.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcRatioMeasure;
		//ENTITY
		class IfcStructuralLoadCase : public IfcStructuralLoadGroup
		{
		public:
			IfcStructuralLoadCase();
			IfcStructuralLoadCase( int id );
			~IfcStructuralLoadCase();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcStructuralLoadCase"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcObjectDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssigns> >		m_HasAssignments_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >			m_Nests_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >			m_IsNestedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDeclares> >		m_HasContext_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >		m_IsDecomposedBy_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >		m_Decomposes_inverse;
			//  std::vector<weak_ptr<IfcRelAssociates> >		m_HasAssociations_inverse;

			// IfcObject -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_ObjectType;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >	m_IsDeclaredBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >	m_Declares_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByType> >	m_IsTypedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByProperties> >	m_IsDefinedBy_inverse;

			// IfcGroup -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssignsToGroup> >	m_IsGroupedBy_inverse;

			// IfcStructuralLoadGroup -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLoadGroupTypeEnum>				m_PredefinedType;
			//  shared_ptr<IfcActionTypeEnum>				m_ActionType;
			//  shared_ptr<IfcActionSourceTypeEnum>			m_ActionSource;
			//  shared_ptr<IfcRatioMeasure>					m_Coefficient;				//optional
			//  shared_ptr<IfcLabel>							m_Purpose;					//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcStructuralResultGroup> >	m_SourceOfResultGroup_inverse;
			//  std::vector<weak_ptr<IfcStructuralAnalysisModel> >	m_LoadGroupFor_inverse;

			// IfcStructuralLoadCase -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcRatioMeasure> >	m_SelfWeightCoefficients;	//optional
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

