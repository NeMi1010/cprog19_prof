#include<stdio.h>
#include<limits.h>

//#define DBG

int main()
{
	char fname[100] = "time.log";
	FILE* fp;
	int min, sec, cnt = 0;
	int current_log, sum_log, avg_log;
	int MIN_log = INT_MAX, MAX_log = INT_MIN;

	fp = fopen(fname, "r");
	
	if (fp == NULL) {
		printf("Failed to open file\n");
		return 0;
	}

	while(!feof(fp)) {
		fscanf(fp, "(%d:%d)\n", &min, &sec);
		current_log = min * 60 + sec;
		cnt += 1;

		sum_log += current_log;
		MAX_log = (current_log > MAX_log) ? current_log : MAX_log;
		MIN_log = (current_log < MIN_log && current_log != 0) ? current_log : MIN_log;

//		printf("min = %d, sec = %d\n", min, sec);

		// get min, max, avg access time 
	}
	avg_log = sum_log / cnt;

#ifdef DBG
	printf("[ %d\t%d\t%d ]\n", sum_log, avg_log, cnt);
#endif

#ifndef DBG
	printf("최장 접속 기록 : %d분 %d초\n", MAX_log/60, MAX_log%60);
	printf("최단 접속 기록 : %d분 %d초\n", MIN_log/60, MIN_log%60);
	printf("평균 접속 기록 : %d분 %d초\n", avg_log/60, avg_log%60);
#endif

	return 0;
}

