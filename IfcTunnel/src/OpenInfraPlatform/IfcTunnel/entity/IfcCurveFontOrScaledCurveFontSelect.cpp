/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <map>
#include "../model/shared_ptr.h"
#include "../model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "include/IfcCurveStyleFontSelect.h"
#include "include/IfcCurveFontOrScaledCurveFontSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcCurveFontOrScaledCurveFontSelect 
		IfcCurveFontOrScaledCurveFontSelect::IfcCurveFontOrScaledCurveFontSelect() {}
		IfcCurveFontOrScaledCurveFontSelect::~IfcCurveFontOrScaledCurveFontSelect() {}
		shared_ptr<IfcCurveFontOrScaledCurveFontSelect> IfcCurveFontOrScaledCurveFontSelect::readStepData( std::string& arg, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			// Read SELECT TYPE
			if( arg.size() == 0 ){ return shared_ptr<IfcCurveFontOrScaledCurveFontSelect>(); }
			if( arg[0] == '#' )
			{
				int id=atoi( arg.substr(1,arg.length()-1).c_str() );
				std::map<int,shared_ptr<IfcTunnelEntity> >::const_iterator it_entity = map.find( id );
				if( it_entity != map.end() )
				{
					shared_ptr<IfcCurveFontOrScaledCurveFontSelect> type_object = dynamic_pointer_cast<IfcCurveFontOrScaledCurveFontSelect>(it_entity->second);
					return type_object;
				}
				else
				{
					std::stringstream strs;
					strs << "Object width id " << id << " not found";
					throw IfcTunnelException( strs.str() );
				}
			}
			else if( arg.compare("$")==0 )
			{
				return shared_ptr<IfcCurveFontOrScaledCurveFontSelect>();
			}
			else if( arg.compare("*")==0 )
			{
				return shared_ptr<IfcCurveFontOrScaledCurveFontSelect>();
			}
			else
			{
				// inline arguments
				std::string keyword;
				std::string inline_arg;
				tokenizeInlineArgument( arg, keyword, inline_arg );
				if( keyword.compare("IFCCURVESTYLEFONTSELECT")== 0 )
				{
					return IfcCurveStyleFontSelect::readStepData( inline_arg, map );
				}
				std::stringstream strs;
				strs << "unhandled inline argument: " << arg << " in function IFC4::IfcCurveFontOrScaledCurveFontSelect::readStepData" << std::endl;
				throw IfcTunnelException( strs.str() );
			}
			return shared_ptr<IfcCurveFontOrScaledCurveFontSelect>();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
