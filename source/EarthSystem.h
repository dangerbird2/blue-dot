/**
 * @file ${FILE}
 * @brief 
 * @license ${LICENSE}
 * Copyright (c) 11/5/15, Steven
 * 
 **/
#ifndef EARTH_SOLARSYSTEM_H
#define EARTH_SOLARSYSTEM_H

#include <glm/glm.hpp>
#include <chrono>

namespace sls {
class EarthSystem {
public:

  glm::vec3 earth_position = glm::vec3(0.f, 0.f, 0.f);

  double aphelion = 150100000.f;
  double perihelion = 150100000.f;
  double semi_major_axis = 149598023.f;
  double eccentricity = 0.0167086f;

  double inclination = float(7.155f * 180/M_PI);

  double radius = 6371.0;


  glm::vec3 get_solar_position(float days);

private:

};
}

#endif //EARTH_SOLARSYSTEM_H
