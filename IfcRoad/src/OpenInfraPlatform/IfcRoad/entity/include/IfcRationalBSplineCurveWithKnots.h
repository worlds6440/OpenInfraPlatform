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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcBSplineCurveWithKnots.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcReal;
		//ENTITY
		class IfcRationalBSplineCurveWithKnots : public IfcBSplineCurveWithKnots
		{
		public:
			IfcRationalBSplineCurveWithKnots();
			IfcRationalBSplineCurveWithKnots( int id );
			~IfcRationalBSplineCurveWithKnots();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRationalBSplineCurveWithKnots"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcCurve -----------------------------------------------------------

			// IfcBoundedCurve -----------------------------------------------------------

			// IfcBSplineCurve -----------------------------------------------------------
			// attributes:
			//  int											m_Degree;
			//  std::vector<shared_ptr<IfcCartesianPoint> >	m_ControlPointsList;
			//  shared_ptr<IfcBSplineCurveForm>				m_CurveForm;
			//  shared_ptr<IfcLogical>						m_ClosedCurve;
			//  shared_ptr<IfcLogical>						m_SelfIntersect;

			// IfcBSplineCurveWithKnots -----------------------------------------------------------
			// attributes:
			//  std::vector<int >							m_KnotMultiplicities;
			//  std::vector<shared_ptr<IfcParameterValue> >	m_Knots;
			//  shared_ptr<IfcKnotType>						m_KnotSpec;

			// IfcRationalBSplineCurveWithKnots -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcReal> >			m_WeightsData;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

