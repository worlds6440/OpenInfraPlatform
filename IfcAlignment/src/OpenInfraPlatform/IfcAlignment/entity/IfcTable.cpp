/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcLabel.h"
#include "include/IfcTable.h"
#include "include/IfcTableColumn.h"
#include "include/IfcTableRow.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcTable 
		IfcTable::IfcTable() { m_entity_enum = IFCTABLE; }
		IfcTable::IfcTable( int id ) { m_id = id; m_entity_enum = IFCTABLE; }
		IfcTable::~IfcTable() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTable::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcTable> other = dynamic_pointer_cast<IfcTable>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Rows = other->m_Rows;
			m_Columns = other->m_Columns;
		}
		void IfcTable::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTABLE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Rows );
			stream << ",";
			writeEntityList( stream, m_Columns );
			stream << ");";
		}
		void IfcTable::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTable::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTable, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcTable, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readEntityReferenceList( args[1], m_Rows, map );
			readEntityReferenceList( args[2], m_Columns, map );
		}
		void IfcTable::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> )
		{
		}
		void IfcTable::unlinkSelf()
		{
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
