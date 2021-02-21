#include <iostream>
#include <string>
using namespace std;

struct node {
    string name;
    node* prevNode;
    node* nextNode;
};

#ifndef FUNC_H
#define FUNC_H
node *create_list(int size);
void printList(node *&first);

void push_front(node *&first, string value);
void push_back(node *&first, string value);
void delete_list(node *&first);
void pop_front(node *&first);
void pop_back(node *&first);
void delete_elem(node *&first, string param);
void insert_elem(node *&first, string value, string param, int mode);
node* insert_arr(string* arr, int size);
void swap(node *&first, string param1, string param2);
#endif