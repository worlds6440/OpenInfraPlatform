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
#include "include/IfcAddress.h"
#include "include/IfcAddressTypeEnum.h"
#include "include/IfcLabel.h"
#include "include/IfcOrganization.h"
#include "include/IfcPerson.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcAddress 
		IfcAddress::IfcAddress() { m_entity_enum = IFCADDRESS; }
		IfcAddress::IfcAddress( int id ) { m_id = id; m_entity_enum = IFCADDRESS; }
		IfcAddress::~IfcAddress() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAddress::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcAddress> other = dynamic_pointer_cast<IfcAddress>(other_entity);
			if( !other) { return; }
			m_Purpose = other->m_Purpose;
			m_Description = other->m_Description;
			m_UserDefinedPurpose = other->m_UserDefinedPurpose;
		}
		void IfcAddress::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCADDRESS" << "(";
			if( m_Purpose ) { m_Purpose->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedPurpose ) { m_UserDefinedPurpose->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcAddress::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAddress::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAddress, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcAddress, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Purpose = IfcAddressTypeEnum::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			m_UserDefinedPurpose = IfcLabel::readStepData( args[2] );
		}
		void IfcAddress::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcAddress::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
