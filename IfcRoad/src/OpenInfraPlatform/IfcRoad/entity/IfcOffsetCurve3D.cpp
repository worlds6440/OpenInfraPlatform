/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcCurve.h"
#include "include/IfcDirection.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcLogical.h"
#include "include/IfcOffsetCurve3D.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcOffsetCurve3D 
		IfcOffsetCurve3D::IfcOffsetCurve3D() { m_entity_enum = IFCOFFSETCURVE3D; }
		IfcOffsetCurve3D::IfcOffsetCurve3D( int id ) { m_id = id; m_entity_enum = IFCOFFSETCURVE3D; }
		IfcOffsetCurve3D::~IfcOffsetCurve3D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcOffsetCurve3D::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcOffsetCurve3D> other = dynamic_pointer_cast<IfcOffsetCurve3D>(other_entity);
			if( !other) { return; }
			m_BasisCurve = other->m_BasisCurve;
			m_Distance = other->m_Distance;
			m_SelfIntersect = other->m_SelfIntersect;
			m_RefDirection = other->m_RefDirection;
		}
		void IfcOffsetCurve3D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCOFFSETCURVE3D" << "(";
			if( m_BasisCurve ) { stream << "#" << m_BasisCurve->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Distance ) { m_Distance->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SelfIntersect ) { m_SelfIntersect->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RefDirection ) { stream << "#" << m_RefDirection->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcOffsetCurve3D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcOffsetCurve3D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcOffsetCurve3D, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcOffsetCurve3D, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisCurve, map );
			m_Distance = IfcLengthMeasure::readStepData( args[1] );
			m_SelfIntersect = IfcLogical::readStepData( args[2] );
			readEntityReference( args[3], m_RefDirection, map );
		}
		void IfcOffsetCurve3D::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcOffsetCurve3D::unlinkSelf()
		{
			IfcCurve::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform