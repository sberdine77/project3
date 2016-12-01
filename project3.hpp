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

#include <chrono>
#include <iostream>

using namespace std;

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

