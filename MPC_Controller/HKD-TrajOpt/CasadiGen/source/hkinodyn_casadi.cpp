/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) hkinodyn_ ## ID
#endif

#include <math.h>
#include <string.h>
#ifdef MATLAB_MEX_FILE
#include <mex.h>
#endif

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int long long int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_fill CASADI_PREFIX(fill)
#define casadi_from_mex CASADI_PREFIX(from_mex)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_to_mex CASADI_PREFIX(to_mex)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

void casadi_fill(casadi_real* x, casadi_int n, casadi_real alpha) {
  casadi_int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = alpha;
  }
}

#ifdef MATLAB_MEX_FILE
casadi_real* casadi_from_mex(const mxArray* p, casadi_real* y, const casadi_int* sp, casadi_real* w) {
  casadi_int nrow, ncol, is_sparse, c, k, p_nrow, p_ncol;
  const casadi_int *colind, *row;
  mwIndex *Jc, *Ir;
  const double* p_data;
  if (!mxIsDouble(p) || mxGetNumberOfDimensions(p)!=2)
    mexErrMsgIdAndTxt("Casadi:RuntimeError",
      "\"from_mex\" failed: Not a two-dimensional matrix of double precision.");
  nrow = *sp++;
  ncol = *sp++;
  colind = sp;
  row = sp+ncol+1;
  p_nrow = mxGetM(p);
  p_ncol = mxGetN(p);
  is_sparse = mxIsSparse(p);
  Jc = 0;
  Ir = 0;
  if (is_sparse) {
    Jc = mxGetJc(p);
    Ir = mxGetIr(p);
  }
  p_data = (const double*)mxGetData(p);
  if (p_nrow==1 && p_ncol==1) {
    casadi_int nnz;
    double v = is_sparse && Jc[1]==0 ? 0 : *p_data;
    nnz = sp[ncol];
    casadi_fill(y, nnz, v);
  } else {
    casadi_int tr = 0;
    if (nrow!=p_nrow || ncol!=p_ncol) {
      tr = nrow==p_ncol && ncol==p_nrow && (nrow==1 || ncol==1);
      if (!tr) mexErrMsgIdAndTxt("Casadi:RuntimeError",
                                 "\"from_mex\" failed: Dimension mismatch. "
                                 "Expected %d-by-%d, got %d-by-%d instead.",
                                 nrow, ncol, p_nrow, p_ncol);
    }
    if (is_sparse) {
      if (tr) {
        for (c=0; c<ncol; ++c)
          for (k=colind[c]; k<colind[c+1]; ++k) w[row[k]+c*nrow]=0;
        for (c=0; c<p_ncol; ++c)
          for (k=Jc[c]; k<(casadi_int) Jc[c+1]; ++k) w[c+Ir[k]*p_ncol] = p_data[k];
        for (c=0; c<ncol; ++c)
          for (k=colind[c]; k<colind[c+1]; ++k) y[k] = w[row[k]+c*nrow];
      } else {
        for (c=0; c<ncol; ++c) {
          for (k=colind[c]; k<colind[c+1]; ++k) w[row[k]]=0;
          for (k=Jc[c]; k<(casadi_int) Jc[c+1]; ++k) w[Ir[k]]=p_data[k];
          for (k=colind[c]; k<colind[c+1]; ++k) y[k]=w[row[k]];
        }
      }
    } else {
      for (c=0; c<ncol; ++c) {
        for (k=colind[c]; k<colind[c+1]; ++k) {
          y[k] = p_data[row[k]+c*nrow];
        }
      }
    }
  }
  return y;
}

#endif

#define casadi_to_double(x) ((double) x)

#ifdef MATLAB_MEX_FILE
mxArray* casadi_to_mex(const casadi_int* sp, const casadi_real* x) {
  casadi_int nrow, ncol, c, k;
#ifndef CASADI_MEX_NO_SPARSE
  casadi_int nnz;
#endif
  const casadi_int *colind, *row;
  mxArray *p;
  double *d;
#ifndef CASADI_MEX_NO_SPARSE
  casadi_int i;
  mwIndex *j;
#endif /* CASADI_MEX_NO_SPARSE */
  nrow = *sp++;
  ncol = *sp++;
  colind = sp;
  row = sp+ncol+1;
#ifndef CASADI_MEX_NO_SPARSE
  nnz = sp[ncol];
  if (nnz!=nrow*ncol) {
    p = mxCreateSparse(nrow, ncol, nnz, mxREAL);
    for (i=0, j=mxGetJc(p); i<=ncol; ++i) *j++ = *colind++;
    for (i=0, j=mxGetIr(p); i<nnz; ++i) *j++ = *row++;
    if (x) {
      d = (double*)mxGetData(p);
      for (i=0; i<nnz; ++i) *d++ = casadi_to_double(*x++);
    }
    return p;
  }
#endif /* CASADI_MEX_NO_SPARSE */
  p = mxCreateDoubleMatrix(nrow, ncol, mxREAL);
  if (x) {
    d = (double*)mxGetData(p);
    for (c=0; c<ncol; ++c) {
      for (k=colind[c]; k<colind[c+1]; ++k) {
        d[row[k]+c*nrow] = casadi_to_double(*x++);
      }
    }
  }
  return p;
}

#endif

static const casadi_int casadi_s0[28] = {24, 1, 0, 24, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
static const casadi_int casadi_s1[5] = {1, 1, 0, 1, 0};
static const casadi_int casadi_s2[8] = {4, 1, 0, 4, 0, 1, 2, 3};

/* hkinodyn:(i0[24],i1[24],i2,i3[4])->(o0[24]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a3, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a4, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a5, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a6, a60, a61, a62, a63, a64, a65, a66, a67, a68, a69, a7, a70, a71, a72, a8, a9;
  a0=arg[0]? arg[0][0] : 0;
  a1=arg[0]? arg[0][2] : 0;
  a2=sin(a1);
  a3=arg[0]? arg[0][1] : 0;
  a4=cos(a3);
  a2=(a2/a4);
  a5=arg[0]? arg[0][7] : 0;
  a2=(a2*a5);
  a6=cos(a1);
  a6=(a6/a4);
  a7=arg[0]? arg[0][8] : 0;
  a6=(a6*a7);
  a2=(a2+a6);
  a6=arg[2]? arg[2][0] : 0;
  a2=(a2*a6);
  a2=(a0+a2);
  if (res[0]!=0) res[0][0]=a2;
  a2=cos(a1);
  a2=(a2*a5);
  a8=sin(a1);
  a8=(a8*a7);
  a2=(a2-a8);
  a2=(a2*a6);
  a2=(a3+a2);
  if (res[0]!=0) res[0][1]=a2;
  a2=arg[0]? arg[0][6] : 0;
  a8=sin(a1);
  a9=sin(a3);
  a8=(a8*a9);
  a8=(a8/a4);
  a8=(a8*a5);
  a8=(a2+a8);
  a9=cos(a1);
  a10=sin(a3);
  a9=(a9*a10);
  a9=(a9/a4);
  a9=(a9*a7);
  a8=(a8+a9);
  a8=(a8*a6);
  a8=(a1+a8);
  if (res[0]!=0) res[0][2]=a8;
  a8=arg[0]? arg[0][3] : 0;
  a9=arg[0]? arg[0][9] : 0;
  a4=(a9*a6);
  a4=(a8+a4);
  if (res[0]!=0) res[0][3]=a4;
  a4=arg[0]? arg[0][4] : 0;
  a10=arg[0]? arg[0][10] : 0;
  a11=(a10*a6);
  a11=(a4+a11);
  if (res[0]!=0) res[0][4]=a11;
  a11=arg[0]? arg[0][5] : 0;
  a12=arg[0]? arg[0][11] : 0;
  a13=(a12*a6);
  a13=(a11+a13);
  if (res[0]!=0) res[0][5]=a13;
  a13=3.6415571589736352e+01;
  a14=1.0842021724855044e-19;
  a15=(a14*a7);
  a16=-1.2037062152420224e-35;
  a17=(a16*a5);
  a15=(a15-a17);
  a15=(a15*a2);
  a17=2.4251579680000002e-01;
  a18=(a17*a7);
  a18=(a18*a5);
  a15=(a15+a18);
  a18=2.6519357680000000e-01;
  a19=(a18*a5);
  a19=(a19*a7);
  a15=(a15-a19);
  a19=arg[3]? arg[3][0] : 0;
  a20=cos(a0);
  a21=sin(a3);
  a22=(a20*a21);
  a23=sin(a1);
  a24=(a22*a23);
  a0=sin(a0);
  a1=cos(a1);
  a25=(a0*a1);
  a24=(a24-a25);
  a25=arg[0]? arg[0][12] : 0;
  a26=(a25-a8);
  a27=(a24*a26);
  a28=(a20*a1);
  a29=(a0*a21);
  a30=(a29*a23);
  a28=(a28+a30);
  a30=arg[0]? arg[0][13] : 0;
  a31=(a30-a4);
  a32=(a28*a31);
  a27=(a27+a32);
  a3=cos(a3);
  a32=(a3*a23);
  a33=(a32*a11);
  a27=(a27-a33);
  a33=(a19*a27);
  a34=(a0*a23);
  a22=(a22*a1);
  a34=(a34+a22);
  a22=arg[1]? arg[1][0] : 0;
  a35=(a34*a22);
  a29=(a29*a1);
  a23=(a20*a23);
  a29=(a29-a23);
  a23=arg[1]? arg[1][1] : 0;
  a36=(a29*a23);
  a35=(a35+a36);
  a1=(a3*a1);
  a36=arg[1]? arg[1][2] : 0;
  a37=(a1*a36);
  a35=(a35+a37);
  a33=(a33*a35);
  a37=(a34*a26);
  a38=(a29*a31);
  a37=(a37+a38);
  a38=(a1*a11);
  a37=(a37-a38);
  a38=(a19*a37);
  a39=(a24*a22);
  a40=(a28*a23);
  a39=(a39+a40);
  a40=(a32*a36);
  a39=(a39+a40);
  a38=(a38*a39);
  a33=(a33-a38);
  a38=arg[3]? arg[3][1] : 0;
  a40=arg[0]? arg[0][15] : 0;
  a41=(a40-a8);
  a42=(a24*a41);
  a43=arg[0]? arg[0][16] : 0;
  a44=(a43-a4);
  a45=(a28*a44);
  a42=(a42+a45);
  a45=(a32*a11);
  a42=(a42-a45);
  a45=(a38*a42);
  a46=arg[1]? arg[1][3] : 0;
  a47=(a34*a46);
  a48=arg[1]? arg[1][4] : 0;
  a49=(a29*a48);
  a47=(a47+a49);
  a49=arg[1]? arg[1][5] : 0;
  a50=(a1*a49);
  a47=(a47+a50);
  a45=(a45*a47);
  a50=(a34*a41);
  a51=(a29*a44);
  a50=(a50+a51);
  a51=(a1*a11);
  a50=(a50-a51);
  a51=(a38*a50);
  a52=(a24*a46);
  a53=(a28*a48);
  a52=(a52+a53);
  a53=(a32*a49);
  a52=(a52+a53);
  a51=(a51*a52);
  a45=(a45-a51);
  a33=(a33+a45);
  a45=arg[3]? arg[3][2] : 0;
  a51=arg[0]? arg[0][18] : 0;
  a53=(a51-a8);
  a54=(a24*a53);
  a55=arg[0]? arg[0][19] : 0;
  a56=(a55-a4);
  a57=(a28*a56);
  a54=(a54+a57);
  a57=(a32*a11);
  a54=(a54-a57);
  a57=(a45*a54);
  a58=arg[1]? arg[1][6] : 0;
  a59=(a34*a58);
  a60=arg[1]? arg[1][7] : 0;
  a61=(a29*a60);
  a59=(a59+a61);
  a61=arg[1]? arg[1][8] : 0;
  a62=(a1*a61);
  a59=(a59+a62);
  a57=(a57*a59);
  a62=(a34*a53);
  a63=(a29*a56);
  a62=(a62+a63);
  a63=(a1*a11);
  a62=(a62-a63);
  a63=(a45*a62);
  a64=(a24*a58);
  a65=(a28*a60);
  a64=(a64+a65);
  a65=(a32*a61);
  a64=(a64+a65);
  a63=(a63*a64);
  a57=(a57-a63);
  a33=(a33+a57);
  a57=arg[3]? arg[3][3] : 0;
  a63=arg[0]? arg[0][21] : 0;
  a8=(a63-a8);
  a65=(a24*a8);
  a66=arg[0]? arg[0][22] : 0;
  a4=(a66-a4);
  a67=(a28*a4);
  a65=(a65+a67);
  a67=(a32*a11);
  a65=(a65-a67);
  a67=(a57*a65);
  a68=arg[1]? arg[1][9] : 0;
  a69=(a34*a68);
  a70=arg[1]? arg[1][10] : 0;
  a71=(a29*a70);
  a69=(a69+a71);
  a71=arg[1]? arg[1][11] : 0;
  a72=(a1*a71);
  a69=(a69+a72);
  a67=(a67*a69);
  a34=(a34*a8);
  a29=(a29*a4);
  a34=(a34+a29);
  a1=(a1*a11);
  a34=(a34-a1);
  a1=(a57*a34);
  a24=(a24*a68);
  a28=(a28*a70);
  a24=(a24+a28);
  a32=(a32*a71);
  a24=(a24+a32);
  a1=(a1*a24);
  a67=(a67-a1);
  a33=(a33+a67);
  a15=(a15+a33);
  a13=(a13*a15);
  a33=-1.6280111378663628e-17;
  a67=(a16*a2);
  a1=2.7460779999999994e-02;
  a32=(a1*a7);
  a67=(a67-a32);
  a67=(a67*a2);
  a32=(a14*a7);
  a32=(a32*a5);
  a67=(a67-a32);
  a18=(a18*a2);
  a32=(a16*a7);
  a18=(a18-a32);
  a18=(a18*a7);
  a67=(a67+a18);
  a37=(a19*a37);
  a20=(a20*a3);
  a18=(a20*a22);
  a0=(a0*a3);
  a3=(a0*a23);
  a18=(a18+a3);
  a3=(a21*a36);
  a18=(a18-a3);
  a37=(a37*a18);
  a26=(a20*a26);
  a31=(a0*a31);
  a26=(a26+a31);
  a31=(a21*a11);
  a26=(a26+a31);
  a31=(a19*a26);
  a31=(a31*a35);
  a37=(a37-a31);
  a50=(a38*a50);
  a31=(a20*a46);
  a35=(a0*a48);
  a31=(a31+a35);
  a35=(a21*a49);
  a31=(a31-a35);
  a50=(a50*a31);
  a41=(a20*a41);
  a44=(a0*a44);
  a41=(a41+a44);
  a44=(a21*a11);
  a41=(a41+a44);
  a44=(a38*a41);
  a44=(a44*a47);
  a50=(a50-a44);
  a37=(a37+a50);
  a62=(a45*a62);
  a50=(a20*a58);
  a44=(a0*a60);
  a50=(a50+a44);
  a44=(a21*a61);
  a50=(a50-a44);
  a62=(a62*a50);
  a53=(a20*a53);
  a56=(a0*a56);
  a53=(a53+a56);
  a56=(a21*a11);
  a53=(a53+a56);
  a56=(a45*a53);
  a56=(a56*a59);
  a62=(a62-a56);
  a37=(a37+a62);
  a34=(a57*a34);
  a62=(a20*a68);
  a56=(a0*a70);
  a62=(a62+a56);
  a56=(a21*a71);
  a62=(a62-a56);
  a34=(a34*a62);
  a20=(a20*a8);
  a0=(a0*a4);
  a20=(a20+a0);
  a21=(a21*a11);
  a20=(a20+a21);
  a21=(a57*a20);
  a21=(a21*a69);
  a34=(a34-a21);
  a37=(a37+a34);
  a67=(a67+a37);
  a37=(a33*a67);
  a13=(a13+a37);
  a37=1.6528925920107902e-33;
  a1=(a1*a5);
  a34=(a14*a2);
  a1=(a1-a34);
  a1=(a1*a2);
  a14=(a14*a5);
  a17=(a17*a2);
  a14=(a14-a17);
  a14=(a14*a5);
  a1=(a1+a14);
  a16=(a16*a5);
  a16=(a16*a7);
  a1=(a1+a16);
  a26=(a19*a26);
  a26=(a26*a39);
  a27=(a19*a27);
  a27=(a27*a18);
  a26=(a26-a27);
  a41=(a38*a41);
  a41=(a41*a52);
  a42=(a38*a42);
  a42=(a42*a31);
  a41=(a41-a42);
  a26=(a26+a41);
  a53=(a45*a53);
  a53=(a53*a64);
  a54=(a45*a54);
  a54=(a54*a50);
  a53=(a53-a54);
  a26=(a26+a53);
  a20=(a57*a20);
  a20=(a20*a24);
  a65=(a57*a65);
  a65=(a65*a62);
  a20=(a20-a65);
  a26=(a26+a20);
  a1=(a1+a26);
  a26=(a37*a1);
  a13=(a13+a26);
  a13=(a13*a6);
  a2=(a2+a13);
  if (res[0]!=0) res[0][6]=a2;
  a33=(a33*a15);
  a2=4.1234427331951844e+00;
  a2=(a2*a67);
  a33=(a33+a2);
  a2=-7.3894969432494111e-52;
  a13=(a2*a1);
  a33=(a33+a13);
  a33=(a33*a6);
  a5=(a5+a33);
  if (res[0]!=0) res[0][7]=a5;
  a37=(a37*a15);
  a2=(a2*a67);
  a37=(a37+a2);
  a2=3.7708303951651367e+00;
  a2=(a2*a1);
  a37=(a37+a2);
  a37=(a37*a6);
  a7=(a7+a37);
  if (res[0]!=0) res[0][8]=a7;
  a22=(a19*a22);
  a46=(a38*a46);
  a22=(a22+a46);
  a58=(a45*a58);
  a22=(a22+a58);
  a68=(a57*a68);
  a22=(a22+a68);
  a68=8.9120000000000008e+00;
  a22=(a22/a68);
  a22=(a22*a6);
  a9=(a9+a22);
  if (res[0]!=0) res[0][9]=a9;
  a23=(a19*a23);
  a48=(a38*a48);
  a23=(a23+a48);
  a60=(a45*a60);
  a23=(a23+a60);
  a70=(a57*a70);
  a23=(a23+a70);
  a23=(a23/a68);
  a23=(a23*a6);
  a10=(a10+a23);
  if (res[0]!=0) res[0][10]=a10;
  a10=-9.8100000000000005e+00;
  a36=(a19*a36);
  a49=(a38*a49);
  a36=(a36+a49);
  a61=(a45*a61);
  a36=(a36+a61);
  a71=(a57*a71);
  a36=(a36+a71);
  a36=(a36/a68);
  a10=(a10+a36);
  a10=(a10*a6);
  a12=(a12+a10);
  if (res[0]!=0) res[0][11]=a12;
  a12=1.;
  a19=(a12-a19);
  a10=arg[1]? arg[1][12] : 0;
  a10=(a19*a10);
  a10=(a10*a6);
  a25=(a25+a10);
  if (res[0]!=0) res[0][12]=a25;
  a25=arg[1]? arg[1][13] : 0;
  a25=(a19*a25);
  a25=(a25*a6);
  a30=(a30+a25);
  if (res[0]!=0) res[0][13]=a30;
  a30=arg[0]? arg[0][14] : 0;
  a25=arg[1]? arg[1][14] : 0;
  a19=(a19*a25);
  a19=(a19*a6);
  a30=(a30+a19);
  if (res[0]!=0) res[0][14]=a30;
  a38=(a12-a38);
  a30=arg[1]? arg[1][15] : 0;
  a30=(a38*a30);
  a30=(a30*a6);
  a40=(a40+a30);
  if (res[0]!=0) res[0][15]=a40;
  a40=arg[1]? arg[1][16] : 0;
  a40=(a38*a40);
  a40=(a40*a6);
  a43=(a43+a40);
  if (res[0]!=0) res[0][16]=a43;
  a43=arg[0]? arg[0][17] : 0;
  a40=arg[1]? arg[1][17] : 0;
  a38=(a38*a40);
  a38=(a38*a6);
  a43=(a43+a38);
  if (res[0]!=0) res[0][17]=a43;
  a45=(a12-a45);
  a43=arg[1]? arg[1][18] : 0;
  a43=(a45*a43);
  a43=(a43*a6);
  a51=(a51+a43);
  if (res[0]!=0) res[0][18]=a51;
  a51=arg[1]? arg[1][19] : 0;
  a51=(a45*a51);
  a51=(a51*a6);
  a55=(a55+a51);
  if (res[0]!=0) res[0][19]=a55;
  a55=arg[0]? arg[0][20] : 0;
  a51=arg[1]? arg[1][20] : 0;
  a45=(a45*a51);
  a45=(a45*a6);
  a55=(a55+a45);
  if (res[0]!=0) res[0][20]=a55;
  a12=(a12-a57);
  a57=arg[1]? arg[1][21] : 0;
  a57=(a12*a57);
  a57=(a57*a6);
  a63=(a63+a57);
  if (res[0]!=0) res[0][21]=a63;
  a63=arg[1]? arg[1][22] : 0;
  a63=(a12*a63);
  a63=(a63*a6);
  a66=(a66+a63);
  if (res[0]!=0) res[0][22]=a66;
  a66=arg[0]? arg[0][23] : 0;
  a63=arg[1]? arg[1][23] : 0;
  a12=(a12*a63);
  a12=(a12*a6);
  a66=(a66+a12);
  if (res[0]!=0) res[0][23]=a66;
  return 0;
}

CASADI_SYMBOL_EXPORT int hkinodyn(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int hkinodyn_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int hkinodyn_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void hkinodyn_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int hkinodyn_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void hkinodyn_release(int mem) {
}

CASADI_SYMBOL_EXPORT void hkinodyn_incref(void) {
}

CASADI_SYMBOL_EXPORT void hkinodyn_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int hkinodyn_n_in(void) { return 4;}

CASADI_SYMBOL_EXPORT casadi_int hkinodyn_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real hkinodyn_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* hkinodyn_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* hkinodyn_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* hkinodyn_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    case 3: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* hkinodyn_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int hkinodyn_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 4;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

#ifdef MATLAB_MEX_FILE
void mex_hkinodyn(int resc, mxArray *resv[], int argc, const mxArray *argv[]) {
  casadi_int i;
  casadi_real w[150];
  casadi_int *iw = 0;
  const casadi_real* arg[4] = {0};
  casadi_real* res[1] = {0};
  if (argc>4) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"hkinodyn\" failed. Too many input arguments (%d, max 4)", argc);
  if (resc>1) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"hkinodyn\" failed. Too many output arguments (%d, max 1)", resc);
  if (--argc>=0) arg[0] = casadi_from_mex(argv[0], w, casadi_s0, w+77);
  if (--argc>=0) arg[1] = casadi_from_mex(argv[1], w+24, casadi_s0, w+77);
  if (--argc>=0) arg[2] = casadi_from_mex(argv[2], w+48, casadi_s1, w+77);
  if (--argc>=0) arg[3] = casadi_from_mex(argv[3], w+49, casadi_s2, w+77);
  --resc;
  res[0] = w+53;
  i = hkinodyn(arg, res, iw, w+77, 0);
  if (i) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"hkinodyn\" failed.");
  if (res[0]) resv[0] = casadi_to_mex(casadi_s0, res[0]);
}
#endif


#ifdef MATLAB_MEX_FILE
void mexFunction(int resc, mxArray *resv[], int argc, const mxArray *argv[]) {
  char buf[9];
  int buf_ok = argc > 0 && !mxGetString(*argv, buf, sizeof(buf));
  if (!buf_ok) {
    mex_hkinodyn(resc, resv, argc, argv);
    return;
  } else if (strcmp(buf, "hkinodyn")==0) {
    mex_hkinodyn(resc, resv, argc-1, argv+1);
    return;
  }
  mexErrMsgTxt("First input should be a command string. Possible values: 'hkinodyn'");
}
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif
