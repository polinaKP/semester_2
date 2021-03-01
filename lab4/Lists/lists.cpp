#include <iostream>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push_left(Node ** head, int value)
{
    Node * p_node = *head;
    Node * new_node = new Node;
    *head = new Node;
    (*head)->value = value;

    if (*head == NULL) {
        (*head)->next = NULL;
        return;
    }
    else (*head)->next = p_node;
}

void clear_list(Node **head)
{
    Node *p_node = *head;
    Node *new_node = NULL;
    while (p_node != NULL){
        new_node = p_node->next;
        delete p_node;
        p_node = new_node;
    }
    *head = NULL;
}

int pop(Node ** head, int index)
{
    Node *p_node = *head;
    int value_delete = 0;
    if (p_node != NULL) {
        Node *new_node = NULL;
        Node *p_node_1 = NULL;
        if (index == 0){
            new_node = p_node->next;
            value_delete = p_node->value;
            delete p_node;
            *head = new_node;
        }
        else {
            for (int i = 1; i < index; i++)
                p_node = p_node->next;
            p_node_1 = p_node->next;
            if (p_node_1 != NULL)
                new_node = p_node_1->next;
            else
                new_node = NULL;
            value_delete = (p_node->next)->value;
            delete p_node->next;
            p_node->next = new_node;
        }
    }
    return value_delete;
}

void print_list(Node *head)
{
    Node *p_node = head;
    std::cout << "List: " << '\n';
    while (p_node->next != NULL) {
        std::cout << p_node->value << ' ';
        p_node = p_node->next;
    }
    std::cout << p_node->value << ' ';
    std::cout << '\n';
}

void remove(Node ** head, int value)
{
    Node *p_node = *head;
    if (p_node != NULL) {
        Node *new_node = NULL;
        Node *p_node_1 = NULL;
        if (p_node->value == value){
            new_node = p_node->next;
            delete p_node;
            *head = new_node;
        }
        else {
            while ((p_node->next)->value != value)
                p_node = p_node->next;
            p_node_1 = p_node->next;
            if (p_node_1 != NULL)
                new_node = p_node_1->next;
            else
                new_node = NULL;
            delete p_node->next;
            p_node->next = new_node;
        }
    }
}

void remove_all(Node ** head, int value)
{
    Node *p_node = *head;
    if (p_node != NULL) {
        Node *new_node = NULL;
        Node *p_node_1 = NULL;
        while(p_node->value == value){
            new_node = p_node->next;
            delete p_node;
            *head = new_node;
            p_node = *head;
        }
        while (p_node->next != NULL) {
            if ((p_node->next)->value == value) {
                p_node_1 = p_node->next;
                if (p_node_1 != NULL)
                    new_node = p_node_1->next;
                else
                    new_node = NULL;
                delete p_node->next;
                p_node->next = new_node;
            }
            else p_node = p_node->next;
        }
    }
}

void replace_all(Node *head, int old_value, int new_value)
{
    Node *p_node = head;
    if (p_node != NULL) {
        while (p_node->next != NULL){
            if (p_node->value == old_value)
                p_node->value = new_value;
            p_node = p_node->next;
        }
        if (p_node->value == old_value)
                p_node->value = new_value;
    }
}

int main(int argc, char const *argv[])
{
    int value,amount;
    Node * list = NULL;
    std::cout << "Enter list size: ";
    std::cin >> amount;
    std::cout << "Enter list:" << '\n';
    for (int i = 1; i <= amount; ++i) {
        std::cin >> value;
        push_left(&list, value);
    }
    print_list(list);

    std::cout << "Enter index to remove: ";
    int index;
    std::cin >> index;
    int value_delete = pop(&list, index - 1);
    print_list(list);

    std::cout << "Enter value to remove: ";
    std::cin >> value;
    remove(&list, value);
    print_list(list);

    std::cout << "Enter value to remove all: ";
    int value_all;
    std::cin >> value_all;
    remove_all(&list, value_all);
    print_list(list);

    std::cout << "Enter old and new value to replace all: ";
    int old_value, new_value;
    std::cin >> old_value >> new_value;
    replace_all(list, old_value, new_value);
    print_list(list);

    //std::cout << "Unique: " << unique(list) << '\n';

    clear_list(&list);
    std::cout << "Clear";
    return 0;
}

