#pragma once

#include "../model/division.h"

namespace quadmesh {

class DivisionCornerChecker {
 public:
  static DivisionCornerChecker of(const Division& division, double abs_angle_threshold_of_corner);
  DivisionCornerChecker() = delete;

 private:
  const Division &division_;
  double abs_angle_threshold_of_corner_;
};

}