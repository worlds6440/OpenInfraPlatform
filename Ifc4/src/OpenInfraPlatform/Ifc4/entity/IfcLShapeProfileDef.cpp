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
#include "include/IfcAxis2Placement2D.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLShapeProfileDef.h"
#include "include/IfcLabel.h"
#include "include/IfcNonNegativeLengthMeasure.h"
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcLShapeProfileDef 
		IfcLShapeProfileDef::IfcLShapeProfileDef() { m_entity_enum = IFCLSHAPEPROFILEDEF; }
		IfcLShapeProfileDef::IfcLShapeProfileDef( int id ) { m_id = id; m_entity_enum = IFCLSHAPEPROFILEDEF; }
		IfcLShapeProfileDef::~IfcLShapeProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLShapeProfileDef::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcLShapeProfileDef> other = dynamic_pointer_cast<IfcLShapeProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_Position = other->m_Position;
			m_Depth = other->m_Depth;
			m_Width = other->m_Width;
			m_Thickness = other->m_Thickness;
			m_FilletRadius = other->m_FilletRadius;
			m_EdgeRadius = other->m_EdgeRadius;
			m_LegSlope = other->m_LegSlope;
		}
		void IfcLShapeProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLSHAPEPROFILEDEF" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Depth ) { m_Depth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Width ) { m_Width->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Thickness ) { m_Thickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FilletRadius ) { m_FilletRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EdgeRadius ) { m_EdgeRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LegSlope ) { m_LegSlope->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLShapeProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLShapeProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLShapeProfileDef, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcLShapeProfileDef, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_Position, map );
			m_Depth = IfcPositiveLengthMeasure::readStepData( args[3] );
			m_Width = IfcPositiveLengthMeasure::readStepData( args[4] );
			m_Thickness = IfcPositiveLengthMeasure::readStepData( args[5] );
			m_FilletRadius = IfcNonNegativeLengthMeasure::readStepData( args[6] );
			m_EdgeRadius = IfcNonNegativeLengthMeasure::readStepData( args[7] );
			m_LegSlope = IfcPlaneAngleMeasure::readStepData( args[8] );
		}
		void IfcLShapeProfileDef::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcParameterizedProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLShapeProfileDef::unlinkSelf()
		{
			IfcParameterizedProfileDef::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
