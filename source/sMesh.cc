/**
 * @file ${FILE}
 * @brief 
 * @license ${LICENSE}
 * Copyright (c) 11/6/15, Steven
 * 
 **/
#include "sMesh.h"
#include <algorithm>
#include <numeric>
#include <vector>


using namespace std;
using namespace glm;

std::vector<sls::Vertex> sls::sMesh::pack_vertices()
{
  auto max_len = std::max(std::max(positions.size(), uvs.size()), normals.size());

  vector<Vertex> verts;

  for (auto i = 0; i < max_len; ++i) {

    Vertex v;
    if (positions.size() > i) {
      v.position = glm::vec3(positions[i].x, positions[i].y, positions[i].z);
    } else {
      v.position = glm::vec3(0.f, 0.f, 0.f);
    }
    if (normals.size() > i) {
      v.normal = glm::vec3(normals[i].x, normals[i].y, normals[i].z);
    } else {
      v.normal = glm::vec3(0.f, 0.f, 1.f);
    }

    if (uvs.size() > i) {
      v.uv = glm::vec2(uvs[i].x, uvs[i].y);
    } else {
      v.uv = glm::vec2(0.f, 0.f);
    }
    verts.push_back(v);
  }

  this->vertices = verts;

  return this->vertices;

}

sls::sMesh sls::sMesh::make_cube()
{
  auto mesh = sls::sMesh();
  using namespace glm;
  using namespace std;
//      {vec3(-1.f, -1.f, -1.f), vec3(-1.f, -1.f, -1.f), vec3(-1.f, -1.f, -1.f), vec3(-1.f, -1.f, -1.f) }


  mesh.triangles = {
      0, 1, 2, 3, 2, 0,
      0+3, 1+3, 2+3, 3+3, 2+3, 0+3//,
      //0+6, 1+6, 2+6, 3+6, 2+6, 0+6//,
      //0+9, 1+9, 2+9, 3+9, 2+9, 0+9
  };
  mesh.positions = {
      glm::vec3(-1.f, -1.f, -1.0), glm::vec3(-1.f, 1.f, 0.0), glm::vec3(1.f, 1.f, -1.0),
      glm::vec3(1.f, -1.f, -1.0), // top

      glm::vec3(-1.f, -1.f, 1.f), glm::vec3(-1.f, 1.f, 1.f), glm::vec3(1.f, 1.f, 1.f),
      glm::vec3(1.f, -1.f, 1.f) // bottom

  };

  int ii = 0;



  for (auto &i: mesh.positions) {
    std::cout << i << ",";
  }


  return mesh;
}
