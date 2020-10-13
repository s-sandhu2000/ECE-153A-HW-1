#ifndef _CACHE_MODEL_H
#define _CACHE_MODEL_H

#define CM_LINE_SIZE 8
#define CM_CACHE_LINES 256 
#define CM_ADDRESS_SPACE_SIZE 65536
#define CM_DRAM_LATENCY 7
#define CM_DRAM_CYCLES_PER_WORD 1
#define CM_CACHE_UPDATE_CYCLES 2
#define CM_DRAM_BUFFER_SIZE 4


// Its neater if you keep the model and your code in two seperate files
// Compile your program with something like
//  gcc main.c cache_model.c -lm
//
// Usage: call cm_init() at the start of your program.
//
// At the start of each simulation run call either cm_enable_cache() or
// cm_disable_cache() to set-up, each of these automatically call
// cm_reset_model() to clear old state.
//
// Per simulated access, call cm_do_access() with the address you randomly 
// generated, then call cm_get_last_access_cycles() to query the simulated
// time that took.

extern void cm_init();
extern void cm_do_access(int address);
extern void cm_reset_model();
extern void cm_enable_cache();
extern void cm_disable_cache();
extern int cm_get_last_access_cycles();

#endif 
