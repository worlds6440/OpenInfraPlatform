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
#include "include/IfcBoolean.h"
#include "include/IfcHalfSpaceSolid.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcHalfSpaceSolid 
		IfcHalfSpaceSolid::IfcHalfSpaceSolid() { m_entity_enum = IFCHALFSPACESOLID; }
		IfcHalfSpaceSolid::IfcHalfSpaceSolid( int id ) { m_id = id; m_entity_enum = IFCHALFSPACESOLID; }
		IfcHalfSpaceSolid::~IfcHalfSpaceSolid() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcHalfSpaceSolid::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcHalfSpaceSolid> other = dynamic_pointer_cast<IfcHalfSpaceSolid>(other_entity);
			if( !other) { return; }
			m_BaseSurface = other->m_BaseSurface;
			m_AgreementFlag = other->m_AgreementFlag;
		}
		void IfcHalfSpaceSolid::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCHALFSPACESOLID" << "(";
			if( m_BaseSurface ) { stream << "#" << m_BaseSurface->getId(); } else { stream << "$"; }
			stream << ",";
			if (m_AgreementFlag == false) { stream << ".F."; }
			else if (m_AgreementFlag == true) { stream << ".T."; }
			stream << ");";
		}
		void IfcHalfSpaceSolid::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcHalfSpaceSolid::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcHalfSpaceSolid, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcHalfSpaceSolid, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BaseSurface, map );
			if (_stricmp(args[1].c_str(), ".F.") == 0) { m_AgreementFlag = false; }
			else if (_stricmp(args[1].c_str(), ".T.") == 0) { m_AgreementFlag = true; }
		}
		void IfcHalfSpaceSolid::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcHalfSpaceSolid::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
