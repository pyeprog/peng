#pragma once

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <array>

namespace quadmesh {

namespace buid = boost::uuids;

template<short N_DIM>
class Coordinate {
 public:
  Coordinate(double x, double y) : id_{buid::random_generator()()}, coords_{{x, y}} {};
  double x() const { return coords_[0]; };
  double y() const { return coords_[1]; };

 private:
  buid::uuid id_;
  std::array<double, N_DIM> coords_;
};

}