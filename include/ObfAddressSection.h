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

#ifndef __OBF_ADDRESS_SECTION_H_
#define __OBF_ADDRESS_SECTION_H_

#include <memory>
#include <tuple>
#include <string>
#include <stdint.h>
#include <limits>

#include <OsmAndCore.h>

#include <QList>

#include <google/protobuf/io/coded_stream.h>
#include <ObfSection.h>
#include <OBF.pb.h>

namespace OsmAnd {

    namespace gpb = google::protobuf;

    namespace Model {
        class StreetIntersection;
        class Street;
        class StreetGroup;
        class Building;
    } // namespace Model

    /**
    'Address' section of OsmAnd Binary File
    */
    struct OSMAND_CORE_API ObfAddressSection : public ObfSection
    {
        struct OSMAND_CORE_API AddressBlocksSection : public ObfSection
        {
            typedef OBF::OsmAndAddressIndex_CitiesIndex_CitiesType _Type;
            enum Type : int
            {
                CitiesOrTowns = _Type::OsmAndAddressIndex_CitiesIndex_CitiesType_CitiesOrTowns,
                Villages = _Type::OsmAndAddressIndex_CitiesIndex_CitiesType_Villages,
                Postcodes = _Type::OsmAndAddressIndex_CitiesIndex_CitiesType_Postcodes,
            };

            AddressBlocksSection(class ObfReader* owner);
            virtual ~AddressBlocksSection();

            Type _type;

            void loadSteetGroupsFromBlock(QList< std::shared_ptr<Model::StreetGroup> >& list);
        protected:
            static void read(ObfReader* reader, AddressBlocksSection* section);
            static void readStreetGroups(ObfReader* reader, AddressBlocksSection* section, QList< std::shared_ptr<Model::StreetGroup> >& list);
            static std::shared_ptr<Model::StreetGroup> readStreetGroupHeader(ObfReader* reader, AddressBlocksSection* section, unsigned int offset);

        private:

        friend struct OsmAnd::ObfAddressSection;
        };

        ObfAddressSection(class ObfReader* owner);
        virtual ~ObfAddressSection();

        QString _latinName;
        
        //! ???
        int _indexNameOffset;

        QList< std::shared_ptr<AddressBlocksSection> > _blocksSections;
        
        //LatLon calculatedCenter = null;

        static void loadStreetGroups(ObfReader* reader, ObfAddressSection* section, QList< std::shared_ptr<Model::StreetGroup> >& list, uint8_t typeBitmask = std::numeric_limits<uint8_t>::max());
        static void loadStreetsFromGroup(ObfReader* reader, Model::StreetGroup* group, QList< std::shared_ptr<Model::Street> >& list);
        static void loadBuildingsFromStreet(ObfReader* reader, Model::Street* street, QList< std::shared_ptr<Model::Building> >& list);
        static void loadIntersectionsFromStreet(ObfReader* reader, Model::Street* street, QList< std::shared_ptr<Model::StreetIntersection> >& list);
    protected:
        static void read(ObfReader* reader, ObfAddressSection* section);
        static void readStreetGroups(ObfReader* reader, ObfAddressSection* section, QList< std::shared_ptr<Model::StreetGroup> >& list, uint8_t typeBitmask = std::numeric_limits<uint8_t>::max());
        static void readStreetsFromGroup(ObfReader* reader, Model::StreetGroup* group, QList< std::shared_ptr<Model::Street> >& list);
        static void readStreet(ObfReader* reader, Model::StreetGroup* group, Model::Street* street);
        static void readBuildingsFromStreet(ObfReader* reader, Model::Street* street, QList< std::shared_ptr<Model::Building> >& list);
        static void readBuilding(ObfReader* reader, Model::Street* street, Model::Building* building);
        static void readIntersectionsFromStreet(ObfReader* reader, Model::Street* street, QList< std::shared_ptr<Model::StreetIntersection> >& list);
        static void readIntersectedStreet(ObfReader* reader, Model::Street* street, Model::StreetIntersection* intersection);

    private:

    friend class OsmAnd::ObfReader;
    };

} // namespace OsmAnd

#endif // __OBF_ADDRESS_SECTION_H_
