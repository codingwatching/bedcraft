#include "ChunkGenerator.hpp"

#include "../chunk/Chunk.hpp"
#include "../biome/provider/BiomeProvider.hpp"
#include "../../WorldGenRegion.hpp"
#include "../../util/Random.hpp"

struct ExampleStructurePiece : StructurePiece {
    ExampleStructurePiece(int32_t pos_x, int32_t pos_z) {
        coordBaseMode = SOUTH;
        boundingBox = StructureBoundingBox::withSize(pos_x - 1, 6, pos_z - 1, 3, 10, 3);
    }

    void place(WorldGenRegion& region, StructureBoundingBox sbb) override {
        for (auto y = 0; y < 10; y++) {
            setBlock(region, sbb, 0, y, 0, {Block::iron_bars->id, 2 | 4});
            setBlock(region, sbb, 0, y, 1, {Block::wood->id, 0});
            setBlock(region, sbb, 0, y, 2, {Block::iron_bars->id, 8 | 4});

            setBlock(region, sbb, 1, y, 0, {Block::wood->id, 0});
            setBlock(region, sbb, 1, y, 1, {Block::wood->id, 0});
            setBlock(region, sbb, 1, y, 2, {Block::wood->id, 0});

            setBlock(region, sbb, 2, y, 0, {Block::iron_bars->id, 2 | 1});
            setBlock(region, sbb, 2, y, 1, {Block::wood->id, 0});
            setBlock(region, sbb, 2, y, 2, {Block::iron_bars->id, 8 | 1});
        }
    }
};

struct ExampleStructureStart : StructureStart {
    void build(int32_t pos_x, int32_t pos_z) override {
        pieces.emplace_back(new ExampleStructurePiece(pos_x + 8, pos_z + 8));
    }
};

void ChunkGenerator::generateStructures(WorldGenRegion &region, Chunk& chunk) {
    if (std::abs(chunk.pos.x) % 2 == std::abs(chunk.pos.z) % 2) {
        auto start = std::make_shared<ExampleStructureStart>();
        start->build(chunk.pos.getStartX(), chunk.pos.getStartZ());
        start->updateBoundingBox();
        chunk.structureStarts.emplace_back(std::move(start));
    }
}

ChunkGenerator::ChunkGenerator(std::unique_ptr<BiomeProvider>&& biomeProvider) : biomeProvider(std::move(biomeProvider)) {}

void ChunkGenerator::getStructureReferences(WorldGenRegion &region, Chunk& chunk) {
    const auto sbb = StructureBoundingBox::fromChunkPos(chunk.pos.x, chunk.pos.z);

    for (auto x = chunk.pos.x - 8; x <= chunk.pos.x + 8; x++) {
        for (auto z = chunk.pos.z - 8; z <= chunk.pos.z + 8; z++) {
            for (auto& start : region.getChunk(x, z)->structureStarts) {
                if (sbb.intersect(start->boundingBox)) {
                    chunk.structureReferences.emplace_back(start);
                }
            }
        }
    }
}

void placeBlock(IBlockWriter auto& blocks, int32_t x, int32_t y, int32_t z, const BlockData& data, const StructureBoundingBox& sbb) {
    if (sbb.contains(x, y, z)) {
        blocks.setData(x, y, z, data);
    }
}

void generateTree(IBlockWriter auto& blocks, int32_t x, int32_t height, int32_t z, Random& rand, const StructureBoundingBox& sbb) {
    const auto treeHeight = 4 + rand.nextInt(0, 2);

    const BlockData leaves{Block::leaves->id, 0};
    const BlockData log{Block::log->id, 0};

    for (auto y = treeHeight - 2; y <= treeHeight + 1; y++) {
        placeBlock(blocks, x - 1, y + height, z - 1, leaves, sbb);
        placeBlock(blocks, x + 0, y + height, z - 1, leaves, sbb);
        placeBlock(blocks, x + 1, y + height, z - 1, leaves, sbb);

        placeBlock(blocks, x - 1, y + height, z, leaves, sbb);
        placeBlock(blocks, x + 0, y + height, z, leaves, sbb);
        placeBlock(blocks, x + 1, y + height, z, leaves, sbb);

        placeBlock(blocks, x - 1, y + height, z + 1, leaves, sbb);
        placeBlock(blocks, x + 0, y + height, z + 1, leaves, sbb);
        placeBlock(blocks, x + 1, y + height, z + 1, leaves, sbb);
    }

    for (auto y = height; y < height + treeHeight; y++) {
        placeBlock(blocks, x, y, z, log, sbb);
    }
}

void ChunkGenerator::generateFeatures(WorldGenRegion &region, Chunk& chunk) {
    Random random{};

    const auto chunkPos = region.getMainChunkPos();
    const auto xStart = chunkPos.getStartX();
    const auto zStart = chunkPos.getStartZ();
    const auto seed = random.setDecorationSeed(region.getSeed(), xStart, zStart);
    const auto sbb = StructureBoundingBox::fromChunkPos(chunkPos.x, chunkPos.z);

    for (auto& structure : chunk.structureReferences) {
        for (auto& piece : structure->pieces) {
            piece->place(region, sbb);
        }
    }

    const BlockData red_flower{Block::red_flower->id, 0};
    const BlockData yellow_flower{Block::yellow_flower->id, 0};

    for (int32_t x = 0; x < 16; x++) {
        const auto xpos = x + xStart;

        for (int32_t z = 0; z < 16; z++) {
            const auto zpos = z + zStart;

			random.setFeatureSeed(seed, xpos, zpos);

            const int32_t ypos = region.getHeight(xpos, zpos);

            if (region.getData(xpos, ypos - 1, zpos).id != Block::water->id) {
                int32_t n = random.nextInt(0, 3000);

                if (n < 15) {
                    generateTree(region, xpos, ypos, zpos, random, sbb);
                } else if (n < 40) {
                    placeBlock(region, xpos, ypos, zpos, red_flower, sbb);
                } else if (n < 80) {
                    placeBlock(region, xpos, ypos, zpos, yellow_flower, sbb);
                } else if (n < 200) {
//                    region.setData(xpos, ypos, zpos, {
//                            BlockData{pallete.getId("tallgrass"), 0},
//                            BlockData{BlockID::AIR, 0}
//                    });
                }
            }
        }
    }
}