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
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPropertySetTemplate.h"
#include "include/IfcPropertySetTemplateTypeEnum.h"
#include "include/IfcPropertyTemplate.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByTemplate.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcPropertySetTemplate 
		IfcPropertySetTemplate::IfcPropertySetTemplate() { m_entity_enum = IFCPROPERTYSETTEMPLATE; }
		IfcPropertySetTemplate::IfcPropertySetTemplate( int id ) { m_id = id; m_entity_enum = IFCPROPERTYSETTEMPLATE; }
		IfcPropertySetTemplate::~IfcPropertySetTemplate() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPropertySetTemplate::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcPropertySetTemplate> other = dynamic_pointer_cast<IfcPropertySetTemplate>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_TemplateType = other->m_TemplateType;
			m_ApplicableEntity = other->m_ApplicableEntity;
			m_HasPropertyTemplates = other->m_HasPropertyTemplates;
		}
		void IfcPropertySetTemplate::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROPERTYSETTEMPLATE" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TemplateType ) { m_TemplateType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ApplicableEntity ) { m_ApplicableEntity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_HasPropertyTemplates );
			stream << ");";
		}
		void IfcPropertySetTemplate::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPropertySetTemplate::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPropertySetTemplate, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcPropertySetTemplate, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_TemplateType = IfcPropertySetTemplateTypeEnum::readStepData( args[4] );
			m_ApplicableEntity = IfcIdentifier::readStepData( args[5] );
			readEntityReferenceList( args[6], m_HasPropertyTemplates, map );
		}
		void IfcPropertySetTemplate::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcPropertyTemplateDefinition::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcPropertySetTemplate> ptr_self = dynamic_pointer_cast<IfcPropertySetTemplate>( ptr_self_entity );
			if( !ptr_self ) { throw IfcTunnelException( "IfcPropertySetTemplate::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_HasPropertyTemplates.size(); ++i )
			{
				if( m_HasPropertyTemplates[i] )
				{
					m_HasPropertyTemplates[i]->m_PartOfPsetTemplate_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcPropertySetTemplate::unlinkSelf()
		{
			IfcPropertyTemplateDefinition::unlinkSelf();
			for( int i=0; i<m_HasPropertyTemplates.size(); ++i )
			{
				if( m_HasPropertyTemplates[i] )
				{
					std::vector<weak_ptr<IfcPropertySetTemplate> >& PartOfPsetTemplate_inverse = m_HasPropertyTemplates[i]->m_PartOfPsetTemplate_inverse;
					std::vector<weak_ptr<IfcPropertySetTemplate> >::iterator it_PartOfPsetTemplate_inverse;
					for( it_PartOfPsetTemplate_inverse = PartOfPsetTemplate_inverse.begin(); it_PartOfPsetTemplate_inverse != PartOfPsetTemplate_inverse.end(); ++it_PartOfPsetTemplate_inverse)
					{
						shared_ptr<IfcPropertySetTemplate> self_candidate( *it_PartOfPsetTemplate_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							PartOfPsetTemplate_inverse.erase( it_PartOfPsetTemplate_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
