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
#include "include/IfcLabel.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRepresentationContext.h"
#include "include/IfcRepresentationItem.h"
#include "include/IfcRepresentationMap.h"
#include "include/IfcShapeAspect.h"
#include "include/IfcTopologyRepresentation.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcTopologyRepresentation 
		IfcTopologyRepresentation::IfcTopologyRepresentation() { m_entity_enum = IFCTOPOLOGYREPRESENTATION; }
		IfcTopologyRepresentation::IfcTopologyRepresentation( int id ) { m_id = id; m_entity_enum = IFCTOPOLOGYREPRESENTATION; }
		IfcTopologyRepresentation::~IfcTopologyRepresentation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTopologyRepresentation::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcTopologyRepresentation> other = dynamic_pointer_cast<IfcTopologyRepresentation>(other_entity);
			if( !other) { return; }
			m_ContextOfItems = other->m_ContextOfItems;
			m_RepresentationIdentifier = other->m_RepresentationIdentifier;
			m_RepresentationType = other->m_RepresentationType;
			m_Items = other->m_Items;
		}
		void IfcTopologyRepresentation::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTOPOLOGYREPRESENTATION" << "(";
			if( m_ContextOfItems ) { stream << "#" << m_ContextOfItems->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RepresentationIdentifier ) { m_RepresentationIdentifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RepresentationType ) { m_RepresentationType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Items );
			stream << ");";
		}
		void IfcTopologyRepresentation::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTopologyRepresentation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTopologyRepresentation, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcTopologyRepresentation, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_ContextOfItems, map );
			m_RepresentationIdentifier = IfcLabel::readStepData( args[1] );
			m_RepresentationType = IfcLabel::readStepData( args[2] );
			readEntityReferenceList( args[3], m_Items, map );
		}
		void IfcTopologyRepresentation::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcShapeModel::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTopologyRepresentation::unlinkSelf()
		{
			IfcShapeModel::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform