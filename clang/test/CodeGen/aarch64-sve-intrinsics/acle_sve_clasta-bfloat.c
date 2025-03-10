// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +bf16 -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +bf16 -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s

// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +bf16 -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -o - %s >/dev/null
#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1, A2_UNUSED, A3, A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1, A2, A3, A4) A1##A2##A3##A4
#endif

svbfloat16_t test_svclasta_bf16(svbool_t pg, svbfloat16_t fallback, svbfloat16_t data) {
  // CHECK-LABEL: test_svclasta_bf16
  // CHECK: %[[PG:.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> %pg)
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 8 x bfloat> @llvm.aarch64.sve.clasta.nxv8bf16(<vscale x 8 x i1> %[[PG]], <vscale x 8 x bfloat> %fallback, <vscale x 8 x bfloat> %data)
  // CHECK: ret <vscale x 8 x bfloat> %[[INTRINSIC]]
  // expected-warning@+1 {{implicit declaration of function 'svclasta_bf16'}}
  return SVE_ACLE_FUNC(svclasta, _bf16, , )(pg, fallback, data);
}

bfloat16_t test_svclasta_n_bf16(svbool_t pg, bfloat16_t fallback, svbfloat16_t data) {
  // CHECK-LABEL: test_svclasta_n_bf16
  // CHECK: %[[PG:.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> %pg)
  // CHECK: %[[INTRINSIC:.*]] = call bfloat @llvm.aarch64.sve.clasta.n.nxv8bf16(<vscale x 8 x i1> %[[PG]], bfloat %fallback, <vscale x 8 x bfloat> %data)
  // CHECK: ret bfloat %[[INTRINSIC]]
  // expected-warning@+1 {{implicit declaration of function 'svclasta_n_bf16'}}
  return SVE_ACLE_FUNC(svclasta, _n_bf16, , )(pg, fallback, data);
}
