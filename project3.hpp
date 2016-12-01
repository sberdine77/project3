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
#include <string>

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

/*Interface for Item*/
template <class KeyType> class Item {
public:
	virtual int compare(const Item<KeyType> *it) const = 0;
	virtual void changeKey(KeyType key) = 0;
	virtual KeyType recoverKey() const = 0;
	virtual ~Item(){};
};

/*My Item*/
class MyItem : public Item<int> {
public: int key;
public:
	MyItem(int key);
	virtual int compare(const Item<int> *item) const;
	virtual void changeKey(int key);
	virtual int recoverKey() const;
	~MyItem(){}
};

MyItem::MyItem(int key){this->key = key;}

int MyItem::compare(const Item<int> *item) const{
	MyItem *it = (MyItem *)item;
	if(this->key < it->key) return -1;
	else if(this->key > it->key) return 1;
	else return 0;
}

void MyItem::changeKey(int key){this->key = key;}

int MyItem::recoverKey(){return this->key;}

/***************************************************************************************************/

/*Sort*/
template<class KeyType> class Sort{
public:
	static void insertionSort(Item<KeyType> **v, int n);
	static void quickSort(Item<KeyType> **v, int n);
	static void radixSort(Item<KeyType> **v, int n);
private:
	typedef struct PartitionEdges{int i, j;} PartitionEdges;
	static PartitionEdges partition(Item<KeyType> **v, int left, int right);
	static void order (Item<KeyType> **v, int left, int right);
};

template<class KeyType>
void Sort<KeyType>::insertionSort(Item<KeyType> **v, int n){
	int j;
	for(int i = 2; i <= n; i++){
		Item<KeyType> *x = v[i];
		j = i -1;
		v[0] = x;
		while(x->compare(v[j]) < 0){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = x;
	}
}

template<class KeyType>
typename Sort<KeyType>::PartitionEdges
Sort<KeyType>::partition(Item<KeyType> **v, int left, int right){
	PartitionEdges p;
	p.i = left;
	p.j = right;
	Item<KeyType> *x = v[(p.i+p.j)/2];
	do{
		while(x->compare(v[p.i]) > 0) p.i++;
		while(x->compare(v[p.j]) < 0) p.j--;
		if(p.i <= p.j){
			Item<KeyType> *w = v[p.i];
			v[p.i] = v[p.j];
			v[p.j] = w;
		}
	}while(p.i <= p.j);
	return p;
}

template<class KeyType>
void Sort<KeyType>::order(Item<KeyType> **v, int left, int right){
	PartitionEdges p = partition(v, left, right);
	if(left < p.j) order(v, left, p.j);
	if(p.i< right) order(v, p.i, right);
}

template<class KeyType>
void Sort quickSort(Item<KeyType> **v, int n){
	order(v, 1, n);
}

/********************************************************************************************************/

int main(int argc, char const *argv[]){
	
	return 0;
}