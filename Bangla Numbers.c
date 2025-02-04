#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	long long int word;
	int i = 1;
	long long int check = 1000000000;
	long long int kuti = 10000000;
	long long int lakh = 100000;
	long long int hajar = 1000;
	long long int shata = 100;
	while (scanf("%lld", &word) != EOF) {
		if (i > 0 && i < 10) {
			printf("   %d.", i);
		}
		else if (i > 9 && i < 100) {
			printf("  %d.", i);
		}
		else if (i > 99 && i < 1000) {
			printf(" %d.", i);
		}
		else {
			printf("%d.", i);
		}
		long long int number = 0;
		long long int count_kuti = 0;
		long long int count_lakh = 0;
		long long int count_hajar = 0;
		long long int count_shata = 0;
		long long int temp = 0;
		if (word == 0) {
			printf(" %lld", word);
		}
		if (word > check) {
			number = word / kuti;
			count_kuti = number / kuti;
			if (count_kuti > 0) {
				printf(" %lld kuti", count_kuti);
			}
			count_lakh = (number % kuti) / lakh;
			if (count_lakh > 0) {
				printf(" %lld lakh", count_lakh);
			}
			count_hajar = (number % lakh) / hajar;
			if (count_hajar > 0) {
				printf(" %lld hajar", count_hajar);
			}
			count_shata = (number % hajar) / shata;
			if (count_shata > 0) {
				printf(" %lld shata", count_shata);
			}
			number = word % check;
			count_kuti = number / kuti;
			if (count_kuti > 0) {
				printf(" %lld kuti", count_kuti);
			}
			else if(count_kuti==0){
				printf(" kuti");
			}
			count_lakh = (number % kuti) / lakh;
			if (count_lakh > 0) {
				printf(" %lld lakh", count_lakh);
			}
			count_hajar = (number % lakh) / hajar;
			if (count_hajar > 0) {
				printf(" %lld hajar", count_hajar);
			}
			count_shata = (number % hajar) / shata;
			if (count_shata > 0) {
				printf(" %lld shata", count_shata);
			}
			temp = (number % shata);
			if (temp > 0) {
				printf(" %lld", temp);
			}
			
			i++;
		}
		else {
			number = word;
			count_kuti = number / kuti;
			if (count_kuti > 0) {
				printf(" %lld kuti", count_kuti);
			}
			count_lakh = (number % kuti) / 100000;
			if (count_lakh > 0) {
				printf(" %lld lakh", count_lakh);
			}
			count_hajar = (number % 100000) / hajar;
			if (count_hajar > 0) {
				printf(" %lld hajar", count_hajar);
			}
			count_shata = (number % hajar) / shata;
			if (count_shata > 0) {
				printf(" %lld shata", count_shata);
			}
			temp = (number % shata);
			if (temp > 0) {
				printf(" %lld", temp);
			}
			
			i++;
		}
		printf("\n");
	}
	return 0;
}