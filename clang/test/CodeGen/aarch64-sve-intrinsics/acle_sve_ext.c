// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -o - %s >/dev/null
#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

svint8_t test_svext_s8(svint8_t op1, svint8_t op2)
{
  // CHECK-LABEL: test_svext_s8
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.ext.nxv16i8(<vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2, i32 0)
  // CHECK: ret <vscale x 16 x i8> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_s8,,)(op1, op2, 0);
}

svint8_t test_svext_s8_1(svint8_t op1, svint8_t op2)
{
  // CHECK-LABEL: test_svext_s8_1
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.ext.nxv16i8(<vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2, i32 255)
  // CHECK: ret <vscale x 16 x i8> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_s8,,)(op1, op2, 255);
}

svint16_t test_svext_s16(svint16_t op1, svint16_t op2)
{
  // CHECK-LABEL: test_svext_s16
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.ext.nxv8i16(<vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2, i32 0)
  // CHECK: ret <vscale x 8 x i16> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_s16,,)(op1, op2, 0);
}

svint16_t test_svext_s16_1(svint16_t op1, svint16_t op2)
{
  // CHECK-LABEL: test_svext_s16_1
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.ext.nxv8i16(<vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2, i32 127)
  // CHECK: ret <vscale x 8 x i16> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_s16,,)(op1, op2, 127);
}

svint32_t test_svext_s32(svint32_t op1, svint32_t op2)
{
  // CHECK-LABEL: test_svext_s32
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.ext.nxv4i32(<vscale x 4 x i32> %op1, <vscale x 4 x i32> %op2, i32 0)
  // CHECK: ret <vscale x 4 x i32> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_s32,,)(op1, op2, 0);
}

svint32_t test_svext_s32_1(svint32_t op1, svint32_t op2)
{
  // CHECK-LABEL: test_svext_s32_1
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.ext.nxv4i32(<vscale x 4 x i32> %op1, <vscale x 4 x i32> %op2, i32 63)
  // CHECK: ret <vscale x 4 x i32> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_s32,,)(op1, op2, 63);
}

svint64_t test_svext_s64(svint64_t op1, svint64_t op2)
{
  // CHECK-LABEL: test_svext_s64
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.ext.nxv2i64(<vscale x 2 x i64> %op1, <vscale x 2 x i64> %op2, i32 0)
  // CHECK: ret <vscale x 2 x i64> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_s64,,)(op1, op2, 0);
}

svint64_t test_svext_s64_1(svint64_t op1, svint64_t op2)
{
  // CHECK-LABEL: test_svext_s64_1
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.ext.nxv2i64(<vscale x 2 x i64> %op1, <vscale x 2 x i64> %op2, i32 31)
  // CHECK: ret <vscale x 2 x i64> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_s64,,)(op1, op2, 31);
}

svuint8_t test_svext_u8(svuint8_t op1, svuint8_t op2)
{
  // CHECK-LABEL: test_svext_u8
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.ext.nxv16i8(<vscale x 16 x i8> %op1, <vscale x 16 x i8> %op2, i32 255)
  // CHECK: ret <vscale x 16 x i8> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_u8,,)(op1, op2, 255);
}

svuint16_t test_svext_u16(svuint16_t op1, svuint16_t op2)
{
  // CHECK-LABEL: test_svext_u16
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.ext.nxv8i16(<vscale x 8 x i16> %op1, <vscale x 8 x i16> %op2, i32 127)
  // CHECK: ret <vscale x 8 x i16> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_u16,,)(op1, op2, 127);
}

svuint32_t test_svext_u32(svuint32_t op1, svuint32_t op2)
{
  // CHECK-LABEL: test_svext_u32
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.ext.nxv4i32(<vscale x 4 x i32> %op1, <vscale x 4 x i32> %op2, i32 63)
  // CHECK: ret <vscale x 4 x i32> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_u32,,)(op1, op2, 63);
}

svuint64_t test_svext_u64(svuint64_t op1, svuint64_t op2)
{
  // CHECK-LABEL: test_svext_u64
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 2 x i64> @llvm.aarch64.sve.ext.nxv2i64(<vscale x 2 x i64> %op1, <vscale x 2 x i64> %op2, i32 31)
  // CHECK: ret <vscale x 2 x i64> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_u64,,)(op1, op2, 31);
}

svfloat16_t test_svext_f16(svfloat16_t op1, svfloat16_t op2)
{
  // CHECK-LABEL: test_svext_f16
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 8 x half> @llvm.aarch64.sve.ext.nxv8f16(<vscale x 8 x half> %op1, <vscale x 8 x half> %op2, i32 127)
  // CHECK: ret <vscale x 8 x half> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_f16,,)(op1, op2, 127);
}

svfloat32_t test_svext_f32(svfloat32_t op1, svfloat32_t op2)
{
  // CHECK-LABEL: test_svext_f32
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 4 x float> @llvm.aarch64.sve.ext.nxv4f32(<vscale x 4 x float> %op1, <vscale x 4 x float> %op2, i32 63)
  // CHECK: ret <vscale x 4 x float> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_f32,,)(op1, op2, 63);
}

svfloat64_t test_svext_f64(svfloat64_t op1, svfloat64_t op2)
{
  // CHECK-LABEL: test_svext_f64
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 2 x double> @llvm.aarch64.sve.ext.nxv2f64(<vscale x 2 x double> %op1, <vscale x 2 x double> %op2, i32 31)
  // CHECK: ret <vscale x 2 x double> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svext,_f64,,)(op1, op2, 31);
}
