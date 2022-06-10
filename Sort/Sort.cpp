// Sort.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <algorithm>
using namespace std;
/*
int swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    return a;
    return b;
}*/
void swapInt(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int* arr, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[j+1] < arr[j]) swap(arr[j+1], arr[j]);
        }
    }
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void QuickSort(int* arr, int low, int high) {
    if (low >= high) return;
    int p = partition(arr, low, high);
    QuickSort(arr, low, p - 1);
    QuickSort(arr, p + 1, high);    
}
void selectSort(int* arr, int size) {
    int min;
    for (int j = 0; j < size - 1; j++) {
        min = j;
        for (int i = j + 1; i < size; i++) {
            if (arr[min] < arr[i]) min = i;
        }
        if(min != j)
        swap (arr[j], arr[min]);
    }
}
void Merge(int* arr, int L, int M, int R) {
    int extraArr[] = { 0 };
    for (int i = L; i <= R; i++) {
        extraArr[i] = arr[i];
    }
    int finger1 = L;
    int finger2 = M + 1;
    int current = L;
    while (finger1 <= M && finger2 <= R) {
        if (extraArr[finger1] <= extraArr[finger2]) {
            arr[current] = extraArr[finger1];
            finger1++;
        }
        else {
            arr[current] = extraArr[finger2];
            finger2++;
        }
        current++;
    }
    while (finger1 <= M) {
        arr[current] = extraArr[finger1];
        current++;
        finger1++;
    }
}

void mergeSort(int* arr, int lIndex, int rIndex) {
    if (lIndex < rIndex) {
        int middle = (lIndex + rIndex) / 2;
        mergeSort(arr, lIndex, middle);
        mergeSort(arr, middle + 1, rIndex);
        Merge(arr, lIndex, middle, rIndex);
    }
}

int gapFun(int size) {
    int gap;
    if (size == 9 || size == 10) gap = 11;
    else
        gap = size / 1.3;
    return gap;
}


void combSort(int* arr, int size) {
    int gap = gapFun(size);
    while (gap > 1) {
        for (int i = 0; i < size - gap; i++) {
            if (arr[i + gap] < arr[i]) swap(arr[i], arr[i + gap]);
    }
        gap = gapFun(gap);
    }
    BubbleSort(arr, size-1);
}



int main()
{
    cout << "Hello World!\n";
    int a = 2;
    int b = 4;
    cout << "a = " << a << " b = " << b << endl;
    swap(a, b);
    cout << "a = " << a << " b = " << b << endl;
    int arr[] = { 7, 10, 12, 8, 4, 3, 0, 1, 24, 19 }; 
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size);
    //BubbleSort(arr, size-1);
    //QuickSort(arr, 0, size-1);
    //selectSort(arr, size);
    //mergeSort(arr, 0, size - 1);
    combSort(arr, size);
    printArr(arr, size);
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
