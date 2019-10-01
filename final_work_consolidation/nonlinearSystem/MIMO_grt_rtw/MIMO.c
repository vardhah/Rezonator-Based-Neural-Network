/*
 * MIMO.c
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

/* Block signals (default storage) */
B_MIMO_T MIMO_B;

/* Block states (default storage) */
DW_MIMO_T MIMO_DW;

/* Real-time model */
RT_MODEL_MIMO_T MIMO_M_;
RT_MODEL_MIMO_T *const MIMO_M = &MIMO_M_;

/* Forward declaration for local functions */
static void MIMO_emxInit_real_T(emxArray_real_T_MIMO_T **pEmxArray, int32_T
  numDimensions);
static void MIMO_genrand_uint32_vector(uint32_T mt[625], uint32_T u[2]);
static real_T MIMO_genrandu(uint32_T mt[625]);
static real_T MIMO_eml_rand_mt19937ar(uint32_T state[625]);
static void MIMO_randn(real_T r[64], DW_RBNN_NN_MIMO_T *localDW);
static void MIMO_randn_a(real_T r[1024], DW_RBNN_NN_MIMO_T *localDW);
static void MIMO_randn_as(real_T r[256], DW_RBNN_NN_MIMO_T *localDW);
static void MIMO_emxEnsureCapacity_real_T(emxArray_real_T_MIMO_T *emxArray,
  int32_T oldNumel);
static void MIMO_emxFree_real_T(emxArray_real_T_MIMO_T **pEmxArray);
static void MIMO_exp(real_T x[8]);
static void MIMO_repmat(const real_T a[8], real_T b[256]);
static void MIMO_repmat_f(const real_T a[32], real_T b[256]);
static void MIMO_repmat_fg(const real_T a[256], real_T b[2048]);
static void MIMO_repmat_fgq(const real_T a[1024], real_T b[32768]);
static void MIMO_repmat_fgqn(const real_T a[64], real_T b[2048]);
static real_T MIMO_mod(real_T x);
static void MIMO_emxInit_real_T(emxArray_real_T_MIMO_T **pEmxArray, int32_T
  numDimensions)
{
  emxArray_real_T_MIMO_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_MIMO_T *)malloc(sizeof(emxArray_real_T_MIMO_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static void MIMO_genrand_uint32_vector(uint32_T mt[625], uint32_T u[2])
{
  uint32_T mti;
  uint32_T y;
  int32_T j;
  int32_T kk;
  for (j = 0; j < 2; j++) {
    mti = mt[624] + 1U;
    if (mti >= 625U) {
      for (kk = 0; kk < 227; kk++) {
        y = (mt[1 + kk] & 2147483647U) | (mt[kk] & 2147483648U);
        if ((y & 1U) == 0U) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        mt[kk] = mt[kk + 397] ^ y;
      }

      for (kk = 0; kk < 396; kk++) {
        y = (mt[kk + 227] & 2147483648U) | (mt[228 + kk] & 2147483647U);
        if ((y & 1U) == 0U) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        mt[kk + 227] = mt[kk] ^ y;
      }

      y = (mt[623] & 2147483648U) | (mt[0] & 2147483647U);
      if ((y & 1U) == 0U) {
        y >>= 1U;
      } else {
        y = y >> 1U ^ 2567483615U;
      }

      mt[623] = mt[396] ^ y;
      mti = 1U;
    }

    y = mt[(int32_T)mti - 1];
    mt[624] = mti;
    y ^= y >> 11U;
    y ^= y << 7U & 2636928640U;
    y ^= y << 15U & 4022730752U;
    u[j] = y >> 18U ^ y;
  }
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static real_T MIMO_genrandu(uint32_T mt[625])
{
  real_T r;
  uint32_T u[2];
  int32_T k;
  boolean_T b_isvalid;
  uint32_T b_r;
  int32_T exitg1;
  boolean_T exitg2;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    exitg1 = 0;
    MIMO_genrand_uint32_vector(mt, u);
    r = ((real_T)(u[0] >> 5U) * 6.7108864E+7 + (real_T)(u[1] >> 6U)) *
      1.1102230246251565E-16;
    if (r == 0.0) {
      if ((mt[624] >= 1U) && (mt[624] < 625U)) {
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (mt[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      } else {
        b_isvalid = false;
      }

      if (!b_isvalid) {
        b_r = 5489U;
        mt[0] = 5489U;
        for (k = 0; k < 623; k++) {
          b_r = ((b_r >> 30U ^ b_r) * 1812433253U + k) + 1U;
          mt[k + 1] = b_r;
        }

        mt[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static real_T MIMO_eml_rand_mt19937ar(uint32_T state[625])
{
  real_T r;
  int32_T i;
  real_T x;
  uint32_T u32[2];
  real_T c_u;
  static const real_T b[257] = { 0.0, 0.215241895984875, 0.286174591792068,
    0.335737519214422, 0.375121332878378, 0.408389134611989, 0.43751840220787,
    0.46363433679088, 0.487443966139235, 0.50942332960209, 0.529909720661557,
    0.549151702327164, 0.567338257053817, 0.584616766106378, 0.601104617755991,
    0.61689699000775, 0.63207223638606, 0.646695714894993, 0.660822574244419,
    0.674499822837293, 0.687767892795788, 0.700661841106814, 0.713212285190975,
    0.725446140909999, 0.737387211434295, 0.749056662017815, 0.760473406430107,
    0.771654424224568, 0.782615023307232, 0.793369058840623, 0.80392911698997,
    0.814306670135215, 0.824512208752291, 0.834555354086381, 0.844444954909153,
    0.854189171008163, 0.863795545553308, 0.87327106808886, 0.882622229585165,
    0.891855070732941, 0.900975224461221, 0.909987953496718, 0.91889818364959,
    0.927710533401999, 0.936429340286575, 0.945058684468165, 0.953602409881086,
    0.96206414322304, 0.970447311064224, 0.978755155294224, 0.986990747099062,
    0.99515699963509, 1.00325667954467, 1.01129241744, 1.01926671746548,
    1.02718196603564, 1.03504043983344, 1.04284431314415, 1.05059566459093,
    1.05829648333067, 1.06594867476212, 1.07355406579244, 1.0811144097034,
    1.08863139065398, 1.09610662785202, 1.10354167942464, 1.11093804601357,
    1.11829717411934, 1.12562045921553, 1.13290924865253, 1.14016484436815,
    1.14738850542085, 1.15458145035993, 1.16174485944561, 1.16887987673083,
    1.17598761201545, 1.18306914268269, 1.19012551542669, 1.19715774787944,
    1.20416683014438, 1.2111537262437, 1.21811937548548, 1.22506469375653,
    1.23199057474614, 1.23889789110569, 1.24578749554863, 1.2526602218949,
    1.25951688606371, 1.26635828701823, 1.27318520766536, 1.27999841571382,
    1.28679866449324, 1.29358669373695, 1.30036323033084, 1.30712898903073,
    1.31388467315022, 1.32063097522106, 1.32736857762793, 1.33409815321936,
    1.3408203658964, 1.34753587118059, 1.35424531676263, 1.36094934303328,
    1.36764858359748, 1.37434366577317, 1.38103521107586, 1.38772383568998,
    1.39441015092814, 1.40109476367925, 1.4077782768464, 1.41446128977547,
    1.42114439867531, 1.42782819703026, 1.43451327600589, 1.44120022484872,
    1.44788963128058, 1.45458208188841, 1.46127816251028, 1.46797845861808,
    1.47468355569786, 1.48139403962819, 1.48811049705745, 1.49483351578049,
    1.50156368511546, 1.50830159628131, 1.51504784277671, 1.521803020761,
    1.52856772943771, 1.53534257144151, 1.542128153229, 1.54892508547417,
    1.55573398346918, 1.56255546753104, 1.56939016341512, 1.57623870273591,
    1.58310172339603, 1.58997987002419, 1.59687379442279, 1.60378415602609,
    1.61071162236983, 1.61765686957301, 1.62462058283303, 1.63160345693487,
    1.63860619677555, 1.64562951790478, 1.65267414708306, 1.65974082285818,
    1.66683029616166, 1.67394333092612, 1.68108070472517, 1.68824320943719,
    1.69543165193456, 1.70264685479992, 1.7098896570713, 1.71716091501782,
    1.72446150294804, 1.73179231405296, 1.73915426128591, 1.74654827828172,
    1.75397532031767, 1.76143636531891, 1.76893241491127, 1.77646449552452,
    1.78403365954944, 1.79164098655216, 1.79928758454972, 1.80697459135082,
    1.81470317596628, 1.82247454009388, 1.83028991968276, 1.83815058658281,
    1.84605785028518, 1.8540130597602, 1.86201760539967, 1.87007292107127,
    1.878180486293, 1.88634182853678, 1.8945585256707, 1.90283220855043,
    1.91116456377125, 1.91955733659319, 1.92801233405266, 1.93653142827569,
    1.94511656000868, 1.95376974238465, 1.96249306494436, 1.97128869793366,
    1.98015889690048, 1.98910600761744, 1.99813247135842, 2.00724083056053,
    2.0164337349062, 2.02571394786385, 2.03508435372962, 2.04454796521753,
    2.05410793165065, 2.06376754781173, 2.07353026351874, 2.0833996939983,
    2.09337963113879, 2.10347405571488, 2.11368715068665, 2.12402331568952,
    2.13448718284602, 2.14508363404789, 2.15581781987674, 2.16669518035431,
    2.17772146774029, 2.18890277162636, 2.20024554661128, 2.21175664288416,
    2.22344334009251, 2.23531338492992, 2.24737503294739, 2.25963709517379,
    2.27210899022838, 2.28480080272449, 2.29772334890286, 2.31088825060137,
    2.32430801887113, 2.33799614879653, 2.35196722737914, 2.36623705671729,
    2.38082279517208, 2.39574311978193, 2.41101841390112, 2.42667098493715,
    2.44272531820036, 2.4592083743347, 2.47614993967052, 2.49358304127105,
    2.51154444162669, 2.53007523215985, 2.54922155032478, 2.56903545268184,
    2.58957598670829, 2.61091051848882, 2.63311639363158, 2.65628303757674,
    2.68051464328574, 2.70593365612306, 2.73268535904401, 2.76094400527999,
    2.79092117400193, 2.82287739682644, 2.85713873087322, 2.89412105361341,
    2.93436686720889, 2.97860327988184, 3.02783779176959, 3.08352613200214,
    3.147889289518, 3.2245750520478, 3.32024473383983, 3.44927829856143,
    3.65415288536101, 3.91075795952492 };

  static const real_T c[257] = { 1.0, 0.977101701267673, 0.959879091800108,
    0.9451989534423, 0.932060075959231, 0.919991505039348, 0.908726440052131,
    0.898095921898344, 0.887984660755834, 0.878309655808918, 0.869008688036857,
    0.860033621196332, 0.851346258458678, 0.842915653112205, 0.834716292986884,
    0.826726833946222, 0.818929191603703, 0.811307874312656, 0.803849483170964,
    0.796542330422959, 0.789376143566025, 0.782341832654803, 0.775431304981187,
    0.768637315798486, 0.761953346836795, 0.755373506507096, 0.748892447219157,
    0.742505296340151, 0.736207598126863, 0.729995264561476, 0.72386453346863,
    0.717811932630722, 0.711834248878248, 0.705928501332754, 0.700091918136512,
    0.694321916126117, 0.688616083004672, 0.682972161644995, 0.677388036218774,
    0.671861719897082, 0.66639134390875, 0.660975147776663, 0.655611470579697,
    0.650298743110817, 0.645035480820822, 0.639820277453057, 0.634651799287624,
    0.629528779924837, 0.624450015547027, 0.619414360605834, 0.614420723888914,
    0.609468064925773, 0.604555390697468, 0.599681752619125, 0.594846243767987,
    0.590047996332826, 0.585286179263371, 0.580559996100791, 0.575868682972354,
    0.571211506735253, 0.566587763256165, 0.561996775814525, 0.557437893618766,
    0.552910490425833, 0.548413963255266, 0.543947731190026, 0.539511234256952,
    0.535103932380458, 0.530725304403662, 0.526374847171684, 0.522052074672322,
    0.517756517229756, 0.513487720747327, 0.509245245995748, 0.505028667943468,
    0.500837575126149, 0.49667156905249, 0.492530263643869, 0.488413284705458,
    0.484320269426683, 0.480250865909047, 0.476204732719506, 0.47218153846773,
    0.468180961405694, 0.464202689048174, 0.460246417812843, 0.456311852678716,
    0.452398706861849, 0.448506701507203, 0.444635565395739, 0.440785034665804,
    0.436954852547985, 0.433144769112652, 0.429354541029442, 0.425583931338022,
    0.421832709229496, 0.418100649837848, 0.414387534040891, 0.410693148270188,
    0.407017284329473, 0.403359739221114, 0.399720314980197, 0.396098818515832,
    0.392495061459315, 0.388908860018789, 0.385340034840077, 0.381788410873393,
    0.378253817245619, 0.374736087137891, 0.371235057668239, 0.367750569779032,
    0.364282468129004, 0.360830600989648, 0.357394820145781, 0.353974980800077,
    0.350570941481406, 0.347182563956794, 0.343809713146851, 0.340452257044522,
    0.337110066637006, 0.333783015830718, 0.330470981379163, 0.327173842813601,
    0.323891482376391, 0.320623784956905, 0.317370638029914, 0.314131931596337,
    0.310907558126286, 0.307697412504292, 0.30450139197665, 0.301319396100803,
    0.298151326696685, 0.294997087799962, 0.291856585617095, 0.288729728482183,
    0.285616426815502, 0.282516593083708, 0.279430141761638, 0.276356989295668,
    0.273297054068577, 0.270250256365875, 0.267216518343561, 0.264195763997261,
    0.261187919132721, 0.258192911337619, 0.255210669954662, 0.252241126055942,
    0.249284212418529, 0.246339863501264, 0.24340801542275, 0.240488605940501,
    0.237581574431238, 0.23468686187233, 0.231804410824339, 0.228934165414681,
    0.226076071322381, 0.223230075763918, 0.220396127480152, 0.217574176724331,
    0.214764175251174, 0.211966076307031, 0.209179834621125, 0.206405406397881,
    0.203642749310335, 0.200891822494657, 0.198152586545776, 0.195425003514135,
    0.192709036903589, 0.190004651670465, 0.187311814223801, 0.1846304924268,
    0.181960655599523, 0.179302274522848, 0.176655321443735, 0.174019770081839,
    0.171395595637506, 0.168782774801212, 0.166181285764482, 0.163591108232366,
    0.161012223437511, 0.158444614155925, 0.15588826472448, 0.153343161060263,
    0.150809290681846, 0.148286642732575, 0.145775208005994, 0.143274978973514,
    0.140785949814445, 0.138308116448551, 0.135841476571254, 0.133386029691669,
    0.130941777173644, 0.12850872228, 0.126086870220186, 0.123676228201597,
    0.12127680548479, 0.11888861344291, 0.116511665625611, 0.114145977827839,
    0.111791568163838, 0.109448457146812, 0.107116667774684, 0.104796225622487,
    0.102487158941935, 0.10018949876881, 0.0979032790388625, 0.095628536713009,
    0.093365311912691, 0.0911136480663738, 0.0888735920682759,
    0.0866451944505581, 0.0844285095703535, 0.082223595813203,
    0.0800305158146631, 0.0778493367020961, 0.0756801303589272,
    0.0735229737139814, 0.0713779490588905, 0.0692451443970068,
    0.0671246538277886, 0.065016577971243, 0.0629210244377582, 0.06083810834954,
    0.0587679529209339, 0.0567106901062031, 0.0546664613248891,
    0.0526354182767924, 0.0506177238609479, 0.0486135532158687,
    0.0466230949019305, 0.0446465522512946, 0.0426841449164746,
    0.0407361106559411, 0.0388027074045262, 0.0368842156885674,
    0.0349809414617162, 0.0330932194585786, 0.0312214171919203,
    0.0293659397581334, 0.0275272356696031, 0.0257058040085489,
    0.0239022033057959, 0.0221170627073089, 0.0203510962300445,
    0.0186051212757247, 0.0168800831525432, 0.0151770883079353,
    0.0134974506017399, 0.0118427578579079, 0.0102149714397015,
    0.00861658276939875, 0.00705087547137324, 0.00552240329925101,
    0.00403797259336304, 0.00260907274610216, 0.0012602859304986,
    0.000477467764609386 };

  int32_T exitg1;
  do {
    exitg1 = 0;
    MIMO_genrand_uint32_vector(state, u32);
    i = (int32_T)((u32[1] >> 24U) + 1U);
    r = (((real_T)(u32[0] >> 3U) * 1.6777216E+7 + (real_T)((int32_T)u32[1] &
           16777215)) * 2.2204460492503131E-16 - 1.0) * b[i];
    if (fabs(r) <= b[i - 1]) {
      exitg1 = 1;
    } else if (i < 256) {
      x = MIMO_genrandu(state);
      if ((c[i - 1] - c[i]) * x + c[i] < exp(-0.5 * r * r)) {
        exitg1 = 1;
      }
    } else {
      do {
        x = MIMO_genrandu(state);
        x = log(x) * 0.273661237329758;
        c_u = MIMO_genrandu(state);
      } while (!(-2.0 * log(c_u) > x * x));

      if (r < 0.0) {
        r = x - 3.65415288536101;
      } else {
        r = 3.65415288536101 - x;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static void MIMO_randn(real_T r[64], DW_RBNN_NN_MIMO_T *localDW)
{
  int32_T k;
  for (k = 0; k < 64; k++) {
    r[k] = MIMO_eml_rand_mt19937ar(localDW->state);
  }
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static void MIMO_randn_a(real_T r[1024], DW_RBNN_NN_MIMO_T *localDW)
{
  int32_T k;
  for (k = 0; k < 1024; k++) {
    r[k] = MIMO_eml_rand_mt19937ar(localDW->state);
  }
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static void MIMO_randn_as(real_T r[256], DW_RBNN_NN_MIMO_T *localDW)
{
  int32_T k;
  for (k = 0; k < 256; k++) {
    r[k] = MIMO_eml_rand_mt19937ar(localDW->state);
  }
}

static void MIMO_emxEnsureCapacity_real_T(emxArray_real_T_MIMO_T *emxArray,
  int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void MIMO_emxFree_real_T(emxArray_real_T_MIMO_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_MIMO_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_MIMO_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static void MIMO_exp(real_T x[8])
{
  int32_T k;
  for (k = 0; k < 8; k++) {
    x[k] = exp(x[k]);
  }
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static void MIMO_repmat(const real_T a[8], real_T b[256])
{
  int32_T jtilecol;
  for (jtilecol = 0; jtilecol < 32; jtilecol++) {
    memcpy(&b[jtilecol << 3], &a[0], sizeof(real_T) << 3U);
  }
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static void MIMO_repmat_f(const real_T a[32], real_T b[256])
{
  int32_T ibmat;
  int32_T jcol;
  int32_T itilerow;
  for (jcol = 0; jcol < 32; jcol++) {
    ibmat = jcol << 3;
    for (itilerow = 0; itilerow < 8; itilerow++) {
      b[ibmat + itilerow] = a[jcol];
    }
  }
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static void MIMO_repmat_fg(const real_T a[256], real_T b[2048])
{
  int32_T ibtile;
  int32_T jtilecol;
  int32_T jcol;
  int32_T iacol_tmp;
  for (jtilecol = 0; jtilecol < 8; jtilecol++) {
    ibtile = (jtilecol << 8) - 1;
    for (jcol = 0; jcol < 32; jcol++) {
      iacol_tmp = jcol << 3;
      memcpy(&b[(iacol_tmp + ibtile) + 1], &a[iacol_tmp], sizeof(real_T) << 3U);
    }
  }
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static void MIMO_repmat_fgq(const real_T a[1024], real_T b[32768])
{
  int32_T ibtile;
  int32_T jtilecol;
  int32_T jcol;
  int32_T iacol_tmp;
  for (jtilecol = 0; jtilecol < 32; jtilecol++) {
    ibtile = (jtilecol << 10) - 1;
    for (jcol = 0; jcol < 32; jcol++) {
      iacol_tmp = jcol << 5;
      memcpy(&b[(iacol_tmp + ibtile) + 1], &a[iacol_tmp], sizeof(real_T) << 5U);
    }
  }
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static void MIMO_repmat_fgqn(const real_T a[64], real_T b[2048])
{
  int32_T ibtile;
  int32_T jtilecol;
  int32_T jcol;
  int32_T iacol_tmp;
  for (jtilecol = 0; jtilecol < 32; jtilecol++) {
    ibtile = (jtilecol << 6) - 1;
    for (jcol = 0; jcol < 2; jcol++) {
      iacol_tmp = jcol << 5;
      memcpy(&b[(iacol_tmp + ibtile) + 1], &a[iacol_tmp], sizeof(real_T) << 5U);
    }
  }
}

/* Function for MATLAB Function: '<Root>/RBNN_NN' */
static real_T MIMO_mod(real_T x)
{
  real_T r;
  if (rtIsInf(x)) {
    r = (rtNaN);
  } else {
    r = fmod(x, 1.0);
    if (r == 0.0) {
      r = 0.0;
    }
  }

  return r;
}

/*
 * System initialize for atomic system:
 *    '<Root>/RBNN_NN'
 *    '<Root>/RBNN_NN1'
 */
void MIMO_RBNN_NN_Init(DW_RBNN_NN_MIMO_T *localDW)
{
  uint32_T r;
  int32_T mti;
  localDW->w1_not_empty = false;
  localDW->w2_not_empty = false;
  localDW->w3_not_empty = false;
  localDW->mult1_not_empty = false;
  localDW->mult2_not_empty = false;
  localDW->mult3_not_empty = false;
  MIMO_emxInit_real_T(&localDW->mult1, 2);
  MIMO_emxInit_real_T(&localDW->mult2, 2);
  MIMO_emxInit_real_T(&localDW->mult3, 2);
  memset(&localDW->state[0], 0, 625U * sizeof(uint32_T));
  r = 5489U;
  localDW->state[0] = 5489U;
  for (mti = 0; mti < 623; mti++) {
    r = ((r >> 30U ^ r) * 1812433253U + mti) + 1U;
    localDW->state[mti + 1] = r;
  }

  localDW->state[624] = 624U;
  localDW->n = 0.0;
  localDW->memory_alloc_flag = 0.0;
  localDW->vy[0] = 0.0;
  localDW->vy[1] = 0.0;
  localDW->itr = 0.0;
  localDW->J = 0.0;
  memset(&localDW->g1[0], 0, sizeof(real_T) << 6U);
  memset(&localDW->g2[0], 0, sizeof(real_T) << 10U);
  memset(&localDW->g3[0], 0, sizeof(real_T) << 8U);
}

/*
 * Output and update for atomic system:
 *    '<Root>/RBNN_NN'
 *    '<Root>/RBNN_NN1'
 */
void MIMO_RBNN_NN(creal_T rtu_u1, real_T rtu_df, const real_T rtu_F[8], real_T
                  rtu_u2, real_T rtu_stop, real_T rtu_alp, B_RBNN_NN_MIMO_T
                  *localB, DW_RBNN_NN_MIMO_T *localDW)
{
  real_T a1[32];
  real_T da3_z3[8];
  real_T dn_a2[256];
  real_T da2_z2[32];
  real_T dn_a1[256];
  int32_T iteration;
  int8_T varargin_2_data[2016];
  real_T z1_out[32];
  real_T z2_out[32];
  real_T z1_out_tmp[64];
  real_T da3_z3_0[256];
  int32_T loop_ub;
  emxArray_real_T_MIMO_T *tmp;
  emxArray_real_T_MIMO_T *tmp_0;
  emxArray_real_T_MIMO_T *tmp_1;
  real_T dn_a2_0[256];
  real_T dn_a1_0[16];
  real_T rtu_F_0[2];
  real_T dn_a1_1[512];
  int32_T i;
  real_T v_idx_0;
  real_T z1_out_0;
  real_T rtu_F_1;
  int32_T loop_ub_tmp;
  int32_T loop_ub_tmp_0;
  if (!localDW->w1_not_empty) {
    MIMO_randn(localDW->w1, localDW);
    for (i = 0; i < 64; i++) {
      localDW->w1[i] *= 0.1;
    }

    localDW->w1_not_empty = true;
  }

  if (!localDW->w2_not_empty) {
    MIMO_randn_a(localDW->w2, localDW);
    for (i = 0; i < 1024; i++) {
      localDW->w2[i] *= 0.1;
    }

    localDW->w2_not_empty = true;
  }

  if (!localDW->w3_not_empty) {
    MIMO_randn_as(localDW->w3, localDW);
    for (i = 0; i < 256; i++) {
      localDW->w3[i] *= 0.1;
    }

    localDW->w3_not_empty = true;
  }

  localDW->n++;
  if (!localDW->mult1_not_empty) {
    i = localDW->mult1->size[0] * localDW->mult1->size[1];
    localDW->mult1->size[0] = 32;
    localDW->mult1->size[1] = 64;
    MIMO_emxEnsureCapacity_real_T(localDW->mult1, i);
    for (i = 0; i < 2048; i++) {
      localDW->mult1->data[i] = 0.0;
    }

    localDW->mult1_not_empty = true;
  }

  if (!localDW->mult2_not_empty) {
    i = localDW->mult2->size[0] * localDW->mult2->size[1];
    localDW->mult2->size[0] = 32;
    localDW->mult2->size[1] = 1024;
    MIMO_emxEnsureCapacity_real_T(localDW->mult2, i);
    for (i = 0; i < 32768; i++) {
      localDW->mult2->data[i] = 0.0;
    }

    localDW->mult2_not_empty = true;
  }

  if (!localDW->mult3_not_empty) {
    i = localDW->mult3->size[0] * localDW->mult3->size[1];
    localDW->mult3->size[0] = 8;
    localDW->mult3->size[1] = 256;
    MIMO_emxEnsureCapacity_real_T(localDW->mult3, i);
    for (i = 0; i < 2048; i++) {
      localDW->mult3->data[i] = 0.0;
    }

    localDW->mult3_not_empty = true;
  }

  if (localDW->memory_alloc_flag == 0.0) {
    localDW->mult1->size[0] = 0;
    localDW->mult1->size[1] = 0;
    localDW->mult1_not_empty = false;
    localDW->mult2->size[0] = 0;
    localDW->mult2->size[1] = 0;
    localDW->mult2_not_empty = false;
    localDW->mult3->size[0] = 0;
    localDW->mult3->size[1] = 0;
    localDW->mult3_not_empty = false;
    MIMO_emxInit_real_T(&tmp, 2);
    for (iteration = 0; iteration < 32; iteration++) {
      loop_ub_tmp_0 = iteration << 1;
      loop_ub_tmp = (31 - iteration) << 1;
      loop_ub = loop_ub_tmp - 1;
      if (0 <= loop_ub_tmp_0 - 1) {
        memset(&varargin_2_data[0], 0, loop_ub_tmp_0 * sizeof(int8_T));
      }

      varargin_2_data[loop_ub_tmp_0] = 1;
      varargin_2_data[1 + loop_ub_tmp_0] = 1;
      if (0 <= loop_ub) {
        memset(&varargin_2_data[loop_ub_tmp_0 + 2], 0, (((loop_ub +
                  loop_ub_tmp_0) - loop_ub_tmp_0) + 1) * sizeof(int8_T));
      }

      if ((localDW->mult1->size[0] != 0) && (localDW->mult1->size[1] != 0)) {
        loop_ub = localDW->mult1->size[1];
      } else {
        loop_ub = (loop_ub_tmp + loop_ub_tmp_0) + 2;
      }

      if ((localDW->mult1->size[0] != 0) && (localDW->mult1->size[1] != 0)) {
        loop_ub_tmp = localDW->mult1->size[0];
      } else {
        loop_ub_tmp = 0;
      }

      i = tmp->size[0] * tmp->size[1];
      tmp->size[0] = loop_ub_tmp + 1;
      tmp->size[1] = loop_ub;
      MIMO_emxEnsureCapacity_real_T(tmp, i);
      for (i = 0; i < loop_ub; i++) {
        for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < loop_ub_tmp; loop_ub_tmp_0++) {
          tmp->data[loop_ub_tmp_0 + tmp->size[0] * i] = localDW->mult1->
            data[loop_ub_tmp * i + loop_ub_tmp_0];
        }
      }

      for (i = 0; i < loop_ub; i++) {
        for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 1; loop_ub_tmp_0++) {
          tmp->data[loop_ub_tmp + tmp->size[0] * i] = varargin_2_data[i];
        }
      }

      i = localDW->mult1->size[0] * localDW->mult1->size[1];
      localDW->mult1->size[0] = tmp->size[0];
      localDW->mult1->size[1] = tmp->size[1];
      MIMO_emxEnsureCapacity_real_T(localDW->mult1, i);
      loop_ub = tmp->size[0] * tmp->size[1];
      for (i = 0; i < loop_ub; i++) {
        localDW->mult1->data[i] = tmp->data[i];
      }

      localDW->mult1_not_empty = ((localDW->mult1->size[0] != 0) &&
        (localDW->mult1->size[1] != 0));
    }

    MIMO_emxFree_real_T(&tmp);
    MIMO_emxInit_real_T(&tmp_1, 2);
    for (iteration = 0; iteration < 32; iteration++) {
      loop_ub_tmp_0 = iteration << 5;
      loop_ub_tmp = (31 - iteration) << 5;
      loop_ub = loop_ub_tmp - 1;
      if (0 <= loop_ub_tmp_0 - 1) {
        memset(&varargin_2_data[0], 0, loop_ub_tmp_0 * sizeof(int8_T));
      }

      for (i = 0; i < 32; i++) {
        varargin_2_data[i + loop_ub_tmp_0] = 1;
      }

      if (0 <= loop_ub) {
        memset(&varargin_2_data[loop_ub_tmp_0 + 32], 0, (((loop_ub +
                  loop_ub_tmp_0) - loop_ub_tmp_0) + 1) * sizeof(int8_T));
      }

      if ((localDW->mult2->size[0] != 0) && (localDW->mult2->size[1] != 0)) {
        loop_ub = localDW->mult2->size[1];
      } else {
        loop_ub = (loop_ub_tmp + loop_ub_tmp_0) + 32;
      }

      if ((loop_ub == 0) || ((localDW->mult2->size[0] != 0) && (localDW->
            mult2->size[1] != 0))) {
        loop_ub_tmp = localDW->mult2->size[0];
      } else {
        loop_ub_tmp = 0;
      }

      i = tmp_1->size[0] * tmp_1->size[1];
      tmp_1->size[0] = loop_ub_tmp + 1;
      tmp_1->size[1] = loop_ub;
      MIMO_emxEnsureCapacity_real_T(tmp_1, i);
      for (i = 0; i < loop_ub; i++) {
        for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < loop_ub_tmp; loop_ub_tmp_0++) {
          tmp_1->data[loop_ub_tmp_0 + tmp_1->size[0] * i] = localDW->mult2->
            data[loop_ub_tmp * i + loop_ub_tmp_0];
        }
      }

      for (i = 0; i < loop_ub; i++) {
        for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 1; loop_ub_tmp_0++) {
          tmp_1->data[loop_ub_tmp + tmp_1->size[0] * i] = varargin_2_data[i];
        }
      }

      i = localDW->mult2->size[0] * localDW->mult2->size[1];
      localDW->mult2->size[0] = tmp_1->size[0];
      localDW->mult2->size[1] = tmp_1->size[1];
      MIMO_emxEnsureCapacity_real_T(localDW->mult2, i);
      loop_ub = tmp_1->size[0] * tmp_1->size[1];
      for (i = 0; i < loop_ub; i++) {
        localDW->mult2->data[i] = tmp_1->data[i];
      }

      localDW->mult2_not_empty = ((localDW->mult2->size[0] != 0) &&
        (localDW->mult2->size[1] != 0));
    }

    MIMO_emxFree_real_T(&tmp_1);
    MIMO_emxInit_real_T(&tmp_0, 2);
    for (iteration = 0; iteration < 8; iteration++) {
      loop_ub = iteration << 5;
      loop_ub_tmp_0 = (7 - iteration) << 5;
      loop_ub_tmp = loop_ub_tmp_0 - 1;
      if (0 <= loop_ub - 1) {
        memset(&varargin_2_data[0], 0, loop_ub * sizeof(int8_T));
      }

      for (i = 0; i < 32; i++) {
        varargin_2_data[i + loop_ub] = 1;
      }

      if (0 <= loop_ub_tmp) {
        memset(&varargin_2_data[loop_ub + 32], 0, (((loop_ub_tmp + loop_ub) -
                 loop_ub) + 1) * sizeof(int8_T));
      }

      if ((localDW->mult3->size[0] != 0) && (localDW->mult3->size[1] != 0)) {
        loop_ub = localDW->mult3->size[1];
      } else {
        loop_ub = (loop_ub_tmp_0 + (iteration << 5)) + 32;
      }

      if ((localDW->mult3->size[0] != 0) && (localDW->mult3->size[1] != 0)) {
        loop_ub_tmp = localDW->mult3->size[0];
      } else {
        loop_ub_tmp = 0;
      }

      i = tmp_0->size[0] * tmp_0->size[1];
      tmp_0->size[0] = loop_ub_tmp + 1;
      tmp_0->size[1] = loop_ub;
      MIMO_emxEnsureCapacity_real_T(tmp_0, i);
      for (i = 0; i < loop_ub; i++) {
        for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < loop_ub_tmp; loop_ub_tmp_0++) {
          tmp_0->data[loop_ub_tmp_0 + tmp_0->size[0] * i] = localDW->mult3->
            data[loop_ub_tmp * i + loop_ub_tmp_0];
        }
      }

      for (i = 0; i < loop_ub; i++) {
        for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 1; loop_ub_tmp_0++) {
          tmp_0->data[loop_ub_tmp + tmp_0->size[0] * i] = varargin_2_data[i];
        }
      }

      i = localDW->mult3->size[0] * localDW->mult3->size[1];
      localDW->mult3->size[0] = tmp_0->size[0];
      localDW->mult3->size[1] = tmp_0->size[1];
      MIMO_emxEnsureCapacity_real_T(localDW->mult3, i);
      loop_ub = tmp_0->size[0] * tmp_0->size[1];
      for (i = 0; i < loop_ub; i++) {
        localDW->mult3->data[i] = tmp_0->data[i];
      }

      localDW->mult3_not_empty = ((localDW->mult3->size[0] != 0) &&
        (localDW->mult3->size[1] != 0));
    }

    MIMO_emxFree_real_T(&tmp_0);
    localDW->vy[0] = 1.0;
    localDW->vy[1] = 0.0;
    localDW->memory_alloc_flag = 1.0;
  }

  v_idx_0 = rtu_u1.re;
  for (i = 0; i < 2; i++) {
    for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 32; loop_ub_tmp_0++) {
      z1_out_tmp[loop_ub_tmp_0 + (i << 5)] = localDW->w1[(loop_ub_tmp_0 << 1) +
        i];
    }
  }

  for (iteration = 0; iteration < 32; iteration++) {
    z1_out_0 = z1_out_tmp[iteration + 32] * rtu_u2 + z1_out_tmp[iteration] *
      v_idx_0;
    for (i = 0; i < 32; i++) {
      localB->z2_out_tmp[i + (iteration << 5)] = localDW->w2[(i << 5) +
        iteration];
    }

    a1[iteration] = 0.1 * fmin(0.0, z1_out_0) + fmax(z1_out_0, 0.0);
  }

  for (iteration = 0; iteration < 32; iteration++) {
    z2_out[iteration] = 0.0;
    for (i = 0; i < 32; i++) {
      z2_out[iteration] += localB->z2_out_tmp[(i << 5) + iteration] * a1[i];
    }

    for (i = 0; i < 8; i++) {
      dn_a2[i + (iteration << 3)] = localDW->w3[(i << 5) + iteration];
    }

    z1_out[iteration] = 0.1 * fmin(0.0, z2_out[iteration]) + fmax
      (z2_out[iteration], 0.0);
  }

  for (i = 0; i < 8; i++) {
    rtu_F_1 = 0.0;
    for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 32; loop_ub_tmp_0++) {
      rtu_F_1 += dn_a2[(loop_ub_tmp_0 << 3) + i] * z1_out[loop_ub_tmp_0];
    }

    localB->nn_op[i] = -rtu_F_1;
  }

  MIMO_exp(localB->nn_op);
  for (loop_ub = 0; loop_ub < 8; loop_ub++) {
    localB->nn_op[loop_ub] = 1.0 / (1.0 + localB->nn_op[loop_ub]);
    da3_z3[loop_ub] = (1.0 - localB->nn_op[loop_ub]) * localB->nn_op[loop_ub] *
      10.0;
  }

  MIMO_repmat(da3_z3, da3_z3_0);
  for (i = 0; i < 256; i++) {
    dn_a2[i] *= da3_z3_0[i];
  }

  for (loop_ub = 0; loop_ub < 32; loop_ub++) {
    da2_z2[loop_ub] = (real_T)!(z1_out[loop_ub] >= 0.0) * 0.1 + (real_T)
      (z1_out[loop_ub] >= 0.0);
  }

  MIMO_repmat_f(da2_z2, da3_z3_0);
  for (i = 0; i < 256; i++) {
    dn_a2_0[i] = dn_a2[i] * da3_z3_0[i];
  }

  for (loop_ub = 0; loop_ub < 32; loop_ub++) {
    for (i = 0; i < 8; i++) {
      iteration = i + (loop_ub << 3);
      dn_a1[iteration] = 0.0;
      for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 32; loop_ub_tmp_0++) {
        dn_a1[iteration] += dn_a2_0[(loop_ub_tmp_0 << 3) + i] *
          localB->z2_out_tmp[(loop_ub << 5) + loop_ub_tmp_0];
      }
    }

    z2_out[loop_ub] = (real_T)!(a1[loop_ub] >= 0.0) * 0.1 + (real_T)(a1[loop_ub]
      >= 0.0);
  }

  MIMO_repmat_f(z2_out, da3_z3_0);
  for (i = 0; i < 256; i++) {
    dn_a2_0[i] = dn_a1[i] * da3_z3_0[i];
  }

  for (i = 0; i < 2; i++) {
    for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 8; loop_ub_tmp_0++) {
      iteration = loop_ub_tmp_0 + (i << 3);
      dn_a1_0[iteration] = 0.0;
      for (loop_ub = 0; loop_ub < 32; loop_ub++) {
        dn_a1_0[iteration] += dn_a2_0[(loop_ub << 3) + loop_ub_tmp_0] *
          z1_out_tmp[(i << 5) + loop_ub];
      }
    }
  }

  z1_out_0 = 0.0;
  for (i = 0; i < 2; i++) {
    rtu_F_0[i] = 0.0;
    for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 8; loop_ub_tmp_0++) {
      rtu_F_1 = dn_a1_0[(i << 3) + loop_ub_tmp_0] * rtu_F[loop_ub_tmp_0] +
        rtu_F_0[i];
      rtu_F_0[i] = rtu_F_1;
    }

    z1_out_0 += rtu_F_0[i] * localDW->vy[i];
  }

  for (i = 0; i < 8; i++) {
    for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 32; loop_ub_tmp_0++) {
      da3_z3_0[i + (loop_ub_tmp_0 << 3)] = da3_z3[i] * z1_out[loop_ub_tmp_0];
    }
  }

  MIMO_repmat_fg(da3_z3_0, localB->dv2);
  for (i = 0; i < 2048; i++) {
    localB->dv3[i] = localB->dv2[i] * localDW->mult3->data[i];
  }

  for (i = 0; i < 256; i++) {
    rtu_F_1 = 0.0;
    for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 8; loop_ub_tmp_0++) {
      rtu_F_1 += localB->dv3[(i << 3) + loop_ub_tmp_0] * rtu_F[loop_ub_tmp_0];
    }

    localDW->g3[i] = z1_out_0 * localDW->g3[i] + rtu_F_1;
  }

  for (i = 0; i < 32; i++) {
    for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 32; loop_ub_tmp_0++) {
      localB->z2_out_tmp[i + (loop_ub_tmp_0 << 5)] = da2_z2[i] *
        a1[loop_ub_tmp_0];
    }
  }

  MIMO_repmat_fgq(localB->z2_out_tmp, localB->dv0);
  for (i = 0; i < 32768; i++) {
    localB->dv1[i] = localB->dv0[i] * localDW->mult2->data[i];
  }

  for (i = 0; i < 1024; i++) {
    for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 8; loop_ub_tmp_0++) {
      iteration = loop_ub_tmp_0 + (i << 3);
      localB->dn_a2[iteration] = 0.0;
      for (loop_ub = 0; loop_ub < 32; loop_ub++) {
        localB->dn_a2[iteration] += dn_a2[(loop_ub << 3) + loop_ub_tmp_0] *
          localB->dv1[(i << 5) + loop_ub];
      }
    }
  }

  for (i = 0; i < 1024; i++) {
    rtu_F_1 = 0.0;
    for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 8; loop_ub_tmp_0++) {
      rtu_F_1 += localB->dn_a2[(i << 3) + loop_ub_tmp_0] * rtu_F[loop_ub_tmp_0];
    }

    localDW->g2[i] = z1_out_0 * localDW->g2[i] + rtu_F_1;
  }

  for (i = 0; i < 32; i++) {
    z1_out_tmp[i] = z2_out[i] * v_idx_0;
    z1_out_tmp[i + 32] = z2_out[i] * rtu_u2;
  }

  MIMO_repmat_fgqn(z1_out_tmp, localB->dv2);
  for (i = 0; i < 2048; i++) {
    localB->dv3[i] = localB->dv2[i] * localDW->mult1->data[i];
  }

  for (i = 0; i < 64; i++) {
    for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 8; loop_ub_tmp_0++) {
      iteration = loop_ub_tmp_0 + (i << 3);
      dn_a1_1[iteration] = 0.0;
      for (loop_ub = 0; loop_ub < 32; loop_ub++) {
        dn_a1_1[iteration] += dn_a1[(loop_ub << 3) + loop_ub_tmp_0] *
          localB->dv3[(i << 5) + loop_ub];
      }
    }
  }

  for (i = 0; i < 64; i++) {
    rtu_F_1 = 0.0;
    for (loop_ub_tmp_0 = 0; loop_ub_tmp_0 < 8; loop_ub_tmp_0++) {
      rtu_F_1 += dn_a1_1[(i << 3) + loop_ub_tmp_0] * rtu_F[loop_ub_tmp_0];
    }

    localDW->g1[i] = z1_out_0 * localDW->g1[i] + rtu_F_1;
  }

  if ((MIMO_mod(localDW->n) == 0.0) && (rtu_stop == 0.0)) {
    v_idx_0 = rtu_alp * rtu_df;
    for (i = 0; i < 64; i++) {
      localDW->w1[i] += v_idx_0 * localDW->g1[i];
    }

    for (i = 0; i < 1024; i++) {
      localDW->w2[i] += v_idx_0 * localDW->g2[i];
    }

    for (i = 0; i < 256; i++) {
      localDW->w3[i] += v_idx_0 * localDW->g3[i];
    }

    localDW->itr++;
    localDW->J = rtu_df * rtu_df / 2.0;
  }

  for (i = 0; i < 8; i++) {
    localB->nn_op[i] = (localB->nn_op[i] - 0.5) * 10.0;
  }

  localB->cost = localDW->J;
}

/*
 * Termination for atomic system:
 *    '<Root>/RBNN_NN'
 *    '<Root>/RBNN_NN1'
 */
void MIMO_RBNN_NN_Term(DW_RBNN_NN_MIMO_T *localDW)
{
  MIMO_emxFree_real_T(&localDW->mult1);
  MIMO_emxFree_real_T(&localDW->mult2);
  MIMO_emxFree_real_T(&localDW->mult3);
}

/*
 * Output and update for atomic system:
 *    '<Root>/RBNN_output'
 *    '<Root>/RBNN_output1'
 */
void MIMO_RBNN_output(const real_T rtu_dft[8], const real_T rtu_freq_char[8],
                      B_RBNN_output_MIMO_T *localB)
{
  real_T rtu_freq_char_0;
  int32_T i;
  rtu_freq_char_0 = 0.0;
  for (i = 0; i < 8; i++) {
    rtu_freq_char_0 += rtu_freq_char[i] * rtu_dft[i];
  }

  localB->yn = rtu_freq_char_0;
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function */
void MIMO_step(void)
{
  /* local block i/o variables */
  real_T rtb_yp1;
  real_T rtb_yp2;
  int32_T k;
  real_T denAccum;
  creal_T dft_trans_data[8];
  int32_T i;
  creal_T dft_trans_data_0[8];
  real_T rtb_y;
  real_T rtb_Filter_Highpass_1000Hz;
  real_T rtb_Filter_BPF_Narrow_band;
  real_T rtb_Filter_LPF_10K;
  real_T rtb_Filter_1000Hz_Elliptic;
  real_T tmp[8];
  real_T tmp_0[8];
  real_T x;
  real_T c_x_tmp;
  real_T c_x;
  real_T x_0;
  real_T c_x_tmp_0;
  real_T c_x_0;
  real_T x_tmp_idx_0;
  real_T c_x_tmp_idx_0;
  real_T c_x_idx_0;
  real_T x_tmp_idx_1;
  real_T x_idx_1;
  real_T c_x_tmp_idx_1;
  real_T c_x_idx_1;
  real_T x_tmp_idx_0_0;
  real_T x_idx_0;
  real_T c_x_tmp_idx_0_0;
  real_T c_x_idx_0_0;
  real_T x_tmp_idx_1_0;
  real_T x_idx_1_0;
  real_T c_x_tmp_idx_1_0;
  real_T c_x_idx_1_0;
  real_T signal_dif_im;
  int32_T i_0;

  /* Delay: '<Root>/y' */
  rtb_y = MIMO_DW.y_DSTATE;

  /* Delay: '<Root>/yp1' */
  rtb_yp1 = MIMO_DW.yp1_DSTATE;

  /* MATLAB Function: '<Root>/buffer_of_op_fft' incorporates:
   *  Sum: '<Root>/Sum50'
   */
  MIMO_B.output_difference_vector_l = rtb_yp1 - rtb_y;
  MIMO_B.output_fft_n.re = rtb_y;
  MIMO_B.output_fft_n.im = 0.0;

  /* S-Function (sdspbiquad): '<S6>/Filter_Highpass_1000Hz' incorporates:
   *  RandomNumber: '<S6>/Random Number_5'
   */
  denAccum = (0.97695338501607265 * MIMO_DW.NextOutput - -1.9287123010024667 *
              MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[0]) - 0.96272243336826424 *
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[1];
  rtb_y = (-1.9832348135082305 * MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[0] +
           denAccum) + MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[1];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[1] =
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[0];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[0] = denAccum;
  denAccum = (0.94318189745195835 * rtb_y - -1.8644843021460256 *
              MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[2]) - 0.894880266245439 *
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[3];
  rtb_y = (-1.985831978484246 * MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[2] +
           denAccum) + MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[3];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[3] =
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[2];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[2] = denAccum;
  denAccum = (0.91536288151617384 * rtb_y - -1.8134894348049562 *
              MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[4]) - 0.83900011952231868 *
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[5];
  rtb_y = (-1.9902093782494479 * MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[4] +
           denAccum) + MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[5];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[5] =
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[4];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[4] = denAccum;
  denAccum = (0.89474670611266194 * rtb_y - -1.7769073371544 *
              MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[6]) - 0.7975910874679879 *
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[7];
  rtb_y = (-1.9949836084362245 * MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[6] +
           denAccum) + MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[7];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[7] =
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[6];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[6] = denAccum;
  denAccum = (0.88210292045176564 * rtb_y - -1.7550125766919558 *
              MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[8]) - 0.77219638651415745 *
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[9];
  rtb_y = (-1.9986365325711279 * MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[8] +
           denAccum) + MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[9];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[9] =
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[8];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[8] = denAccum;
  denAccum = (0.93693381860552993 * rtb_y - -0.87386763721105976 *
              MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[10]) - 0.0 *
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[11];
  rtb_Filter_Highpass_1000Hz = (denAccum +
    -MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[10]) + 0.0 *
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[11];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[11] =
    MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[10];
  MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[10] = denAccum;

  /* S-Function (sdspbiquad): '<S6>/Filter_BPF_Narrow_band' incorporates:
   *  RandomNumber: '<S6>/Random Number_5'
   */
  denAccum = (0.64492557394928385 * MIMO_DW.NextOutput - 0.53141822466131627 *
              MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[0]) - 0.98091973065241667 *
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[1];
  rtb_y = (0.62090288091487722 * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[0] +
           denAccum) + MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[1];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[1] =
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[0];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[0] = denAccum;
  denAccum = (0.64492557394928385 * rtb_y - 0.21290614610304937 *
              MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[2]) - 0.98031453139974845 *
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[3];
  rtb_y = (0.12360330270167032 * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[2] +
           denAccum) + MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[3];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[3] =
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[2];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[2] = denAccum;
  denAccum = (0.59478429054858828 * rtb_y - 0.51759714787485733 *
              MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[4]) - 0.94109944836843162 *
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[5];
  rtb_y = (0.64603860165544358 * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[4] +
           denAccum) + MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[5];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[5] =
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[4];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[4] = denAccum;
  denAccum = (0.59478429054858828 * rtb_y - 0.21183511407367767 *
              MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[6]) - 0.93930845670321006 *
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[7];
  rtb_y = (0.0957486348882209 * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[6] +
           denAccum) + MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[7];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[7] =
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[6];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[6] = denAccum;
  denAccum = (0.49932225731035124 * rtb_y - 0.49416277208678916 *
              MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[8]) - 0.89590475749957321 *
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[9];
  rtb_y = (0.71145920866407719 * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[8] +
           denAccum) + MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[9];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[9] =
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[8];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[8] = denAccum;
  denAccum = (0.49932225731035124 * rtb_y - 0.21884422469867965 *
              MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[10]) - 0.89306130445488452
    * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[11];
  rtb_y = (0.021873468628494416 * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[10] +
           denAccum) + MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[11];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[11] =
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[10];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[10] = denAccum;
  denAccum = (0.34838267808004042 * rtb_y - 0.45089248581220753 *
              MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[12]) - 0.84715521652707737
    * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[13];
  rtb_y = (0.87725677403040825 * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[12] +
           denAccum) + MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[13];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[13] =
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[12];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[12] = denAccum;
  denAccum = (0.34838267808004042 * rtb_y - 0.24526307140291831 *
              MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[14]) - 0.84405026304818087
    * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[15];
  rtb_y = (-0.17476459239363229 * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[14] +
           denAccum) + MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[15];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[15] =
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[14];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[14] = denAccum;
  denAccum = (0.15518626123477505 * rtb_y - 0.38161627090508649 *
              MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[16]) - 0.81018748921523254
    * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[17];
  rtb_y = (1.4704569904056173 * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[16] +
           denAccum) + MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[17];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[17] =
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[16];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[16] = denAccum;
  denAccum = (0.15518626123477505 * rtb_y - 0.30262072908659821 *
              MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[18]) - 0.80871624586626634
    * MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[19];
  rtb_Filter_BPF_Narrow_band = (-1.0116275293074677 *
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[18] + denAccum) +
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[19];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[19] =
    MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[18];
  MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[18] = denAccum;

  /* S-Function (sdspbiquad): '<S6>/Filter_LPF_10K' incorporates:
   *  RandomNumber: '<S6>/Random Number_5'
   */
  denAccum = (0.34064333050371942 * MIMO_DW.NextOutput - -0.61248541763485032 *
              MIMO_DW.Filter_LPF_10K_FILT_STATES[0]) - 0.975058739649728 *
    MIMO_DW.Filter_LPF_10K_FILT_STATES[1];
  rtb_y = (2.0 * MIMO_DW.Filter_LPF_10K_FILT_STATES[0] + denAccum) +
    MIMO_DW.Filter_LPF_10K_FILT_STATES[1];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[1] = MIMO_DW.Filter_LPF_10K_FILT_STATES[0];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[0] = denAccum;
  denAccum = (0.3068896047194154 * rtb_y - -0.69804357742175727 *
              MIMO_DW.Filter_LPF_10K_FILT_STATES[2]) - 0.92560199629941908 *
    MIMO_DW.Filter_LPF_10K_FILT_STATES[3];
  rtb_y = (2.0 * MIMO_DW.Filter_LPF_10K_FILT_STATES[2] + denAccum) +
    MIMO_DW.Filter_LPF_10K_FILT_STATES[3];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[3] = MIMO_DW.Filter_LPF_10K_FILT_STATES[2];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[2] = denAccum;
  denAccum = (0.25015501518684569 * rtb_y - -0.87447647225956526 *
              MIMO_DW.Filter_LPF_10K_FILT_STATES[4]) - 0.87509653300694779 *
    MIMO_DW.Filter_LPF_10K_FILT_STATES[5];
  rtb_y = (2.0 * MIMO_DW.Filter_LPF_10K_FILT_STATES[4] + denAccum) +
    MIMO_DW.Filter_LPF_10K_FILT_STATES[5];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[5] = MIMO_DW.Filter_LPF_10K_FILT_STATES[4];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[4] = denAccum;
  denAccum = (0.175606500390419 * rtb_y - -1.1212962596492491 *
              MIMO_DW.Filter_LPF_10K_FILT_STATES[6]) - 0.82372226121092507 *
    MIMO_DW.Filter_LPF_10K_FILT_STATES[7];
  rtb_y = (2.0 * MIMO_DW.Filter_LPF_10K_FILT_STATES[6] + denAccum) +
    MIMO_DW.Filter_LPF_10K_FILT_STATES[7];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[7] = MIMO_DW.Filter_LPF_10K_FILT_STATES[6];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[6] = denAccum;
  denAccum = (0.095400343924137557 * rtb_y - -1.3939715501267027 *
              MIMO_DW.Filter_LPF_10K_FILT_STATES[8]) - 0.775572925823253 *
    MIMO_DW.Filter_LPF_10K_FILT_STATES[9];
  rtb_y = (2.0 * MIMO_DW.Filter_LPF_10K_FILT_STATES[8] + denAccum) +
    MIMO_DW.Filter_LPF_10K_FILT_STATES[9];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[9] = MIMO_DW.Filter_LPF_10K_FILT_STATES[8];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[8] = denAccum;
  denAccum = (0.030729214029482581 * rtb_y - -1.6165158510699218 *
              MIMO_DW.Filter_LPF_10K_FILT_STATES[10]) - 0.73943270718785215 *
    MIMO_DW.Filter_LPF_10K_FILT_STATES[11];
  rtb_y = (2.0 * MIMO_DW.Filter_LPF_10K_FILT_STATES[10] + denAccum) +
    MIMO_DW.Filter_LPF_10K_FILT_STATES[11];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[11] = MIMO_DW.Filter_LPF_10K_FILT_STATES[10];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[10] = denAccum;
  denAccum = (0.074045875134555322 * rtb_y - -0.85190824973088941 *
              MIMO_DW.Filter_LPF_10K_FILT_STATES[12]) - 0.0 *
    MIMO_DW.Filter_LPF_10K_FILT_STATES[13];
  rtb_Filter_LPF_10K = (denAccum + MIMO_DW.Filter_LPF_10K_FILT_STATES[12]) + 0.0
    * MIMO_DW.Filter_LPF_10K_FILT_STATES[13];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[13] = MIMO_DW.Filter_LPF_10K_FILT_STATES[12];
  MIMO_DW.Filter_LPF_10K_FILT_STATES[12] = denAccum;

  /* S-Function (sdspbiquad): '<S6>/Filter_1000Hz_Elliptic' incorporates:
   *  RandomNumber: '<S6>/Random Number_5'
   */
  denAccum = (0.15674201262458531 * MIMO_DW.NextOutput - -1.9793983593039173 *
              MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[0]) - 0.99644764778294193 *
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[1];
  rtb_y = (-1.9763227464113309 * MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[0] +
           denAccum) + MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[1];
  MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[1] =
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[0];
  MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[0] = denAccum;
  denAccum = (0.54861869941848085 * rtb_y - -1.972373029258897 *
              MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[2]) - 0.98730124834243593 *
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[3];
  rtb_y = (-1.9727894453846317 * MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[2] +
           denAccum) + MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[3];
  MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[3] =
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[2];
  MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[2] = denAccum;
  denAccum = (0.25475716037438895 * rtb_y - -1.9623577130824694 *
              MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[4]) - 0.97266042124171093 *
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[5];
  rtb_y = (-1.9595587101689276 * MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[4] +
           denAccum) + MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[5];
  MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[5] =
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[4];
  MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[4] = denAccum;
  denAccum = (0.035299988916345823 * rtb_y - -1.950078922733236 *
              MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[6]) - 0.954154972801176 *
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[7];
  rtb_y = (-1.8845311232929902 * MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[6] +
           denAccum) + MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[7];
  MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[7] =
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[6];
  MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[6] = denAccum;
  denAccum = (0.064621492680459483 * rtb_y - -0.97186690799728737 *
              MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[8]) - 0.0 *
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[9];
  rtb_Filter_1000Hz_Elliptic = (denAccum +
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[8]) + 0.0 *
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[9];
  MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[9] =
    MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[8];
  MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[8] = denAccum;

  /* S-Function (sdspbiquad): '<S6>/Filter_LPF_500Hz1' incorporates:
   *  RandomNumber: '<S6>/Random Number_5'
   */
  denAccum = (0.72113260336818674 * MIMO_DW.NextOutput - -1.9890283136461042 *
              MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[0]) - 0.9935124525991188 *
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[1];
  rtb_y = (-1.9937818108180512 * MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[0] +
           denAccum) + MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[1];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[1] =
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[0];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[0] = denAccum;
  denAccum = (0.70230402543459058 * rtb_y - -1.9752384633404498 *
              MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[2]) - 0.979918343946878 *
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[3];
  rtb_y = (-1.9933363893172444 * MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[2] +
           denAccum) + MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[3];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[3] =
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[2];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[2] = denAccum;
  denAccum = (0.6668363107986508 * rtb_y - -1.9590258796973423 *
              MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[4]) - 0.96415455584356236 *
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[5];
  rtb_y = (-1.99230894289473 * MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[4] +
           denAccum) + MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[5];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[5] =
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[4];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[4] = denAccum;
  denAccum = (0.60966319640745126 * rtb_y - -1.93837876272327 *
              MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[6]) - 0.94427588837131771 *
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[7];
  rtb_y = (-1.9903272402159133 * MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[6] +
           denAccum) + MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[7];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[7] =
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[6];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[6] = denAccum;
  denAccum = (0.52301963806480889 * rtb_y - -1.9107332533063635 *
              MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[8]) - 0.9178248216592656 *
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[9];
  rtb_y = (-1.9864411050048882 * MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[8] +
           denAccum) + MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[9];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[9] =
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[8];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[8] = denAccum;
  denAccum = (0.39845943001868805 * rtb_y - -1.8734668147272706 *
              MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[10]) - 0.88229584974702047 *
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[11];
  rtb_y = (-1.9778420728571142 * MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[10] +
           denAccum) + MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[11];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[11] =
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[10];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[10] = denAccum;
  denAccum = (0.2371706758353945 * rtb_y - -1.8267392427066584 *
              MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[12]) - 0.83783059101917379 *
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[13];
  rtb_y = (-1.9532347400307906 * MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[12] +
           denAccum) + MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[13];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[13] =
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[12];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[12] = denAccum;
  denAccum = (0.076350677833548486 * rtb_y - -1.7808396139010538 *
              MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[14]) - 0.7941923769027569 *
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[15];
  rtb_y = (-1.8251127117585888 * MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[14] +
           denAccum) + MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[15];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[15] =
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[14];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[14] = denAccum;
  denAccum = (0.059951697745483971 * rtb_y - -0.880096604509032 *
              MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[16]) - 0.0 *
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[17];
  rtb_y = (denAccum + MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[16]) + 0.0 *
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[17];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[17] =
    MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[16];
  MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[16] = denAccum;

  /* ManualSwitch: '<Root>/signal_C//D2' */
  if (MIMO_P.signal_CD2_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/signalX' incorporates:
     *  ManualSwitch: '<Root>/signal_C//D'
     */
    if (MIMO_P.signalX_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/signal_A//B' incorporates:
       *  Gain: '<S6>/Gain1'
       */
      if (MIMO_P.signal_AB_CurrentSetting == 1) {
        rtb_yp2 = rtb_Filter_Highpass_1000Hz;
      } else {
        rtb_yp2 = MIMO_P.Gain1_Gain * rtb_Filter_BPF_Narrow_band;
      }

      /* End of ManualSwitch: '<Root>/signal_A//B' */
    } else if (MIMO_P.signal_CD_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/signal_C//D' */
      rtb_yp2 = rtb_Filter_LPF_10K;
    } else {
      rtb_yp2 = rtb_Filter_1000Hz_Elliptic;
    }

    /* End of ManualSwitch: '<Root>/signalX' */
  } else {
    rtb_yp2 = rtb_y;
  }

  /* End of ManualSwitch: '<Root>/signal_C//D2' */

  /* Gain: '<Root>/GainRBNN2' */
  MIMO_B.GainRBNN2 = MIMO_P.GainRBNN2_Gain * rtb_yp2;

  /* ManualSwitch: '<Root>/signal_J//K2' incorporates:
   *  Sin: '<S1>/Sine Wave14'
   *  Sin: '<S1>/Sine Wave15'
   *  Sin: '<S1>/Sine Wave16'
   *  Sin: '<S1>/Sine Wave17'
   *  Sin: '<S1>/Sine Wave18'
   *  Sin: '<S1>/Sine Wave19'
   *  Sin: '<S1>/Sine Wave20'
   *  Sin: '<S1>/Sine Wave21'
   *  Sin: '<S1>/Sine Wave22'
   *  Sin: '<S1>/Sine Wave23'
   *  Sin: '<S1>/Sine Wave4'
   *  Sum: '<S1>/Sum3'
   *  Sum: '<S1>/Sum4'
   *  Sum: '<S1>/Sum5'
   */
  if (MIMO_P.signal_JK2_CurrentSetting == 1) {
    rtb_Filter_1000Hz_Elliptic = sin(MIMO_P.SineWave4_Freq * MIMO_M->Timing.t[0]
      + MIMO_P.SineWave4_Phase) * MIMO_P.SineWave4_Amp + MIMO_P.SineWave4_Bias;
  } else {
    /* Sin: '<S1>/Sine Wave14' incorporates:
     *  Sin: '<S1>/Sine Wave15'
     *  Sin: '<S1>/Sine Wave16'
     *  Sin: '<S1>/Sine Wave17'
     *  Sin: '<S1>/Sine Wave18'
     *  Sin: '<S1>/Sine Wave19'
     *  Sin: '<S1>/Sine Wave20'
     *  Sin: '<S1>/Sine Wave21'
     *  Sin: '<S1>/Sine Wave22'
     *  Sin: '<S1>/Sine Wave23'
     */
    rtb_Filter_LPF_10K = MIMO_M->Timing.t[0];
    rtb_Filter_1000Hz_Elliptic = (((((sin(MIMO_P.SineWave14_Freq *
      rtb_Filter_LPF_10K + MIMO_P.SineWave14_Phase) * MIMO_P.SineWave14_Amp +
      MIMO_P.SineWave14_Bias) + (sin(MIMO_P.SineWave15_Freq * rtb_Filter_LPF_10K
      + MIMO_P.SineWave15_Phase) * MIMO_P.SineWave15_Amp +
      MIMO_P.SineWave15_Bias)) + (sin(MIMO_P.SineWave17_Freq *
      rtb_Filter_LPF_10K + MIMO_P.SineWave17_Phase) * MIMO_P.SineWave17_Amp +
      MIMO_P.SineWave17_Bias)) + (sin(MIMO_P.SineWave20_Freq *
      rtb_Filter_LPF_10K + MIMO_P.SineWave20_Phase) * MIMO_P.SineWave20_Amp +
      MIMO_P.SineWave20_Bias)) + (sin(MIMO_P.SineWave16_Freq *
      rtb_Filter_LPF_10K + MIMO_P.SineWave16_Phase) * MIMO_P.SineWave16_Amp +
      MIMO_P.SineWave16_Bias)) + (((((sin(MIMO_P.SineWave23_Freq *
      rtb_Filter_LPF_10K + MIMO_P.SineWave23_Phase) * MIMO_P.SineWave23_Amp +
      MIMO_P.SineWave23_Bias) + (sin(MIMO_P.SineWave21_Freq * rtb_Filter_LPF_10K
      + MIMO_P.SineWave21_Phase) * MIMO_P.SineWave21_Amp +
      MIMO_P.SineWave21_Bias)) + (sin(MIMO_P.SineWave22_Freq *
      rtb_Filter_LPF_10K + MIMO_P.SineWave22_Phase) * MIMO_P.SineWave22_Amp +
      MIMO_P.SineWave22_Bias)) + (sin(MIMO_P.SineWave18_Freq *
      rtb_Filter_LPF_10K + MIMO_P.SineWave18_Phase) * MIMO_P.SineWave18_Amp +
      MIMO_P.SineWave18_Bias)) + (sin(MIMO_P.SineWave19_Freq *
      rtb_Filter_LPF_10K + MIMO_P.SineWave19_Phase) * MIMO_P.SineWave19_Amp +
      MIMO_P.SineWave19_Bias));
  }

  /* End of ManualSwitch: '<Root>/signal_J//K2' */

  /* ManualSwitch: '<Root>/TT' incorporates:
   *  ManualSwitch: '<Root>/signal_J//K1'
   */
  if (MIMO_P.TT_CurrentSetting == 1) {
    MIMO_B.TT = MIMO_B.GainRBNN2;
  } else if (MIMO_P.signal_JK1_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/signal_J//K' incorporates:
     *  ManualSwitch: '<Root>/signal_J//K1'
     *  Sin: '<S1>/Sine Wave1'
     *  Sin: '<S1>/Sine Wave10'
     *  Sin: '<S1>/Sine Wave11'
     *  Sin: '<S1>/Sine Wave7'
     *  Sin: '<S1>/Sine Wave8'
     *  Sin: '<S1>/Sine Wave9'
     *  Sum: '<S1>/Sum2'
     */
    if (MIMO_P.signal_JK_CurrentSetting == 1) {
      rtb_Filter_LPF_10K = sin(MIMO_P.SineWave1_Freq * MIMO_M->Timing.t[0] +
        MIMO_P.SineWave1_Phase) * MIMO_P.SineWave1_Amp + MIMO_P.SineWave1_Bias;
    } else {
      rtb_Filter_LPF_10K = ((((sin(MIMO_P.SineWave7_Freq * MIMO_M->Timing.t[0] +
        MIMO_P.SineWave7_Phase) * MIMO_P.SineWave7_Amp + MIMO_P.SineWave7_Bias)
        + (sin(MIMO_P.SineWave8_Freq * MIMO_M->Timing.t[0] +
               MIMO_P.SineWave8_Phase) * MIMO_P.SineWave8_Amp +
           MIMO_P.SineWave8_Bias)) + (sin(MIMO_P.SineWave11_Freq *
        MIMO_M->Timing.t[0] + MIMO_P.SineWave11_Phase) * MIMO_P.SineWave11_Amp +
        MIMO_P.SineWave11_Bias)) + (sin(MIMO_P.SineWave9_Freq * MIMO_M->
        Timing.t[0] + MIMO_P.SineWave9_Phase) * MIMO_P.SineWave9_Amp +
        MIMO_P.SineWave9_Bias)) + (sin(MIMO_P.SineWave10_Freq * MIMO_M->
        Timing.t[0] + MIMO_P.SineWave10_Phase) * MIMO_P.SineWave10_Amp +
        MIMO_P.SineWave10_Bias);
    }

    /* End of ManualSwitch: '<Root>/signal_J//K' */

    /* ManualSwitch: '<Root>/signal_J//K1' incorporates:
     *  Gain: '<Root>/GainRBNN1'
     */
    MIMO_B.TT = MIMO_P.GainRBNN1_Gain * rtb_Filter_LPF_10K;
  } else {
    /* ManualSwitch: '<Root>/signal_J//K1' */
    MIMO_B.TT = rtb_Filter_1000Hz_Elliptic;
  }

  /* End of ManualSwitch: '<Root>/TT' */

  /* ZeroOrderHold: '<Root>/Zero-Order Hold3' */
  MIMO_B.ZeroOrderHold3 = MIMO_B.TT;

  /* ManualSwitch: '<Root>/Signal_switch4' */
  if (MIMO_P.Signal_switch4_CurrentSetting == 1) {
    rtb_Filter_LPF_10K = MIMO_B.ZeroOrderHold3;
  } else {
    rtb_Filter_LPF_10K = MIMO_B.TT;
  }

  /* End of ManualSwitch: '<Root>/Signal_switch4' */

  /* MATLAB Function: '<Root>/software_rezonator' */
  if (!MIMO_DW.g_not_empty_b) {
    MIMO_DW.g.size[0] = 8;
    MIMO_DW.g.size[1] = 8;
    memset(&MIMO_DW.g.data[0], 0, sizeof(creal_T) << 6U);
    MIMO_DW.g_not_empty_b = true;
  }

  if (!MIMO_DW.c_not_empty_k) {
    MIMO_DW.c.size[0] = 8;
    MIMO_DW.c.size[1] = 8;
    memset(&MIMO_DW.c.data[0], 0, sizeof(creal_T) << 6U);
    MIMO_DW.c_not_empty_k = true;
  }

  if (MIMO_DW.memory_alloc_flag_g == 0.0) {
    for (i = 0; i < 8; i++) {
      for (k = 0; k < 8; k++) {
        denAccum = (real_T)i * -6.2831853071795862 * (real_T)k;
        if (denAccum == 0.0) {
          signal_dif_im = 0.0;
        } else {
          signal_dif_im = denAccum / 8.0;
        }

        if (signal_dif_im == 0.0) {
          rtb_Filter_BPF_Narrow_band = 1.0;
          signal_dif_im = 0.0;
        } else {
          rtb_Filter_BPF_Narrow_band = cos(signal_dif_im);
          signal_dif_im = sin(signal_dif_im);
        }

        i_0 = i + (k << 3);
        MIMO_DW.g.data[i_0].re = 0.125 * rtb_Filter_BPF_Narrow_band;
        MIMO_DW.g.data[i_0].im = 0.125 * signal_dif_im;
        denAccum = (real_T)i * 6.2831853071795862 * (real_T)k;
        if (denAccum == 0.0) {
          signal_dif_im = 0.0;
        } else {
          signal_dif_im = denAccum / 8.0;
        }

        if (signal_dif_im == 0.0) {
          MIMO_DW.c.data[i_0].re = 1.0;
          MIMO_DW.c.data[i_0].im = 0.0;
        } else {
          MIMO_DW.c.data[i_0].re = cos(signal_dif_im);
          MIMO_DW.c.data[i_0].im = sin(signal_dif_im);
        }
      }
    }

    MIMO_DW.memory_alloc_flag_g = 1.0;
  }

  if (!MIMO_DW.bfr_rezo_sm_not_empty_h) {
    MIMO_DW.bfr_rezo_sm.size = 8;
    memset(&MIMO_DW.bfr_rezo_sm.data[0], 0, sizeof(creal_T) << 3U);
    MIMO_DW.bfr_rezo_sm_not_empty_h = true;
  }

  if (!MIMO_DW.aft_delay_not_empty_m) {
    MIMO_DW.aft_delay.size = 8;
    memset(&MIMO_DW.aft_delay.data[0], 0, sizeof(creal_T) << 3U);
    MIMO_DW.aft_delay_not_empty_m = true;
  }

  if (!MIMO_DW.dft_out_not_empty_c) {
    MIMO_DW.dft_out.size = 8;
    memset(&MIMO_DW.dft_out.data[0], 0, sizeof(creal_T) << 3U);
    MIMO_DW.dft_out_not_empty_c = true;
  }

  if (rtIsInf(MIMO_DW.n_f)) {
    rtb_Filter_BPF_Narrow_band = (rtNaN);
  } else if (MIMO_DW.n_f == 0.0) {
    rtb_Filter_BPF_Narrow_band = 0.0;
  } else {
    rtb_Filter_BPF_Narrow_band = fmod(MIMO_DW.n_f, 8.0);
    if (rtb_Filter_BPF_Narrow_band == 0.0) {
      rtb_Filter_BPF_Narrow_band = 0.0;
    }
  }

  i = (int32_T)(rtb_Filter_BPF_Narrow_band + 1.0);
  MIMO_DW.dft_out.size = 8;
  for (i_0 = 0; i_0 < 8; i_0++) {
    rtb_Filter_BPF_Narrow_band = MIMO_DW.c.data[((i - 1) << 3) + i_0].re;
    signal_dif_im = MIMO_DW.c.data[((i - 1) << 3) + i_0].im;
    MIMO_DW.dft_out.data[i_0].re = rtb_Filter_BPF_Narrow_band *
      MIMO_DW.aft_delay.data[i_0].re - signal_dif_im *
      MIMO_DW.aft_delay.data[i_0].im;
    MIMO_DW.dft_out.data[i_0].im = rtb_Filter_BPF_Narrow_band *
      MIMO_DW.aft_delay.data[i_0].im + signal_dif_im *
      MIMO_DW.aft_delay.data[i_0].re;
  }

  MIMO_DW.dft_out_not_empty_c = true;
  rtb_Filter_BPF_Narrow_band = MIMO_DW.dft_out.data[0].re;
  signal_dif_im = MIMO_DW.dft_out.data[0].im;
  for (k = 0; k < 7; k++) {
    rtb_Filter_BPF_Narrow_band += MIMO_DW.dft_out.data[k + 1].re;
    signal_dif_im += MIMO_DW.dft_out.data[k + 1].im;
  }

  rtb_Filter_BPF_Narrow_band = rtb_Filter_LPF_10K - rtb_Filter_BPF_Narrow_band;
  MIMO_DW.bfr_rezo_sm.size = 8;
  MIMO_DW.bfr_rezo_sm_not_empty_h = true;
  MIMO_DW.n_f++;
  denAccum = 6.2831853071795862 * MIMO_DW.n_f / 8.0;
  rtb_Filter_Highpass_1000Hz = cos(denAccum);
  x_tmp_idx_0 = sin(denAccum);
  c_x_tmp = 31.415926535897931 * MIMO_DW.n_f / 8.0;
  c_x_idx_0 = cos(c_x_tmp);
  c_x_tmp_idx_0 = sin(c_x_tmp);
  denAccum = 12.566370614359172 * MIMO_DW.n_f / 8.0;
  x_idx_1 = cos(denAccum);
  x_tmp_idx_1 = sin(denAccum);
  c_x_tmp = 37.699111843077517 * MIMO_DW.n_f / 8.0;
  c_x_idx_1 = cos(c_x_tmp);
  c_x_tmp_idx_1 = sin(c_x_tmp);
  denAccum = 18.849555921538759 * MIMO_DW.n_f / 8.0;
  x = cos(denAccum);
  denAccum = sin(denAccum);
  c_x_tmp = 43.982297150257104 * MIMO_DW.n_f / 8.0;
  c_x = cos(c_x_tmp);
  c_x_tmp = sin(c_x_tmp);
  MIMO_DW.aft_delay.size = 8;
  for (i_0 = 0; i_0 < 8; i_0++) {
    MIMO_DW.bfr_rezo_sm.data[i_0].re = MIMO_DW.g.data[((i - 1) << 3) + i_0].re *
      rtb_Filter_BPF_Narrow_band - MIMO_DW.g.data[((i - 1) << 3) + i_0].im *
      (0.0 - signal_dif_im);
    MIMO_DW.bfr_rezo_sm.data[i_0].im = MIMO_DW.g.data[((i - 1) << 3) + i_0].re *
      (0.0 - signal_dif_im) + MIMO_DW.g.data[((i - 1) << 3) + i_0].im *
      rtb_Filter_BPF_Narrow_band;
    dft_trans_data[i_0] = MIMO_DW.aft_delay.data[i_0];
    MIMO_DW.aft_delay.data[i_0].re += MIMO_DW.bfr_rezo_sm.data[i_0].re;
    MIMO_DW.aft_delay.data[i_0].im += MIMO_DW.bfr_rezo_sm.data[i_0].im;
  }

  MIMO_DW.aft_delay_not_empty_m = true;

  /* Gain: '<Root>/GainRBNN3' */
  MIMO_B.GainRBNN3 = MIMO_P.GainRBNN3_Gain * rtb_y;

  /* ManualSwitch: '<Root>/TT1' */
  if (MIMO_P.TT1_CurrentSetting == 1) {
    rtb_y = MIMO_B.GainRBNN3;
  } else {
    rtb_y = rtb_Filter_1000Hz_Elliptic;
  }

  /* End of ManualSwitch: '<Root>/TT1' */

  /* MATLAB Function: '<Root>/software_rezonator1' */
  if (!MIMO_DW.g_not_empty) {
    MIMO_DW.g_b.size[0] = 8;
    MIMO_DW.g_b.size[1] = 8;
    memset(&MIMO_DW.g_b.data[0], 0, sizeof(creal_T) << 6U);
    MIMO_DW.g_not_empty = true;
  }

  if (!MIMO_DW.c_not_empty) {
    MIMO_DW.c_j.size[0] = 8;
    MIMO_DW.c_j.size[1] = 8;
    memset(&MIMO_DW.c_j.data[0], 0, sizeof(creal_T) << 6U);
    MIMO_DW.c_not_empty = true;
  }

  if (MIMO_DW.memory_alloc_flag == 0.0) {
    for (i = 0; i < 8; i++) {
      for (k = 0; k < 8; k++) {
        rtb_Filter_BPF_Narrow_band = (real_T)i * -6.2831853071795862 * (real_T)k;
        if (rtb_Filter_BPF_Narrow_band == 0.0) {
          signal_dif_im = 0.0;
        } else {
          signal_dif_im = rtb_Filter_BPF_Narrow_band / 8.0;
        }

        if (signal_dif_im == 0.0) {
          rtb_Filter_BPF_Narrow_band = 1.0;
          signal_dif_im = 0.0;
        } else {
          rtb_Filter_BPF_Narrow_band = cos(signal_dif_im);
          signal_dif_im = sin(signal_dif_im);
        }

        MIMO_DW.g_b.data[i + (k << 3)].re = 0.125 * rtb_Filter_BPF_Narrow_band;
        MIMO_DW.g_b.data[i + (k << 3)].im = 0.125 * signal_dif_im;
        rtb_Filter_BPF_Narrow_band = (real_T)i * 6.2831853071795862 * (real_T)k;
        if (rtb_Filter_BPF_Narrow_band == 0.0) {
          signal_dif_im = 0.0;
        } else {
          signal_dif_im = rtb_Filter_BPF_Narrow_band / 8.0;
        }

        if (signal_dif_im == 0.0) {
          MIMO_DW.c_j.data[i + (k << 3)].re = 1.0;
          MIMO_DW.c_j.data[i + (k << 3)].im = 0.0;
        } else {
          MIMO_DW.c_j.data[i + (k << 3)].re = cos(signal_dif_im);
          MIMO_DW.c_j.data[i + (k << 3)].im = sin(signal_dif_im);
        }
      }
    }

    MIMO_DW.memory_alloc_flag = 1.0;
  }

  if (!MIMO_DW.bfr_rezo_sm_not_empty) {
    MIMO_DW.bfr_rezo_sm_p.size = 8;
    memset(&MIMO_DW.bfr_rezo_sm_p.data[0], 0, sizeof(creal_T) << 3U);
    MIMO_DW.bfr_rezo_sm_not_empty = true;
  }

  if (!MIMO_DW.aft_delay_not_empty) {
    MIMO_DW.aft_delay_l.size = 8;
    memset(&MIMO_DW.aft_delay_l.data[0], 0, sizeof(creal_T) << 3U);
    MIMO_DW.aft_delay_not_empty = true;
  }

  if (!MIMO_DW.dft_out_not_empty) {
    MIMO_DW.dft_out_e.size = 8;
    memset(&MIMO_DW.dft_out_e.data[0], 0, sizeof(creal_T) << 3U);
    MIMO_DW.dft_out_not_empty = true;
  }

  if (rtIsInf(MIMO_DW.n)) {
    rtb_Filter_BPF_Narrow_band = (rtNaN);
  } else if (MIMO_DW.n == 0.0) {
    rtb_Filter_BPF_Narrow_band = 0.0;
  } else {
    rtb_Filter_BPF_Narrow_band = fmod(MIMO_DW.n, 8.0);
    if (rtb_Filter_BPF_Narrow_band == 0.0) {
      rtb_Filter_BPF_Narrow_band = 0.0;
    }
  }

  i = (int32_T)(rtb_Filter_BPF_Narrow_band + 1.0);
  MIMO_DW.dft_out_e.size = 8;
  for (i_0 = 0; i_0 < 8; i_0++) {
    rtb_Filter_BPF_Narrow_band = MIMO_DW.c_j.data[((i - 1) << 3) + i_0].re;
    signal_dif_im = MIMO_DW.c_j.data[((i - 1) << 3) + i_0].im;
    MIMO_DW.dft_out_e.data[i_0].re = rtb_Filter_BPF_Narrow_band *
      MIMO_DW.aft_delay_l.data[i_0].re - signal_dif_im *
      MIMO_DW.aft_delay_l.data[i_0].im;
    MIMO_DW.dft_out_e.data[i_0].im = rtb_Filter_BPF_Narrow_band *
      MIMO_DW.aft_delay_l.data[i_0].im + signal_dif_im *
      MIMO_DW.aft_delay_l.data[i_0].re;
  }

  MIMO_DW.dft_out_not_empty = true;
  rtb_Filter_BPF_Narrow_band = MIMO_DW.dft_out_e.data[0].re;
  signal_dif_im = MIMO_DW.dft_out_e.data[0].im;
  for (k = 0; k < 7; k++) {
    rtb_Filter_BPF_Narrow_band += MIMO_DW.dft_out_e.data[k + 1].re;
    signal_dif_im += MIMO_DW.dft_out_e.data[k + 1].im;
  }

  rtb_Filter_BPF_Narrow_band = rtb_y - rtb_Filter_BPF_Narrow_band;
  MIMO_DW.bfr_rezo_sm_p.size = 8;
  MIMO_DW.bfr_rezo_sm_not_empty = true;
  MIMO_DW.n++;
  rtb_Filter_1000Hz_Elliptic = 6.2831853071795862 * MIMO_DW.n / 8.0;
  x_idx_0 = cos(rtb_Filter_1000Hz_Elliptic);
  x_tmp_idx_0_0 = sin(rtb_Filter_1000Hz_Elliptic);
  c_x_tmp_0 = 31.415926535897931 * MIMO_DW.n / 8.0;
  c_x_idx_0_0 = cos(c_x_tmp_0);
  c_x_tmp_idx_0_0 = sin(c_x_tmp_0);
  rtb_Filter_1000Hz_Elliptic = 12.566370614359172 * MIMO_DW.n / 8.0;
  x_idx_1_0 = cos(rtb_Filter_1000Hz_Elliptic);
  x_tmp_idx_1_0 = sin(rtb_Filter_1000Hz_Elliptic);
  c_x_tmp_0 = 37.699111843077517 * MIMO_DW.n / 8.0;
  c_x_idx_1_0 = cos(c_x_tmp_0);
  c_x_tmp_idx_1_0 = sin(c_x_tmp_0);
  rtb_Filter_1000Hz_Elliptic = 18.849555921538759 * MIMO_DW.n / 8.0;
  x_0 = cos(rtb_Filter_1000Hz_Elliptic);
  rtb_Filter_1000Hz_Elliptic = sin(rtb_Filter_1000Hz_Elliptic);
  c_x_tmp_0 = 43.982297150257104 * MIMO_DW.n / 8.0;
  c_x_0 = cos(c_x_tmp_0);
  c_x_tmp_0 = sin(c_x_tmp_0);
  MIMO_DW.aft_delay_l.size = 8;
  for (i_0 = 0; i_0 < 8; i_0++) {
    MIMO_DW.bfr_rezo_sm_p.data[i_0].re = MIMO_DW.g_b.data[((i - 1) << 3) + i_0].
      re * rtb_Filter_BPF_Narrow_band - MIMO_DW.g_b.data[((i - 1) << 3) + i_0].
      im * (0.0 - signal_dif_im);
    MIMO_DW.bfr_rezo_sm_p.data[i_0].im = MIMO_DW.g_b.data[((i - 1) << 3) + i_0].
      re * (0.0 - signal_dif_im) + MIMO_DW.g_b.data[((i - 1) << 3) + i_0].im *
      rtb_Filter_BPF_Narrow_band;
    dft_trans_data_0[i_0] = MIMO_DW.aft_delay_l.data[i_0];
    MIMO_DW.aft_delay_l.data[i_0].re += MIMO_DW.bfr_rezo_sm_p.data[i_0].re;
    MIMO_DW.aft_delay_l.data[i_0].im += MIMO_DW.bfr_rezo_sm_p.data[i_0].im;
  }

  MIMO_DW.aft_delay_not_empty = true;

  /* MATLAB Function: '<Root>/software_rezonator' */
  tmp[0] = 5.0 * dft_trans_data[0].re;
  tmp[4] = 5.0 * -dft_trans_data[4].re;

  /* MATLAB Function: '<Root>/software_rezonator1' */
  tmp_0[0] = 5.0 * dft_trans_data_0[0].re;
  tmp_0[4] = 5.0 * -dft_trans_data_0[4].re;

  /* MATLAB Function: '<Root>/software_rezonator' */
  tmp[1] = (dft_trans_data[1].re * rtb_Filter_Highpass_1000Hz - dft_trans_data[1]
            .im * x_tmp_idx_0) * 2.0 * 5.0;
  tmp[5] = (dft_trans_data[5].im * c_x_idx_0 + dft_trans_data[5].re *
            c_x_tmp_idx_0) * -2.0 * 5.0;

  /* MATLAB Function: '<Root>/software_rezonator1' */
  tmp_0[1] = (dft_trans_data_0[1].re * x_idx_0 - dft_trans_data_0[1].im *
              x_tmp_idx_0_0) * 2.0 * 5.0;
  tmp_0[5] = (dft_trans_data_0[5].im * c_x_idx_0_0 + dft_trans_data_0[5].re *
              c_x_tmp_idx_0_0) * -2.0 * 5.0;

  /* MATLAB Function: '<Root>/software_rezonator' */
  tmp[2] = (dft_trans_data[2].re * x_idx_1 - dft_trans_data[2].im * x_tmp_idx_1)
    * 2.0 * 5.0;
  tmp[6] = (dft_trans_data[6].im * c_x_idx_1 + dft_trans_data[6].re *
            c_x_tmp_idx_1) * -2.0 * 5.0;

  /* MATLAB Function: '<Root>/software_rezonator1' */
  tmp_0[2] = (dft_trans_data_0[2].re * x_idx_1_0 - dft_trans_data_0[2].im *
              x_tmp_idx_1_0) * 2.0 * 5.0;
  tmp_0[6] = (dft_trans_data_0[6].im * c_x_idx_1_0 + dft_trans_data_0[6].re *
              c_x_tmp_idx_1_0) * -2.0 * 5.0;

  /* MATLAB Function: '<Root>/software_rezonator' */
  tmp[3] = (dft_trans_data[3].re * x - dft_trans_data[3].im * denAccum) * 2.0 *
    5.0;
  tmp[7] = (dft_trans_data[7].im * c_x + dft_trans_data[7].re * c_x_tmp) * -2.0 *
    5.0;

  /* MATLAB Function: '<Root>/software_rezonator1' */
  tmp_0[3] = (dft_trans_data_0[3].re * x_0 - dft_trans_data_0[3].im *
              rtb_Filter_1000Hz_Elliptic) * 2.0 * 5.0;
  tmp_0[7] = (dft_trans_data_0[7].im * c_x_0 + dft_trans_data_0[7].re *
              c_x_tmp_0) * -2.0 * 5.0;

  /* Sum: '<Root>/Sum' */
  for (i_0 = 0; i_0 < 8; i_0++) {
    MIMO_B.Sum[i_0] = tmp[i_0] + tmp_0[i_0];
  }

  /* End of Sum: '<Root>/Sum' */

  /* ManualSwitch: '<Root>/External Stop_RBNN' incorporates:
   *  Constant: '<Root>/Training OFF'
   *  Constant: '<Root>/Training ON'
   */
  if (MIMO_P.ExternalStop_RBNN_CurrentSettin == 1) {
    MIMO_B.ExternalStop_RBNN = MIMO_P.TrainingOFF_Value;
  } else {
    MIMO_B.ExternalStop_RBNN = MIMO_P.TrainingON_Value;
  }

  /* End of ManualSwitch: '<Root>/External Stop_RBNN' */

  /* MATLAB Function: '<Root>/RBNN_NN' incorporates:
   *  Constant: '<Root>/LR_RBNN'
   *  Constant: '<Root>/u2'
   */
  MIMO_RBNN_NN(MIMO_B.output_fft_n, MIMO_B.output_difference_vector_l,
               MIMO_B.Sum, MIMO_P.u2_Value, MIMO_B.ExternalStop_RBNN,
               MIMO_P.LR_RBNN_Value, &MIMO_B.sf_RBNN_NN, &MIMO_DW.sf_RBNN_NN);

  /* Delay: '<Root>/y1' */
  rtb_Filter_1000Hz_Elliptic = MIMO_DW.y1_DSTATE;

  /* Delay: '<Root>/yp2' */
  rtb_yp2 = MIMO_DW.yp2_DSTATE;

  /* MATLAB Function: '<Root>/buffer_of_op_fft1' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  MIMO_B.output_difference_vector = rtb_yp2 - rtb_Filter_1000Hz_Elliptic;
  MIMO_B.output_fft.re = rtb_Filter_1000Hz_Elliptic;
  MIMO_B.output_fft.im = 0.0;

  /* ManualSwitch: '<Root>/External Stop_RBNN1' incorporates:
   *  Constant: '<Root>/Training OFF1'
   *  Constant: '<Root>/Training ON1'
   */
  if (MIMO_P.ExternalStop_RBNN1_CurrentSetti == 1) {
    MIMO_B.ExternalStop_RBNN1 = MIMO_P.TrainingOFF1_Value;
  } else {
    MIMO_B.ExternalStop_RBNN1 = MIMO_P.TrainingON1_Value;
  }

  /* End of ManualSwitch: '<Root>/External Stop_RBNN1' */

  /* MATLAB Function: '<Root>/RBNN_NN1' incorporates:
   *  Constant: '<Root>/LR_RBNN1'
   *  Constant: '<Root>/u1'
   */
  MIMO_RBNN_NN(MIMO_B.output_fft, MIMO_B.output_difference_vector, MIMO_B.Sum,
               MIMO_P.u1_Value, MIMO_B.ExternalStop_RBNN1, MIMO_P.LR_RBNN1_Value,
               &MIMO_B.sf_RBNN_NN1, &MIMO_DW.sf_RBNN_NN1);

  /* Delay: '<S7>/Delay' */
  MIMO_B.Delay = MIMO_DW.Delay_DSTATE;

  /* Delay: '<S7>/Delay1' */
  MIMO_B.Delay1 = MIMO_DW.Delay1_DSTATE;

  /* MATLAB Function: '<S7>/MATLAB Function' */
  MIMO_B.yp1 = (rtb_y - 0.8) * rtb_y * (rtb_y + 0.5) + MIMO_B.Delay1 / (1.0 +
    MIMO_B.Delay1);
  MIMO_B.yp2 = (rtb_Filter_LPF_10K - 0.8) * rtb_Filter_LPF_10K *
    (rtb_Filter_LPF_10K + 0.5) + (MIMO_B.Delay + MIMO_B.Delay) * MIMO_B.Delay1;

  /* ToWorkspace: '<Root>/To Workspace' */
  rt_UpdateLogVar((LogVar *)(LogVar*) (MIMO_DW.ToWorkspace_PWORK.LoggedData),
                  &MIMO_B.yp1, 0);

  /* ToWorkspace: '<Root>/To Workspace1' */
  rt_UpdateLogVar((LogVar *)(LogVar*) (MIMO_DW.ToWorkspace1_PWORK.LoggedData),
                  &MIMO_B.yp2, 0);

  /* MATLAB Function: '<Root>/RBNN_output' */
  MIMO_RBNN_output(MIMO_B.Sum, MIMO_B.sf_RBNN_NN.nn_op, &MIMO_B.sf_RBNN_output);

  /* Gain: '<Root>/Out_RBNN1' */
  MIMO_B.Out_RBNN1 = MIMO_P.Out_RBNN1_Gain * MIMO_B.sf_RBNN_output.yn;

  /* MATLAB Function: '<Root>/RBNN_output1' */
  MIMO_RBNN_output(MIMO_B.Sum, MIMO_B.sf_RBNN_NN1.nn_op, &MIMO_B.sf_RBNN_output1);

  /* Gain: '<Root>/Out_RBNN2' */
  MIMO_B.Out_RBNN2 = MIMO_P.Out_RBNN2_Gain * MIMO_B.sf_RBNN_output1.yn;

  /* Matfile logging */
  rt_UpdateTXYLogVars(MIMO_M->rtwLogInfo, (MIMO_M->Timing.t));

  /* Update for Delay: '<Root>/y' */
  MIMO_DW.y_DSTATE = MIMO_B.Out_RBNN1;

  /* Update for Delay: '<Root>/yp1' */
  MIMO_DW.yp1_DSTATE = MIMO_B.yp1;

  /* Update for RandomNumber: '<S6>/Random Number_5' */
  MIMO_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&MIMO_DW.RandSeed) *
    MIMO_P.RandomNumber_5_StdDev + MIMO_P.RandomNumber_5_Mean;

  /* Update for Delay: '<Root>/y1' */
  MIMO_DW.y1_DSTATE = MIMO_B.Out_RBNN2;

  /* Update for Delay: '<Root>/yp2' */
  MIMO_DW.yp2_DSTATE = MIMO_B.yp2;

  /* Update for Delay: '<S7>/Delay' */
  MIMO_DW.Delay_DSTATE = MIMO_B.yp1;

  /* Update for Delay: '<S7>/Delay1' */
  MIMO_DW.Delay1_DSTATE = MIMO_B.yp2;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(MIMO_M)!=-1) &&
        !((rtmGetTFinal(MIMO_M)-MIMO_M->Timing.t[0]) > MIMO_M->Timing.t[0] *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(MIMO_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++MIMO_M->Timing.clockTick0)) {
    ++MIMO_M->Timing.clockTickH0;
  }

  MIMO_M->Timing.t[0] = MIMO_M->Timing.clockTick0 * MIMO_M->Timing.stepSize0 +
    MIMO_M->Timing.clockTickH0 * MIMO_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [1.0E-5s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    MIMO_M->Timing.clockTick1++;
    if (!MIMO_M->Timing.clockTick1) {
      MIMO_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void MIMO_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MIMO_M, 0,
                sizeof(RT_MODEL_MIMO_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MIMO_M->solverInfo, &MIMO_M->Timing.simTimeStep);
    rtsiSetTPtr(&MIMO_M->solverInfo, &rtmGetTPtr(MIMO_M));
    rtsiSetStepSizePtr(&MIMO_M->solverInfo, &MIMO_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&MIMO_M->solverInfo, (&rtmGetErrorStatus(MIMO_M)));
    rtsiSetRTModelPtr(&MIMO_M->solverInfo, MIMO_M);
  }

  rtsiSetSimTimeStep(&MIMO_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&MIMO_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(MIMO_M, &MIMO_M->Timing.tArray[0]);
  rtmSetTFinal(MIMO_M, -1);
  MIMO_M->Timing.stepSize0 = 1.0E-5;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    MIMO_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(MIMO_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(MIMO_M->rtwLogInfo, (NULL));
    rtliSetLogT(MIMO_M->rtwLogInfo, "tout");
    rtliSetLogX(MIMO_M->rtwLogInfo, "");
    rtliSetLogXFinal(MIMO_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(MIMO_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(MIMO_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(MIMO_M->rtwLogInfo, 0);
    rtliSetLogDecimation(MIMO_M->rtwLogInfo, 1);
    rtliSetLogY(MIMO_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(MIMO_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(MIMO_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &MIMO_B), 0,
                sizeof(B_MIMO_T));

  /* states (dwork) */
  (void) memset((void *)&MIMO_DW, 0,
                sizeof(DW_MIMO_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(MIMO_M->rtwLogInfo, 0.0, rtmGetTFinal(MIMO_M),
    MIMO_M->Timing.stepSize0, (&rtmGetErrorStatus(MIMO_M)));

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace' */
  {
    int_T dimensions[1] = { 1 };

    MIMO_DW.ToWorkspace_PWORK.LoggedData = rt_CreateLogVar(
      MIMO_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(MIMO_M),
      MIMO_M->Timing.stepSize0,
      (&rtmGetErrorStatus(MIMO_M)),
      "y1out",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      1.0E-5,
      1);
    if (MIMO_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace1' */
  {
    int_T dimensions[1] = { 1 };

    MIMO_DW.ToWorkspace1_PWORK.LoggedData = rt_CreateLogVar(
      MIMO_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(MIMO_M),
      MIMO_M->Timing.stepSize0,
      (&rtmGetErrorStatus(MIMO_M)),
      "y2out",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      1.0E-5,
      1);
    if (MIMO_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Delay: '<Root>/y' */
    MIMO_DW.y_DSTATE = MIMO_P.y_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/yp1' */
    MIMO_DW.yp1_DSTATE = MIMO_P.yp1_InitialCondition;

    /* InitializeConditions for RandomNumber: '<S6>/Random Number_5' */
    tmp = floor(MIMO_P.RandomNumber_5_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    MIMO_DW.RandSeed = tseed;
    MIMO_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&MIMO_DW.RandSeed) *
      MIMO_P.RandomNumber_5_StdDev + MIMO_P.RandomNumber_5_Mean;

    /* End of InitializeConditions for RandomNumber: '<S6>/Random Number_5' */

    /* InitializeConditions for S-Function (sdspbiquad): '<S6>/Filter_Highpass_1000Hz' */
    memset(&MIMO_DW.Filter_Highpass_1000Hz_FILT_STA[0], 0, 12U * sizeof(real_T));

    /* InitializeConditions for S-Function (sdspbiquad): '<S6>/Filter_BPF_Narrow_band' */
    memset(&MIMO_DW.Filter_BPF_Narrow_band_FILT_STA[0], 0, 20U * sizeof(real_T));

    /* InitializeConditions for S-Function (sdspbiquad): '<S6>/Filter_LPF_10K' */
    memset(&MIMO_DW.Filter_LPF_10K_FILT_STATES[0], 0, 14U * sizeof(real_T));

    /* InitializeConditions for S-Function (sdspbiquad): '<S6>/Filter_1000Hz_Elliptic' */
    memset(&MIMO_DW.Filter_1000Hz_Elliptic_FILT_STA[0], 0, 10U * sizeof(real_T));

    /* InitializeConditions for S-Function (sdspbiquad): '<S6>/Filter_LPF_500Hz1' */
    memset(&MIMO_DW.Filter_LPF_500Hz1_FILT_STATES[0], 0, 18U * sizeof(real_T));

    /* InitializeConditions for Delay: '<Root>/y1' */
    MIMO_DW.y1_DSTATE = MIMO_P.y1_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/yp2' */
    MIMO_DW.yp2_DSTATE = MIMO_P.yp2_InitialCondition;

    /* InitializeConditions for Delay: '<S7>/Delay' */
    MIMO_DW.Delay_DSTATE = MIMO_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S7>/Delay1' */
    MIMO_DW.Delay1_DSTATE = MIMO_P.Delay1_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<Root>/software_rezonator' */
    MIMO_DW.g_not_empty_b = false;
    MIMO_DW.c_not_empty_k = false;
    MIMO_DW.bfr_rezo_sm_not_empty_h = false;
    MIMO_DW.aft_delay_not_empty_m = false;
    MIMO_DW.dft_out_not_empty_c = false;
    MIMO_DW.g.size[1] = 0;
    MIMO_DW.c.size[1] = 0;
    MIMO_DW.bfr_rezo_sm.size = 0;
    MIMO_DW.aft_delay.size = 0;
    MIMO_DW.dft_out.size = 0;

    /* SystemInitialize for MATLAB Function: '<Root>/software_rezonator' */
    MIMO_DW.memory_alloc_flag_g = 0.0;
    MIMO_DW.n_f = 0.0;

    /* SystemInitialize for MATLAB Function: '<Root>/software_rezonator1' */
    MIMO_DW.g_not_empty = false;
    MIMO_DW.c_not_empty = false;
    MIMO_DW.bfr_rezo_sm_not_empty = false;
    MIMO_DW.aft_delay_not_empty = false;
    MIMO_DW.dft_out_not_empty = false;
    MIMO_DW.g_b.size[1] = 0;
    MIMO_DW.c_j.size[1] = 0;
    MIMO_DW.bfr_rezo_sm_p.size = 0;
    MIMO_DW.aft_delay_l.size = 0;
    MIMO_DW.dft_out_e.size = 0;

    /* SystemInitialize for MATLAB Function: '<Root>/software_rezonator1' */
    MIMO_DW.memory_alloc_flag = 0.0;
    MIMO_DW.n = 0.0;

    /* SystemInitialize for MATLAB Function: '<Root>/RBNN_NN' */
    MIMO_RBNN_NN_Init(&MIMO_DW.sf_RBNN_NN);

    /* SystemInitialize for MATLAB Function: '<Root>/RBNN_NN1' */
    MIMO_RBNN_NN_Init(&MIMO_DW.sf_RBNN_NN1);
  }
}

/* Model terminate function */
void MIMO_terminate(void)
{
  /* Terminate for MATLAB Function: '<Root>/RBNN_NN' */
  MIMO_RBNN_NN_Term(&MIMO_DW.sf_RBNN_NN);

  /* Terminate for MATLAB Function: '<Root>/RBNN_NN1' */
  MIMO_RBNN_NN_Term(&MIMO_DW.sf_RBNN_NN1);
}
