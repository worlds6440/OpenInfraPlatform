/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcActorRole.h"
#include "include/IfcAddress.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOrganization.h"
#include "include/IfcOrganizationRelationship.h"
#include "include/IfcPersonAndOrganization.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcOrganization 
		IfcOrganization::IfcOrganization() { m_entity_enum = IFCORGANIZATION; }
		IfcOrganization::IfcOrganization( int id ) { m_id = id; m_entity_enum = IFCORGANIZATION; }
		IfcOrganization::~IfcOrganization() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcOrganization::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcOrganization> other = dynamic_pointer_cast<IfcOrganization>(other_entity);
			if( !other) { return; }
			m_Identification = other->m_Identification;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Roles = other->m_Roles;
			m_Addresses = other->m_Addresses;
		}
		void IfcOrganization::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCORGANIZATION" << "(";
			if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Roles );
			stream << ",";
			writeEntityList( stream, m_Addresses );
			stream << ");";
		}
		void IfcOrganization::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcOrganization::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcOrganization, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcOrganization, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Identification = IfcIdentifier::readStepData( args[0] );
			m_Name = IfcLabel::readStepData( args[1] );
			m_Description = IfcText::readStepData( args[2] );
			readEntityReferenceList( args[3], m_Roles, map );
			readEntityReferenceList( args[4], m_Addresses, map );
		}
		void IfcOrganization::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			shared_ptr<IfcOrganization> ptr_self = dynamic_pointer_cast<IfcOrganization>( ptr_self_entity );
			if( !ptr_self ) { throw IfcTunnelException( "IfcOrganization::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_Addresses.size(); ++i )
			{
				if( m_Addresses[i] )
				{
					m_Addresses[i]->m_OfOrganization_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcOrganization::unlinkSelf()
		{
			for( int i=0; i<m_Addresses.size(); ++i )
			{
				if( m_Addresses[i] )
				{
					std::vector<weak_ptr<IfcOrganization> >& OfOrganization_inverse = m_Addresses[i]->m_OfOrganization_inverse;
					std::vector<weak_ptr<IfcOrganization> >::iterator it_OfOrganization_inverse;
					for( it_OfOrganization_inverse = OfOrganization_inverse.begin(); it_OfOrganization_inverse != OfOrganization_inverse.end(); ++it_OfOrganization_inverse)
					{
						shared_ptr<IfcOrganization> self_candidate( *it_OfOrganization_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							OfOrganization_inverse.erase( it_OfOrganization_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
