/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int long long int
#endif

int hkinodyn_par(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem);
int hkinodyn_par_alloc_mem(void);
int hkinodyn_par_init_mem(int mem);
void hkinodyn_par_free_mem(int mem);
int hkinodyn_par_checkout(void);
void hkinodyn_par_release(int mem);
void hkinodyn_par_incref(void);
void hkinodyn_par_decref(void);
casadi_int hkinodyn_par_n_out(void);
casadi_int hkinodyn_par_n_in(void);
casadi_real hkinodyn_par_default_in(casadi_int i);
const char* hkinodyn_par_name_in(casadi_int i);
const char* hkinodyn_par_name_out(casadi_int i);
const casadi_int* hkinodyn_par_sparsity_in(casadi_int i);
const casadi_int* hkinodyn_par_sparsity_out(casadi_int i);
int hkinodyn_par_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w);
#ifdef __cplusplus
} /* extern "C" */
#endif
