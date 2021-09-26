#pragma once

#include <world/gen/feature/structure/StructurePiece.hpp>

struct BastionRemnantPiece : StructurePiece {
    BastionRemnantPiece(Random& random, int x, int z) : StructurePiece(0, BoundingBox{}) {}

    bool addComponentParts(WorldGenRegion& region, StructureManager& structureManager, ChunkGenerator& generator, Random& random, const BoundingBox& bb, const ChunkPos& chunkPos, const BlockPos& blockPos) override;
};