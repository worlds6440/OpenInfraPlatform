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
#include "include/IfcBoundaryEdgeCondition.h"
#include "include/IfcLabel.h"
#include "include/IfcModulusOfRotationalSubgradeReactionSelect.h"
#include "include/IfcModulusOfTranslationalSubgradeReactionSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcBoundaryEdgeCondition 
		IfcBoundaryEdgeCondition::IfcBoundaryEdgeCondition() { m_entity_enum = IFCBOUNDARYEDGECONDITION; }
		IfcBoundaryEdgeCondition::IfcBoundaryEdgeCondition( int id ) { m_id = id; m_entity_enum = IFCBOUNDARYEDGECONDITION; }
		IfcBoundaryEdgeCondition::~IfcBoundaryEdgeCondition() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoundaryEdgeCondition::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcBoundaryEdgeCondition> other = dynamic_pointer_cast<IfcBoundaryEdgeCondition>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_TranslationalStiffnessByLengthX = other->m_TranslationalStiffnessByLengthX;
			m_TranslationalStiffnessByLengthY = other->m_TranslationalStiffnessByLengthY;
			m_TranslationalStiffnessByLengthZ = other->m_TranslationalStiffnessByLengthZ;
			m_RotationalStiffnessByLengthX = other->m_RotationalStiffnessByLengthX;
			m_RotationalStiffnessByLengthY = other->m_RotationalStiffnessByLengthY;
			m_RotationalStiffnessByLengthZ = other->m_RotationalStiffnessByLengthZ;
		}
		void IfcBoundaryEdgeCondition::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOUNDARYEDGECONDITION" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TranslationalStiffnessByLengthX ) { m_TranslationalStiffnessByLengthX->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TranslationalStiffnessByLengthY ) { m_TranslationalStiffnessByLengthY->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TranslationalStiffnessByLengthZ ) { m_TranslationalStiffnessByLengthZ->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalStiffnessByLengthX ) { m_RotationalStiffnessByLengthX->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalStiffnessByLengthY ) { m_RotationalStiffnessByLengthY->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalStiffnessByLengthZ ) { m_RotationalStiffnessByLengthZ->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBoundaryEdgeCondition::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBoundaryEdgeCondition::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBoundaryEdgeCondition, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcBoundaryEdgeCondition, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_TranslationalStiffnessByLengthX = IfcModulusOfTranslationalSubgradeReactionSelect::readStepData( args[1], map );
			m_TranslationalStiffnessByLengthY = IfcModulusOfTranslationalSubgradeReactionSelect::readStepData( args[2], map );
			m_TranslationalStiffnessByLengthZ = IfcModulusOfTranslationalSubgradeReactionSelect::readStepData( args[3], map );
			m_RotationalStiffnessByLengthX = IfcModulusOfRotationalSubgradeReactionSelect::readStepData( args[4], map );
			m_RotationalStiffnessByLengthY = IfcModulusOfRotationalSubgradeReactionSelect::readStepData( args[5], map );
			m_RotationalStiffnessByLengthZ = IfcModulusOfRotationalSubgradeReactionSelect::readStepData( args[6], map );
		}
		void IfcBoundaryEdgeCondition::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcBoundaryCondition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoundaryEdgeCondition::unlinkSelf()
		{
			IfcBoundaryCondition::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform