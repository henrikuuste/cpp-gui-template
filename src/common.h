#pragma once

#include <SFML/System.hpp>
#include <spdlog/spdlog.h>

struct AppContext {
  sf::Time dtime;
  sf::Clock deltaClock;
};
