#pragma once
#include "../common.h"

#include <imgui.h>

class StatsGUI {
public:
  void draw(AppContext &ctx) {
    ImGui::Begin("Stats");
    ImGui::Text("%.1f FPS", static_cast<double>(ImGui::GetIO().Framerate));
    ImGui::End();
  }
};