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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcMaterial.h"
#include "include/IfcMaterialProfileSet.h"
#include "include/IfcMaterialProfileWithOffsets.h"
#include "include/IfcMaterialProperties.h"
#include "include/IfcProfileDef.h"
#include "include/IfcRelAssociatesMaterial.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcMaterialProfileWithOffsets 
		IfcMaterialProfileWithOffsets::IfcMaterialProfileWithOffsets() { m_entity_enum = IFCMATERIALPROFILEWITHOFFSETS; }
		IfcMaterialProfileWithOffsets::IfcMaterialProfileWithOffsets( int id ) { m_id = id; m_entity_enum = IFCMATERIALPROFILEWITHOFFSETS; }
		IfcMaterialProfileWithOffsets::~IfcMaterialProfileWithOffsets() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialProfileWithOffsets::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcMaterialProfileWithOffsets> other = dynamic_pointer_cast<IfcMaterialProfileWithOffsets>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Material = other->m_Material;
			m_Profile = other->m_Profile;
			m_Priority = other->m_Priority;
			m_Category = other->m_Category;
			m_OffsetValues = other->m_OffsetValues;
		}
		void IfcMaterialProfileWithOffsets::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALPROFILEWITHOFFSETS" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Material ) { stream << "#" << m_Material->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Profile ) { stream << "#" << m_Profile->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Priority == m_Priority ){ stream << m_Priority; }
			else { stream << "$"; }
			stream << ",";
			if( m_Category ) { m_Category->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeOfRealList( stream, m_OffsetValues );
			stream << ");";
		}
		void IfcMaterialProfileWithOffsets::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialProfileWithOffsets::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialProfileWithOffsets, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcMaterialProfileWithOffsets, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_Material, map );
			readEntityReference( args[3], m_Profile, map );
			readIntValue( args[4], m_Priority );
			m_Category = IfcLabel::readStepData( args[5] );
			readTypeOfRealList( args[6], m_OffsetValues );
		}
		void IfcMaterialProfileWithOffsets::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcMaterialProfile::setInverseCounterparts( ptr_self_entity );
		}
		void IfcMaterialProfileWithOffsets::unlinkSelf()
		{
			IfcMaterialProfile::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
