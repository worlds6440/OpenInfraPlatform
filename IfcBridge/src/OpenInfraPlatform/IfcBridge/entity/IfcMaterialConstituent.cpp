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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcMaterial.h"
#include "include/IfcMaterialConstituent.h"
#include "include/IfcMaterialConstituentSet.h"
#include "include/IfcMaterialProperties.h"
#include "include/IfcNormalisedRatioMeasure.h"
#include "include/IfcRelAssociatesMaterial.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcMaterialConstituent 
		IfcMaterialConstituent::IfcMaterialConstituent() { m_entity_enum = IFCMATERIALCONSTITUENT; }
		IfcMaterialConstituent::IfcMaterialConstituent( int id ) { m_id = id; m_entity_enum = IFCMATERIALCONSTITUENT; }
		IfcMaterialConstituent::~IfcMaterialConstituent() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialConstituent::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcMaterialConstituent> other = dynamic_pointer_cast<IfcMaterialConstituent>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Material = other->m_Material;
			m_Fraction = other->m_Fraction;
			m_Category = other->m_Category;
		}
		void IfcMaterialConstituent::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALCONSTITUENT" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Material ) { stream << "#" << m_Material->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Fraction ) { m_Fraction->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Category ) { m_Category->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterialConstituent::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialConstituent::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialConstituent, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcMaterialConstituent, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_Material, map );
			m_Fraction = IfcNormalisedRatioMeasure::readStepData( args[3] );
			m_Category = IfcLabel::readStepData( args[4] );
		}
		void IfcMaterialConstituent::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcMaterialDefinition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcMaterialConstituent::unlinkSelf()
		{
			IfcMaterialDefinition::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
