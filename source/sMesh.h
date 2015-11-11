/**
 * @file ${FILE}
 * @brief 
 * @license ${LICENSE}
 * Copyright (c) 11/6/15, Steven
 * 
 **/
#ifndef EARTH_SLSMESH_H
#define EARTH_SLSMESH_H

#include <common/ObjMesh.h>
#include <array>

#include <assimp/mesh.h>
namespace sls {

using Triangle = glm::ivec3;

struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 uv;
};


class sMesh : public Mesh {
public:

  static sMesh make_cube();


  using index_t = uint32_t;

  std::vector<Vertex> pack_vertices();


  std::vector<uint32_t> triangles;


  std::vector<Vertex> const &getVertices() const { return vertices; }


protected:
  std::vector<Vertex> vertices;

  aiMesh *mesh;



};

}

#endif //EARTH_SLSMESH_H
