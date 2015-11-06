// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/

#ifndef __OBJLOADER__
#define __OBJLOADER__

#include "Angel.h"
#include <vector>
#include <list>
#include <glm/glm.hpp>

//using namespace Angel;



class Mesh {
public:
  bool hasUV;

  std::vector<Angel::vec4> _vertices;
  std::vector<Angel::vec2> uvs;
  std::vector<Angel::vec3> normals;

  Angel::vec3 Box_min =
      vec3(std::numeric_limits<float>::max(), std::numeric_limits<float>::max(),
           std::numeric_limits<float>::max());
  Angel::vec3 Box_max = vec3(0, 0, 0);

  unsigned int getNumTri() { return _vertices.size() / 3; }

  class SphereTriangle {
  public:
    SphereTriangle(Angel::vec3 _p1, Angel::vec3 _p2, Angel::vec3 _p3) : a(_p1), b(_p2), c(_p3){};
    Angel::vec3 a;
    Angel::vec3 b;
    Angel::vec3 c;
  };

  bool loadOBJ(const char* path);

  bool makeSphere(int steps = 8);

  Angel::vec3 setLength(Angel::vec3 p1, float r) {
    float rl = r / length(p1);
    return Angel::vec3(p1.x * rl, p1.y * rl, p1.z * rl);
  }

  friend std::ostream& operator<<(std::ostream& os, const Mesh& v);
};


#endif //#ifndef __OBJLOADER__
