/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"
#include "IfcPreDefinedPropertySet.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcPositiveLengthMeasure;
		class IfcNonNegativeLengthMeasure;
		class IfcLengthMeasure;
		class IfcShapeAspect;
		//ENTITY
		class IfcDoorLiningProperties : public IfcPreDefinedPropertySet
		{
		public:
			IfcDoorLiningProperties();
			IfcDoorLiningProperties( int id );
			~IfcDoorLiningProperties();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcDoorLiningProperties"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcPropertyDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDeclares> >		m_HasContext_inverse;
			//  std::vector<weak_ptr<IfcRelAssociates> >		m_HasAssociations_inverse;

			// IfcPropertySetDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcTypeObject> >		m_DefinesType_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByTemplate> >	m_IsDefinedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByProperties> >	m_DefinesOccurrence_inverse;

			// IfcPreDefinedPropertySet -----------------------------------------------------------

			// IfcDoorLiningProperties -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPositiveLengthMeasure>			m_LiningDepth;				//optional
			shared_ptr<IfcNonNegativeLengthMeasure>		m_LiningThickness;			//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_ThresholdDepth;			//optional
			shared_ptr<IfcNonNegativeLengthMeasure>		m_ThresholdThickness;		//optional
			shared_ptr<IfcNonNegativeLengthMeasure>		m_TransomThickness;			//optional
			shared_ptr<IfcLengthMeasure>					m_TransomOffset;			//optional
			shared_ptr<IfcLengthMeasure>					m_LiningOffset;				//optional
			shared_ptr<IfcLengthMeasure>					m_ThresholdOffset;			//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_CasingThickness;			//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_CasingDepth;				//optional
			shared_ptr<IfcShapeAspect>					m_ShapeAspectStyle;			//optional
			shared_ptr<IfcLengthMeasure>					m_LiningToPanelOffsetX;		//optional
			shared_ptr<IfcLengthMeasure>					m_LiningToPanelOffsetY;		//optional
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

