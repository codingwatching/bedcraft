#include "StructureFeatures.hpp"
#include "Structure.hpp"
#include "Structures.hpp"

Registry<StructureFeature> StructureFeatures::registry{};

StructureFeature* StructureFeatures::PILLAGER_OUTPOST;
StructureFeature* StructureFeatures::MINESHAFT;
StructureFeature* StructureFeatures::MINESHAFT_BADLANDS;
StructureFeature* StructureFeatures::MANSION;
StructureFeature* StructureFeatures::JUNGLE_PYRAMID;
StructureFeature* StructureFeatures::DESERT_PYRAMID;
StructureFeature* StructureFeatures::IGLOO;
StructureFeature* StructureFeatures::SHIPWRECK;
StructureFeature* StructureFeatures::SHIPWRECK_BEACHED;
StructureFeature* StructureFeatures::SWAMP_HUT;
StructureFeature* StructureFeatures::STRONGHOLD;
StructureFeature* StructureFeatures::MONUMENT;
StructureFeature* StructureFeatures::OCEAN_RUIN_COLD;
StructureFeature* StructureFeatures::OCEAN_RUIN_WARM;
StructureFeature* StructureFeatures::FORTRESS;
StructureFeature* StructureFeatures::NETHER_FOSSIL;
StructureFeature* StructureFeatures::END_CITY;
StructureFeature* StructureFeatures::BURIED_TREASURE;
StructureFeature* StructureFeatures::BASTION_REMNANT;
StructureFeature* StructureFeatures::VILLAGE_PLAINS;
StructureFeature* StructureFeatures::VILLAGE_DESERT;
StructureFeature* StructureFeatures::VILLAGE_SAVANNA;
StructureFeature* StructureFeatures::VILLAGE_SNOWY;
StructureFeature* StructureFeatures::VILLAGE_TAIGA;
StructureFeature* StructureFeatures::RUINED_PORTAL;
StructureFeature* StructureFeatures::RUINED_PORTAL_DESERT;
StructureFeature* StructureFeatures::RUINED_PORTAL_JUNGLE;
StructureFeature* StructureFeatures::RUINED_PORTAL_SWAMP;
StructureFeature* StructureFeatures::RUINED_PORTAL_MOUNTAIN;
StructureFeature* StructureFeatures::RUINED_PORTAL_OCEAN;
StructureFeature* StructureFeatures::RUINED_PORTAL_NETHER;

static auto configure(std::string name, Structure* structure, StructureConfig config) -> StructureFeature* {
    return StructureFeatures::registry.add(std::move(name), std::make_unique<StructureFeature>(StructureFeature{
		.structure = structure,
		.config = config
	}));
}

void StructureFeatures::configureStructures() {
//    PILLAGER_OUTPOST = configure("pillager_outpost", Structures::PILLAGER_OUTPOST, new VillageConfig(() -> {
//        return PillagerOutpostPools.field_244088_a;
//    }, 7)));
    MINESHAFT = configure("mineshaft", Structures::MINESHAFT, MineshaftConfig{0.004F, MineshaftType::NORMAL});
    MINESHAFT_BADLANDS = configure("mineshaft_mesa", Structures::MINESHAFT, MineshaftConfig{0.004F, MineshaftType::MESA});
//    MANSION = configure("mansion", Structures::WOODLAND_MANSION, NoFeatureConfig{}));
    JUNGLE_PYRAMID = configure("jungle_pyramid", Structures::JUNGLE_PYRAMID, NoFeatureConfig{});
    DESERT_PYRAMID = configure("desert_pyramid", Structures::DESERT_PYRAMID, NoFeatureConfig{});
//    IGLOO = configure("igloo", Structures::IGLOO, NoFeatureConfig{}));
//    SHIPWRECK = configure("shipwreck", Structures::SHIPWRECK, new ShipwreckConfig(false)));
//    SHIPWRECK_BEACHED = configure("shipwreck_beached", Structures::SHIPWRECK, new ShipwreckConfig(true)));
    SWAMP_HUT = configure("swamp_hut", Structures::SWAMP_HUT, NoFeatureConfig{});
//    STRONGHOLD = configure("stronghold", Structures::STRONGHOLD, NoFeatureConfig{}));
//    MONUMENT = configure("monument", Structures::MONUMENT, NoFeatureConfig{}));
//    OCEAN_RUIN_COLD = configure("ocean_ruin_cold", Structures::OCEAN_RUIN, new OceanRuinConfig(OceanRuinStructures::Type.COLD, 0.3F, 0.9F)));
//    OCEAN_RUIN_WARM = configure("ocean_ruin_warm", Structures::OCEAN_RUIN, new OceanRuinConfig(OceanRuinStructures::Type.WARM, 0.3F, 0.9F)));
//    FORTRESS = configure("fortress", Structures::FORTRESS, NoFeatureConfig{}));
//    NETHER_FOSSIL = configure("nether_fossil", Structures::NETHER_FOSSIL, NoFeatureConfig{}));
//    END_CITY = configure("end_city", Structures::END_CITY, NoFeatureConfig{}));
//    BURIED_TREASURE = configure("buried_treasure", Structures::BURIED_TREASURE, new ProbabilityConfig(0.01F)));
//    BASTION_REMNANT = configure("bastion_remnant", Structures::BASTION_REMNANT, new VillageConfig(() -> {
//        return BastionRemnantsPieces.field_243686_a;
//    }, 6)));
//    VILLAGE_PLAINS = configure("village_plains", Structures::VILLAGE, new VillageConfig(() -> {
//        return PlainsVillagePools.field_244090_a;
//    }, 6)));
//    VILLAGE_DESERT = configure("village_desert", Structures::VILLAGE, new VillageConfig(() -> {
//        return DesertVillagePools.field_243774_a;
//    }, 6)));
//    VILLAGE_SAVANNA = configure("village_savanna", Structures::VILLAGE, new VillageConfig(() -> {
//        return SavannaVillagePools.field_244128_a;
//    }, 6)));
//    VILLAGE_SNOWY = configure("village_snowy", Structures::VILLAGE, new VillageConfig(() -> {
//        return SnowyVillagePools.field_244129_a;
//    }, 6)));
//    VILLAGE_TAIGA = configure("village_taiga", Structures::VILLAGE, new VillageConfig(() -> {
//        return TaigaVillagePools.field_244193_a;
//    }, 6)));
//    RUINED_PORTAL = configure("ruined_portal", Structures::RUINED_PORTAL, new RuinedPortalFeatureConfig(RuinedPortalStructures::Location.STANDARD)));
//    RUINED_PORTAL_DESERT = configure("ruined_portal_desert", Structures::RUINED_PORTAL, new RuinedPortalFeatureConfig(RuinedPortalStructures::Location.DESERT)));
//    RUINED_PORTAL_JUNGLE = configure("ruined_portal_jungle", Structures::RUINED_PORTAL, new RuinedPortalFeatureConfig(RuinedPortalStructures::Location.JUNGLE)));
//    RUINED_PORTAL_SWAMP = configure("ruined_portal_swamp", Structures::RUINED_PORTAL, new RuinedPortalFeatureConfig(RuinedPortalStructures::Location.SWAMP)));
//    RUINED_PORTAL_MOUNTAIN = configure("ruined_portal_mountain", Structures::RUINED_PORTAL, new RuinedPortalFeatureConfig(RuinedPortalStructures::Location.MOUNTAIN)));
//    RUINED_PORTAL_OCEAN = configure("ruined_portal_ocean", Structures::RUINED_PORTAL, new RuinedPortalFeatureConfig(RuinedPortalStructures::Location.OCEAN)));
//    RUINED_PORTAL_NETHER = configure("ruined_portal_nether", Structures::RUINED_PORTAL, new RuinedPortalFeatureConfig(RuinedPortalStructures::Location.NETHER)));
}
