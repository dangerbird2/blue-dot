// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/

#ifndef __OBJLOADER__
#define __OBJLOADER__

#include "Angel.h"
#include <vector>
#include <list>
#include <glm/glm>

using namespace Angel;

namespace sls {

struct Vertex {

};

}

class Mesh {
public:
  bool hasUV;

  std::vector<vec4> vertices;
  std::vector<vec2> uvs;
  std::vector<vec3> normals;

  vec3 Box_min =
      vec3(std::numeric_limits<float>::max(), std::numeric_limits<float>::max(),
           std::numeric_limits<float>::max());
  vec3 Box_max = vec3(0, 0, 0);

  unsigned int getNumTri() { return vertices.size() / 3; }

  class SphereTriangle {
  public:
    SphereTriangle(vec3 _p1, vec3 _p2, vec3 _p3) : a(_p1), b(_p2), c(_p3){};
    vec3 a;
    vec3 b;
    vec3 c;
  };

  bool loadOBJ(const char* path);

  bool makeSphere(int steps = 8);

  vec3 setLength(vec3 p1, float r) {
    float rl = r / length(p1);
    return vec3(p1.x * rl, p1.y * rl, p1.z * rl);
  }

  friend std::ostream& operator<<(std::ostream& os, const Mesh& v);
};


#endif //#ifndef __OBJLOADER__
