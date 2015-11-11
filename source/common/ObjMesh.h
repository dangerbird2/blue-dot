// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/

#ifndef __OBJLOADER__
#define __OBJLOADER__

#include "Angel.h"
#include <vector>
#include <list>
#include <iomanip>
#include <glm/glm.hpp>

//using namespace Angel;



class Mesh {
public:
  bool hasUV;

  std::vector<glm::vec3> positions;
  std::vector<glm::vec2> uvs;
  std::vector<glm::vec3> normals;

  glm::vec3 Box_min =
      glm::vec3(std::numeric_limits<float>::max(),
                std::numeric_limits<float>::max(),
                std::numeric_limits<float>::max());
  glm::vec3 Box_max = glm::vec3(0, 0, 0);

  unsigned int getNumTri() { return positions.size() / 3; }

  class SphereTriangle {
  public:
    SphereTriangle(glm::vec3 _p1, glm::vec3 _p2, glm::vec3 _p3) : a(_p1), b(_p2), c(_p3) { };
    glm::vec3 a;
    glm::vec3 b;
    glm::vec3 c;
  };


  bool loadOBJ(const char *path);

  virtual bool make_sphere(int steps = 8);

  static glm::vec3 set_length(glm::vec3 p1, float r)
  {

    float rl = r / p1.length();
    return glm::vec3(p1.x * rl, p1.y * rl, p1.z * rl);
  }

  friend std::ostream &operator<<(std::ostream &os, const Mesh &v);
};

std::ostream& operator<<(std::ostream& os, const glm::vec3& v);

std::ostream& operator<<(std::ostream& os, const glm::vec2& v);

std::ostream& operator<<(std::ostream& os, const glm::vec4& v);


#endif //#ifndef __OBJLOADER__
