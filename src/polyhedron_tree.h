#pragma once

#include <memory>
#include <vector>

#include "polyhedron_node.h"

struct PolyhedronTree {
    PolyhedronTree();
    ~PolyhedronTree();

    std::shared_ptr<PolyhedronNode> root;
};
