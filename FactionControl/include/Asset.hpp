#ifndef ASSET_HPP
#define ASSET_HPP

#include <cstdint>
#include <iostream>
#include <string>

#include <cereal/cereal.hpp>

#include "DiceRoll.hpp"

namespace SwnGmTool
{
    const std::string RatingType[] =
    {
        "Force",
        "Cunning",
        "Wealth"
    };

    const std::string AssetTypes[] =
    {
        "Military Unit",
        "Special Forces",
        "Special",
        "Facility",
        "Tactic",
        "Starship",
        "Logistics Facility"
    };

    struct Asset
    {
        std::string Name;

        std::string RatingType;
        std::string AssetType;

        DiceRoll Attack;
        std::string Defender;
        DiceRoll Counter;

        uint8_t TechLevel;
        uint8_t Cost;

        uint8_t CurrentHP;
        uint8_t MaxHP;
    };

    std::string to_string(const Asset& a)
    {
        return (a.Name + " " + a.RatingType + " " + a.AssetType + " " + to_string(a) + " " + to_string(a.Counter) );
    }

    std::ostream& operator<<(std::ostream& os, const Asset& a)
    {
        os << to_string(a);
        return os;
    }

    template<class Archive>
    void serialize(Archive& archive, Asset& a)
    {
        archive(cereal::make_nvp("Name", a.Name),
                cereal::make_nvp("RatingType", a.RatingType),
                cereal::make_nvp("AssetType", a.AssetType),
                cereal::make_nvp("Attack", a.Attack),
                cereal::make_nvp("Defender", a.Defender),
                cereal::make_nvp("Counter", a.Counter),
                cereal::make_nvp("TechLevel", a.TechLevel),
                cereal::make_nvp("Cost", a.Cost),
                cereal::make_nvp("CurrentHP", a.CurrentHP),
                cereal::make_nvp("MaxHP", a.MaxHP) );
    }
}

#endif
