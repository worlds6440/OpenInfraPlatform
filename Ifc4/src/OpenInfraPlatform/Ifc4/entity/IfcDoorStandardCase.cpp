/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcDoorStandardCase.h"
#include "include/IfcDoorTypeEnum.h"
#include "include/IfcDoorTypeOperationEnum.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelConnectsElements.h"
#include "include/IfcRelConnectsWithRealizingElements.h"
#include "include/IfcRelContainedInSpatialStructure.h"
#include "include/IfcRelCoversBldgElements.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelFillsElement.h"
#include "include/IfcRelInterferesElements.h"
#include "include/IfcRelNests.h"
#include "include/IfcRelProjectsElement.h"
#include "include/IfcRelReferencedInSpatialStructure.h"
#include "include/IfcRelSpaceBoundary.h"
#include "include/IfcRelVoidsElement.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcDoorStandardCase 
		IfcDoorStandardCase::IfcDoorStandardCase() { m_entity_enum = IFCDOORSTANDARDCASE; }
		IfcDoorStandardCase::IfcDoorStandardCase( int id ) { m_id = id; m_entity_enum = IFCDOORSTANDARDCASE; }
		IfcDoorStandardCase::~IfcDoorStandardCase() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDoorStandardCase::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcDoorStandardCase> other = dynamic_pointer_cast<IfcDoorStandardCase>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_ObjectPlacement = other->m_ObjectPlacement;
			m_Representation = other->m_Representation;
			m_Tag = other->m_Tag;
			m_OverallHeight = other->m_OverallHeight;
			m_OverallWidth = other->m_OverallWidth;
			m_PredefinedType = other->m_PredefinedType;
			m_OperationType = other->m_OperationType;
			m_UserDefinedOperationType = other->m_UserDefinedOperationType;
		}
		void IfcDoorStandardCase::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDOORSTANDARDCASE" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ObjectPlacement ) { stream << "#" << m_ObjectPlacement->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Representation ) { stream << "#" << m_Representation->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Tag ) { m_Tag->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OverallHeight ) { m_OverallHeight->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OverallWidth ) { m_OverallWidth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OperationType ) { m_OperationType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedOperationType ) { m_UserDefinedOperationType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcDoorStandardCase::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDoorStandardCase::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<13 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDoorStandardCase, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>13 ){ std::cout << "Wrong parameter count for entity IfcDoorStandardCase, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			readEntityReference( args[5], m_ObjectPlacement, map );
			readEntityReference( args[6], m_Representation, map );
			m_Tag = IfcIdentifier::readStepData( args[7] );
			m_OverallHeight = IfcPositiveLengthMeasure::readStepData( args[8] );
			m_OverallWidth = IfcPositiveLengthMeasure::readStepData( args[9] );
			m_PredefinedType = IfcDoorTypeEnum::readStepData( args[10] );
			m_OperationType = IfcDoorTypeOperationEnum::readStepData( args[11] );
			m_UserDefinedOperationType = IfcLabel::readStepData( args[12] );
		}
		void IfcDoorStandardCase::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcDoor::setInverseCounterparts( ptr_self_entity );
		}
		void IfcDoorStandardCase::unlinkSelf()
		{
			IfcDoor::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform