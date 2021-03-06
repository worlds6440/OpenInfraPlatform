/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universit�t M�nchen
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_OkstraExport_37e91449_2c4b_4ad1_8308_5c5c876098c9_h
#define OpenInfraPlatform_Infrastructure_OkstraExport_37e91449_2c4b_4ad1_8308_5c5c876098c9_h

#include "OpenInfraPlatform/Infrastructure/Export/Export.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment2DBased3D.h"

#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API OkstraExport : public Export
		{
		public:
			//! Default constructor.
			OkstraExport(int majorVersion, int minorVersion, buw::ReferenceCounted<buw::AlignmentModel> am, buw::ReferenceCounted<buw::DigitalElevationModel> dem, const std::string& filename);

			//! Virtual destructor.
			virtual ~OkstraExport();

		private:
			class OkstraExportImpl;
			std::shared_ptr<OkstraExportImpl> impl_;

		}; // end class OkstraExport
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::OkstraExport;
}

#endif // end define OpenInfraPlatform_Infrastructure_OkstraExport_37e91449_2c4b_4ad1_8308_5c5c876098c9_h
