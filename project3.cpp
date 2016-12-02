/******************************************************************************
* Univesidade Federal de Pernambuco -- UFPE (http://www.ufpe.br)
* Centro de Informatica -- CIn (http://www.cin.ufpe.br)
* Bacharelado em Engenharia da Computação
* IF672 -- Algoritmos e Estruturas de Dados
*
* Autor:        Sávio Berdine
* Email:        sbsx@cin.ufpe.br
* Data:         02/11/2016
*
* Descricao:  
*
* Licenca: 
*
*******************************************************************************/

#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iostream>
#include <string>
#include <limits.h>
#define E5 100000
#define E6 1000000
#define E7 10000000
#define E8 100000000
#define E9 1000000000
#define E10 10000000000
#define E11 100000000000
#define E12 1000000000000
#define E13 10000000000000
#define E14 100000000000000
#define E15 1000000000000000
#define E16 10000000000000000
#define E17 100000000000000000
#define E18 1000000000000000000

using namespace std;
using std::string;

/*Class to count execution time*/
class Counter{
	chrono::high_resolution_clock::time_point begin;
public:
	Counter();
	double time_elapsed();
};

Counter::Counter(){
	begin = chrono::high_resolution_clock::now();
}

//Returns the time elapsed since the criation in milliseconds
double Counter::time_elapsed(){
	return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - begin).count()/1000.0;
}

/***************************************************************************************************************************/

void insertionSort(int arr[], int n){
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
/* 
 * count sort of arr[]
 */  
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
/* 
 * sorts arr[] of size n using Radix Sort
 */   
void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

long long int randomInt(long long int bigger, long long int smaller){
	srand((unsigned)time(0));
	long long int number = rand()%(bigger - smaller + 1) + smaller;
	return number;
}

int main(int argc, char const *argv[]){

	cout << "Generating arrays...\n";

	int *v1 = new int[E7];
	int *v2 = new int[E7];
	int *v3 = new int[E7];

	
	/* v1 ordenação crescente, v2 ordenação decrescente*/
	for (long long int i = 0; i < E7 /*10^5*/; i++){
		v1[i] = i;
		v2[(E7 - 1) - i] = ((E7 - 1) - i);
	}

	for (long long int i = 0; i < E7; i++){
		v3[i] = randomInt(E7, 0);
	}

	Counter *cron;
	cron = new Counter();
	quickSort(v3, 0, E7);
	cout << cron->time_elapsed() << "\n";
	delete cron;

	delete[] v1;
	delete[] v2;
	delete[] v2;

	return 0;
}