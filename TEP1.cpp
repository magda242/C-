// TEP1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "TEP1.h"
#include <iostream>
using namespace std;
 

//zadanie 1

void alloc_table_add_5(int iSize)
{

	if (iSize <= 0 || iSize >sizeof(int)) {
		return;
	}
	else {
		int* pi_table;
		pi_table = new int[iSize];

		for (int ii = 0; ii < iSize; ii++) {
			pi_table[ii] = VALUE_TO_ADD + ii;
		}

		for (int i = 0; i <= iSize - 1; i++)
		{
			cout << pi_table[i] << " "; 
		}
		cout << endl;
		
		delete[] pi_table;
	}

}


//zadanie 2




bool b_alloc_table_2_di(int*** piTable, int iSizeX, int iSizeY) {

	if (iSizeX <= 0 || iSizeY <= 0 ){
		return false;
	}
	else {

		*piTable = new int*[iSizeY];

		if (*piTable == nullptr) {
			return false;
		}

		for (int i = 0; i < iSizeY; i++) {
			(*piTable)[i]= new int[iSizeX];
			//lub (**piTable)+i = new int[iSizeX];
		}

		return true;
	}
}


//zadanie 3 


bool b_dealloc_table_2_dim(int** piTable, int iSizeX, int iSizeY) {
	if (iSizeX <= 0 || iSizeY <= 0) {
		return false;
	}
	else {
		for (int ii = 0; ii < iSizeY; ii++) {
			delete[] piTable[ii];
		}
		delete[] piTable;
		return true;
	}
}








int i_sum(int** piTable, int iSizeX, int iSizeY) {
	if (iSizeX <= 0 || iSizeY <= 0) {
		return false;
	}
	else {
		int i_sum = 0;
		for (int i = 0; i < iSizeY; i++) {
			for (int j = 0; j < iSizeX; j++) {
				i_sum += piTable[i][j];
			}
		}
		return i_sum;
	}
}






int main()
{
	int** pi_table;
	b_alloc_table_2_di(&pi_table, 2, 3);

	cout << i_sum(pi_table, 5, 3);
	b_dealloc_table_2_dim(pi_table, 5, 3);

	cout << endl;
	int *table;
	alloc_table_add_5(10);


}