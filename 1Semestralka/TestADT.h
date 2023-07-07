#pragma once
#include "heap_monitor.h"
#include <stdlib.h> 
#include <time.h>  
#include "list/list.h"
#include "list/array_list.h"
#include "list/linked_list.h"
#include "double_linked_list.h"
#include "priority_queue/priority_queue_sorted_array_list.h"
#include "priority_queue/priority_queue_two_lists.h"
#include "priority_queue/heap.h"
#include "matrix.h"
#include "matrix_contiguous.h"
#include "matrix_noncontiguous.h"
#include "TimeMeasurement.h"
#include <iostream>
#include <fstream>

#define MAX_ROWS 2000
#define MAX_COLUMNS 2000

using namespace std;
using namespace structures;
using namespace chrono;
class TestADT
{
public:
	typedef nanoseconds TimerUnits;
private:
	/// <summary> Subor do htoreho sa zapisuju vysledky testov. </summary>
	ofstream file;
	/// <summary> Meranie casu. </summary>
	TimeMeasurement tm;
public:
	/// <summary> Konstruktor. </summary>
	TestADT();
	/// <summary> Metoda pre testovanie zoznamov. </summary>
	/// <param name="other">Testovany zoznam</param>
	/// <param name="numOfOperations">Pocet vykonanych operacii jedneho scenara.</param>
	/// <param name="a">Podiel prvej skupiny operacii.</param>
	/// <param name="b">Podiel druhej skupiny operacii.</param>
	/// <param name="c">Podiel tretej skupiny operacii.</param>
	/// <param name="d">Podiel stvrtej skupiny operacii.</param>
	void testList(List<int>* other, int numOfOperations = 100000, int a = 0, int b = 0, int c = 0, int d = 0);
	
	/// <summary> Metoda pre testovanie prioritnych frontov. </summary>
	/// <param name="other">Testovany prioritny front</param>
	/// <param name="numOfOperations"> Pocet vykonanych operacii jedneho scenara</param>
	/// <param name="a">Podiel prvej skupiny operacii.</param>
	/// <param name="b">Podiel druhej skupiny operacii.</param>
	/// <param name="c">Podiel tretej skupiny operacii.</param>
	void testPriorityQueue(PriorityQueue<int>* other, int numOfOperations = 100000, int a = 0, int b = 0, int c = 0);
	
	/// <summary> Metoda pre testovanie matic. </summary>
	/// <param name="matrixA">Matica ktora sa bude scitavat/nasobit</param>
	/// <param name="matrixB">Matica ktora sa bude scitavat/nasobit</param>
	/// <param name="matrixC">Vysledna matica.</param>
	void testMatrix(Matrix<int>* matrixA, Matrix<int>* matrixB, Matrix<int>* matrixC);

	/// <summary> Metoda pre zapis do suboru. </summary>
	/// <param name="duration">Cas trvania vykonanej operacie.</param>
	/// <param name="nameOfOperation">Nazov vykonanej operacie</param>
	/// <param name="numOfValues">Pocet hodnot.</param>
	/// <param name="numOfValuesB">Pocet hodnot.</param>
	/// <param name="numOfValuesC">Pocet hodnot.</param>
	void writeToCSV(TimerUnits duration, string nameOfOperation, int numOfValues, int numOfValuesB = 0, int numOfValuesC = 0);
	
	/// <summary> Destruktor. </summary>
	~TestADT();

};
