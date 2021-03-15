#include <iostream>

typedef struct Stack {
    int value;
    struct Stack *next;
} Stack;

void clear_stack(Stack **head)
{
    Stack *p_stack = *head;
    Stack *new_stack = NULL;
    while (p_stack != NULL){
        new_stack = p_stack->next;
        delete p_stack;
        p_stack = new_stack;
    }
    *head = NULL;
}

int pop(Stack ** head)
{
    Stack *p_stack = *head;
    Stack *new_stack = NULL;
    int value_delete = 0;
    if (p_stack->next == NULL) {
        value_delete = p_stack->value;
        delete p_stack;
        *head = NULL;
    }
    else {
        while (p_stack->next != NULL) {
            new_stack = p_stack;
            p_stack = p_stack->next;
        }
        value_delete = p_stack->value;
        delete p_stack;
        p_stack = new_stack;
        p_stack->next = NULL;
    }
    return value_delete;
}

void push(Stack ** head, int value)
{
    if (*head == NULL) {
        *head = new Stack;
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }

    Stack * p_stack = *head;
    while (p_stack->next != NULL) {
        p_stack = p_stack->next;
    }
    Stack * new_stack = new Stack;
    p_stack->next = new_stack;
    new_stack->value = value;
    new_stack->next = NULL;
}

void print_stack(Stack *head)
{
    Stack *p_stack = head;
    std::cout << "Stack: " << '\n';
    while (p_stack->next != NULL) {
        std::cout << p_stack->value << ' ';
        p_stack = p_stack->next;
    }
    std::cout << p_stack->value << ' ';
    std::cout << '\n';
}

int top(Stack ** head)
{
    Stack *p_stack = *head;
    int value_top = 0;
    while (p_stack->next != NULL)
        p_stack = p_stack->next;
    value_top = p_stack->value;
    return value_top;
}

int main()
{
    int value, last;
    int old_value;
    int lenght = 0;
    Stack * list = NULL;
    std::cout << "Enter list:" << '\n';
    std::cin >> value;
    while (value != 0) {
        push(&list, value);
        lenght += 1;
        std::cin >> value;
    }
    last = top(&list);
    std::cout << "Length stack: " << lenght << ", last value: " << last << '\n';
    print_stack(list);

    clear_stack(&list);
    std::cout << "Clear";
    return 0;
}

