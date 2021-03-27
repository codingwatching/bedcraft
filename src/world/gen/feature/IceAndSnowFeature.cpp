#include "IceAndSnowFeature.hpp"
#include "../../WorldGenRegion.hpp"
#include "../../biome/Biome.hpp"
#include "../../../block/Block.hpp"
#include "../../../block/Blocks.hpp"
#include "../../../block/SnowyDirtBlock.hpp"

bool IceAndSnowFeature::generate(WorldGenRegion& region, ChunkGenerator &generator, Random &random, glm::ivec3 pos, const FeatureConfig &config) {
    for (int x = 0; x < 16; x++) {
        for (int z = 0; z < 16; z++) {
            const int xpos = pos.x + x;
            const int zpos = pos.z + z;
            const int ypos = region.getHeight(/*Heightmap::Type::MOTION_BLOCKING,*/ xpos, zpos);
            const glm::ivec3 blockpos1{xpos, ypos, zpos};
            const glm::ivec3 blockpos2{xpos, ypos - 1, zpos};
            auto biome = region.getBiome(blockpos1);
            if (biome->doesWaterFreeze(region, blockpos2, false)) {
                region.setData(blockpos2, Blocks::ICE->getDefaultState()/*, 2*/);
            }

            if (biome->doesSnowGenerate(region, blockpos1)) {
                region.setData(blockpos1, Blocks::SNOW->getDefaultState()/*, 2*/);
                const auto data = region.getData(blockpos2);
                if (data.hasProperty(SnowyDirtBlock::SNOWY)) {
//                    region.setData(blockpos2, data.with(SnowyDirtBlock::SNOWY, true)/*, 2*/);
                }
            }
        }
    }
    return true;
}