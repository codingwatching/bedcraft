#include "StructureFeatures.hpp"
#include "Structures.hpp"
#include "Structure.hpp"

#include <fstream>
#include <filesystem>
#include <configs.hpp>

Registry<StructureFeature> StructureFeatures::registry{};

void StructureFeatures::init() {
    for (auto&& entry : std::filesystem::directory_iterator{"definitions/configured_structure_features"}) {
        if (!entry.is_regular_file()) {
            continue;
        }

        auto o = Json::Read::read(std::ifstream{entry.path(), std::ios::binary}).value();
        auto structure = Structures::registry.get(o.at("type").to_string()).value();
        auto config = structure->deserialize(o.at("config")).value();

        configure(entry.path().stem().string(), structure, config);
    }

//    for (auto&& [name, structure] : registry.objects) {
//        std::ofstream out{fmt::format("definitions/configured_structure_features/{}.json", name), std::ios::binary};
//        out << Json{
//            {"type", structure->structure},
//            {"config", structure->config}
//        };
//    }
}
