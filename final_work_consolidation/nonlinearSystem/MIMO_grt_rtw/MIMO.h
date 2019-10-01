/*
 * MIMO.h
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

#ifndef RTW_HEADER_MIMO_h_
#define RTW_HEADER_MIMO_h_
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#ifndef MIMO_COMMON_INCLUDES_
# define MIMO_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* MIMO_COMMON_INCLUDES_ */

#include "MIMO_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals for system '<Root>/RBNN_NN' */
typedef struct {
  real_T dv0[32768];
  real_T dv1[32768];
  real_T dn_a2[8192];
  real_T dv2[2048];
  real_T dv3[2048];
  real_T z2_out_tmp[1024];
  real_T nn_op[8];                     /* '<Root>/RBNN_NN' */
  real_T cost;                         /* '<Root>/RBNN_NN' */
} B_RBNN_NN_MIMO_T;

/* Block states (default storage) for system '<Root>/RBNN_NN' */
typedef struct {
  real_T w1[64];                       /* '<Root>/RBNN_NN' */
  real_T w2[1024];                     /* '<Root>/RBNN_NN' */
  real_T w3[256];                      /* '<Root>/RBNN_NN' */
  real_T vy[2];                        /* '<Root>/RBNN_NN' */
  real_T g1[64];                       /* '<Root>/RBNN_NN' */
  real_T g2[1024];                     /* '<Root>/RBNN_NN' */
  real_T g3[256];                      /* '<Root>/RBNN_NN' */
  real_T itr;                          /* '<Root>/RBNN_NN' */
  real_T J;                            /* '<Root>/RBNN_NN' */
  real_T memory_alloc_flag;            /* '<Root>/RBNN_NN' */
  real_T n;                            /* '<Root>/RBNN_NN' */
  emxArray_real_T_MIMO_T* mult1;       /* '<Root>/RBNN_NN' */
  emxArray_real_T_MIMO_T* mult2;       /* '<Root>/RBNN_NN' */
  emxArray_real_T_MIMO_T* mult3;       /* '<Root>/RBNN_NN' */
  uint32_T state[625];                 /* '<Root>/RBNN_NN' */
  boolean_T w1_not_empty;              /* '<Root>/RBNN_NN' */
  boolean_T w2_not_empty;              /* '<Root>/RBNN_NN' */
  boolean_T w3_not_empty;              /* '<Root>/RBNN_NN' */
  boolean_T mult1_not_empty;           /* '<Root>/RBNN_NN' */
  boolean_T mult2_not_empty;           /* '<Root>/RBNN_NN' */
  boolean_T mult3_not_empty;           /* '<Root>/RBNN_NN' */
} DW_RBNN_NN_MIMO_T;

/* Block signals for system '<Root>/RBNN_output' */
typedef struct {
  real_T yn;                           /* '<Root>/RBNN_output' */
} B_RBNN_output_MIMO_T;

/* Block signals (default storage) */
typedef struct {
  creal_T output_fft;                  /* '<Root>/buffer_of_op_fft1' */
  creal_T output_fft_n;                /* '<Root>/buffer_of_op_fft' */
  real_T GainRBNN2;                    /* '<Root>/GainRBNN2' */
  real_T TT;                           /* '<Root>/TT' */
  real_T ZeroOrderHold3;               /* '<Root>/Zero-Order Hold3' */
  real_T GainRBNN3;                    /* '<Root>/GainRBNN3' */
  real_T Sum[8];                       /* '<Root>/Sum' */
  real_T ExternalStop_RBNN;            /* '<Root>/External Stop_RBNN' */
  real_T ExternalStop_RBNN1;           /* '<Root>/External Stop_RBNN1' */
  real_T Delay;                        /* '<S7>/Delay' */
  real_T Delay1;                       /* '<S7>/Delay1' */
  real_T Out_RBNN1;                    /* '<Root>/Out_RBNN1' */
  real_T Out_RBNN2;                    /* '<Root>/Out_RBNN2' */
  real_T output_difference_vector;     /* '<Root>/buffer_of_op_fft1' */
  real_T output_difference_vector_l;   /* '<Root>/buffer_of_op_fft' */
  real_T yp1;                          /* '<S7>/MATLAB Function' */
  real_T yp2;                          /* '<S7>/MATLAB Function' */
  B_RBNN_output_MIMO_T sf_RBNN_output1;/* '<Root>/RBNN_output1' */
  B_RBNN_output_MIMO_T sf_RBNN_output; /* '<Root>/RBNN_output' */
  B_RBNN_NN_MIMO_T sf_RBNN_NN1;        /* '<Root>/RBNN_NN1' */
  B_RBNN_NN_MIMO_T sf_RBNN_NN;         /* '<Root>/RBNN_NN' */
} B_MIMO_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  emxArray_creal_T_8x8_MIMO_T g;       /* '<Root>/software_rezonator' */
  emxArray_creal_T_8x8_MIMO_T c;       /* '<Root>/software_rezonator' */
  emxArray_creal_T_8x8_MIMO_T g_b;     /* '<Root>/software_rezonator1' */
  emxArray_creal_T_8x8_MIMO_T c_j;     /* '<Root>/software_rezonator1' */
  emxArray_creal_T_8_MIMO_T bfr_rezo_sm;/* '<Root>/software_rezonator' */
  emxArray_creal_T_8_MIMO_T aft_delay; /* '<Root>/software_rezonator' */
  emxArray_creal_T_8_MIMO_T dft_out;   /* '<Root>/software_rezonator' */
  emxArray_creal_T_8_MIMO_T bfr_rezo_sm_p;/* '<Root>/software_rezonator1' */
  emxArray_creal_T_8_MIMO_T aft_delay_l;/* '<Root>/software_rezonator1' */
  emxArray_creal_T_8_MIMO_T dft_out_e; /* '<Root>/software_rezonator1' */
  real_T y_DSTATE;                     /* '<Root>/y' */
  real_T yp1_DSTATE;                   /* '<Root>/yp1' */
  real_T Filter_Highpass_1000Hz_FILT_STA[12];/* '<S6>/Filter_Highpass_1000Hz' */
  real_T Filter_BPF_Narrow_band_FILT_STA[20];/* '<S6>/Filter_BPF_Narrow_band' */
  real_T Filter_LPF_10K_FILT_STATES[14];/* '<S6>/Filter_LPF_10K' */
  real_T Filter_1000Hz_Elliptic_FILT_STA[10];/* '<S6>/Filter_1000Hz_Elliptic' */
  real_T Filter_LPF_500Hz1_FILT_STATES[18];/* '<S6>/Filter_LPF_500Hz1' */
  real_T y1_DSTATE;                    /* '<Root>/y1' */
  real_T yp2_DSTATE;                   /* '<Root>/yp2' */
  real_T Delay_DSTATE;                 /* '<S7>/Delay' */
  real_T Delay1_DSTATE;                /* '<S7>/Delay1' */
  real_T NextOutput;                   /* '<S6>/Random Number_5' */
  real_T n;                            /* '<Root>/software_rezonator1' */
  real_T memory_alloc_flag;            /* '<Root>/software_rezonator1' */
  real_T n_f;                          /* '<Root>/software_rezonator' */
  real_T memory_alloc_flag_g;          /* '<Root>/software_rezonator' */
  struct {
    void *LoggedData;
  } Costs_exp1_PWORK;                  /* '<Root>/Costs_exp1' */

  struct {
    void *LoggedData;
  } Costs_exp2_PWORK;                  /* '<Root>/Costs_exp2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData[4];
  } outputs_PWORK;                     /* '<Root>/outputs' */

  uint32_T RandSeed;                   /* '<S6>/Random Number_5' */
  boolean_T g_not_empty;               /* '<Root>/software_rezonator1' */
  boolean_T c_not_empty;               /* '<Root>/software_rezonator1' */
  boolean_T bfr_rezo_sm_not_empty;     /* '<Root>/software_rezonator1' */
  boolean_T aft_delay_not_empty;       /* '<Root>/software_rezonator1' */
  boolean_T dft_out_not_empty;         /* '<Root>/software_rezonator1' */
  boolean_T g_not_empty_b;             /* '<Root>/software_rezonator' */
  boolean_T c_not_empty_k;             /* '<Root>/software_rezonator' */
  boolean_T bfr_rezo_sm_not_empty_h;   /* '<Root>/software_rezonator' */
  boolean_T aft_delay_not_empty_m;     /* '<Root>/software_rezonator' */
  boolean_T dft_out_not_empty_c;       /* '<Root>/software_rezonator' */
  DW_RBNN_NN_MIMO_T sf_RBNN_NN1;       /* '<Root>/RBNN_NN1' */
  DW_RBNN_NN_MIMO_T sf_RBNN_NN;        /* '<Root>/RBNN_NN' */
} DW_MIMO_T;

/* Parameters (default storage) */
struct P_MIMO_T_ {
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T GainRBNN1_Gain;               /* Expression: 0.2
                                        * Referenced by: '<Root>/GainRBNN1'
                                        */
  real_T TrainingON1_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/Training ON1'
                                        */
  real_T TrainingOFF1_Value;           /* Expression: 1
                                        * Referenced by: '<Root>/Training OFF1'
                                        */
  real_T TrainingON_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Training ON'
                                        */
  real_T TrainingOFF_Value;            /* Expression: 1
                                        * Referenced by: '<Root>/Training OFF'
                                        */
  real_T y_InitialCondition;           /* Expression: 0
                                        * Referenced by: '<Root>/y'
                                        */
  real_T yp1_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/yp1'
                                        */
  real_T RandomNumber_5_Mean;          /* Expression: 0
                                        * Referenced by: '<S6>/Random Number_5'
                                        */
  real_T RandomNumber_5_StdDev;     /* Computed Parameter: RandomNumber_5_StdDev
                                     * Referenced by: '<S6>/Random Number_5'
                                     */
  real_T RandomNumber_5_Seed;          /* Expression: 0
                                        * Referenced by: '<S6>/Random Number_5'
                                        */
  real_T GainRBNN2_Gain;               /* Expression: 0.5
                                        * Referenced by: '<Root>/GainRBNN2'
                                        */
  real_T SineWave1_Amp;                /* Expression: 0.5
                                        * Referenced by: '<S1>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 431
                                        * Referenced by: '<S1>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave1'
                                        */
  real_T SineWave7_Amp;                /* Expression: 2
                                        * Referenced by: '<S1>/Sine Wave7'
                                        */
  real_T SineWave7_Bias;               /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave7'
                                        */
  real_T SineWave7_Freq;               /* Expression: 28230
                                        * Referenced by: '<S1>/Sine Wave7'
                                        */
  real_T SineWave7_Phase;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave7'
                                        */
  real_T SineWave8_Amp;                /* Expression: 2
                                        * Referenced by: '<S1>/Sine Wave8'
                                        */
  real_T SineWave8_Bias;               /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave8'
                                        */
  real_T SineWave8_Freq;               /* Expression: 33927
                                        * Referenced by: '<S1>/Sine Wave8'
                                        */
  real_T SineWave8_Phase;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave8'
                                        */
  real_T SineWave11_Amp;               /* Expression: 2
                                        * Referenced by: '<S1>/Sine Wave11'
                                        */
  real_T SineWave11_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave11'
                                        */
  real_T SineWave11_Freq;              /* Expression: 30637
                                        * Referenced by: '<S1>/Sine Wave11'
                                        */
  real_T SineWave11_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave11'
                                        */
  real_T SineWave9_Amp;                /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave9'
                                        */
  real_T SineWave9_Bias;               /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave9'
                                        */
  real_T SineWave9_Freq;               /* Expression: 53787
                                        * Referenced by: '<S1>/Sine Wave9'
                                        */
  real_T SineWave9_Phase;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave9'
                                        */
  real_T SineWave10_Amp;               /* Expression: 2
                                        * Referenced by: '<S1>/Sine Wave10'
                                        */
  real_T SineWave10_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave10'
                                        */
  real_T SineWave10_Freq;              /* Expression: 47000
                                        * Referenced by: '<S1>/Sine Wave10'
                                        */
  real_T SineWave10_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave10'
                                        */
  real_T SineWave4_Amp;                /* Expression: 0.5
                                        * Referenced by: '<S1>/Sine Wave4'
                                        */
  real_T SineWave4_Bias;               /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave4'
                                        */
  real_T SineWave4_Freq;               /* Expression: 50
                                        * Referenced by: '<S1>/Sine Wave4'
                                        */
  real_T SineWave4_Phase;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave4'
                                        */
  real_T SineWave14_Amp;               /* Expression: 0.1
                                        * Referenced by: '<S1>/Sine Wave14'
                                        */
  real_T SineWave14_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave14'
                                        */
  real_T SineWave14_Freq;              /* Expression: 43
                                        * Referenced by: '<S1>/Sine Wave14'
                                        */
  real_T SineWave14_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave14'
                                        */
  real_T SineWave15_Amp;               /* Expression: 0.1
                                        * Referenced by: '<S1>/Sine Wave15'
                                        */
  real_T SineWave15_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave15'
                                        */
  real_T SineWave15_Freq;              /* Expression: 89
                                        * Referenced by: '<S1>/Sine Wave15'
                                        */
  real_T SineWave15_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave15'
                                        */
  real_T SineWave17_Amp;               /* Expression: 0.1
                                        * Referenced by: '<S1>/Sine Wave17'
                                        */
  real_T SineWave17_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave17'
                                        */
  real_T SineWave17_Freq;              /* Expression: 167
                                        * Referenced by: '<S1>/Sine Wave17'
                                        */
  real_T SineWave17_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave17'
                                        */
  real_T SineWave20_Amp;               /* Expression: 0.1
                                        * Referenced by: '<S1>/Sine Wave20'
                                        */
  real_T SineWave20_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave20'
                                        */
  real_T SineWave20_Freq;              /* Expression: 193
                                        * Referenced by: '<S1>/Sine Wave20'
                                        */
  real_T SineWave20_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave20'
                                        */
  real_T SineWave16_Amp;               /* Expression: 0.1
                                        * Referenced by: '<S1>/Sine Wave16'
                                        */
  real_T SineWave16_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave16'
                                        */
  real_T SineWave16_Freq;              /* Expression: 229
                                        * Referenced by: '<S1>/Sine Wave16'
                                        */
  real_T SineWave16_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave16'
                                        */
  real_T SineWave23_Amp;               /* Expression: 0.1
                                        * Referenced by: '<S1>/Sine Wave23'
                                        */
  real_T SineWave23_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave23'
                                        */
  real_T SineWave23_Freq;              /* Expression: 271
                                        * Referenced by: '<S1>/Sine Wave23'
                                        */
  real_T SineWave23_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave23'
                                        */
  real_T SineWave21_Amp;               /* Expression: 0.1
                                        * Referenced by: '<S1>/Sine Wave21'
                                        */
  real_T SineWave21_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave21'
                                        */
  real_T SineWave21_Freq;              /* Expression: 337
                                        * Referenced by: '<S1>/Sine Wave21'
                                        */
  real_T SineWave21_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave21'
                                        */
  real_T SineWave22_Amp;               /* Expression: 0.1
                                        * Referenced by: '<S1>/Sine Wave22'
                                        */
  real_T SineWave22_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave22'
                                        */
  real_T SineWave22_Freq;              /* Expression: 379
                                        * Referenced by: '<S1>/Sine Wave22'
                                        */
  real_T SineWave22_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave22'
                                        */
  real_T SineWave18_Amp;               /* Expression: 0.1
                                        * Referenced by: '<S1>/Sine Wave18'
                                        */
  real_T SineWave18_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave18'
                                        */
  real_T SineWave18_Freq;              /* Expression: 409
                                        * Referenced by: '<S1>/Sine Wave18'
                                        */
  real_T SineWave18_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave18'
                                        */
  real_T SineWave19_Amp;               /* Expression: 0.1
                                        * Referenced by: '<S1>/Sine Wave19'
                                        */
  real_T SineWave19_Bias;              /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave19'
                                        */
  real_T SineWave19_Freq;              /* Expression: 499
                                        * Referenced by: '<S1>/Sine Wave19'
                                        */
  real_T SineWave19_Phase;             /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave19'
                                        */
  real_T GainRBNN3_Gain;               /* Expression: 0.5
                                        * Referenced by: '<Root>/GainRBNN3'
                                        */
  real_T u2_Value;                     /* Expression: 1
                                        * Referenced by: '<Root>/u2'
                                        */
  real_T LR_RBNN_Value;                /* Expression: 0.3
                                        * Referenced by: '<Root>/LR_RBNN'
                                        */
  real_T y1_InitialCondition;          /* Expression: 0
                                        * Referenced by: '<Root>/y1'
                                        */
  real_T yp2_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/yp2'
                                        */
  real_T u1_Value;                     /* Expression: 1
                                        * Referenced by: '<Root>/u1'
                                        */
  real_T LR_RBNN1_Value;               /* Expression: 0.3
                                        * Referenced by: '<Root>/LR_RBNN1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S7>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S7>/Delay1'
                                        */
  real_T Out_RBNN1_Gain;               /* Expression: 1
                                        * Referenced by: '<Root>/Out_RBNN1'
                                        */
  real_T Out_RBNN2_Gain;               /* Expression: 1
                                        * Referenced by: '<Root>/Out_RBNN2'
                                        */
  uint32_T y_DelayLength;              /* Computed Parameter: y_DelayLength
                                        * Referenced by: '<Root>/y'
                                        */
  uint32_T yp1_DelayLength;            /* Computed Parameter: yp1_DelayLength
                                        * Referenced by: '<Root>/yp1'
                                        */
  uint32_T y1_DelayLength;             /* Computed Parameter: y1_DelayLength
                                        * Referenced by: '<Root>/y1'
                                        */
  uint32_T yp2_DelayLength;            /* Computed Parameter: yp2_DelayLength
                                        * Referenced by: '<Root>/yp2'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S7>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S7>/Delay1'
                                        */
  uint8_T signal_CD_CurrentSetting;
                                 /* Computed Parameter: signal_CD_CurrentSetting
                                  * Referenced by: '<Root>/signal_C//D'
                                  */
  uint8_T signal_AB_CurrentSetting;
                                 /* Computed Parameter: signal_AB_CurrentSetting
                                  * Referenced by: '<Root>/signal_A//B'
                                  */
  uint8_T signalX_CurrentSetting;  /* Computed Parameter: signalX_CurrentSetting
                                    * Referenced by: '<Root>/signalX'
                                    */
  uint8_T signal_JK_CurrentSetting;
                                 /* Computed Parameter: signal_JK_CurrentSetting
                                  * Referenced by: '<Root>/signal_J//K'
                                  */
  uint8_T signal_JK1_CurrentSetting;
                                /* Computed Parameter: signal_JK1_CurrentSetting
                                 * Referenced by: '<Root>/signal_J//K1'
                                 */
  uint8_T signal_CD2_CurrentSetting;
                                /* Computed Parameter: signal_CD2_CurrentSetting
                                 * Referenced by: '<Root>/signal_C//D2'
                                 */
  uint8_T signal_JK2_CurrentSetting;
                                /* Computed Parameter: signal_JK2_CurrentSetting
                                 * Referenced by: '<Root>/signal_J//K2'
                                 */
  uint8_T TT_CurrentSetting;           /* Computed Parameter: TT_CurrentSetting
                                        * Referenced by: '<Root>/TT'
                                        */
  uint8_T Signal_switch4_CurrentSetting;
                            /* Computed Parameter: Signal_switch4_CurrentSetting
                             * Referenced by: '<Root>/Signal_switch4'
                             */
  uint8_T TT1_CurrentSetting;          /* Computed Parameter: TT1_CurrentSetting
                                        * Referenced by: '<Root>/TT1'
                                        */
  uint8_T ExternalStop_RBNN_CurrentSettin;
                          /* Computed Parameter: ExternalStop_RBNN_CurrentSettin
                           * Referenced by: '<Root>/External Stop_RBNN'
                           */
  uint8_T ExternalStop_RBNN1_CurrentSetti;
                          /* Computed Parameter: ExternalStop_RBNN1_CurrentSetti
                           * Referenced by: '<Root>/External Stop_RBNN1'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_MIMO_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_MIMO_T MIMO_P;

/* Block signals (default storage) */
extern B_MIMO_T MIMO_B;

/* Block states (default storage) */
extern DW_MIMO_T MIMO_DW;

/* Model entry point functions */
extern void MIMO_initialize(void);
extern void MIMO_step(void);
extern void MIMO_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MIMO_T *const MIMO_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MIMO'
 * '<S1>'   : 'MIMO/HIgh_frequency_signal_generator'
 * '<S2>'   : 'MIMO/RBNN_NN'
 * '<S3>'   : 'MIMO/RBNN_NN1'
 * '<S4>'   : 'MIMO/RBNN_output'
 * '<S5>'   : 'MIMO/RBNN_output1'
 * '<S6>'   : 'MIMO/Random_signal_generator'
 * '<S7>'   : 'MIMO/Subsystem'
 * '<S8>'   : 'MIMO/buffer_of_op_fft'
 * '<S9>'   : 'MIMO/buffer_of_op_fft1'
 * '<S10>'  : 'MIMO/software_rezonator'
 * '<S11>'  : 'MIMO/software_rezonator1'
 * '<S12>'  : 'MIMO/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_MIMO_h_ */
