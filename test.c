#include <stdio.h>
#include "proc.h"

#if defined(WIN32) || defined(_WIN32)
# include <time.h>
# include <windows.h>
#elif defined(__unix__) || defined(__unix) || defined(unix) || (defined(__APPLE__) && defined(__MACH__))
# include <unistd.h>
# include <time.h>
# include <sys/time.h>
#endif

static void sleep_ms(int ms)
{
#if defined(WIN32) || defined(_WIN32)
        Sleep(ms);
#else
        usleep((useconds_t)ms * 1000);
#endif
}


int main(int argc, const char *argv[])
{
	char s[128];
	int i=0;
	for (;;) {
		sleep_ms(1000);
		struct timeval tv;
		for (i=0; i< 500000; i++) {
			gettimeofday(&tv, NULL);
			snprintf(s, sizeof(s)-1, "sec=%08lx,usec=%08x", tv.tv_sec, tv.tv_usec);
		}
		printf("==================================\n");
		printf("currss=%zu\n", getProcCurrentRSS());
		printf("peakrss=%zu\n", getProcPeakRSS());
		printf("phymem=%zu\n", getPhyMemorySize());
		printf("cputime=%g\n", getCPUTime());
		printf("cpuusage=%g\n", getCPUUsage());

	}
	return 0;
}



