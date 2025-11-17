#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <iostream>
#include <string>
using namespace std;

//deklarasi isi data struct product
struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

struct Node {
    Product info;
    Node* next;
};

struct List {
    Node* head;
};

// Deklarasi fungsi
bool isEmpty(List L);
void createList(List &L);
Node* allocate(Product P);
void deallocate(Node* P);

void insertFirst(List &L, Product P);
void insertLast(List &L, Product P);
void insertAfter(List &L, Node* Q, Product P);

void deleteFirst(List &L, Product &P);
void deleteLast(List &L, Product &P);
void deleteAfter(List &L, Node* Q, Product &P);

void updateAtPosition(List &L, int posisi, Product P);
void viewList(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);

float finalPrice(Product P);

void MaxHargaAkhir(List L);

#endif