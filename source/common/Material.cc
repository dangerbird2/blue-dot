#include "Material.h"

#include <regex>
#include <png.h>
#include <iostream>

namespace sls {

Material::Material() { }

Material::Material(Material &cpy) { }

Material::Material(Material &&mov) :
    diffuse_tex(std::move(mov.diffuse_tex)) { }

Material::~Material() { }


void
Material::build_textures(GLuint program, std::string const &diffuse_tex_file)
noexcept
{
  using namespace std;
  auto is_png = regex_match(diffuse_tex_file, regex(".*\\.png(?!.)"));

  if (!is_png) {
    cerr << "WARNING!: " << diffuse_tex_file << " is not a png file\n";
  }




}


GLuint copy_texture(GLuint tex)
{
  GLuint cpy = 0;

  glGenTextures(1, &cpy);

  return cpy;
}

}