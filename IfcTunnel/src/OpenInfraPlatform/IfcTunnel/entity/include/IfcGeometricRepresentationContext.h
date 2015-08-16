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
#include "IfcCoordinateReferenceSystemSelect.h"
#include "IfcRepresentationContext.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcDimensionCount;
		class IfcAxis2Placement;
		class IfcDirection;
		class IfcGeometricRepresentationSubContext;
		//ENTITY
		class IfcGeometricRepresentationContext : public IfcCoordinateReferenceSystemSelect, public IfcRepresentationContext
		{
		public:
			IfcGeometricRepresentationContext();
			IfcGeometricRepresentationContext( int id );
			~IfcGeometricRepresentationContext();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcGeometricRepresentationContext"; }


			// IfcRepresentationContext -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>											m_ContextIdentifier;		//optional
			//  shared_ptr<IfcLabel>											m_ContextType;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRepresentation> >					m_RepresentationsInContext_inverse;

			// IfcGeometricRepresentationContext -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcDimensionCount>								m_CoordinateSpaceDimension;
			double														m_Precision;				//optional
			shared_ptr<IfcAxis2Placement>								m_WorldCoordinateSystem;
			shared_ptr<IfcDirection>										m_TrueNorth;				//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcGeometricRepresentationSubContext> >	m_HasSubContexts_inverse;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
