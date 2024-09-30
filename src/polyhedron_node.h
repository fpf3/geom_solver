#pragma once

#include <memory>
#include <vector>

#include <armadillo>

using namespace arma;

struct PolyhedronNode {
    PolyhedronNode()
        : origin(vec(3, fill::zeros)) // init to zero origin
        , rot(eye(3,3))
    {}

    PolyhedronNode(vec::fixed<3> origin)
        :rot(eye(3,3))
    {}

    ~PolyhedronNode()
    {}

    void AddVertex(vec::fixed<3> vert);
    void AddChild(PolyhedronNode child);
    void SetParentEdge(int i1, int i2);

    std::vector<std::shared_ptr<PolyhedronNode>> children;
    std::vector<vec::fixed<3>> vertices;
    std::pair<vec::fixed<3>,vec::fixed<3>> parent_edge; // edge linking to parent, in parent's coordinate system

    std::map<std::uint32_t, std::pair<vec::fixed<3>,vec::fixed<3>>> edgemap;

    vec::fixed<3> origin;
    mat::fixed<3,3> rot;
};
