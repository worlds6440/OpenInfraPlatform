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
#include "include/IfcLightDistributionData.h"
#include "include/IfcLuminousIntensityDistributionMeasure.h"
#include "include/IfcPlaneAngleMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcLightDistributionData 
		IfcLightDistributionData::IfcLightDistributionData() { m_entity_enum = IFCLIGHTDISTRIBUTIONDATA; }
		IfcLightDistributionData::IfcLightDistributionData( int id ) { m_id = id; m_entity_enum = IFCLIGHTDISTRIBUTIONDATA; }
		IfcLightDistributionData::~IfcLightDistributionData() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLightDistributionData::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcLightDistributionData> other = dynamic_pointer_cast<IfcLightDistributionData>(other_entity);
			if( !other) { return; }
			m_MainPlaneAngle = other->m_MainPlaneAngle;
			m_SecondaryPlaneAngle = other->m_SecondaryPlaneAngle;
			m_LuminousIntensity = other->m_LuminousIntensity;
		}
		void IfcLightDistributionData::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLIGHTDISTRIBUTIONDATA" << "(";
			if( m_MainPlaneAngle ) { m_MainPlaneAngle->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeOfRealList( stream, m_SecondaryPlaneAngle );
			stream << ",";
			writeTypeOfRealList( stream, m_LuminousIntensity );
			stream << ");";
		}
		void IfcLightDistributionData::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLightDistributionData::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLightDistributionData, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcLightDistributionData, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_MainPlaneAngle = IfcPlaneAngleMeasure::readStepData( args[0] );
			readTypeOfRealList( args[1], m_SecondaryPlaneAngle );
			readTypeOfRealList( args[2], m_LuminousIntensity );
		}
		void IfcLightDistributionData::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcLightDistributionData::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
