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

}
