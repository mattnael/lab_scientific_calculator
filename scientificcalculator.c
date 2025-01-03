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

int main() {
    int choice;
    double num1, num2, result, derajat, PI = 3.14;

    while (1) {
    	menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0){
            printf("Exiting the calculator. Goodbye!\n");
            saveResultToFile();
            break;
        }

        switch(choice){
            case 1:{
            	system("cls");
            	printf("Masukkan dua angka: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                addToLastResult(result);
                system("pause");
				break;
			}

            case 2:{
            	system("cls");
            	printf("Masukkan dua angka: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                addToLastResult(result);
                system("pause");
				break;
			}

            case 3:{
            	system("cls");
            	printf("Masukkan dua angka: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                addToLastResult(result);
                system("pause");
				break;
			}

            case 4:{
            	system("cls");
            	printf("Masukkan dua angka: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                    addToLastResult(result);
                } else {
                    printf("Error: Division by zero.\n");
                }
                system("pause");
				break;
			}

            case 5:{
            	system("cls");
            	printf("Masukkan angka dan pangkatnya: ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("Result: %.2lf\n", result);
                addToLastResult(result);
                system("pause");
				break;
			}

            case 6:{
            	system("cls");
            	printf("Masukkan Angka: ");
                scanf("%lf", &num1);
                if (num1 >= 0) {
                    result = sqrt(num1);
                    printf("Result: %.2lf\n", result);
                    addToLastResult(result);
                } else {
                    printf("Error: Cannot compute square root of a negative number.\n");
                }
                system("pause");
				break;
			}
			
            case 7:{
            	system("cls");
            	printf("Masukkan derajat: ");
                scanf("%lf", &num1);
                result = sin(radianskederajat(num1));
                printf("Result: %.2lf\n", result);
                addToLastResult(result);
                system("pause");
				break;
			}

            case 8:{
            	system("cls");
            	printf("Masukkan derajat: ");
                scanf("%lf", &num1);
                result = cos(radianskederajat(num1));
                printf("Result: %.2lf\n", result);
                addToLastResult(result);
                system("pause");
				break;
			}

            case 9:{
            	system("cls");
            	printf("Masukkan derajat: ");
                scanf("%lf", &num1);
                result = tan(radianskederajat(num1));
                printf("Result: %.2lf\n", result);
                addToLastResult(result);
                system("pause");
				break;
			}
			
			case 10: {
    			system("cls");
    			printf("Masukkan Nilai antara -1 dan 1: ");
    			scanf("%lf", &num1);
    			if (num1 >= -1 && num1 <= 1) {
        			result = asin(num1) * (180.0 / 3.14);
        			printf("Result: %.2lf degrees\n", result);
        			addToLastResult(result);
    			} else {
        			printf("Error: Input out of range for asin function.\n");
    			}
    			system("pause");
    			break;
			}

			case 11: {
    			system("cls");
    			printf("Masukkan Nilai antara -1 dan 1: ");
    			scanf("%lf", &num1);
    			if (num1 >= -1 && num1 <= 1) {
        			result = acos(num1) * (180.0 / 3.14);
        			printf("Result: %.2lf degrees\n", result);
        			addToLastResult(result);
    			} else {
        			printf("Error: Input out of range for acos function.\n");
    			}
    			system("pause");
    			break;
			}

			case 12: {
    			system("cls");
    			printf("Masukkan Nilai: ");
    			scanf("%lf", &num1);
    			result = atan(num1) * (180.0 / 3.14);
    			printf("Result: %.2lf degrees\n", result);
    			addToLastResult(result);
    			system("pause");
    			break;
			}

			
			case 13:{
				system("cls");
    			int input, i;
    			int faktorial = 1;
    			puts("Masukkan angka yang ingin dihitung faktorial!");
    			scanf("%d", &input);
    
    			if(input < 0) {
        			printf("Faktorial tidak terdefinisi untuk bilangan negatif.\n");
        			break; 
    			}

    			for(i = input; i > 0; i--){
        			faktorial *= i;
    			}
    
    			printf("Nilai faktorial dari %d adalah %d\n", input, faktorial);
    			result = faktorial;
    			addToLastResult(result);
    			system("pause");
			break;
			}
			
			case 14:{
				printf("Masukkan Angka: ");
				scanf("%lf", &num1);
				result = sinh(num1);
				printf("Sin Hiperbolik dari %.2lf adalah %.2lf\n", num1, result);
				addToLastResult(result);
				system("pause");
				break;
			}
			
			case 15:{
				printf("Masukkan Angka: ");
				scanf("%lf", &num1);
				result = cosh(num1);
				printf("Cos Hiperbolik dari %.2lf adalah %.2lf\n", num1, result);
				addToLastResult(result);
				system("pause");
				break;
			}
			
			case 16:{
				printf("Masukkan Angka: ");
				scanf("%lf", &num1);
				result = tanh(num1);
				printf("Tan Hiperbolik dari %.2lf adalah %.2lf\n", num1, result);
				addToLastResult(result);
				system("pause");
				break;
			}
			
			case 17:{
				printf("Masukkan angka (n) untuk menghitung logaritma (Log10 n): ");
  				scanf("%lf", &num1);

    			if (num1 > 0) {
        			result = log10(num1);
        			printf("Logaritma basis 10 dari %.3f adalah: %.2f\n", num1, result);
        			addToLastResult(result);
    			}else {
        			printf("Angka harus lebih dari 0 untuk menghitung logaritma basis 10\n");
    			}
				system("pause");
				break;
			}
			
			case 18:{
				double basis;
				printf("Masukkan basis logaritma: ");
  				scanf("%lf", &basis);
   				printf("Masukkan angka (n) untuk menghitung logaritma: ");
    			scanf("%lf", &num1);

    			if (basis > 0 && basis != 1 && num1 > 0) {
      				result = log(num1) / log(basis);
      				printf("Logaritma dari %.2f dengan basis %.2f adalah: %.3f\n", num1, basis, result);
      				addToLastResult(result);
    			} else {
       				printf("Basis harus lebih dari 0 dan tidak sama dengan 1, serta n harus lebih dari 0\n");
   				}
				system("pause");
				break;
			}
			
			case 19:{
				menuTambahan();
				break;
			}

            default:{
                printf("INVALID INPUT\n");
                system("pause");
                continue;
				break;
			}
			
        }
        printf("\n");
    }

    return 0;
}

