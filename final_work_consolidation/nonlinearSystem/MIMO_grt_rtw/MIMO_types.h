/*
 * MIMO_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MIMO".
 *
 * Model version              : 1.503
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Wed Sep 18 11:21:41 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MIMO_types_h_
#define RTW_HEADER_MIMO_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Custom Type definition for MATLAB Function: '<Root>/RBNN_NN' */
#ifndef struct_tag_skA4KFEZ4HPkJJBOYCrevdH
#define struct_tag_skA4KFEZ4HPkJJBOYCrevdH

struct tag_skA4KFEZ4HPkJJBOYCrevdH
{
  uint32_T SafeEq;
  uint32_T Absolute;
  uint32_T NaNBias;
  uint32_T NaNWithFinite;
  uint32_T FiniteWithNaN;
  uint32_T NaNWithNaN;
};

#endif                                 /*struct_tag_skA4KFEZ4HPkJJBOYCrevdH*/

#ifndef typedef_skA4KFEZ4HPkJJBOYCrevdH_MIMO_T
#define typedef_skA4KFEZ4HPkJJBOYCrevdH_MIMO_T

typedef struct tag_skA4KFEZ4HPkJJBOYCrevdH skA4KFEZ4HPkJJBOYCrevdH_MIMO_T;

#endif                                /*typedef_skA4KFEZ4HPkJJBOYCrevdH_MIMO_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T_MIMO_T
#define typedef_emxArray_real_T_MIMO_T

typedef struct emxArray_real_T emxArray_real_T_MIMO_T;

#endif                                 /*typedef_emxArray_real_T_MIMO_T*/

#ifndef struct_tag_sJCxfmxS8gBOONUZjbjUd9E
#define struct_tag_sJCxfmxS8gBOONUZjbjUd9E

struct tag_sJCxfmxS8gBOONUZjbjUd9E
{
  boolean_T CaseSensitivity;
  boolean_T StructExpand;
  char_T PartialMatching[6];
  boolean_T IgnoreNulls;
};

#endif                                 /*struct_tag_sJCxfmxS8gBOONUZjbjUd9E*/

#ifndef typedef_sJCxfmxS8gBOONUZjbjUd9E_MIMO_T
#define typedef_sJCxfmxS8gBOONUZjbjUd9E_MIMO_T

typedef struct tag_sJCxfmxS8gBOONUZjbjUd9E sJCxfmxS8gBOONUZjbjUd9E_MIMO_T;

#endif                                /*typedef_sJCxfmxS8gBOONUZjbjUd9E_MIMO_T*/

/* Custom Type definition for MATLAB Function: '<Root>/software_rezonator1' */
#ifndef typedef_emxArray_creal_T_8x8_MIMO_T
#define typedef_emxArray_creal_T_8x8_MIMO_T

typedef struct {
  creal_T data[64];
  int32_T size[2];
} emxArray_creal_T_8x8_MIMO_T;

#endif                                 /*typedef_emxArray_creal_T_8x8_MIMO_T*/

#ifndef typedef_emxArray_creal_T_8_MIMO_T
#define typedef_emxArray_creal_T_8_MIMO_T

typedef struct {
  creal_T data[8];
  int32_T size;
} emxArray_creal_T_8_MIMO_T;

#endif                                 /*typedef_emxArray_creal_T_8_MIMO_T*/

/* Parameters (default storage) */
typedef struct P_MIMO_T_ P_MIMO_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_MIMO_T RT_MODEL_MIMO_T;

#endif                                 /* RTW_HEADER_MIMO_types_h_ */
