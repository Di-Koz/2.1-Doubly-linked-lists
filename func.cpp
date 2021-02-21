#include <iostream>
#include <string>
#include "func.h"
using namespace std;

node* create_list(int size) {
    if (size <= 0) {
        return 0;
    }
    else {
        node* first = new node;
        first = nullptr;

        for (int i = 0; i < size; ++i) {
            push_back(first, "num" + to_string(i + 1));
        }

        return first;
    }
}

void printList(node *&first) {
    node* copyFirst = first;

    if (copyFirst != nullptr) {
        for (copyFirst; copyFirst->nextNode != nullptr; copyFirst = copyFirst->nextNode) {
            cout << copyFirst->name << " ";
        }

        cout << copyFirst->name << endl;
    }
    
    for (copyFirst; copyFirst != nullptr; copyFirst = copyFirst->prevNode) {
        cout << copyFirst->name << " ";
    }
}

void push_front(node *&first, string value) {
    node* elem = new node;
    elem->name = value;

    if (first != nullptr) {
        first->prevNode = elem;
    }

    elem->nextNode = first;
    elem->prevNode = nullptr;

    first = elem;
}

void push_back(node *&first, string value) {
    node* elem = new node;
    elem->name = value;

    if (first == nullptr) {
        first = elem;
        first->nextNode = nullptr;
        first->prevNode = nullptr;
    }
    else {
        node* copyFirst = first;

        while (copyFirst->nextNode != nullptr) {
            copyFirst = copyFirst->nextNode;
        }

        copyFirst->nextNode = elem;

        elem->nextNode = nullptr;
        elem->prevNode = copyFirst;
    }
}
//
void delete_list(node *&first) {
    node* temp = first;

    while (first != nullptr) {
        temp = first;
        first = first->nextNode;
        delete temp;
        temp = nullptr;
    }

    delete first;
}

void pop_front(node *&first) {
    if (first == nullptr) {
        return;
    }
    else {
        node* copyFirst = first;

        first = first->nextNode;
        
        if (first != nullptr) {
            first->prevNode = nullptr;
        }
        else {
            delete first;
        }
        
        delete copyFirst;
        copyFirst = nullptr;
    }
}

void pop_back(node *&first) {
    if (first == nullptr) {
        return;
    }
    else {
        if (first->nextNode == nullptr) {
            delete first;
            first = nullptr;
        }
        else {
            node* copyFirst = first;

            while (copyFirst->nextNode->nextNode != nullptr) {
                copyFirst = copyFirst->nextNode;
            }

            copyFirst->nextNode = nullptr;
            delete copyFirst->nextNode;
        }
    }
}

void delete_elem(node *&first, string param) {
    if (first == nullptr) {
        return;
    }
    else {
        if (first->name == param) {
            pop_front(first);
        }
        else {
            node* copyFirst = first;

            while ((copyFirst->nextNode != nullptr) && (copyFirst->nextNode->name != param)) {
                copyFirst = copyFirst->nextNode;
            }

            if (copyFirst->nextNode == nullptr) {
                return;
            }

            node* deleteElem = copyFirst->nextNode;
            copyFirst->nextNode = deleteElem->nextNode;

            if (deleteElem->nextNode != nullptr) {
                deleteElem->nextNode->prevNode = copyFirst;
            }
           
            delete deleteElem;
            deleteElem = nullptr;
        }
    }
}

void insert_elem(node *&first, string value, string param, int mode) {
    if (first == nullptr) {
        return;
    }
    else {
        node* elem = new node;
        elem->name = value;

        node* copyFirst = first;

        if (mode == 1) {
            while ((copyFirst->nextNode != nullptr) && (copyFirst->name != param)) {
                copyFirst = copyFirst->nextNode;
            }

            if ((copyFirst->name == param) && (copyFirst->nextNode == nullptr)) {
                push_back(first, value);
            }
            else {
                if (copyFirst->nextNode == nullptr) {
                    return;
                }

                elem->nextNode = copyFirst->nextNode;
                elem->prevNode = copyFirst;

                copyFirst->nextNode = elem;
                elem->nextNode->prevNode = elem;
            }
        }
        else if (mode == 0) {
            if (first->name == param) {
                push_front(first, value);
            }
            else {
                while ((copyFirst->nextNode != nullptr) && (copyFirst->nextNode->name != param)) {
                    copyFirst = copyFirst->nextNode;
                }

                if (copyFirst->nextNode == nullptr) {
                    return;
                }

                elem->nextNode = copyFirst->nextNode;
                elem->prevNode = copyFirst;

                copyFirst->nextNode = elem;
                elem->nextNode->prevNode = elem;
            }
        }
    }
}

node* insert_arr(string* arr, int size) {
    node* first = new node;
    node* copyFirst = first;

    for (int i = 0; i < size; ++i) {
        first->name = arr[i];

        if (i == size - 1) {
            first->nextNode = nullptr;
        }
        else {
            node* nextElem = new node;
            first->nextNode = nextElem;

            if (i == 0) {
                first->prevNode = nullptr;
            }

            nextElem->prevNode = first;
            first = nextElem;
        }
    }

    return copyFirst;
}

void swap(node*& first, string param1, string param2) {
    if (param1 == param2) {
        return;
    }
    else {
        node* copyFirst = first;
        node* elem1 = new node, * elem2 = new node;
        elem1 = elem2 = nullptr;
        bool findFirst = false;
        //сложное определение какой эл-нт идет первым в списке
        while ((copyFirst != nullptr) && (!findFirst)) {
            if (copyFirst->name == param1) {
                for (node* temp = copyFirst->nextNode; temp != nullptr; temp = temp->nextNode) {
                    if (temp->name == param2) {
                        elem1 = copyFirst;
                        elem2 = temp;
                        findFirst = true;
                        break;
                    }
                }
                //если до сих пор не нашли
                if (!findFirst) {
                    elem2 = copyFirst;
                    for (node* temp = copyFirst->prevNode; temp != nullptr; temp = temp->prevNode) {
                        if (temp->name == param2) {
                            elem1 = temp;
                            findFirst = true;
                            break;
                        }
                    }
                }
            }
            copyFirst = copyFirst->nextNode;
        }
        //если не нашли какой-либо эл-нт
        if ((elem1 == nullptr) || (elem2 == nullptr)) {
            return;
        }
        else {
            cout << elem1->name << endl << elem2->name << endl;

            node* tempEl1Next = new node, * tempEl2Prev = new node,
                * tempEl1Prev = new node, * tempEl2Next = new node;

            tempEl1Next = elem1->nextNode;
            tempEl2Prev = elem2->prevNode;

            tempEl1Prev = elem1->prevNode;
            tempEl2Next = elem2->nextNode;

            elem1->nextNode = elem2->nextNode;

            //если эл-ты соседние
            if (tempEl1Next == elem2) {
                elem1->prevNode = elem2;
            }
            else {
                elem1->prevNode = elem2->prevNode;
            }
            //если эл-ты соседние
            if (tempEl2Prev == elem1) {
                elem2->nextNode = elem1;
            }
            else {
                elem2->nextNode = tempEl1Next;
            }

            elem2->prevNode = tempEl1Prev;

            //если меняем с первым эл-ом
            if (tempEl1Prev == nullptr) {
                first = elem2;
            }
            else {
                tempEl1Prev->nextNode = elem2;
            }

            //если меняем не с последним эл-ом
            if (tempEl2Next != nullptr) {
                tempEl2Next->prevNode = elem1;
            }

            //если эл-ты не соседние
            if (tempEl1Next != elem2) {
                tempEl1Next->prevNode = elem2;
                tempEl2Prev->nextNode = elem1;
            }
        }
    }
}