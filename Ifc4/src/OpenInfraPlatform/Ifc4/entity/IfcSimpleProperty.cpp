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
#include "include/IfcComplexProperty.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcPropertyDependencyRelationship.h"
#include "include/IfcPropertySet.h"
#include "include/IfcResourceApprovalRelationship.h"
#include "include/IfcResourceConstraintRelationship.h"
#include "include/IfcSimpleProperty.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcSimpleProperty 
		IfcSimpleProperty::IfcSimpleProperty() { m_entity_enum = IFCSIMPLEPROPERTY; }
		IfcSimpleProperty::IfcSimpleProperty( int id ) { m_id = id; m_entity_enum = IFCSIMPLEPROPERTY; }
		IfcSimpleProperty::~IfcSimpleProperty() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSimpleProperty::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcSimpleProperty> other = dynamic_pointer_cast<IfcSimpleProperty>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
		}
		void IfcSimpleProperty::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSIMPLEPROPERTY" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSimpleProperty::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSimpleProperty::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSimpleProperty, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcSimpleProperty, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcIdentifier::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
		}
		void IfcSimpleProperty::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcProperty::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSimpleProperty::unlinkSelf()
		{
			IfcProperty::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
