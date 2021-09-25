#pragma once

#include <world/gen/feature/structure/Structure.hpp>

struct MineshaftStructure : CfgStructure<MineshaftConfig> {
    MineshaftStructure() : CfgStructure(&MineshaftStructure::createComponents) {}

    bool canGenerate(ChunkGenerator& generator, BiomeProvider& biomes, int64_t seed, Random& random, int x, int z, Biome& biome, const ChunkPos& pos, const StructureConfig& config) override;

    static void createComponents(StructurePieces& pieces, StructureGenerateContext& context, const StructureConfig& config);
};