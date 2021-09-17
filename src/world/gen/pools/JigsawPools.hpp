#pragma once

#include <util/Registry.hpp>

struct JigsawPattern;
struct JigsawPools {
    static Registry<JigsawPattern> pools;

    static void init();
};

struct PlainVillagePools {
    static JigsawPattern* START;

    static void init();
};

struct SnowyVillagePools {
    static JigsawPattern* START;

    static void init();
};

struct SavannaVillagePools {
    static JigsawPattern* START;

    static void init();
};

struct DesertVillagePools {
    static JigsawPattern* START;

    static void init();
};

struct TaigaVillagePools {
    static JigsawPattern* START;

    static void init();
};

struct PillagerOutpostPools {
    static JigsawPattern* START;

    static void init();
};

struct BastionRemnantsPieces {
    static JigsawPattern* START;

    static void init();
};