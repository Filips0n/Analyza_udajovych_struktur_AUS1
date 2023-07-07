
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <iostream>
#include "list/array_list.h"
#include "double_linked_list.h"
#include "vector/vector.h"
#include "priority_queue/priority_queue_sorted_array_list.h"
#include "priority_queue/priority_queue_two_lists.h"
#include "priority_queue/heap.h"
#include "matrix_contiguous.h"
#include "matrix_noncontiguous.h"
#include "matrix.h"
#include "TestADT.h"

using namespace std;

int main() {
	initHeapMonitor();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));
	TestADT test;
	TimeMeasurement timeM = TimeMeasurement();
	int num = 0;
	do {
		cout << "Zadaj cislo testovanej skupiny struktur: " << endl;
		cout << "1 - Zoznamy" << endl;
		cout << "2 - Fronty" << endl;
		cout << "3 - Matice" << endl;
		cout << "0 - Ukonci" << endl;
		cin >> num;
		cout << endl;
		system("CLS");

		if (num == 1)
		{
			cout << "Zadaj cislo testovanej struktury: " << endl;
			cout << "1 - ArrayList" << endl;
			cout << "2 - LinkedList" << endl;
			cout << "3 - Obojstr. zretazeny cykl. zoznam" << endl;
			int num2;
			cin >> num2;

			cout << endl;
			cout << "Zadat vlastny scenar?" << endl;
			cout << "1 - Ano" << endl;
			cout << "2 - Nie" << endl;
			int num3;
			cin >> num3;
			system("CLS");
			int scenar[4] = {0,0,0,0};
			int num5;
			if (num3 == 1)
			{
				cout << "Zadaj celkovy pocet operacii: " << endl;
				cin >> num5;
				int max = 100;
				string nazvyOperacii[4]{ "Vloz", "Zrus", "Spristupni/Nastav", "Index prvku" };
				int i = 0;
				cout << "Dostupne operacie: 'Vloz' 'Zrus' 'Spristupni / Nastav' 'Index prvku'" << endl;
				while (max > 0)
				{
					cout << "Zadaj podiel poctu operacii '" << nazvyOperacii[i] << "'   zostava: " << max << endl;
					int num4;
					cin >> num4;
					if (max - num4 >= 0) 
					{
						scenar[i] = num4;
						max -= num4;
						i++;
					}
					else {
						cout << "Prilis vysoky pomer!" << endl;
					}
				}
				system("CLS");
			}
			if (num2 == 1)
			{
				structures::ArrayList<int>* Apole = new structures::ArrayList<int>;
				timeM.start();
				num3 == 1 ? test.testList(Apole, num5, scenar[0], scenar[1], scenar[2], scenar[3]) : test.testList(Apole);
				timeM.stop();
				chrono::duration<float> duration1 = timeM.elapsed();
				duration1 = timeM.elapsed();
				cout << duration1.count() << " s" << endl;
				cout << chrono::duration_cast<chrono::milliseconds>(timeM.elapsed()).count() << " ms" << endl;
				timeM.reset();
				delete Apole;
			}
			else  if (num2 == 2) {
				structures::LinkedList<int>* Lpole = new structures::LinkedList<int>;
				timeM.start();
				num3 == 1 ? test.testList(Lpole, num5, scenar[0], scenar[1], scenar[2], scenar[3]) : test.testList(Lpole);
				timeM.stop();
				chrono::duration<float> duration1 = timeM.elapsed();
				cout << duration1.count() << " s" << endl;
				cout << chrono::duration_cast<chrono::milliseconds>(timeM.elapsed()).count() << " ms" << endl;
				timeM.reset();
				delete Lpole;
			}
			else if (num2 == 3) {
				structures::DoubleLinkedList<int>* Dpole = new structures::DoubleLinkedList<int>;
				timeM.start();
				num3 == 1 ? test.testList(Dpole, num5, scenar[0], scenar[1], scenar[2], scenar[3]) : test.testList(Dpole);
				timeM.stop();
				chrono::duration<float> duration1 = timeM.elapsed();
				duration1 = timeM.elapsed();
				cout << duration1.count() << " s" << endl;
				cout << chrono::duration_cast<chrono::milliseconds>(timeM.elapsed()).count() << " ms" << endl;
				timeM.reset();
				delete Dpole;
			}
		}
		else if (num == 2) {
			cout << "Zadaj cislo testovanej struktury: " << endl;
			cout << "1 - Zoznam utriedeny podla priorit" << endl;
			cout << "2 - Lavostranna halda" << endl;
			cout << "3 - Dvojzoznam ako implementacia prio. frontu" << endl;
			int num2;
			cin >> num2;

			cout << endl;
			cout << "Zadat vlastny scenar?" << endl;
			cout << "1 - Ano" << endl;
			cout << "2 - Nie" << endl;
			int num3;
			cin >> num3;
			system("CLS");
			int scenar[3] = { 0,0,0};
			int num5 = 0;
			if (num3 == 1)
			{
				cout << "Zadaj celkovy pocet operacii: " << endl;
				cin >> num5;
				int max = 100;
				string nazvyOperacii[3]{ "Vloz", "Vyber", "Ukaz"};
				int i = 0;
				cout << "Dostupne operacie: 'Vloz' 'Vyber' 'Ukaz'" << endl;
				while (max > 0)
				{
					cout << "Zadaj podiel poctu operacii '" << nazvyOperacii[i] << "'   zostava: " << max << endl;
					int num4;
					cin >> num4;
					if (max - num4 >= 0)
					{
						scenar[i] = num4;
						max -= num4;
						i++;
					}
					else {
						cout << "Prilis vysoky pomer!" << endl;
					}
				}
				system("CLS");
			}
			if (num2 == 1)
			{
				structures::PriorityQueueSortedArrayList<int>* PrQueSoAL = new structures::PriorityQueueSortedArrayList<int>;
				timeM.start();
				num3 == 1 ? test.testPriorityQueue(PrQueSoAL, num5, scenar[0], scenar[1], scenar[2]) : test.testPriorityQueue(PrQueSoAL);
				timeM.stop();
				chrono::duration<float> duration1 = timeM.elapsed();
				cout << duration1.count() << " s" << endl;
				cout << chrono::duration_cast<chrono::milliseconds>(timeM.elapsed()).count() << " ms" << endl;
				timeM.reset();
				delete PrQueSoAL;
			}
			else if (num2 == 2) {
				structures::Heap<int>* Heap = new structures::Heap<int>;
				timeM.start();
				num3 == 1 ? test.testPriorityQueue(Heap, num5, scenar[0], scenar[1], scenar[2]) : test.testPriorityQueue(Heap);
				timeM.stop();
				chrono::duration<float> duration1 = timeM.elapsed();
				cout << duration1.count() << " s" << endl;
				cout << chrono::duration_cast<chrono::milliseconds>(timeM.elapsed()).count() << " ms" << endl;
				timeM.reset();
				delete Heap;
			}
			else if (num2 == 3) {
				cout << "Zadaj cislo dlzky kratsieho zoznamu: " << endl;
				cout << "1 - 1/1000" << endl;
				cout << "2 - sqrt(n)" << endl;
				cout << "3 - n/2" << endl;
				int num4;
				cin >> num4;
				system("CLS");
				if (num4 == 1) {
					structures::PriorityQueueTwoLists<int>* PQTpoleA = new structures::PriorityQueueTwoLists<int>('A');
					timeM.start();
					num3 == 1 ? test.testPriorityQueue(PQTpoleA, num5, scenar[0], scenar[1], scenar[2]) : test.testPriorityQueue(PQTpoleA);
					timeM.stop();
					chrono::duration<float> duration1 = timeM.elapsed();
					duration1 = timeM.elapsed();
					cout << duration1.count() << " s" << endl;
					cout << chrono::duration_cast<chrono::milliseconds>(timeM.elapsed()).count() << " ms" << endl;
					timeM.reset();
					delete PQTpoleA;

				}
				else if (num4 == 2) {
					structures::PriorityQueueTwoLists<int>* PQTpoleB = new structures::PriorityQueueTwoLists<int>('B');
					timeM.start();
					num3 == 1 ? test.testPriorityQueue(PQTpoleB, num5, scenar[0], scenar[1], scenar[2]) : test.testPriorityQueue(PQTpoleB);
					timeM.stop();
					chrono::duration<float> duration2 = timeM.elapsed();
					duration2 = timeM.elapsed();
					cout << duration2.count() << " s" << endl;
					cout << chrono::duration_cast<chrono::milliseconds>(timeM.elapsed()).count() << " ms" << endl;
					timeM.reset();
					delete PQTpoleB;
				}
				else if (num4 == 3) {
					structures::PriorityQueueTwoLists<int>* PQTpoleC = new structures::PriorityQueueTwoLists<int>('C');
					timeM.start();
					num3 == 1 ? test.testPriorityQueue(PQTpoleC, num5, scenar[0], scenar[1], scenar[2]) : test.testPriorityQueue(PQTpoleC);
					timeM.stop();
					chrono::duration<float> duration3 = timeM.elapsed();
					duration3 = timeM.elapsed();
					cout << duration3.count() << " s" << endl;
					cout << chrono::duration_cast<chrono::milliseconds>(timeM.elapsed()).count() << " ms" << endl;
					timeM.reset();
					delete PQTpoleC;
				}
			}
		}
		else if (num == 3) {
			cout << "Zadaj cislo testovanej struktury: " << endl;
			cout << "1 - Matica v suvislej pamati" << endl;
			cout << "2 - Matica v nesuvislej pamati" << endl;
			int num2;
			cin >> num2;
			system("CLS");
			if (num2 == 1)
			{
				structures::Contiguous_Matrix<int>* MatA = new structures::Contiguous_Matrix<int>(50, 50, rand() % 100);
				structures::Contiguous_Matrix<int>* MatB = new structures::Contiguous_Matrix<int>(50, 50, rand() % 100);
				structures::Contiguous_Matrix<int>* MatC = new structures::Contiguous_Matrix<int>(50, 50, rand() % 100);
				timeM.start();
				test.testMatrix(MatA, MatB, MatC);
				timeM.stop();
				chrono::duration<float> duration1 = timeM.elapsed();
				cout << duration1.count() << " s" << endl;
				cout << chrono::duration_cast<chrono::milliseconds>(timeM.elapsed()).count() << " ms" << endl;
				timeM.reset();
				delete MatA;
				delete MatB;
				delete MatC;
			}
			else if (num2 == 2) {
				structures::Noncontiguous_Matrix<int>* MatA = new structures::Noncontiguous_Matrix<int>(2000, 2000, rand() % 100);
				structures::Noncontiguous_Matrix<int>* MatB = new structures::Noncontiguous_Matrix<int>(2000, 2000, rand() % 100);
				structures::Noncontiguous_Matrix<int>* MatC = new structures::Noncontiguous_Matrix<int>(2000, 2000, rand() % 100);
				timeM.start();
				test.testMatrix(MatA, MatB, MatC);
				timeM.stop();
				chrono::duration<float> duration1 = timeM.elapsed();
				cout << duration1.count() << " s" << endl;
				cout << chrono::duration_cast<chrono::milliseconds>(timeM.elapsed()).count() << " ms" << endl;
				timeM.reset();
				delete MatA;
				delete MatB;
				delete MatC;
			}
		}
		cout << endl;
	} while (num != 0);
	return 0;
}