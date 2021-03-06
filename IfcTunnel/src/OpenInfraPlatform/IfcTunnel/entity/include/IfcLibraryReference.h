/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcTunnelObject.h"
#include "IfcLibrarySelect.h"
#include "IfcExternalReference.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcText;
		class IfcLanguageId;
		class IfcLibraryInformation;
		class IfcRelAssociatesLibrary;
		//ENTITY
		class IfcLibraryReference : public IfcLibrarySelect, public IfcExternalReference
		{
		public:
			IfcLibraryReference();
			IfcLibraryReference( int id );
			~IfcLibraryReference();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcLibraryReference"; }


			// IfcExternalReference -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcURIReference>						m_Location;					//optional
			//  shared_ptr<IfcIdentifier>						m_Identification;			//optional
			//  shared_ptr<IfcLabel>								m_Name;						//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_ExternalReferenceForResources_inverse;

			// IfcLibraryReference -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcText>								m_Description;				//optional
			shared_ptr<IfcLanguageId>						m_Language;					//optional
			shared_ptr<IfcLibraryInformation>				m_ReferencedLibrary;		//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcRelAssociatesLibrary> >	m_LibraryRefForObjects_inverse;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

