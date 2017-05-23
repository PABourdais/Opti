#ifndef _RDTSC_TIMER_H
#define _RDTSC_TIMER_H

#include <sys/time.h>
#include <time.h>
#include <stdio.h>  
#include <unistd.h>

#ifdef __i386__
#define RDTSC_CLOBBER "%eax", "%ebx", "%ecx", "%edx"
#elif __x86_64__
#define RDTSC_CLOBBER "%rax", "%rbx", "%rcx", "%rdx"
#else
# error unknown platform
#endif

#define RDTSC_START(cycle)                                \
    do {                                                   \
        register unsigned cycle_h, cycle_l;               \
        asm volatile("CPUID\n\t"                           \
                     "RDTSC\n\t"                           \
                     "mov %%edx, %0\n\t"                   \
                     "mov %%eax, %1\n\t"                   \
                     : "=r" (cycle_h), "=r" (cycle_l)     \
                     :: RDTSC_CLOBBER);                      \
        (cycle) = ((uint64_t)cycle_h << 32) | cycle_l;   \
    } while (0)

#define RDTSC_STOP(cycle)                                 \
    do {                                                   \
        register unsigned cycle_h, cycle_l;               \
        asm volatile("RDTSC\n\t"                          \
                     "mov %%edx, %0\n\t"                   \
                     "mov %%eax, %1\n\t"                   \
                     "CPUID\n\t"                           \
                     : "=r" (cycle_h), "=r" (cycle_l)     \
                     :: RDTSC_CLOBBER);                      \
        (cycle) = ((uint64_t)cycle_h << 32) | cycle_l;   \
    } while(0)
#endif

#define TIME_START(time)                                \
    do {                                                   \
        (time) = ((double)clock()/(double)CLOCKS_PER_SEC);   \
    } while (0)

#define TIME_STOP(time)                                \
    do {                                                   \
        (time) = ((double)clock()/(double)CLOCKS_PER_SEC);   \
    } while (0)


#define TIME_START2(time)                                \
    do {                                                   \
			struct timeval start;				\
			gettimeofday(&start, NULL);			\
			(time) = (double)start.tv_sec+(double)start.tv_usec/1000000.0; \
    } while (0)


#define TIME_STOP2(time)                                \
    do {                                                   \
	struct timeval stop;				\
	gettimeofday(&stop, NULL);			\
	(time) = (double)stop.tv_sec+(double)stop.tv_usec/1000000.0; \
    } while (0)


