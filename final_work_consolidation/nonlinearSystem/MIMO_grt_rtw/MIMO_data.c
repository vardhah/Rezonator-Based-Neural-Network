/*
 * MIMO_data.c
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

#include "MIMO.h"
#include "MIMO_private.h"

/* Block parameters (default storage) */
P_MIMO_T MIMO_P = {
  /* Expression: 1
   * Referenced by: '<S6>/Gain1'
   */
  1.0,

  /* Expression: 0.2
   * Referenced by: '<Root>/GainRBNN1'
   */
  0.2,

  /* Expression: 0
   * Referenced by: '<Root>/Training ON1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Training OFF1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Training ON'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Training OFF'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/y'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/yp1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Random Number_5'
   */
  0.0,

  /* Computed Parameter: RandomNumber_5_StdDev
   * Referenced by: '<S6>/Random Number_5'
   */
  0.70710678118654757,

  /* Expression: 0
   * Referenced by: '<S6>/Random Number_5'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/GainRBNN2'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S1>/Sine Wave1'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave1'
   */
  0.0,

  /* Expression: 431
   * Referenced by: '<S1>/Sine Wave1'
   */
  431.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S1>/Sine Wave7'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave7'
   */
  0.0,

  /* Expression: 28230
   * Referenced by: '<S1>/Sine Wave7'
   */
  28230.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave7'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S1>/Sine Wave8'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave8'
   */
  0.0,

  /* Expression: 33927
   * Referenced by: '<S1>/Sine Wave8'
   */
  33927.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave8'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S1>/Sine Wave11'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave11'
   */
  0.0,

  /* Expression: 30637
   * Referenced by: '<S1>/Sine Wave11'
   */
  30637.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave9'
   */
  0.0,

  /* Expression: 53787
   * Referenced by: '<S1>/Sine Wave9'
   */
  53787.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave9'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S1>/Sine Wave10'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave10'
   */
  0.0,

  /* Expression: 47000
   * Referenced by: '<S1>/Sine Wave10'
   */
  47000.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave10'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Sine Wave4'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave4'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S1>/Sine Wave4'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave4'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Sine Wave14'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave14'
   */
  0.0,

  /* Expression: 43
   * Referenced by: '<S1>/Sine Wave14'
   */
  43.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave14'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Sine Wave15'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave15'
   */
  0.0,

  /* Expression: 89
   * Referenced by: '<S1>/Sine Wave15'
   */
  89.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave15'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Sine Wave17'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave17'
   */
  0.0,

  /* Expression: 167
   * Referenced by: '<S1>/Sine Wave17'
   */
  167.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave17'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Sine Wave20'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave20'
   */
  0.0,

  /* Expression: 193
   * Referenced by: '<S1>/Sine Wave20'
   */
  193.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave20'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Sine Wave16'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave16'
   */
  0.0,

  /* Expression: 229
   * Referenced by: '<S1>/Sine Wave16'
   */
  229.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave16'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Sine Wave23'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave23'
   */
  0.0,

  /* Expression: 271
   * Referenced by: '<S1>/Sine Wave23'
   */
  271.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave23'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Sine Wave21'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave21'
   */
  0.0,

  /* Expression: 337
   * Referenced by: '<S1>/Sine Wave21'
   */
  337.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave21'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Sine Wave22'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave22'
   */
  0.0,

  /* Expression: 379
   * Referenced by: '<S1>/Sine Wave22'
   */
  379.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave22'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Sine Wave18'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave18'
   */
  0.0,

  /* Expression: 409
   * Referenced by: '<S1>/Sine Wave18'
   */
  409.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave18'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Sine Wave19'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave19'
   */
  0.0,

  /* Expression: 499
   * Referenced by: '<S1>/Sine Wave19'
   */
  499.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave19'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/GainRBNN3'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<Root>/u2'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<Root>/LR_RBNN'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<Root>/y1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/yp2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/u1'
   */
  1.0,

  /* Expression: 0.3
   * Referenced by: '<Root>/LR_RBNN1'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S7>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Delay1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Out_RBNN1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Out_RBNN2'
   */
  1.0,

  /* Computed Parameter: y_DelayLength
   * Referenced by: '<Root>/y'
   */
  1U,

  /* Computed Parameter: yp1_DelayLength
   * Referenced by: '<Root>/yp1'
   */
  1U,

  /* Computed Parameter: y1_DelayLength
   * Referenced by: '<Root>/y1'
   */
  1U,

  /* Computed Parameter: yp2_DelayLength
   * Referenced by: '<Root>/yp2'
   */
  1U,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<S7>/Delay'
   */
  1U,

  /* Computed Parameter: Delay1_DelayLength
   * Referenced by: '<S7>/Delay1'
   */
  1U,

  /* Computed Parameter: signal_CD_CurrentSetting
   * Referenced by: '<Root>/signal_C//D'
   */
  0U,

  /* Computed Parameter: signal_AB_CurrentSetting
   * Referenced by: '<Root>/signal_A//B'
   */
  0U,

  /* Computed Parameter: signalX_CurrentSetting
   * Referenced by: '<Root>/signalX'
   */
  0U,

  /* Computed Parameter: signal_JK_CurrentSetting
   * Referenced by: '<Root>/signal_J//K'
   */
  1U,

  /* Computed Parameter: signal_JK1_CurrentSetting
   * Referenced by: '<Root>/signal_J//K1'
   */
  1U,

  /* Computed Parameter: signal_CD2_CurrentSetting
   * Referenced by: '<Root>/signal_C//D2'
   */
  0U,

  /* Computed Parameter: signal_JK2_CurrentSetting
   * Referenced by: '<Root>/signal_J//K2'
   */
  1U,

  /* Computed Parameter: TT_CurrentSetting
   * Referenced by: '<Root>/TT'
   */
  1U,

  /* Computed Parameter: Signal_switch4_CurrentSetting
   * Referenced by: '<Root>/Signal_switch4'
   */
  0U,

  /* Computed Parameter: TT1_CurrentSetting
   * Referenced by: '<Root>/TT1'
   */
  0U,

  /* Computed Parameter: ExternalStop_RBNN_CurrentSettin
   * Referenced by: '<Root>/External Stop_RBNN'
   */
  0U,

  /* Computed Parameter: ExternalStop_RBNN1_CurrentSetti
   * Referenced by: '<Root>/External Stop_RBNN1'
   */
  0U
};
