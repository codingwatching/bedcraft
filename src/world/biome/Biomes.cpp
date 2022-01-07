#include "Biomes.hpp"
#include "Biome.hpp"

#include <Json.hpp>
#include <ResourceManager.hpp>

Registry<Biome> Biomes::biomes;

void Biomes::init() {
    static const auto ids = std::map<std::string, int> {
        { "ocean", 0 },
        { "plains", 1 },
        { "desert", 2 },
        { "mountains", 3 },
        { "forest", 4 },
        { "taiga", 5 },
        { "swamp", 6 },
        { "river", 7 },
        { "nether_wastes", 8 },
        { "the_end", 9 },
        { "frozen_ocean", 10 },
        { "frozen_river", 11 },
        { "snowy_tundra", 12 },
        { "snowy_mountains", 13 },
        { "mushroom_fields", 14 },
        { "mushroom_field_shore", 15 },
        { "beach", 16 },
        { "desert_hills", 17 },
        { "wooded_hills", 18 },
        { "taiga_hills", 19 },
        { "mountain_edge", 20 },
        { "jungle", 21 },
        { "jungle_hills", 22 },
        { "jungle_edge", 23 },
        { "deep_ocean", 24 },
        { "stone_shore", 25 },
        { "snowy_beach", 26 },
        { "birch_forest", 27 },
        { "birch_forest_hills", 28 },
        { "dark_forest", 29 },
        { "snowy_taiga", 30 },
        { "snowy_taiga_hills", 31 },
        { "giant_tree_taiga", 32 },
        { "giant_tree_taiga_hills", 33 },
        { "wooded_mountains", 34 },
        { "savanna", 35 },
        { "savanna_plateau", 36 },
        { "badlands", 37 },
        { "wooded_badlands_plateau", 38 },
        { "badlands_plateau", 39 },
        { "small_end_islands", 40 },
        { "end_midlands", 41 },
        { "end_highlands", 42 },
        { "end_barrens", 43 },
        { "warm_ocean", 44 },
        { "lukewarm_ocean", 45 },
        { "cold_ocean", 46 },
        { "deep_warm_ocean", 47 },
        { "deep_lukewarm_ocean", 48 },
        { "deep_cold_ocean", 49 },
        { "deep_frozen_ocean", 50 },
        { "the_void", 127 },
        { "sunflower_plains", 129 },
        { "desert_lakes", 130 },
        { "gravelly_mountains", 131 },
        { "flower_forest", 132 },
        { "taiga_mountains", 133 },
        { "swamp_hills", 134 },
        { "ice_spikes", 140 },
        { "modified_jungle", 149 },
        { "modified_jungle_edge", 151 },
        { "tall_birch_forest", 155 },
        { "tall_birch_hills", 156 },
        { "dark_forest_hills", 157 },
        { "snowy_taiga_mountains", 158 },
        { "giant_spruce_taiga", 160 },
        { "giant_spruce_taiga_hills", 161 },
        { "modified_gravelly_mountains", 162 },
        { "shattered_savanna", 163 },
        { "shattered_savanna_plateau", 164 },
        { "eroded_badlands", 165 },
        { "modified_wooded_badlands_plateau", 166 },
        { "modified_badlands_plateau", 167 },
        { "bamboo_jungle", 168 },
        { "bamboo_jungle_hills", 169 },
        { "soul_sand_valley", 170 },
        { "crimson_forest", 171 },
        { "warped_forest", 172 },
        { "basalt_deltas", 173 }
    };

    ResourceManager::enumerate("definitions/biomes/", [](std::istream& stream) {
        auto o = Json::Read::read(stream).value();
        auto&& name = o.at("name").as_string().value();

        biomes.add(ids.at(name), name, std::make_unique<Biome>(Biome{
            .climate {
               .precipitation = o.at("precipitation"),
               .temperature = o.at("temperature"),
               .temperatureModifier = o.at("temperature_modifier"),
               .downfall = o.at("downfall")
            },
            .biomeGenerationSettings{
               .surfaceBuilder = o.at("surface_builder"),
               .carvers = o.at("carvers"),
               .features = o.at("features"),
               .structures = o.at("structures")
            },
            .mobSpawnInfo{
               .creatureSpawnProbability = o.at("creature_spawn_probability"),
               .spawners = o.at("spawners"),
               .spawnCosts = o.at("spawn_costs"),
               .playerSpawnFriendly = o.at("player_spawn_friendly"),
            },
            .depth = o.at("depth"),
            .scale = o.at("scale"),
            .category = o.at("category"),
            .effects = o.at("effects")
        }));
    });

//    for (const auto& [name, biome] : Biomes::biomes.objects) {
//        std::ofstream out{fmt::format("definitions/biomes/{}.json", name), std::ios::binary};
//        out << Json{
//            {"name", name},
//            {"depth", biome->depth},
//            {"scale", biome->scale},
//            {"precipitation", biome->climate.precipitation},
//            {"category", biome->category},
//            {"temperature", biome->climate.temperature},
//            {"temperature_modifier", biome->climate.temperatureModifier},
//            {"downfall", biome->climate.downfall},
//            {"player_spawn_friendly", biome->mobSpawnInfo.playerSpawnFriendly},
//            {"creature_spawn_probability", biome->mobSpawnInfo.creatureSpawnProbability},
//            {"effects", biome->effects},
//            {"surface_builder", biome->biomeGenerationSettings.surfaceBuilder},
//            {"carvers", biome->biomeGenerationSettings.carvers},
//            {"features", biome->biomeGenerationSettings.features},
//            {"structures", biome->biomeGenerationSettings.structures},
//            {"spawners", biome->mobSpawnInfo.spawners},
//            {"spawn_costs", biome->mobSpawnInfo.spawnCosts}
//        };
//    }
}