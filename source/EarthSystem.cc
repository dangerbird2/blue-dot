/**
 * @file ${FILE}
 * @brief 
 * @license ${LICENSE}
 * Copyright (c) 11/5/15, Steven
 * 
 **/
#include "EarthSystem.h"

glm::vec3 sls::EarthSystem::get_solar_position(float days)
{

  // TODO Use kepler's law to calculate system
  using namespace glm;

  auto theta = float(2 * M_PI * days/365.25f);

  auto pos = vec3(cos(theta)* semi_major_axis, sin(theta) * semi_major_axis, 0.0) ;

  return pos;

}
