// Zajecia_22_05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int val;
	node *next;
};

void ADD(node *&H, int x) {
	node*p = new node;
	p->val = x;
	p->next = H;
	H = p;
}

void Show(node *H) {
	cout << "H->";
	node *p = H;
	while (p != NULL) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}
void Del(node *&H) {
	if (H != NULL) {
		node *p = H;
		H = p->next;
		delete p;
	}
}

void Del_x(node *&H, int x)
{
	if (H != NULL)
	{
		if (H->val == x) Del(H);
		else {
			node *p = H;
			while (p->next != NULL && p->next->val != x)
				p = p->next;
			//if (p->next != NULL) //przy stosowanie funkcji zewnetrzne
			Del(p->next);
		}
	}
}
void cp(node *&H) {
	if (H != NULL) {
		ADD(H, H->val);
		node *p = H->next->next;
		while (p != NULL) {
			ADD(p->next, p->val);
			p = p->next->next;
		}

	}
}
void insertSortedlist(node*& H, int x)
{
	if (H == NULL)
		ADD(H, x);
	else {
		if (H->val > x)
			ADD(H, x);

		else {
			node* p = H;
			while (p->next != NULL && p->next->val < x)
			{
				p = p->next;
				ADD(p->next, x);
			}
		}
	}

}

int length(node* H)
{
	int n = 0;
	node*p = H;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return int(n / 2) - 1;
}
void Split(node*& H, node*& H1, node*& H2)
{
	H1 = H;
	if (H != NULL && H->next == NULL) H = NULL;
	else
	{
		node* p = H;
		int dl = length(H);
		for (int i = 0; dl > i; i++)
		{
			p = p->next;
		}
		H2 = p->next;
		p->next = NULL;
		H = NULL;

	}
}

void marge(node*&H, node*& H1, node*& H2)
{
	if (H1 == NULL && H2 != NULL)
	{
		H = H2;
		H2 = NULL;
	}

	if (H2 == NULL && H1 != NULL)
	{
		H = H1;
		H1 = NULL;
	}
	if (H1 != NULL && H2 != NULL)
	{
		node* T = NULL;
		node*p = NULL;
		while (H1 && H2)
		{
			if (H1->val < H2->val)
			{
				p = H1;
				H1 = H1->next;

				if (H == NULL)
				{
					H = p;
					T = p;
				}
				else
				{
					T->next = p;
					T = p;
				}
			}
			else
			{
				p = H2;
				H2 = H2->next;
				if (H == NULL)
				{
					H = p;
					T = p;

				}
				else
				{

					T->next = p;
					T = p;

				}
			}
		}
		if (H1 == NULL)
		{
			T->next = H2;
			H2 = NULL;
		}
		else
		{
			T->next = H1;
			H1 = NULL;
		}
	}
}


void MargeSort(node*& H) {
	if (H && H->next != NULL) {
		node* H1 = NULL;
		node* H2 = NULL;
		Split(H, H1, H2);
		MargeSort(H1);
		MargeSort(H2);
		marge(H, H1, H2);
	}
}

void SortB(node*& H)
{
	node* p = NULL;
	node* e = H;
	node* f = H->next;
	if (e != NULL && f != NULL) {
		while (e->next != p)
		{
			if (e->val > f->val)				
			e->next = f->next;
			f->next = e;
		}
	}
}

// tablica 
void heapify(int* T, int heapsize, int i) {
	int L = 2 * i;
	int R = L + 1;
	int largest = i;
	if (L <= heapsize && T[L] > T[i]) largest = L;
	if (R <= heapsize && T[R] > T[largest]) largest = R;
	if (largest != i)
	{
		swap(T[i], T[largest]);
		heapify(T, heapsize, largest);
	}
}
void BuildHeap(int* T, int heapsize)
{
	for (int i = heapsize / 2; i > 0; i--)
	{
		heapify(T, heapsize, i);
	}
}
void HeapSort(int* T, int size)
{
	int heapsize = size-1;
	BuildHeap(T, heapsize);
	while (heapsize > 1)
	{
		swap(T[1], T[heapsize]);
		heapsize--;
		heapify(T, heapsize, 1);
	}
}

int main()
{
	node *H = NULL;	
	ADD(H, 8);
	ADD(H, 3);
	ADD(H, 2);
	ADD(H, -6);
	ADD(H, 16);
	ADD(H, 5);
	ADD(H, 22);
	ADD(H, -8);
	ADD(H, 4);
	
	//MargeSort(H);
	Show(H);

	// tablica
	int * T = new int[10]{0, 20, -10, 6, -6, 3, 15, 8, 8, 30 };
	HeapSort(T, 10);
	for (int i = 1; i < 10; i++)
	{
		cout << T[i]<< " "; 
	}
	system("pause");
    return 0;
}

