/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "../model/shared_ptr.h"

namespace OpenInfraPlatform
{
    namespace Ifc4
    {
        class Ifc4Object;

        std::string encodeStepString( std::string arg_str );
        void writeIntList( std::stringstream& stream, const std::vector<int>& vec );
        void writeIntList2D( std::stringstream& stream, const std::vector<std::vector<int> >& vec );
        void writeIntList3D( std::stringstream& stream, const std::vector<std::vector<std::vector<int> > >& vec );
        void writeDoubleList( std::stringstream& stream, const std::vector<double>& vec );
        void writeDoubleList2D( std::stringstream& stream, const std::vector<std::vector<double> >& vec );
        void writeDoubleList3D( std::stringstream& stream, const  std::vector<std::vector<std::vector<double> > >& vec );
        void writeConstCharList( std::stringstream& stream, const std::vector<const char*>& vec );
        void writeStringList( std::stringstream& stream, const std::vector<std::string>& vec );

        template<class T>
        void writeTypeOfIntList( std::stringstream& stream, const std::vector<shared_ptr<T> >& vec )
        {
            //(38,12,4)
            stream << "(";
            typename std::vector<shared_ptr<T> >::const_iterator it;
            for( it=vec.begin(); it!=vec.end(); ++it )
            {
                if( it != vec.begin() )
                {
                    stream << ",";
                }
                stream << (*it)->m_value;
            }
            stream << ")";
        }

        template<class T>
        void writeTypeOfRealList( std::stringstream& stream, const std::vector<shared_ptr<T> >& vec )
        {
            //(.38,12.0,.04)
            stream << "(";
            typename std::vector<shared_ptr<T> >::const_iterator it;

            for( it=vec.begin(); it!=vec.end(); ++it )
            {
                if( it != vec.begin() )
                {
                    stream << ",";
                }
                stream << (*it)->m_value;
            }
            stream << ")";
        }

        template<class T>
        void writeTypeOfRealList2D( std::stringstream& stream, const std::vector<std::vector<shared_ptr<T> > >& vec )
        {
            //((.38,12.0,.04),(.38,1.0,346.0),(1.8,1.0,.04))
            typename std::vector<std::vector<shared_ptr<T> > >::const_iterator it;
            stream << "(";
            for( it=vec.begin(); it!=vec.end(); ++it )
            {
                const std::vector<shared_ptr<T> >& inner_vec = (*it);

                if( it != vec.begin() )
                {
                    stream << ",";
                }
                writeTypeOfRealList( stream, inner_vec );
            }
            stream << ")";
        }

        template<class T>
        void writeEntityList( std::stringstream& stream, const std::vector<shared_ptr<T> >& vec )
        {
            //(#287,#291,$,#299)
            stream << "(";
            typename std::vector<shared_ptr<T> >::const_iterator it;
            for( it=vec.begin(); it!=vec.end(); ++it )
            {
                if( it != vec.begin() )
                {
                    stream << ",";
                }

                if( (*it) )
                {
                    stream << "#" << (*it)->getId();
                }
                else
                {
                    stream << "$";
                }
            }
            stream << ")";
        }

        template<class T>
        void writeEntityList2D( std::stringstream& stream, const std::vector<std::vector<shared_ptr<T> > >& vec )
        {
            //((#287,#291,$,#299),(#287,#291,$,#299))
            stream << "(";
            typename std::vector<std::vector<shared_ptr<T> > >::const_iterator it;
            for( it=vec.begin(); it!=vec.end(); ++it )
            {
                const std::vector<shared_ptr<T> >& inner_vec = (*it);

                if( it != vec.begin() )
                {
                    stream << ",";
                }
                writeEntityList( stream, inner_vec );
            }
            stream << ")";
        }

        template<class T>
        void writeEntityList3D( std::stringstream& stream, const std::vector<std::vector<std::vector<shared_ptr<T> > > >& vec )
        {
            //(((#287,#291,$,#299),(#287,#291,$,#299)),((#287,#291,$,#299),(#287,#291,$,#299)))
            stream << "(";
            typename std::vector<std::vector<std::vector<shared_ptr<T> > > >::const_iterator it;
            for( it=vec.begin(); it!=vec.end(); ++it )
            {
                const std::vector<std::vector<shared_ptr<T> > >& inner_vec = (*it);

                if( it != vec.begin() )
                {
                    stream << ",";
                }
                writeEntityList2D( stream, inner_vec );

            }
            stream << ")";
        }

        template<class T>
        void writeTypeList( std::stringstream& stream, const std::vector<shared_ptr<T> >& vec, bool is_select_type = false )
        {
            //(#287,#291,$,#299)
            if( vec.size() == 0 )
            {
                stream << "()";
                return;
            }
            stream << "(";
            typename std::vector<shared_ptr<T> >::const_iterator it;
            for( it=vec.begin(); it!=vec.end(); ++it )
            {
                if( it != vec.begin() )
                {
                    stream << ",";
                }
                if( (*it) )
                {
                    (*it)->getStepParameter( stream, is_select_type );
                }
                else
                {
                    stream << "$";
                }
            }
            stream << ")";
        }

        template<class T>
        void writeTypeList2D( std::stringstream& stream, const std::vector<std::vector<shared_ptr<T> > >& vec, bool is_select_type = false )
        {
            //(#287,#291,$,#299)
            if( vec.size() == 0 )
            {
                stream << "()";
                return;
            }
            stream << "(";

            typename std::vector<std::vector<shared_ptr<T> > >::const_iterator it_outer;
            typename std::vector<shared_ptr<T> >::const_iterator it_inner;

            for( it_outer=vec.begin(); it_outer!=vec.end(); ++it_outer )
            {
                const std::vector<shared_ptr<T> >&inner_vec = (*it_outer);

                if( it_outer != vec.begin() )
                {
                    stream << "),(";
                }

                for( it_inner=inner_vec.begin(); it_inner!=inner_vec.end(); ++it_inner )
                {
                    if( it_inner != inner_vec.begin() )
                    {
                        stream << ",";
                    }
                    if( (*it_inner) )
                    {
                        (*it_inner)->getStepParameter( stream, is_select_type );
                    }
                    else
                    {
                        stream << "$";
                    }
                }
            }
            stream << ")";
        }
    } // end namespace Ifc4
} // end namespace OpenInfraPlatform