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
#include "include/IfcCurvatureMeasure.h"
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcStructuralLoadSingleDisplacementDistortion.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcStructuralLoadSingleDisplacementDistortion 
		IfcStructuralLoadSingleDisplacementDistortion::IfcStructuralLoadSingleDisplacementDistortion() { m_entity_enum = IFCSTRUCTURALLOADSINGLEDISPLACEMENTDISTORTION; }
		IfcStructuralLoadSingleDisplacementDistortion::IfcStructuralLoadSingleDisplacementDistortion( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOADSINGLEDISPLACEMENTDISTORTION; }
		IfcStructuralLoadSingleDisplacementDistortion::~IfcStructuralLoadSingleDisplacementDistortion() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoadSingleDisplacementDistortion::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcStructuralLoadSingleDisplacementDistortion> other = dynamic_pointer_cast<IfcStructuralLoadSingleDisplacementDistortion>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_DisplacementX = other->m_DisplacementX;
			m_DisplacementY = other->m_DisplacementY;
			m_DisplacementZ = other->m_DisplacementZ;
			m_RotationalDisplacementRX = other->m_RotationalDisplacementRX;
			m_RotationalDisplacementRY = other->m_RotationalDisplacementRY;
			m_RotationalDisplacementRZ = other->m_RotationalDisplacementRZ;
			m_Distortion = other->m_Distortion;
		}
		void IfcStructuralLoadSingleDisplacementDistortion::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALLOADSINGLEDISPLACEMENTDISTORTION" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DisplacementX ) { m_DisplacementX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DisplacementY ) { m_DisplacementY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DisplacementZ ) { m_DisplacementZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalDisplacementRX ) { m_RotationalDisplacementRX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalDisplacementRY ) { m_RotationalDisplacementRY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalDisplacementRZ ) { m_RotationalDisplacementRZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Distortion ) { m_Distortion->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStructuralLoadSingleDisplacementDistortion::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralLoadSingleDisplacementDistortion::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoadSingleDisplacementDistortion, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoadSingleDisplacementDistortion, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_DisplacementX = IfcLengthMeasure::readStepData( args[1] );
			m_DisplacementY = IfcLengthMeasure::readStepData( args[2] );
			m_DisplacementZ = IfcLengthMeasure::readStepData( args[3] );
			m_RotationalDisplacementRX = IfcPlaneAngleMeasure::readStepData( args[4] );
			m_RotationalDisplacementRY = IfcPlaneAngleMeasure::readStepData( args[5] );
			m_RotationalDisplacementRZ = IfcPlaneAngleMeasure::readStepData( args[6] );
			m_Distortion = IfcCurvatureMeasure::readStepData( args[7] );
		}
		void IfcStructuralLoadSingleDisplacementDistortion::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcStructuralLoadSingleDisplacement::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralLoadSingleDisplacementDistortion::unlinkSelf()
		{
			IfcStructuralLoadSingleDisplacement::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
