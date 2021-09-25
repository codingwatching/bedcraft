#pragma once

#include "JigsawPiece.hpp"

struct SingleJigsawPiece : JigsawPiece {
    std::string location;
    StructureProcessorList* processors;

    SingleJigsawPiece(std::string location, StructureProcessorList* processors, JigsawProjection projection)
        : JigsawPiece(projection)
        , location(std::move(location))
        , processors(processors) {}

    auto to_json() -> Json override;
    static auto from_json(const Json& o) -> std::unique_ptr<JigsawPiece>;
};