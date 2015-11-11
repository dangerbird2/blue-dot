#ifndef SLS_MATERIAL_H
#define SLS_MATERIAL_H

#include "Angel.h"

#include <map>

namespace sls {

struct Material {
public:
  Material();
  Material(Material &cpy);
  Material(Material &&mov);

  Material operator=(Material &cpy) { return Material(cpy); }

  virtual ~Material();


  GLuint diffuse_tex;


  void build_textures(GLuint program,
                      std::string const &diffuse_tex_file) noexcept ;

private:


};


GLuint copy_texture(GLuint tex);

} // sls



#endif // SLS_MATERIAL_H
