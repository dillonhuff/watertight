#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "parse_stl.h"
#include "triangular_mesh.h"

namespace watertight {

  TEST_CASE("Volume") {
    triangular_mesh mesh = parse_stl("./test/meshes/Box1x1x1.stl", 0.0001);

    REQUIRE(within_eps(mesh.volume(), 1.0, 0.0001));
  }
}
