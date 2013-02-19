/**
* @file
*
* @section LICENSE
*
* OsmAnd - Android navigation software based on OSM maps.
* Copyright (C) 2010-2013  OsmAnd Authors listed in AUTHORS file
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __OBF_POI_REGION_SECTION_H_
#define __OBF_POI_REGION_SECTION_H_

#include <OsmAndCore.h>
#include <memory>
#include <list>
#include <string>
#include <google/protobuf/io/coded_stream.h>
#include <ObfSection.h>

namespace OsmAnd {

    namespace gpb = google::protobuf;

    /**
    'POI Region' section of OsmAnd Binary File
    */
    struct OSMAND_CORE_API ObfPoiRegionSection : public ObfSection
    {
        std::list<std::string> _categories;
        std::list< std::list<std::string> > _subcategories;
        //List<AmenityType> categoriesType = new ArrayList<AmenityType>();
        
        double _leftLongitude;
        double _rightLongitude;
        double _topLatitude;
        double _bottomLatitude;
    protected:
        static void read(gpb::io::CodedInputStream* cis, ObfPoiRegionSection* section, bool readCategories);

    private:
        static void readPoiBoundariesIndex(gpb::io::CodedInputStream* cis, ObfPoiRegionSection* section);
        static void readCategory(gpb::io::CodedInputStream* cis, ObfPoiRegionSection* section);

    friend class ObfReader;
    };

} // namespace OsmAnd

#endif // __OBF_POI_REGION_SECTION_H_