cmake_minimum_required(VERSION 3.15)
project(
  cpp-gui
  VERSION 0.1.0
  LANGUAGES CXX)

find_package(spdlog REQUIRED)
find_package(docopt REQUIRED)
find_package(SFML REQUIRED)
find_package(imgui REQUIRED)

add_executable(${PROJECT_NAME} 
  app.cpp
  options.cpp
  imgui-sfml/imgui-SFML.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog docopt::docopt SFML::SFML imgui::imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE project_options project_warnings)

add_subdirectory(config)
