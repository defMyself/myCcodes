#include <sys/time.h>
#include <signal.h>
#include <time.h>

// int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);

int main() {
	struct itimerval itv;
	static struct timeval start;
	struct timeval curr;
	static int callNum = 0;
	
	if(callNum == 0)
		if (gettimeofday(&stat, NULL) == -1)
			err	
}
