// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2012 Preferred Networks and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef JUBATUS_CORE_REGRESSION_PASSIVE_AGGRESSIVE_2_HPP_
#define JUBATUS_CORE_REGRESSION_PASSIVE_AGGRESSIVE_2_HPP_

#include <limits>
#include "jubatus/util/data/serialization.h"
#include "linear_regression.hpp"

namespace jubatus {
namespace core {
namespace regression {

class passive_aggressive_2 : public linear_regression {
 public:
  struct config {
    config()
        : regularization_weight(std::numeric_limits<float>::max()),
          sensitivity(0.1f) {
    }
    float regularization_weight;
    float sensitivity;

    template<typename Ar>
    void serialize(Ar& ar) {
      ar & JUBA_NAMED_MEMBER("regularization_weight", regularization_weight)
         & JUBA_NAMED_MEMBER("sensitivity", sensitivity);
    }
  };

  passive_aggressive_2(
      const config& config,
      storage_ptr storage);
  explicit passive_aggressive_2(storage_ptr storage);

  void train(const common::sfv_t& fv, float value);

  void clear();

 private:
  config config_;
  float sum_;
  float sq_sum_;
  float count_;
};

}  // namespace regression
}  // namespace core
}  // namespace jubatus

#endif  // JUBATUS_CORE_REGRESSION_PASSIVE_AGGRESSIVE_2_HPP_
