/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcLabel.h"
#include "include/IfcPreDefinedCurveFont.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcPreDefinedCurveFont 
		IfcPreDefinedCurveFont::IfcPreDefinedCurveFont() { m_entity_enum = IFCPREDEFINEDCURVEFONT; }
		IfcPreDefinedCurveFont::IfcPreDefinedCurveFont( int id ) { m_id = id; m_entity_enum = IFCPREDEFINEDCURVEFONT; }
		IfcPreDefinedCurveFont::~IfcPreDefinedCurveFont() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPreDefinedCurveFont::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcPreDefinedCurveFont> other = dynamic_pointer_cast<IfcPreDefinedCurveFont>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
		}
		void IfcPreDefinedCurveFont::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPREDEFINEDCURVEFONT" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPreDefinedCurveFont::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPreDefinedCurveFont::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPreDefinedCurveFont, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcPreDefinedCurveFont, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
		}
		void IfcPreDefinedCurveFont::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcPreDefinedItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPreDefinedCurveFont::unlinkSelf()
		{
			IfcPreDefinedItem::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
