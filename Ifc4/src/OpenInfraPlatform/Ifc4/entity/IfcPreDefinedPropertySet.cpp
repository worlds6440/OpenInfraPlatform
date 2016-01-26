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
#include "include/IfcPreDefinedPropertySet.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByTemplate.h"
#include "include/IfcText.h"
#include "include/IfcTypeObject.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPreDefinedPropertySet 
		IfcPreDefinedPropertySet::IfcPreDefinedPropertySet() { m_entity_enum = IFCPREDEFINEDPROPERTYSET; }
		IfcPreDefinedPropertySet::IfcPreDefinedPropertySet( int id ) { m_id = id; m_entity_enum = IFCPREDEFINEDPROPERTYSET; }
		IfcPreDefinedPropertySet::~IfcPreDefinedPropertySet() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPreDefinedPropertySet::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcPreDefinedPropertySet> other = dynamic_pointer_cast<IfcPreDefinedPropertySet>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
		}
		void IfcPreDefinedPropertySet::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPREDEFINEDPROPERTYSET" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPreDefinedPropertySet::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPreDefinedPropertySet::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPreDefinedPropertySet, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcPreDefinedPropertySet, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
		}
		void IfcPreDefinedPropertySet::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPropertySetDefinition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPreDefinedPropertySet::unlinkSelf()
		{
			IfcPropertySetDefinition::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform