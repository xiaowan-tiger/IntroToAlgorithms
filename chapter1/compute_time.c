#include <stdio.h>
#include <math.h>
#include <limits.h>

#define TIME_LIST_COUNT 7

enum compute_tyep{
	LOGN= 0,
	SQRT,
	N,
	NLOGN,
	NSQARE,
	NTUBE,
	TWOTON,
	NFACT
};

unsigned long long compute_n(int type, int time) {
	unsigned long long n = 0;
	switch(type) {
		case LOGN:
			n = pow(10,1000 * time);
			break;
		case SQRT:
			n = pow(1000 * time, 2);
			break;
		case N:
			n = 1000 * time;
			break;
		case NLOGN:
			break;
		defaut:
		break;
	}
	return n;
}

int main(int argc, char* argv[]) {
	unsigned long long log_n[TIME_LIST_COUNT] = {0};
	unsigned long long sqrt_n[TIME_LIST_COUNT] = {0};
	unsigned long long n[TIME_LIST_COUNT] = {0};
	unsigned long long hour =  3600;
	unsigned long long day = 24 * hour;
	unsigned long long month = 30 * day;
	unsigned long long year = 365 * day;
	unsigned long long century = 100 * year;
	unsigned long long time_list[] = {1, 60, hour,day, month, year, century};
	size_t len = sizeof(time_list) / sizeof(time_list[0]);
	
		
	printf("\t1sec\t1minute\t1hour\t1day\t1month\t1year\t1century\n");
	for (int i = 0; i < len; i++) {

		log_n[i] = compute_n(LOGN, time_list[i]);
		sqrt_n[i] = compute_n(SQRT, time_list[i]);
		n[i] = compute_n(N, time_list[i]);
	}
	//printf("lgn");
	for (int i = 0; i < len; i++) {
		//printf("\t%llu",n[i]);
	}
	//printf("\n");
	printf("%llu", ULLONG_MAX);
	return 0;	
}
