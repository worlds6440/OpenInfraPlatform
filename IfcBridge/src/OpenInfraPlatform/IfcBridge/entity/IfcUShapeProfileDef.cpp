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
#include "include/IfcAxis2Placement2D.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcNonNegativeLengthMeasure.h"
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"
#include "include/IfcUShapeProfileDef.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcUShapeProfileDef 
		IfcUShapeProfileDef::IfcUShapeProfileDef() { m_entity_enum = IFCUSHAPEPROFILEDEF; }
		IfcUShapeProfileDef::IfcUShapeProfileDef( int id ) { m_id = id; m_entity_enum = IFCUSHAPEPROFILEDEF; }
		IfcUShapeProfileDef::~IfcUShapeProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcUShapeProfileDef::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcUShapeProfileDef> other = dynamic_pointer_cast<IfcUShapeProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_Position = other->m_Position;
			m_Depth = other->m_Depth;
			m_FlangeWidth = other->m_FlangeWidth;
			m_WebThickness = other->m_WebThickness;
			m_FlangeThickness = other->m_FlangeThickness;
			m_FilletRadius = other->m_FilletRadius;
			m_EdgeRadius = other->m_EdgeRadius;
			m_FlangeSlope = other->m_FlangeSlope;
		}
		void IfcUShapeProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCUSHAPEPROFILEDEF" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Depth ) { m_Depth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FlangeWidth ) { m_FlangeWidth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_WebThickness ) { m_WebThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FlangeThickness ) { m_FlangeThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FilletRadius ) { m_FilletRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EdgeRadius ) { m_EdgeRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FlangeSlope ) { m_FlangeSlope->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcUShapeProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcUShapeProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<10 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcUShapeProfileDef, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>10 ){ std::cout << "Wrong parameter count for entity IfcUShapeProfileDef, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_Position, map );
			m_Depth = IfcPositiveLengthMeasure::readStepData( args[3] );
			m_FlangeWidth = IfcPositiveLengthMeasure::readStepData( args[4] );
			m_WebThickness = IfcPositiveLengthMeasure::readStepData( args[5] );
			m_FlangeThickness = IfcPositiveLengthMeasure::readStepData( args[6] );
			m_FilletRadius = IfcNonNegativeLengthMeasure::readStepData( args[7] );
			m_EdgeRadius = IfcNonNegativeLengthMeasure::readStepData( args[8] );
			m_FlangeSlope = IfcPlaneAngleMeasure::readStepData( args[9] );
		}
		void IfcUShapeProfileDef::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcParameterizedProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcUShapeProfileDef::unlinkSelf()
		{
			IfcParameterizedProfileDef::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform