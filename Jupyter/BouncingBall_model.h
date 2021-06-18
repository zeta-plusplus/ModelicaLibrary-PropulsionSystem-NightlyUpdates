/* Simulation code for BouncingBall generated by the OpenModelica Compiler OpenModelica 1.17.0. */
#if !defined(BouncingBall__MODEL_H)
#define BouncingBall__MODEL_H

#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "simulation/simulation_info_json.h"
#include "simulation/simulation_runtime.h"
#include "util/omc_error.h"
#include "util/parallel_helper.h"
#include "simulation/solver/model_help.h"
#include "simulation/solver/delay.h"
#include "simulation/solver/linearSystem.h"
#include "simulation/solver/nonlinearSystem.h"
#include "simulation/solver/mixedSystem.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>

#include "BouncingBall_functions.h"


extern void BouncingBall_callExternalObjectDestructors(DATA *_data, threadData_t *threadData);
#if !defined(OMC_NUM_NONLINEAR_SYSTEMS) || OMC_NUM_NONLINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_LINEAR_SYSTEMS) || OMC_NUM_LINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_MIXED_SYSTEMS) || OMC_NUM_MIXED_SYSTEMS>0
#endif
#if !defined(OMC_NO_STATESELECTION)
extern void BouncingBall_initializeStateSets(int nStateSets, STATE_SET_DATA* statesetData, DATA *data);
#endif
extern int BouncingBall_functionAlgebraics(DATA *data, threadData_t *threadData);
extern int BouncingBall_function_storeDelayed(DATA *data, threadData_t *threadData);
extern int BouncingBall_updateBoundVariableAttributes(DATA *data, threadData_t *threadData);
extern int BouncingBall_functionInitialEquations(DATA *data, threadData_t *threadData);
extern int BouncingBall_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData);
extern int BouncingBall_functionRemovedInitialEquations(DATA *data, threadData_t *threadData);
extern int BouncingBall_updateBoundParameters(DATA *data, threadData_t *threadData);
extern int BouncingBall_checkForAsserts(DATA *data, threadData_t *threadData);
extern int BouncingBall_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData);
extern int BouncingBall_function_ZeroCrossings(DATA *data, threadData_t *threadData, double* gout);
extern int BouncingBall_function_updateRelations(DATA *data, threadData_t *threadData, int evalZeroCross);
extern const char* BouncingBall_zeroCrossingDescription(int i, int **out_EquationIndexes);
extern const char* BouncingBall_relationDescription(int i);
extern void BouncingBall_function_initSample(DATA *data, threadData_t *threadData);
extern int BouncingBall_initialAnalyticJacobianG(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int BouncingBall_initialAnalyticJacobianA(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int BouncingBall_initialAnalyticJacobianB(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int BouncingBall_initialAnalyticJacobianC(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int BouncingBall_initialAnalyticJacobianD(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int BouncingBall_initialAnalyticJacobianF(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int BouncingBall_functionJacG_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int BouncingBall_functionJacA_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int BouncingBall_functionJacB_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int BouncingBall_functionJacC_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int BouncingBall_functionJacD_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int BouncingBall_functionJacF_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern const char* BouncingBall_linear_model_frame(void);
extern const char* BouncingBall_linear_model_datarecovery_frame(void);
extern int BouncingBall_mayer(DATA* data, modelica_real** res, short *);
extern int BouncingBall_lagrange(DATA* data, modelica_real** res, short *, short *);
extern int BouncingBall_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
extern int BouncingBall_setInputData(DATA *data, const modelica_boolean file);
extern int BouncingBall_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
extern void BouncingBall_function_initSynchronous(DATA * data, threadData_t *threadData);
extern void BouncingBall_function_updateSynchronous(DATA * data, threadData_t *threadData, long i);
extern int BouncingBall_function_equationsSynchronous(DATA * data, threadData_t *threadData, long i);
extern void BouncingBall_read_input_fmu(MODEL_DATA* modelData, SIMULATION_INFO* simulationData);
extern void BouncingBall_function_savePreSynchronous(DATA *data, threadData_t *threadData);
extern int BouncingBall_inputNames(DATA* data, char ** names);
extern int BouncingBall_dataReconciliationInputNames(DATA* data, char ** names);
extern int BouncingBall_initializeDAEmodeData(DATA *data, DAEMODE_DATA*);
extern int BouncingBall_functionLocalKnownVars(DATA*, threadData_t*);
extern int BouncingBall_symbolicInlineSystem(DATA*, threadData_t*);

#include "BouncingBall_literals.h"




#if defined(HPCOM) && !defined(_OPENMP)
  #error "HPCOM requires OpenMP or the results are wrong"
#endif
#if defined(_OPENMP)
  #include <omp.h>
#else
  /* dummy omp defines */
  #define omp_get_max_threads() 1
#endif

#if defined(__cplusplus)
}
#endif

#endif /* !defined(BouncingBall__MODEL_H) */


