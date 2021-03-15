#pragma once

#include "SurfaceBuilderConfig.hpp"

struct Random;
struct Chunk;
struct SurfaceBuilder;

struct ConfiguredSurfaceBuilder {
    SurfaceBuilder* builder{};
    SurfaceBuilderConfig config{};

    void setSeed(int64_t seed);
    void buildSurface(Random& rand, Chunk& chunk, int xStart, int zStart, int startHeight, double noise, BlockData defaultBlock, BlockData defaultFluid, int sealevel);
};