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
#include "include/IfcDataOriginEnum.h"
#include "include/IfcLabel.h"
#include "include/IfcSchedulingTime.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcSchedulingTime 
		IfcSchedulingTime::IfcSchedulingTime() { m_entity_enum = IFCSCHEDULINGTIME; }
		IfcSchedulingTime::IfcSchedulingTime( int id ) { m_id = id; m_entity_enum = IFCSCHEDULINGTIME; }
		IfcSchedulingTime::~IfcSchedulingTime() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSchedulingTime::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcSchedulingTime> other = dynamic_pointer_cast<IfcSchedulingTime>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_DataOrigin = other->m_DataOrigin;
			m_UserDefinedDataOrigin = other->m_UserDefinedDataOrigin;
		}
		void IfcSchedulingTime::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSCHEDULINGTIME" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DataOrigin ) { m_DataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedDataOrigin ) { m_UserDefinedDataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSchedulingTime::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSchedulingTime::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSchedulingTime, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcSchedulingTime, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_DataOrigin = IfcDataOriginEnum::readStepData( args[1] );
			m_UserDefinedDataOrigin = IfcLabel::readStepData( args[2] );
		}
		void IfcSchedulingTime::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcSchedulingTime::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
