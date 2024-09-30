#include "polyhedron_node.h"

void PolyhedronNode::AddVertex(vec::fixed<3> vert) {
    vertices.push_back(vert);
}
