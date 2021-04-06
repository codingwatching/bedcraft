#include "Features.hpp"
#include "OreFeature.hpp"
#include "TreeFeature.hpp"
#include "LakesFeature.hpp"
#include "VinesFeature.hpp"
#include "BambooFeature.hpp"
#include "BlockPileFeature.hpp"
#include "DecoratedFeature.hpp"
#include "IceAndSnowFeature.hpp"
#include "RandomPatchFeature.hpp"
#include "SingleRandomFeature.hpp"
#include "DefaultFlowersFeature.hpp"
#include "BigRedMushroomFeature.hpp"
#include "BigBrownMushroomFeature.hpp"
#include "TwoFeatureChoiceFeature.hpp"
#include "MultipleWithChanceRandomFeature.hpp"

std::map<std::string, std::unique_ptr<Feature>> Features::features;
Feature* Features::NO_OP;
Feature* Features::TREE;
FlowersFeature* Features::FLOWER;
FlowersFeature* Features::NO_BONEMEAL_FLOWER;
Feature* Features::RANDOM_PATCH;
Feature* Features::BLOCK_PILE;
Feature* Features::SPRING_FEATURE;
Feature* Features::CHORUS_PLANT;
Feature* Features::EMERALD_ORE;
Feature* Features::VOID_START_PLATFORM;
Feature* Features::DESERT_WELL;
Feature* Features::FOSSIL;
Feature* Features::HUGE_RED_MUSHROOM;
Feature* Features::HUGE_BROWN_MUSHROOM;
Feature* Features::ICE_SPIKE;
Feature* Features::GLOWSTONE_BLOB;
Feature* Features::FREEZE_TOP_LAYER;
Feature* Features::VINES;
Feature* Features::MONSTER_ROOM;
Feature* Features::BLUE_ICE;
Feature* Features::ICEBERG;
Feature* Features::FOREST_ROCK;
Feature* Features::DISK;
Feature* Features::ICE_PATCH;
Feature* Features::LAKE;
Feature* Features::ORE;
Feature* Features::END_SPIKE;
Feature* Features::END_ISLAND;
Feature* Features::END_GATEWAY;
SeaGrassFeature* Features::SEAGRASS;
Feature* Features::KELP;
Feature* Features::CORAL_TREE;
Feature* Features::CORAL_MUSHROOM;
Feature* Features::CORAL_CLAW;
Feature* Features::SEA_PICKLE;
Feature* Features::SIMPLE_BLOCK;
Feature* Features::BAMBOO;
Feature* Features::HUGE_FUNGUS;
Feature* Features::NETHER_FOREST_VEGETATION;
Feature* Features::WEEPING_VINES;
Feature* Features::TWISTING_VINES;
Feature* Features::BASALT_COLUMNS;
Feature* Features::DELTA_FEATURE;
Feature* Features::NETHERRACK_REPLACE_BLOBS;
Feature* Features::FILL_LAYER;
BonusChestFeature* Features::BONUS_CHEST;
Feature* Features::BASALT_PILLAR;
Feature* Features::NO_SURFACE_ORE;
Feature* Features::RANDOM_SELECTOR;
Feature* Features::SIMPLE_RANDOM_SELECTOR;
Feature* Features::RANDOM_BOOLEAN_SELECTOR;
Feature* Features::DECORATED;

template <typename T, typename... Args>
static T* createFeature(std::string name, Args&&... args) {
    auto feature = new T(std::forward<Args>(args)...);
    Features::features.emplace(std::move(name), feature);
    return feature;
}

void Features::registerFeatures() {
//    NO_OP = createFeature<NoOpFeature>("no_op");
    TREE = createFeature<TreeFeature>("tree");
    FLOWER = createFeature<DefaultFlowersFeature>("flower");
    NO_BONEMEAL_FLOWER = createFeature<DefaultFlowersFeature>("no_bonemeal_flower");
    RANDOM_PATCH = createFeature<RandomPatchFeature>("random_patch");
    BLOCK_PILE = createFeature<BlockPileFeature>("block_pile");
//    SPRING_FEATURE = createFeature<SpringFeature>("spring_feature");
//    CHORUS_PLANT = createFeature<ChorusPlantFeature>("chorus_plant");
//    EMERALD_ORE = createFeature<ReplaceBlockFeature>("emerald_ore");
//    VOID_START_PLATFORM = createFeature<VoidStartPlatformFeature>("void_start_platform");
//    DESERT_WELL = createFeature<DesertWellsFeature>("desert_well");
//    FOSSIL = createFeature<FossilsFeature>("fossil");
    HUGE_RED_MUSHROOM = createFeature<BigRedMushroomFeature>("huge_red_mushroom");
    HUGE_BROWN_MUSHROOM = createFeature<BigBrownMushroomFeature>("huge_brown_mushroom");
//    ICE_SPIKE = createFeature<IceSpikeFeature>("ice_spike");
//    GLOWSTONE_BLOB = createFeature<GlowstoneBlobFeature>("glowstone_blob");
    FREEZE_TOP_LAYER = createFeature<IceAndSnowFeature>("freeze_top_layer");
    VINES = createFeature<VinesFeature>("vines");
//    MONSTER_ROOM = createFeature<DungeonsFeature>("monster_room");
//    BLUE_ICE = createFeature<BlueIceFeature>("blue_ice");
//    ICEBERG = createFeature<IcebergFeature>("iceberg");
//    FOREST_ROCK = createFeature<BlockBlobFeature>("forest_rock");
//    DISK = createFeature<SphereReplaceFeature>("disk");
//    ICE_PATCH = createFeature<IcePathFeature>("ice_patch");
    LAKE = createFeature<LakesFeature>("lake");
    ORE = createFeature<OreFeature>("ore");
//    END_SPIKE = createFeature<EndSpikeFeature>("end_spike");
//    END_ISLAND = createFeature<EndIslandFeature>("end_island");
//    END_GATEWAY = createFeature<EndGatewayFeature>("end_gateway");
//    SEAGRASS = createFeature<SeaGrassFeature>("seagrass");
//    KELP = createFeature<KelpFeature>("kelp");
//    CORAL_TREE = createFeature<CoralTreeFeature>("coral_tree");
//    CORAL_MUSHROOM = createFeature<CoralMushroomFeature>("coral_mushroom");
//    CORAL_CLAW = createFeature<CoralClawFeature>("coral_claw");
//    SEA_PICKLE = createFeature<SeaPickleFeature>("sea_pickle");
//    SIMPLE_BLOCK = createFeature<BlockWithContextFeature>("simple_block");
    BAMBOO = createFeature<BambooFeature>("bamboo");
//    HUGE_FUNGUS = createFeature<HugeFungusFeature>("huge_fungus");
//    NETHER_FOREST_VEGETATION = createFeature<NetherVegetationFeature>("nether_forest_vegetation");
//    WEEPING_VINES = createFeature<WeepingVineFeature>("weeping_vines");
//    TWISTING_VINES = createFeature<TwistingVineFeature>("twisting_vines");
//    BASALT_COLUMNS = createFeature<BasaltColumnFeature>("basalt_columns");
//    DELTA_FEATURE = createFeature<BasaltDeltasStructure>("delta_feature");
//    NETHERRACK_REPLACE_BLOBS = createFeature<NetherackBlobReplacementStructure>("netherrack_replace_blobs");
//    FILL_LAYER = createFeature<FillLayerFeature>("fill_layer");
//    BONUS_CHEST = createFeature<BonusChestFeature>("bonus_chest");
//    BASALT_PILLAR = createFeature<BasaltPillarFeature>("basalt_pillar");
//    NO_SURFACE_ORE = createFeature<NoExposedOreFeature>("no_surface_ore");
    RANDOM_SELECTOR = createFeature<MultipleWithChanceRandomFeature>("random_selector");
    SIMPLE_RANDOM_SELECTOR = createFeature<SingleRandomFeature>("simple_random_selector");
    RANDOM_BOOLEAN_SELECTOR = createFeature<TwoFeatureChoiceFeature>("random_boolean_selector");
    DECORATED = createFeature<DecoratedFeature>("decorated");
}
