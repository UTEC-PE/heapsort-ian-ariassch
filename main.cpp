#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>

using namespace std;

#define MIN 100
#define MAX 500

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapsortmax(int* array, size_t size);
bool validate(int* array, size_t size);

void heapifymax(int array[], size_t size, int i)
{
    int mayor = i;
    int izq = 2*i + 1;
    int der = 2*i + 2;

    if (izq < size && array[izq] > array[mayor])
        mayor = izq;

    if (der < size && array[der] > array[mayor])
        mayor = der;


    if (mayor != i)
    {
        swap(array[i], array[mayor]);
        heapifymax(array, size, mayor);
    }

}


int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    int *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }

    printArray(numbers, numberOfElements);
    cout << endl;
    heapsortmax(numbers, numberOfElements);
    cout << endl;
    printArray(numbers, numberOfElements);
    cout << endl;
    assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");
    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max); 
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void heapsortmax(int* array, size_t size){
    for (int i = size / 2 - 1; i >= 0; i--)
        heapifymax(array, size, i);

    for (int i=size-1; i>=0; i--)
    {
        swap(array[0], array[i]);
        heapifymax(array, i, 0);
    }
};


bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}