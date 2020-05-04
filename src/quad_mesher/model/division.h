#pragma once

#include "coordinate.h"
#include <vector>

namespace quadmesh {

class Division {
//TODO: finish this
 private:
  std::vector<Coordinate<2>> exterior_;
  std::vector<std::vector<Coordinate<2>>> interiors_;
};

}

