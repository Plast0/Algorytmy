// Lista_cwiczenia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

struct node {
	int val;
	node* next;
};

void ADD(node*& H, int x) {
	
		node* p = new node;
		p->val = x;
		p->next = H;
		H = p;
	
}

void show(node* H) {
	cout << "H->";
	node* p = H;
	while (p != NULL) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

void Del(node*& H) {
	if (H != NULL) {
		node* p = new node;
		p = H;
		H = p->next;
		delete p;
	}
}

void DelX(node*& H, int x) {
	if (H != NULL) {
		node* p = H;
		while (p->next->val != x && p->next != NULL) {
			p = p->next;
		}
		if(p->next != NULL) Del(p->next);				
	}
}

unsigned Len(node* H)
{
	unsigned c = 0;
	while (H)
	{
		c++;
		H = H->next;
	}
	return c;
}

void Lenght(node* H) {
	unsigned c = 0;
	while (H)
	{
		c++;
		H = H->next;
	}
	cout << "Lenght of list: " << c << endl;
}
void changeFL(node*& H) {
	if(H != NULL)
	{node* p = H;
	node* e = p;
	if (e->next != NULL) {
		while (e->next->next != NULL) {
			e = e->next;
		}		
	}	
	H = e->next;
	H->next = p->next;
	e->next = p;
	p->next = NULL;
	}
}

void push_back(node*& H, int x) {
	node* p = H;
	node* e = new node; 
	e->val = x;
	e->next = NULL;
	if (p != NULL)
	{
		while (p->next != NULL) p = p->next;
		p->next = e;
	}
	else H = e; 
}

void changeFS(node*& H) {
	if (H != NULL && H->next != NULL) {
		node* p = H;
		node* e = p->next;
		p->next = p->next->next;
		H = e;
		e->next = p;
	}
}
void sortADD(node*& H, int x)
{
	if (H == NULL) ADD(H, x);
	else {
		if (H->val > x) ADD(H, x);
		else {			
			node* p = H;
			while (p->next != NULL && p->next->val < x) {
				p = p->next;
			}
			ADD(p->next, x);
			}

		}	
}
void copyEnd(node*& H)
{
	if (H != NULL) {
		node* p = H;
		node* H1 = NULL;
		ADD(H1, p->val);
		while (p->next != NULL)
		{ 
			ADD(H1, p->next->val);
			p = p->next;
		}
		p->next = H1;
	}
}
void copyFront(node*& H)
{
	if (H != NULL) {
		node* p = H;
		node* H1 = NULL;
		ADD(H1, p->val);
		while (p->next != NULL)
		{
			ADD(H1, p->next->val);
			p = p->next;
		}
		ADD(H, H1->val);
		while (H1->next != NULL)
		{
			ADD(H, H1->next->val);
			H1 = H1->next;
		}
	}
}

void Split(node*& H, node*& H1, node*& H2) {
	H1 = H;
	if (H != NULL && H->next == NULL) H2 = NULL;
	else {
		unsigned c = 0;
		node* p = H;
		while (p) {
			c++;
			p = p->next;
		}
		p = H1;
		for (int i = 1; i < c / 2; i++) {
			p = p->next;
		}
		H2 = p->next;
		p->next = NULL;
	}
}

int main()
{
	cout << "Dzin dybry."<<endl;
	node* H = NULL;
	ADD(H, 5);
	show(H);
	ADD(H, 51);
	show(H);
	ADD(H, 25);
	show(H);
	//Del(H);
	DelX(H, 5);
	show(H);
	cout<<Len(H)<<endl;
	Lenght(H);
	show(H);
	push_back(H, 8);	
	ADD(H, 120);
	show(H);
	changeFL(H);
	show(H);
	changeFS(H);
	show(H);
	node* H1 = NULL;
	show(H1);
	push_back(H1, 1);
	show(H1);
	//changeFS(H1);
	//show(H1);
	sortADD(H1, 6);
	sortADD(H1, 3);
	sortADD(H1, 8);
	sortADD(H1, 7);
	show(H1);
	Lenght(H1);
	copyEnd(H1);
	show(H1);
	copyFront(H);
	show(H);
	node* H2 = NULL;
	node* H3 = NULL;
	Split(H1, H2, H3);
	show(H1);
	show(H2);
	show(H3);
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
