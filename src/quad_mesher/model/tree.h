#pragma once

#include <vector>

namespace quadmesh {

template<class T>
class TreeNode {
 public:
  TreeNode(const T &data) : data_{&data} {};
  TreeNode(T *p_data) : data_{p_} {};

 private:
  T *p_data_;
  TreeNode *p_next_;
  TreeNode *p_prev_;
  TreeNode *p_parent_;
  std::vector<TreeNode *> children_p_;
};

}