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
#include "IfcPresentationItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcIdentifier;
		class IfcCartesianTransformationOperator2D;
		class IfcTextureCoordinate;
		class IfcSurfaceStyleWithTextures;
		//ENTITY
		class IfcSurfaceTexture : public IfcPresentationItem
		{
		public:
			IfcSurfaceTexture();
			IfcSurfaceTexture( int id );
			~IfcSurfaceTexture();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSurfaceTexture"; }


			// IfcPresentationItem -----------------------------------------------------------

			// IfcSurfaceTexture -----------------------------------------------------------
			// attributes:
			bool													m_RepeatS;
			bool													m_RepeatT;
			shared_ptr<IfcIdentifier>							m_Mode;						//optional
			shared_ptr<IfcCartesianTransformationOperator2D>		m_TextureTransform;			//optional
			std::vector<shared_ptr<IfcIdentifier> >				m_Parameter;				//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcTextureCoordinate> >			m_IsMappedBy_inverse;
			std::vector<weak_ptr<IfcSurfaceStyleWithTextures> >	m_UsedInStyles_inverse;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

