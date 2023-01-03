#include "options.h"
#include "config.h"

static constexpr auto USAGE =
    R"(Cpp GUI.
  Usage:
          cpp-gui [options]

  Options:
          -h --help         Show this screen.
          -v --verbose      Verbose output.
          --width=WIDTH     Screen width in pixels [default: 1024].
          --height=HEIGHT   Screen height in pixels [default: 1024].
)";

Options::Options(std::vector<std::string> const &argv) {
  args = docopt::docopt(USAGE, argv,
                        true,                  // show help if requested
                        app::project_version); // version string

  if (args["--verbose"].asBool())
    spdlog::set_level(spdlog::level::debug);

  width  = static_cast<unsigned int>(args["--width"].asLong());
  height = static_cast<unsigned int>(args["--height"].asLong());
}

void Options::checkOptions() const {
  if (width < 8 || height < 8) {
    spdlog::error("Command line options are out of reasonable range.");
    for (auto const &arg : args) {
      if (arg.second.isString()) {
        spdlog::info("Parameter set: {}='{}'", arg.first, arg.second.asString());
      }
    }
    abort();
  }
}