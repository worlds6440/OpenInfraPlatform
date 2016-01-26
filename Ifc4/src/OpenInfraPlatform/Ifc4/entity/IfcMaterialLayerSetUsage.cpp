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
#include "include/IfcDirectionSenseEnum.h"
#include "include/IfcLayerSetDirectionEnum.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcMaterialLayerSet.h"
#include "include/IfcMaterialLayerSetUsage.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcRelAssociatesMaterial.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcMaterialLayerSetUsage 
		IfcMaterialLayerSetUsage::IfcMaterialLayerSetUsage() { m_entity_enum = IFCMATERIALLAYERSETUSAGE; }
		IfcMaterialLayerSetUsage::IfcMaterialLayerSetUsage( int id ) { m_id = id; m_entity_enum = IFCMATERIALLAYERSETUSAGE; }
		IfcMaterialLayerSetUsage::~IfcMaterialLayerSetUsage() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialLayerSetUsage::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcMaterialLayerSetUsage> other = dynamic_pointer_cast<IfcMaterialLayerSetUsage>(other_entity);
			if( !other) { return; }
			m_ForLayerSet = other->m_ForLayerSet;
			m_LayerSetDirection = other->m_LayerSetDirection;
			m_DirectionSense = other->m_DirectionSense;
			m_OffsetFromReferenceLine = other->m_OffsetFromReferenceLine;
			m_ReferenceExtent = other->m_ReferenceExtent;
		}
		void IfcMaterialLayerSetUsage::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALLAYERSETUSAGE" << "(";
			if( m_ForLayerSet ) { stream << "#" << m_ForLayerSet->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_LayerSetDirection ) { m_LayerSetDirection->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DirectionSense ) { m_DirectionSense->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OffsetFromReferenceLine ) { m_OffsetFromReferenceLine->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ReferenceExtent ) { m_ReferenceExtent->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterialLayerSetUsage::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialLayerSetUsage::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialLayerSetUsage, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcMaterialLayerSetUsage, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_ForLayerSet, map );
			m_LayerSetDirection = IfcLayerSetDirectionEnum::readStepData( args[1] );
			m_DirectionSense = IfcDirectionSenseEnum::readStepData( args[2] );
			m_OffsetFromReferenceLine = IfcLengthMeasure::readStepData( args[3] );
			m_ReferenceExtent = IfcPositiveLengthMeasure::readStepData( args[4] );
		}
		void IfcMaterialLayerSetUsage::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcMaterialUsageDefinition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcMaterialLayerSetUsage::unlinkSelf()
		{
			IfcMaterialUsageDefinition::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
