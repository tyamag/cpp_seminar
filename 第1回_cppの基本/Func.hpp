#pragma once

#include <algorithm>
#include <iterator>
#include <numeric>

namespace Func {

template<class Range, class OutType>
OutType Fold(const Range& range, OutType init) {
  return std::accumulate(std::cbegin(range), std::cend(range), init);
}

template<class Range, class OutType, class BinaryOperation>
OutType Fold(const Range& range, OutType init, BinaryOperation binary_op) {
  return std::accumulate(std::cbegin(range), std::cend(range), init, binary_op);
}

template<class OutType, class Generator>
OutType GenerateN(const OutType& out_type, size_t n, Generator generator) {
  OutType out(n);
  std::generate(std::begin(out), std::end(out), generator);
  return out;  // move
}

template<class Range, class OutType, class UnaryOperation>
OutType Map(const Range& range1, const OutType& out_type, UnaryOperation unary_op) {
  OutType out(std::size(range1));
  std::transform(std::cbegin(range1), std::cend(range1), std::begin(out), unary_op);
  return out;  // move
}

template<class Range1, class Range2, class OutType, class BinaryOperation>
OutType Map(const Range1& range1, const Range2& range2, const OutType& out_type, BinaryOperation binary_op) {
  OutType out(std::size(range1));
  std::transform(std::cbegin(range1), std::cend(range1), std::cbegin(range2), std::begin(out), binary_op);
  return out;  // move
}

template<class Range>
Range Reverse(const Range& range) {
  Range out(range);  // copy
  std::reverse(std::begin(out), std::end(out));
  return out;
}

}