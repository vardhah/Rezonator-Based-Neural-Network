/*
 * MIMO_private.h
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

#ifndef RTW_HEADER_MIMO_private_h_
#define RTW_HEADER_MIMO_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "MIMO.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern void MIMO_RBNN_NN_Init(DW_RBNN_NN_MIMO_T *localDW);
extern void MIMO_RBNN_NN(creal_T rtu_u1, real_T rtu_df, const real_T rtu_F[8],
  real_T rtu_u2, real_T rtu_stop, real_T rtu_alp, B_RBNN_NN_MIMO_T *localB,
  DW_RBNN_NN_MIMO_T *localDW);
extern void MIMO_RBNN_output(const real_T rtu_dft[8], const real_T
  rtu_freq_char[8], B_RBNN_output_MIMO_T *localB);
extern void MIMO_RBNN_NN_Term(DW_RBNN_NN_MIMO_T *localDW);

#endif                                 /* RTW_HEADER_MIMO_private_h_ */
