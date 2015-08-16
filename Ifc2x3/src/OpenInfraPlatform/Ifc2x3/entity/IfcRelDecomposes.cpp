/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectDefinition.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelDecomposes.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRelDecomposes 
		IfcRelDecomposes::IfcRelDecomposes() { m_entity_enum = IFCRELDECOMPOSES; }
		IfcRelDecomposes::IfcRelDecomposes( int id ) { m_id = id; m_entity_enum = IFCRELDECOMPOSES; }
		IfcRelDecomposes::~IfcRelDecomposes() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelDecomposes::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRelDecomposes> other = dynamic_pointer_cast<IfcRelDecomposes>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingObject = other->m_RelatingObject;
			m_RelatedObjects = other->m_RelatedObjects;
		}
		void IfcRelDecomposes::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELDECOMPOSES" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingObject ) { stream << "#" << m_RelatingObject->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RelatedObjects );
			stream << ");";
		}
		void IfcRelDecomposes::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelDecomposes::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelDecomposes, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelDecomposes, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReference( args[4], m_RelatingObject, map );
			readEntityReferenceList( args[5], m_RelatedObjects, map );
		}
		void IfcRelDecomposes::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcRelationship::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelDecomposes> ptr_self = dynamic_pointer_cast<IfcRelDecomposes>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcRelDecomposes::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_RelatedObjects.size(); ++i )
			{
				if( m_RelatedObjects[i] )
				{
					m_RelatedObjects[i]->m_Decomposes_inverse.push_back( ptr_self );
				}
			}
			if( m_RelatingObject )
			{
				m_RelatingObject->m_IsDecomposedBy_inverse.push_back( ptr_self );
			}
		}
		void IfcRelDecomposes::unlinkSelf()
		{
			IfcRelationship::unlinkSelf();
			for( int i=0; i<m_RelatedObjects.size(); ++i )
			{
				if( m_RelatedObjects[i] )
				{
					std::vector<weak_ptr<IfcRelDecomposes> >& Decomposes_inverse = m_RelatedObjects[i]->m_Decomposes_inverse;
					std::vector<weak_ptr<IfcRelDecomposes> >::iterator it_Decomposes_inverse;
					for( it_Decomposes_inverse = Decomposes_inverse.begin(); it_Decomposes_inverse != Decomposes_inverse.end(); ++it_Decomposes_inverse)
					{
						shared_ptr<IfcRelDecomposes> self_candidate( *it_Decomposes_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							Decomposes_inverse.erase( it_Decomposes_inverse );
							break;
						}
					}
				}
			}
			if( m_RelatingObject )
			{
				std::vector<weak_ptr<IfcRelDecomposes> >& IsDecomposedBy_inverse = m_RelatingObject->m_IsDecomposedBy_inverse;
				std::vector<weak_ptr<IfcRelDecomposes> >::iterator it_IsDecomposedBy_inverse;
				for( it_IsDecomposedBy_inverse = IsDecomposedBy_inverse.begin(); it_IsDecomposedBy_inverse != IsDecomposedBy_inverse.end(); ++it_IsDecomposedBy_inverse)
				{
					shared_ptr<IfcRelDecomposes> self_candidate( *it_IsDecomposedBy_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						IsDecomposedBy_inverse.erase( it_IsDecomposedBy_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform