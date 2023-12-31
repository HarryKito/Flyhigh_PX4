// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: compute_flow_xy_innov_var_and_hx
 *
 * Args:
 *     state: Matrix24_1
 *     P: Matrix24_24
 *     distance: Scalar
 *     R: Scalar
 *     epsilon: Scalar
 *
 * Outputs:
 *     innov_var: Matrix21
 *     H: Matrix24_1
 */
template <typename Scalar>
void ComputeFlowXyInnovVarAndHx(const matrix::Matrix<Scalar, 24, 1>& state,
                                const matrix::Matrix<Scalar, 24, 24>& P, const Scalar distance,
                                const Scalar R, const Scalar epsilon,
                                matrix::Matrix<Scalar, 2, 1>* const innov_var = nullptr,
                                matrix::Matrix<Scalar, 24, 1>* const H = nullptr) {
  // Total ops: 291

  // Input arrays

  // Intermediate terms (28)
  const Scalar _tmp0 = 1 - 2 * std::pow(state(3, 0), Scalar(2));
  const Scalar _tmp1 =
      Scalar(1.0) /
      (distance + epsilon * (2 * math::min<Scalar>(0, (((distance) > 0) - ((distance) < 0))) + 1));
  const Scalar _tmp2 = _tmp1 * (_tmp0 - 2 * std::pow(state(1, 0), Scalar(2)));
  const Scalar _tmp3 = 2 * state(1, 0);
  const Scalar _tmp4 = 2 * state(3, 0);
  const Scalar _tmp5 = _tmp4 * state(6, 0);
  const Scalar _tmp6 = _tmp1 * (_tmp3 * state(4, 0) + _tmp5);
  const Scalar _tmp7 = _tmp3 * state(6, 0);
  const Scalar _tmp8 = _tmp1 * (-_tmp4 * state(4, 0) + _tmp7);
  const Scalar _tmp9 = _tmp4 * state(0, 0);
  const Scalar _tmp10 = _tmp3 * state(2, 0);
  const Scalar _tmp11 = _tmp1 * (_tmp10 - _tmp9);
  const Scalar _tmp12 = 2 * state(0, 0);
  const Scalar _tmp13 = 4 * state(5, 0);
  const Scalar _tmp14 = 2 * state(2, 0);
  const Scalar _tmp15 = _tmp14 * state(6, 0);
  const Scalar _tmp16 = _tmp1 * (-_tmp12 * state(4, 0) - _tmp13 * state(3, 0) + _tmp15);
  const Scalar _tmp17 = _tmp12 * state(6, 0);
  const Scalar _tmp18 = _tmp1 * (-_tmp13 * state(1, 0) + _tmp14 * state(4, 0) + _tmp17);
  const Scalar _tmp19 = _tmp1 * (_tmp12 * state(1, 0) + _tmp4 * state(2, 0));
  const Scalar _tmp20 = _tmp1 * (_tmp0 - 2 * std::pow(state(2, 0), Scalar(2)));
  const Scalar _tmp21 = _tmp1 * (_tmp10 + _tmp9);
  const Scalar _tmp22 = _tmp1 * (-_tmp12 * state(2, 0) + _tmp4 * state(1, 0));
  const Scalar _tmp23 = 4 * state(4, 0);
  const Scalar _tmp24 = _tmp1 * (_tmp12 * state(5, 0) - _tmp23 * state(3, 0) + _tmp7);
  const Scalar _tmp25 = _tmp1 * (-_tmp17 - _tmp23 * state(2, 0) + _tmp3 * state(5, 0));
  const Scalar _tmp26 = _tmp1 * (-_tmp15 + _tmp4 * state(5, 0));
  const Scalar _tmp27 = _tmp1 * (_tmp14 * state(5, 0) + _tmp5);

  // Output terms (2)
  if (innov_var != nullptr) {
    matrix::Matrix<Scalar, 2, 1>& _innov_var = (*innov_var);

    _innov_var(0, 0) =
        R +
        _tmp11 * (P(0, 4) * _tmp8 + P(1, 4) * _tmp18 + P(2, 4) * _tmp6 + P(3, 4) * _tmp16 +
                  P(4, 4) * _tmp11 + P(5, 4) * _tmp2 + P(6, 4) * _tmp19) +
        _tmp16 * (P(0, 3) * _tmp8 + P(1, 3) * _tmp18 + P(2, 3) * _tmp6 + P(3, 3) * _tmp16 +
                  P(4, 3) * _tmp11 + P(5, 3) * _tmp2 + P(6, 3) * _tmp19) +
        _tmp18 * (P(0, 1) * _tmp8 + P(1, 1) * _tmp18 + P(2, 1) * _tmp6 + P(3, 1) * _tmp16 +
                  P(4, 1) * _tmp11 + P(5, 1) * _tmp2 + P(6, 1) * _tmp19) +
        _tmp19 * (P(0, 6) * _tmp8 + P(1, 6) * _tmp18 + P(2, 6) * _tmp6 + P(3, 6) * _tmp16 +
                  P(4, 6) * _tmp11 + P(5, 6) * _tmp2 + P(6, 6) * _tmp19) +
        _tmp2 * (P(0, 5) * _tmp8 + P(1, 5) * _tmp18 + P(2, 5) * _tmp6 + P(3, 5) * _tmp16 +
                 P(4, 5) * _tmp11 + P(5, 5) * _tmp2 + P(6, 5) * _tmp19) +
        _tmp6 * (P(0, 2) * _tmp8 + P(1, 2) * _tmp18 + P(2, 2) * _tmp6 + P(3, 2) * _tmp16 +
                 P(4, 2) * _tmp11 + P(5, 2) * _tmp2 + P(6, 2) * _tmp19) +
        _tmp8 * (P(0, 0) * _tmp8 + P(1, 0) * _tmp18 + P(2, 0) * _tmp6 + P(3, 0) * _tmp16 +
                 P(4, 0) * _tmp11 + P(5, 0) * _tmp2 + P(6, 0) * _tmp19);
    _innov_var(1, 0) =
        R -
        _tmp20 * (-P(0, 4) * _tmp26 - P(1, 4) * _tmp27 - P(2, 4) * _tmp25 - P(3, 4) * _tmp24 -
                  P(4, 4) * _tmp20 - P(5, 4) * _tmp21 - P(6, 4) * _tmp22) -
        _tmp21 * (-P(0, 5) * _tmp26 - P(1, 5) * _tmp27 - P(2, 5) * _tmp25 - P(3, 5) * _tmp24 -
                  P(4, 5) * _tmp20 - P(5, 5) * _tmp21 - P(6, 5) * _tmp22) -
        _tmp22 * (-P(0, 6) * _tmp26 - P(1, 6) * _tmp27 - P(2, 6) * _tmp25 - P(3, 6) * _tmp24 -
                  P(4, 6) * _tmp20 - P(5, 6) * _tmp21 - P(6, 6) * _tmp22) -
        _tmp24 * (-P(0, 3) * _tmp26 - P(1, 3) * _tmp27 - P(2, 3) * _tmp25 - P(3, 3) * _tmp24 -
                  P(4, 3) * _tmp20 - P(5, 3) * _tmp21 - P(6, 3) * _tmp22) -
        _tmp25 * (-P(0, 2) * _tmp26 - P(1, 2) * _tmp27 - P(2, 2) * _tmp25 - P(3, 2) * _tmp24 -
                  P(4, 2) * _tmp20 - P(5, 2) * _tmp21 - P(6, 2) * _tmp22) -
        _tmp26 * (-P(0, 0) * _tmp26 - P(1, 0) * _tmp27 - P(2, 0) * _tmp25 - P(3, 0) * _tmp24 -
                  P(4, 0) * _tmp20 - P(5, 0) * _tmp21 - P(6, 0) * _tmp22) -
        _tmp27 * (-P(0, 1) * _tmp26 - P(1, 1) * _tmp27 - P(2, 1) * _tmp25 - P(3, 1) * _tmp24 -
                  P(4, 1) * _tmp20 - P(5, 1) * _tmp21 - P(6, 1) * _tmp22);
  }

  if (H != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _h = (*H);

    _h.setZero();

    _h(0, 0) = _tmp8;
    _h(1, 0) = _tmp18;
    _h(2, 0) = _tmp6;
    _h(3, 0) = _tmp16;
    _h(4, 0) = _tmp11;
    _h(5, 0) = _tmp2;
    _h(6, 0) = _tmp19;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
