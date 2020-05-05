#pragma once

#include "../model/division.h"

namespace quadmesh {

class DivisionFeature {
 public:
  DivisionFeature(const Division& division): division_{division} {};



 private:
  const Division& division_;
};


}