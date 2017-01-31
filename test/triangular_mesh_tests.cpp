#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "parse_stl.h"
#include "triangular_mesh.h"

using namespace std;

namespace watertight {

  TEST_CASE("Volume") {
    stl_data mesh = parse_stl("./test/meshes/Box1x1x1.stl");

    double vol = volume(mesh.triangles);

    cout << "Volume = " << vol << endl;

    REQUIRE(within_eps(vol, 1.0, 0.0001));
  }
}
