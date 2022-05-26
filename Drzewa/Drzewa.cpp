// Drzewa.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

struct node {
	node* R;
	node* L;
	node* UP;
	int val;
};

void insertBST(node*& root, int x, node* rootU = NULL ) {
	if (root == NULL) {
		root = new node;
		root->val = x;
		root->R = root->L  = NULL;
		root->UP = rootU;
	}
	else {
		if (x < root->val) insertBST(root->L, x, root);
		else insertBST(root->R, x, root);
	}
}

void Inorder(node* root) {
	if (root != NULL) {
		Inorder(root->L);
		cout << root->val << " ";
		if(root->UP != NULL)
		cout << "\nJego Up: "<<root->UP->val << endl;
		Inorder(root->R);

	}
}
/*
void poprzednik(node* root, int x) {
	if(root->)
}
void następnik(node* root) {
	
}*/

int main()
{

	node* root = NULL;
	insertBST(root,  13);
	insertBST(root,  8);
	insertBST(root, 10);
	insertBST(root, -3);
	insertBST(root, 8);
	insertBST(root, 12);
	insertBST(root, 36);
	insertBST(root, 18);
	insertBST(root, 22);
	Inorder(root);
	//for (;;);
	system("pause");
	return 0;


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
