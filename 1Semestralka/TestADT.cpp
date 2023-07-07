#include "TestADT.h"

TestADT::TestADT()
{
	//cout << "TestADT" << endl;
	tm = TimeMeasurement();
}

void TestADT::testList(List<int>* other, int numOfOperations, int a, int b, int c, int d)
{
	string operacia;
	int pocetScenarov = 1;
	int scenare[3][4] = { {20,20,50,10}, {35,35,20,10}, {45,45,5,5} };
	int aktScenar[4] = { a,b,c,d };
	int sum = aktScenar[0] + aktScenar[1] + aktScenar[2] + aktScenar[3];

	if (dynamic_cast<ArrayList<int>*>(other) == nullptr && dynamic_cast<DoubleLinkedList<int>*>(other) == nullptr)
	{
		cout << "Som LinkedList" << endl;
		dynamic_cast<LinkedList<int>*>(other);
		file.open("testLinkedList.csv");
	}
	else if (dynamic_cast<LinkedList<int>*>(other) == nullptr && dynamic_cast<DoubleLinkedList<int>*>(other) == nullptr) {
		cout << "Som ArrayList" << endl;
		dynamic_cast<ArrayList<int>*>(other);
		file.open("testArrayList.csv");
	} else if (dynamic_cast<LinkedList<int>*>(other) == nullptr && dynamic_cast<ArrayList<int>*>(other) == nullptr) {
		cout << "Som Obojstranne zretazeny cyklicky zoznam" << endl;
		dynamic_cast<DoubleLinkedList<int>*>(other);
		file.open("testDoubleLinkedList.csv");
	}

	for (int i = 0; i < pocetScenarov; i++)
	{
		if (sum == 0)
		{
			pocetScenarov = 3;
			for (int j = 0; j < 4; j++)
			{
				aktScenar[j] = scenare[i][j];
			}
		}
		cout << "Vykonava sa " << i + 1 << ". scenar" <<endl;
		other->clear();
		for (int j = 0; j < numOfOperations; j++)
		{
			tm.reset();
			int nahoda = rand() % 100;
			//cout << "Velkost pola: " << other->size() << endl;
			//cout << "Nahoda: " << nahoda;
			if (nahoda <= aktScenar[0])
			{	
				int nahodaOperacia = rand() % 3;
				//cout << " " << nahodaOperacia;
				switch (nahodaOperacia)
				{
					case 0:
						tm.start();
						other->insert(rand() % 100, 0);
						tm.stop();
						operacia = "vloz prvy";
						break;
					case 1:
						tm.start();
						other->add(rand() % 100);
						tm.stop();
						operacia = "vloz posledny";
						break;
					case 2:
						tm.start();
						(other->size() == 0) ? other->add(rand() % 100) : other->insert(rand() % 100, rand() % other->size());
						tm.stop();
						operacia = "vloz na index";
						break;
					default:
						break;
					}
			} else if (nahoda > aktScenar[0] && nahoda <= (aktScenar[0] + aktScenar[1]) && other->size() != 0) {
				int nahodaOperacia = rand() % 3;
				//cout << " " << nahodaOperacia << endl;
				switch (nahodaOperacia)
				{
				case 0:
					tm.start();
					other->removeAt(0);
					tm.stop();
					operacia = "zrus prvy";
					break;
				case 1:
					tm.start();
					other->removeAt(other->size() - 1);
					tm.stop();
					operacia = "zrus posledny";
					break;
				case 2:
					tm.start();
					other->removeAt((other->size() == 0) ? 0 : rand() % other->size());
					tm.stop();
					operacia = "zrus na indexe";
					break;
				default:
					break;
				}
			} else if (nahoda > (aktScenar[0] + aktScenar[1]) && nahoda <= (aktScenar[0] + aktScenar[1] + aktScenar[2]) && other->size() != 0) {
				int nahodaOperacia = rand() % 2;
				//cout << " " << nahodaOperacia << endl;
				switch (nahodaOperacia)
				{
				case 0:
					tm.start();
					(*other)[rand() % other->size()];
					tm.stop();
					operacia = "spristupni";
					break;
				case 1:
					tm.start();
					(*other)[rand() % other->size()] = rand() % 100;
					tm.stop();
					operacia = "nastav";
					break;
				}
			} else if (nahoda > (aktScenar[0] + aktScenar[1] + aktScenar[2])) {
				tm.start();
				other->getIndexOf(rand() % 100);
				tm.stop();
				operacia = "index prvku";
			}
			//cout << endl;
			//cout << chrono::duration_cast<chrono::nanoseconds>(tm.elapsed()).count() << " ns" << endl;
			writeToCSV(tm.elapsed(), operacia, static_cast<int>(other->size()));
		}		
	}
	tm.reset();
	file.close();
}

void TestADT::testPriorityQueue(PriorityQueue<int>* other, int numOfOperations, int a, int b, int c)
{
	string operacia;
	int scenare[3][3] = { {35,35,30}, {50,30,20}, {70,25,5} };
	int pocetScenarov = 1;
	int aktScenar[3] = { a,b,c};
	int sum = aktScenar[0] + aktScenar[1] + aktScenar[2];
	if (dynamic_cast<PriorityQueueSortedArrayList<int>*>(other) == nullptr && dynamic_cast<PriorityQueueTwoLists<int>*>(other) == nullptr)
	{
		cout << "Som Heap" << endl;
		dynamic_cast<Heap<int>*>(other);
		file.open("testHeap.csv");
	}
	else if (dynamic_cast<Heap<int>*>(other) == nullptr && dynamic_cast<PriorityQueueTwoLists<int>*>(other) == nullptr) {
		cout << "Som PriorityQueueSortedArrayList" << endl;
		dynamic_cast<PriorityQueueSortedArrayList<int>*>(other);
		file.open("testPriorityQueueSortedArrayList.csv");
	}
	else if (dynamic_cast<Heap<int>*>(other) == nullptr && dynamic_cast<PriorityQueueSortedArrayList<int>*>(other) == nullptr) {
		cout << "Som PriorityQueueTwoLists" << endl;
		dynamic_cast<PriorityQueueTwoLists<int>*>(other);
		string s(1, other->getTypeOfShortList());
		string nazovSuboru = "testPriorityQueueTwoLists" + s + ".csv";
		file.open(nazovSuboru);
	}

	for (int i = 0; i < pocetScenarov; i++)
	{
		if (sum == 0)
		{
			pocetScenarov = 3;
			for (int j = 0; j < 3; j++)
			{
				aktScenar[j] = scenare[i][j];
			}
		}
		if (dynamic_cast<Heap<int>*>(other) == nullptr && dynamic_cast<PriorityQueueSortedArrayList<int>*>(other) == nullptr && other->getTypeOfShortList() == 'A') {
			other->setScenario(i);
		}
		cout << "Vykonava sa " << i + 1 << ". scenar" << endl;
		other->clear();
		for (int j = 0; j < numOfOperations; j++)
		{
			tm.reset();
			int nahoda = rand() % 100;
			int nahodnaPriorita = rand() % 10001;
			//cout << "Velkost pola: " << other->size() << endl;
			//cout << "Nahoda: " << nahoda;
			if (nahoda <= aktScenar[0])
			{
				tm.start();
				other->push(nahodnaPriorita, rand() % 100);
				tm.stop();
				operacia = "vloz";
			}
			else if (nahoda > aktScenar[0] && nahoda <= (aktScenar[0] + aktScenar[1]) && other->size() != 0) {
				tm.start();
				other->pop();
				tm.stop();
				operacia = "vyber";
			}
			else if (nahoda > (aktScenar[0] + aktScenar[1]) && other->size() != 0) {
				tm.start();
				other->peek();
				tm.stop();
				operacia = "ukaz";
			}
			//cout << endl;
			//cout << chrono::duration_cast<chrono::nanoseconds>(tm.elapsed()).count() << " ns" << endl;
			writeToCSV(tm.elapsed(), operacia, static_cast<int>(other->size()), nahodnaPriorita);
		}
	}
	tm.reset();
	file.close();
}

void TestADT::testMatrix(Matrix<int>* matrixA, Matrix<int>* matrixB, Matrix<int>* matrixC)
{
	if (dynamic_cast<Contiguous_Matrix<int>*>(matrixA) == nullptr)
	{
		cout << "Som Noncontiguous Matrix" << endl;
		dynamic_cast<Noncontiguous_Matrix<int>*>(matrixA);
		file.open("testNoncontiguousMatrix.csv");
	}
	else if (dynamic_cast<Noncontiguous_Matrix<int>*>(matrixA) == nullptr) {
		cout << "Som Contiguous Matrix" << endl;
		dynamic_cast<Contiguous_Matrix<int>*>(matrixA);
		file.open("testContiguousMatrix.csv");
	}

	cout << "Zaciatok scitovania" << endl;
	for (int k = 1; k <= MAX_ROWS; k = k + 50)
	{
		for (int l = 1; l <= MAX_COLUMNS; l = l + 50)
		{
			//cout << k << " " << l << endl;
			matrixA->setDimensions(k, l);
			matrixB->setDimensions(k, l);
			matrixC->setDimensions(k, l);
			tm.reset();
			tm.start();
			for (int i = 0; i < matrixA->getRows(); i++)
			{
				for (int j = 0; j < matrixB->getColumns(); j++) {
					matrixC->setData(i, j, matrixA->accessData(i, j) + matrixB->accessData(i, j));
				}
			}
			tm.stop();
			writeToCSV(tm.elapsed(), "scitovanie", k, l);
			if (l == 1) { l--; };
		}
		if (k == 1) { k--; };
	}

	cout << "Zaciatok nasobenia" << endl;
	int vysledok;
	for (int m = 1; m <= (MAX_ROWS-500); m=m+50)
	{
		for (int n = 1; n <= (MAX_COLUMNS-500); n=n+50) {
			//cout << m << " " << n << endl;
			matrixA->setDimensions(m, n);
			matrixB->setDimensions(n, m);
			matrixC->setDimensions(m, m);
			tm.reset();
			tm.start();
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < m; j++) {
					vysledok = 0;
					for (int k = 0; k < n; k++)
					{
						vysledok += matrixA->accessData(i, k) * matrixB->accessData(k, j);
					}
					matrixC->setData(i, j, vysledok);
				}
			}
			tm.stop();
			writeToCSV(tm.elapsed(), "nasobenie", m, m, n);
			if (n == 1) { n--; };
		}
		if (m == 1) { m--; };
	}
	tm.reset();
	file.close();
}

void TestADT::writeToCSV(TimerUnits duration, string nameOfOperation, int numOfValues, int numOfValuesB, int numOfValuesC)
{
	if (numOfValuesB == 0)
	{
		file << nameOfOperation << ";" << (duration).count() << ";" << numOfValues << "\n";
	}
	else if (numOfValuesC == 0){
		file << nameOfOperation << ";" << (duration).count() << ";" << numOfValues << ";" << numOfValuesB << "\n";
	}
	else {
		file << nameOfOperation << ";" << (duration).count() << ";" << numOfValues << ";" << numOfValuesB
			<< ";" << numOfValuesB << ";" << numOfValuesC << ";" << numOfValuesC << ";" << numOfValuesB << "\n";
	}
}

TestADT::~TestADT()
{
}
