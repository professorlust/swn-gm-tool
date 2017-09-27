#ifndef FACTION_ASSET_MAP_HPP
#define FACTION_ASSET_MAP_HPP

#include <list>
#include <string>
#include <vector>

#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>

#include "AssetDTO.hpp"
#include "FactionDTO.hpp"

namespace SwnGmTool
{
    typedef std::list<AssetDTO> Asset_List;

    struct FactionAssetControl
    {
        FactionDTO Faction;
        Asset_List AssetList;
    };

    typedef FactionAssetControl FAC;

    class FactionAssetMap : public std::vector<FAC>
    {
        public:
            std::vector<FAC>::iterator find(std::string);
    };

    template<class Archive>
    void serialize(Archive& archive, FAC& f)
    {
        archive(cereal::make_nvp("Faction", f.Faction), 
                cereal::make_nvp("AssetList", f.AssetList) );
    }
}

#endif
