#pragma once

#include "coordinate.h"
#include <utility>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <vector>

namespace quadmesh {

namespace buid = boost::uuids;

typedef std::vector<Coord2D> Coord2Ds;

class Division {
 public:
  Division(Coord2Ds exterior) : id_{buid::random_generator()()},
                                exterior_{std::move(exterior)} {};

  Division(Coord2Ds exterior, std::vector<Coord2Ds> interiors) : id_{buid::random_generator()()},
                                                                 exterior_{std::move(exterior)},
                                                                 interiors_{std::move(interiors)} {};

 private:
  buid::uuid id_;
  std::vector<Coord2D> exterior_;
  std::vector<std::vector<Coord2D>> interiors_;
};

}

