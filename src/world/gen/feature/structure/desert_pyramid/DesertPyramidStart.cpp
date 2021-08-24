#include "DesertPyramidStart.hpp"
#include "DesertPyramidPiece.hpp"

void DesertPyramidStructure::Start::createComponents(ChunkGenerator &generator, TemplateManager &templateManager, int chunkx, int chunkz, Biome &biome, const StructureConfig &config, int64_t seed) {
    auto random = Random::fromLargeFeatureSeed(seed, chunkx, chunkz);
    auto piece = new DesertPyramidPiece(random, chunkx << 4, chunkz << 4);
    components.emplace_back(piece);
    recalculateStructureSize();
}