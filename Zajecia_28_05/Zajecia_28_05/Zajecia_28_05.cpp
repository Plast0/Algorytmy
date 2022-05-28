// Zajecia_28_05.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
int gapfun(int size) {
	int gap;
	if (size == 9 || size == 10) gap = 11;
	else gap = size / 1.3;
	return gap;
}


void CombSort(int* tab, int size) {
	int gap = gapfun(size);

	while (gap > 1) {

		for (int i = 0; i < size - gap; i++) {
			if (tab[i + gap] < tab[i])
				swap(tab[i], tab[i + gap]);
		}
		for (int i = 0; i < 8; i++) {
			cout << tab[i] << " ";
		}
		cout << endl;
		gap = gapfun(gap);
	}
	//Bubblesort teraz tutaj
}
int partition_Lomuto(int* tab, int l, int r) {
	int x = tab[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (tab[j] < x) {
			i++;
			swap(tab[i], tab[j]);
		}

	}
	swap(tab[i + 1], tab[r]);
	return i + 1;

}
int partition_Lomuto_swap(int* tab, int l, int r) {
	swap(tab[l + 1], tab[(l + r) >> 1]);
	if (tab[l + 1] > tab[r]) swap(tab[l + 1], tab[r]);
	if (tab[l] > tab[r]) swap(tab[l], tab[r]);
	if (tab[l + 1] > tab[l]) swap(tab[l + 1], tab[l]);
	int x = tab[r];
	int i = l;
	for (int j = l; j < r; j++) {
		if (tab[j] < x) {
			i++;
			swap(tab[i], tab[j]);
		}
	}
	swap(tab[i + 1], tab[r]);
	return i + 1;
}

void QuickSort(int* tab, int l, int r) {
	if (l >= r) return;
	int p = partition_Lomuto(tab, l, r);
	QuickSort(tab, l, p - 1);
	QuickSort(tab, p + 1, r);
}

int main()
{
	cout << "hello" << endl;
	int tab[8] = { 8, 1, 6, -5, 33, -16, 25, 7 };
	int size = sizeof(tab) / sizeof(tab[0]);
	//CombSort(tab, size);
	QuickSort(tab, 0, size - 1);
	for (int i = 0; i < size; i++) {
		cout << tab[i] << " ";
	}
	cout << endl;
	system("pause");

	return 0;
}

