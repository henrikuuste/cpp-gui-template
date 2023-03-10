#include "common.h"

#include <SFML/Graphics.hpp>

#include "gui/stats.hpp"
#include "imgui-sfml/imgui-SFML.h"
#include "options.h"

void handleEvents(sf::RenderWindow &window);

static constexpr float DPI_SCALE = 2.0F;

int main(int argc, const char **argv) {
  Options const opt({std::next(argv), std::next(argv, argc)});
  opt.checkOptions();

  spdlog::info("Starting application");

  sf::RenderWindow window(sf::VideoMode(opt.width, opt.height), "Template application",
                          sf::Style::Titlebar | sf::Style::Close);
  if (!ImGui::SFML::Init(window)) {
    spdlog::error("Failed to initialize ImGUI");
    abort();
  }
  ImGui::GetIO().FontGlobalScale =
      DPI_SCALE; // DPI scaling for 4K screen...need to figure this out for actual use

  AppContext ctx;
  StatsGUI statsGUI;
  while (window.isOpen()) {
    ctx.dtime = ctx.deltaClock.restart();
    ImGui::SFML::Update(window, ctx.dtime);

    statsGUI.draw(ctx);
    window.clear();
    ImGui::SFML::Render(window);
    window.display();

    handleEvents(window);
  }
  spdlog::info("Exiting");
  ImGui::SFML::Shutdown();
}

void handleEvents(sf::RenderWindow &window) {
  sf::Event event{};
  while (window.pollEvent(event)) {
    ImGui::SFML::ProcessEvent(event);

    if (event.type == sf::Event::Closed) {
      window.close();
    }

    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Escape) { // NOLINT
        window.close();
      }
    }
  }
}