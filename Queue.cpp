// Queue.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
};
void enQueue(node*& Q, node*& T, int x) {
    node* p = new node;
    p->val = x;
    p->next = NULL;
    if (Q == NULL) {
        Q = p;
        T = p;
    }
    else {
        T->next = p;
        T = p;
    }
}
void deQueue(node*& Q, node*& T) {
    node* p = Q;
    if (Q != NULL) {
        Q = p->next;
        delete p;
    }
}
void peek(node* Q)
{
    if (Q != NULL) cout << "Pierwszy element kolejki : " << Q->val << endl;
}

bool isEmpty(node* Q)
{
    if (Q == NULL)return true;
    else return false;
}

int main()
{    
    node* Q = NULL;
    node* T = NULL;
    Q = T;
    enQueue(Q, T, 5);
    enQueue(Q, T, 10);
    enQueue(Q, T, 20);
    peek(Q);
    deQueue(Q, T);
    peek(Q);
    deQueue(Q, T);
    peek(Q);
    if (isEmpty(Q) == true) cout << "Kolejka jest pusta." << endl;
    else cout << "Kolejka nie jest pusta." << endl;
    deQueue(Q, T);
    if (isEmpty(Q) == true) cout << "Kolejka jest pusta." << endl;
    else cout << "Kolejka nie jest pusta." << endl;
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
