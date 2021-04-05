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

int pop_index(Stack ** head, int index)
{
    Stack *p_stack = *head;
    int value_delete = 0;
    if (p_stack != NULL) {
        Stack *new_stack = NULL;
        Stack *p_stack_1 = NULL;
        if (index == 0){
            new_stack = p_stack->next;
            value_delete = p_stack->value;
            delete p_stack;
            *head = new_stack;
        }
        else {
            for (int i = 1; i < index; i++)
                p_stack = p_stack->next;
            p_stack_1 = p_stack->next;
            if (p_stack_1 != NULL)
                new_stack = p_stack_1->next;
            else
                new_stack = NULL;
            value_delete = (p_stack->next)->value;
            delete p_stack->next;
            p_stack->next = new_stack;
        }
    }
    return value_delete;
}

void push(Stack ** head, int value, int index)
{
    if (*head == NULL) {
        *head = new Stack;
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }

    Stack *p_stack = *head;
    for (int i = 1; i < index; i++)
        p_stack = p_stack->next;
    Stack *new_stack = new Stack;
    Stack *new_stack_1 = p_stack->next;
    p_stack->next = new_stack;
    new_stack->next = new_stack_1;
    new_stack->value = value;
}

int main()
{
    int N;
    std::cin >> N;
    int value;
    char sign;
    int lenght = 0;
    int place = 0;
    int j = 0;
    int value_delete;
    int *value_delete_list = new int[N];
    for (int i = 0; i < N; i++)
        value_delete_list[i] = '0';
    Stack * list = NULL;
    while (j < N) {
        std::cin >> sign;
        if (sign == '+'){
            std::cin >> value;
            push(&list, value, lenght);
            lenght += 1;
        } else if (sign == '*'){
            std::cin >> value;
            if (lenght % 2 == 0)
                place = lenght / 2;
            else place = lenght / 2 + 1;
            push(&list, value, place);
            lenght += 1;
        } else if (sign == '-'){
            if (lenght != 0){
                value_delete = pop_index(&list, 0);
                value_delete_list[j] = value_delete;
                lenght--;
            }
        }
        j++;
    }
    for (int i = 0; i < N; i++)
        if (value_delete_list[i] != '0')
            std:: cout << value_delete_list[i] << '\n';

    clear_stack(&list);
    delete[] value_delete_list;
    return 0;
}
