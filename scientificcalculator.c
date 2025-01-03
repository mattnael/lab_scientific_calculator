#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESULTS 100
#define FILE_NAME "results.txt"

double lastResult[MAX_RESULTS];
int resultCount = 0;

void saveResultToFile(){
	FILE *fp = fopen(FILE_NAME, "w");
	if(fp == NULL){
		printf("Tidak dapat membuka file!\n");
		return;
	}
	
	int i;
	for(i = 0; i < resultCount; i++){
		fprintf(fp, "%/.2lf\n", lastResult[i]);
	}
	fclose(fp);
	puts("Hasil berhasil disimpan!");
}

void loadResultFromFile(){
	FILE *fp = fopen(FILE_NAME, "r");
	if(fp == NULL){
		puts("File tidak ditemukan, membuat file baru");
		return;
	}
	resultCount = 0;
	while(resultCount < MAX_RESULTS && fscanf(fp, "%lf", &lastResult[resultCount]) != EOF && resultCount < MAX_RESULTS){
		resultCount++;
	}
	fclose(fp);
	printf("Hasil berhasil dibaca dari file\n");
}

void addToLastResult(double result){
	if(resultCount < MAX_RESULTS){
		lastResult[resultCount++] = result;
		saveResultToFile();
	} else{
		printf("Array hasil sudah penuh!");
	}
}


    return 0;
}

