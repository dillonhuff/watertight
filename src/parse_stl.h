#ifndef PARSE_STL_H
#define PARSE_STL_H

#include <string>
#include <vector>

#include "triangular_mesh.h"

namespace watertight {

  struct point {
    float x;
    float y;
    float z;

    point() : x(0), y(0), z(0) {}
    point(float xp, float yp, float zp) : x(xp), y(yp), z(zp) {}
  };

  static inline float dot(const point l, const point r) {
    return l.x*r.x + l.y*r.y + l.z*r.z;
  }

  static inline point operator-(const point l, const point r) {
    return point(l.x - r.x, l.y - r.y, l.z - r.z);
  }

  struct triangle {
    point normal;
    point v1;
    point v2;
    point v3;
    triangle(point normalp, point v1p, point v2p, point v3p) :
      normal(normalp), v1(v1p), v2(v2p), v3(v3p) {}
  };

  static inline point vertex_0(const triangle t) {
    return t.v1;
  }


  static inline point vertex_1(const triangle t) {
    return t.v2;
  }

  static inline point vertex_2(const triangle t) {
    return t.v3;
  }
  
  static inline point cross(const point u, const point v) {
    double x = u.y * v.z - v.y * u.z;
    double y = u.z * v.x - v.z * u.x;
    double z = u.x * v.y - v.x * u.y;
    return point(x, y, z);
  }
  

  std::ostream& operator<<(std::ostream& out, const triangle& t);

  struct stl_data {
    std::string name;
    std::vector<triangle> triangles;

    stl_data(std::string namep) : name(namep) {}
  };

  stl_data parse_stl(const std::string& stl_path);

}

#endif
