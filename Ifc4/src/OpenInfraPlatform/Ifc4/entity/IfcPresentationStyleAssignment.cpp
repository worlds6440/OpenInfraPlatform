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
#include "include/IfcPresentationStyleAssignment.h"
#include "include/IfcPresentationStyleSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPresentationStyleAssignment 
		IfcPresentationStyleAssignment::IfcPresentationStyleAssignment() { m_entity_enum = IFCPRESENTATIONSTYLEASSIGNMENT; }
		IfcPresentationStyleAssignment::IfcPresentationStyleAssignment( int id ) { m_id = id; m_entity_enum = IFCPRESENTATIONSTYLEASSIGNMENT; }
		IfcPresentationStyleAssignment::~IfcPresentationStyleAssignment() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPresentationStyleAssignment::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcPresentationStyleAssignment> other = dynamic_pointer_cast<IfcPresentationStyleAssignment>(other_entity);
			if( !other) { return; }
			m_Styles = other->m_Styles;
		}
		void IfcPresentationStyleAssignment::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPRESENTATIONSTYLEASSIGNMENT" << "(";
			writeTypeList( stream, m_Styles, true );
			stream << ");";
		}
		void IfcPresentationStyleAssignment::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPresentationStyleAssignment::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPresentationStyleAssignment, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcPresentationStyleAssignment, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_Styles, map );
		}
		void IfcPresentationStyleAssignment::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcPresentationStyleAssignment::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
