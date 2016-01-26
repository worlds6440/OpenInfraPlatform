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
#include "include/IfcLabel.h"
#include "include/IfcPresentationStyle.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPresentationStyle 
		IfcPresentationStyle::IfcPresentationStyle() { m_entity_enum = IFCPRESENTATIONSTYLE; }
		IfcPresentationStyle::IfcPresentationStyle( int id ) { m_id = id; m_entity_enum = IFCPRESENTATIONSTYLE; }
		IfcPresentationStyle::~IfcPresentationStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPresentationStyle::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcPresentationStyle> other = dynamic_pointer_cast<IfcPresentationStyle>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
		}
		void IfcPresentationStyle::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPRESENTATIONSTYLE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPresentationStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPresentationStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPresentationStyle, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcPresentationStyle, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
		}
		void IfcPresentationStyle::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcPresentationStyle::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
