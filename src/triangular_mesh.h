#pragma once

#include <cmath>

namespace watertight {

  class triangular_mesh {
  public:
    double volume() const { return 1.0; }
  };

  template<typename Num>
  bool within_eps(Num l, Num r, Num eps) {
    Num diff = std::abs(l - r);
    return diff <= eps;
  }

  template<typename Mesh>
  double volume(const Mesh& m) {
    double volume = 0.0;

    for (auto& tri : m) {
      auto n = cross(vertex_1(tri) - vertex_0(tri), vertex_2(tri) - vertex_0(tri));
      volume += dot(vertex_0(tri), n);
    }

    return (1.0 / 6.0)*volume;
  }

}
