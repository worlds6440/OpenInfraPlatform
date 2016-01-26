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
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPermeableCoveringOperationEnum.h"
#include "include/IfcPermeableCoveringProperties.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByTemplate.h"
#include "include/IfcShapeAspect.h"
#include "include/IfcText.h"
#include "include/IfcTypeObject.h"
#include "include/IfcWindowPanelPositionEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPermeableCoveringProperties 
		IfcPermeableCoveringProperties::IfcPermeableCoveringProperties() { m_entity_enum = IFCPERMEABLECOVERINGPROPERTIES; }
		IfcPermeableCoveringProperties::IfcPermeableCoveringProperties( int id ) { m_id = id; m_entity_enum = IFCPERMEABLECOVERINGPROPERTIES; }
		IfcPermeableCoveringProperties::~IfcPermeableCoveringProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPermeableCoveringProperties::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcPermeableCoveringProperties> other = dynamic_pointer_cast<IfcPermeableCoveringProperties>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_OperationType = other->m_OperationType;
			m_PanelPosition = other->m_PanelPosition;
			m_FrameDepth = other->m_FrameDepth;
			m_FrameThickness = other->m_FrameThickness;
			m_ShapeAspectStyle = other->m_ShapeAspectStyle;
		}
		void IfcPermeableCoveringProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPERMEABLECOVERINGPROPERTIES" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OperationType ) { m_OperationType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PanelPosition ) { m_PanelPosition->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FrameDepth ) { m_FrameDepth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FrameThickness ) { m_FrameThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ShapeAspectStyle ) { stream << "#" << m_ShapeAspectStyle->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPermeableCoveringProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPermeableCoveringProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPermeableCoveringProperties, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcPermeableCoveringProperties, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_OperationType = IfcPermeableCoveringOperationEnum::readStepData( args[4] );
			m_PanelPosition = IfcWindowPanelPositionEnum::readStepData( args[5] );
			m_FrameDepth = IfcPositiveLengthMeasure::readStepData( args[6] );
			m_FrameThickness = IfcPositiveLengthMeasure::readStepData( args[7] );
			readEntityReference( args[8], m_ShapeAspectStyle, map );
		}
		void IfcPermeableCoveringProperties::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPreDefinedPropertySet::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPermeableCoveringProperties::unlinkSelf()
		{
			IfcPreDefinedPropertySet::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
