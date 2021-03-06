/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcElementQuantity.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPhysicalQuantity.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByTemplate.h"
#include "include/IfcText.h"
#include "include/IfcTypeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcElementQuantity 
		IfcElementQuantity::IfcElementQuantity() { m_entity_enum = IFCELEMENTQUANTITY; }
		IfcElementQuantity::IfcElementQuantity( int id ) { m_id = id; m_entity_enum = IFCELEMENTQUANTITY; }
		IfcElementQuantity::~IfcElementQuantity() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcElementQuantity::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcElementQuantity> other = dynamic_pointer_cast<IfcElementQuantity>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_MethodOfMeasurement = other->m_MethodOfMeasurement;
			m_Quantities = other->m_Quantities;
		}
		void IfcElementQuantity::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCELEMENTQUANTITY" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_MethodOfMeasurement ) { m_MethodOfMeasurement->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Quantities );
			stream << ");";
		}
		void IfcElementQuantity::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcElementQuantity::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcElementQuantity, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcElementQuantity, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_MethodOfMeasurement = IfcLabel::readStepData( args[4] );
			readEntityReferenceList( args[5], m_Quantities, map );
		}
		void IfcElementQuantity::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcQuantitySet::setInverseCounterparts( ptr_self_entity );
		}
		void IfcElementQuantity::unlinkSelf()
		{
			IfcQuantitySet::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
