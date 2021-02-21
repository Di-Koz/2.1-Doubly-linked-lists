#include <iostream>
#include <string>
#include "func.h"
using namespace std;

int main() {
    node* cur = create_list(5);
    printList(cur);
    cout << endl;
    push_front(cur, "num0");
    //push_back(cur, "num0");
    //delete_list(cur);
    //pop_front(cur);
    //pop_back(cur);
    //delete_elem(cur, "num4");
    //insert_elem(cur, "num0", "num1", 0);
    //insert_elem(cur, "num0", "num1", 1);
    //string mas[5] = {"num56", "num3", "num78", "num12", "num13"};
    //cur = insert_arr(mas, 5);
    //swap(cur, "num1", "num4");
    printList(cur);
}
