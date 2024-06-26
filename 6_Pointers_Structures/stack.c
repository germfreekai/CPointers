#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// info to pass
typedef struct _employee
{
    char name[32];
    unsigned char age;
}Employee;

// node to hold info
typedef struct _node
{
    void *data;
    struct _node *next;
}Node;

// struct of nodes
typedef struct _linkedList
{
    Node *head;
    Node *tail;
    Node *current;
}LinkedList;

// make user we know what a queue is
typedef LinkedList Queue;

// same for stack
typedef LinkedList Stack;

// pointer to functions
typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*, void*);

// Stack functions declarations
void initializeStack(Stack *stack);
void push(Stack *stack, void *data);
void *pop(Stack *stack);

// Queue functions declarations
void initializeQueue(Queue *queue);
void enqueue(Queue *queue, void *node);
void *dequeue(Queue *queue);

// Linked list functions declaration
void initializeList(LinkedList *list);
void addHead(LinkedList *list, void *data);
void addTail(LinkedList *list, void *data);
void delete(LinkedList *list, Node *node);
Node *getNode(LinkedList *list, COMPARE compare, void *data);
void displayLinkedList(LinkedList *list, DISPLAY display);

int compareEmployee(Employee *e1, Employee *e2)
{
    return strcmp(e1->name, e2->name);
}

int displayEmployee(Employee *employee)
{
    fprintf(stdout, "%s\t%d\n", employee->name, employee->age);
}

int main(void)
{
    Stack stack;
    initializeStack(&stack);

    Employee *samuel = (Employee*)malloc(sizeof(Employee));
    strcpy(samuel->name, "Samuel");
    samuel->age = 32;

    Employee *rene = (Employee*)malloc(sizeof(Employee));
    strcpy(rene->name, "Rene");
    rene->age = 26;

    Employee *nicky = (Employee*)malloc(sizeof(Employee));
    strcpy(nicky->name, "Nicky");
    nicky->age = 21;

    push(&stack, samuel);
    push(&stack, rene);
    push(&stack, nicky);

    Employee *employee;

    for (size_t i = 0; i < 3; i++)
    {
        employee = (Employee*) pop(&stack);
        fprintf(stdout, "Popped: %s\n", employee->name);
    }

    free(samuel);
    free(rene);
    free(nicky);

    return EXIT_SUCCESS;
}

void initializeList(LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void addHead(LinkedList *list, void *data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;

    if (list->head == NULL)
    {
        list->tail = node;
        node->next = NULL;
    }
    else
    {
        node->next = list->head;
    }
    list->head = node;
}

void addTail(LinkedList *list, void *data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        list->tail->next = node;
    }
    list->tail = node;
}

// Helper function to get node
Node *getNode(LinkedList *list, COMPARE compare, void *data)
{
    Node *node = list->head;
    while (node != NULL)
    {
        if (compare(node->data, data) == 0)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void delete(LinkedList *list, Node *node)
{
    if (node == list->head)
    {
        if (list->head->next == NULL)
        {
            list->head = list->tail = NULL;
        }
        else
        {
            list->head = list->head->next;
        }
    }
    else
    {
        Node *tmp = list->head;
        while (tmp != NULL && tmp->next != node)
        {
            tmp = tmp->next;
        }
        if (tmp != NULL)
        {
            tmp->next = node->next;
        }
    }
    free(node);
}

void displayLinkedList(LinkedList *list, DISPLAY display)
{
    fprintf(stdout, "LINKED LIST\n");
    Node *current = list->head;
    while (current != NULL)
    {
        display(current->data);
        current = current->next;
    }
}

// QUEUE functions
void initializeQueue(Queue *queue)
{
    initializeList(queue);
}
void enqueue(Queue *queue, void *node)
{
    addHead(queue, node);
}
void *dequeue(Queue *queue)
{
    Node *tmp = queue->head;
    void *data;
    
    if (queue->head == NULL)
    {
        data = NULL;
    }
    else if (queue->head == queue->tail)
    {
        queue->head = queue->tail = NULL;
        data = tmp->data;
        free(tmp);
    }
    else
    {
        while (tmp->next != queue->tail)
        {
            tmp = tmp->next;
        }
        queue->tail = tmp;
        tmp = tmp->next;
        queue->tail->next = NULL;
        data = tmp->data;
        free(tmp);
    }
    return data;
}

// STACK functions
void initializeStack(Stack *stack)
{
    initializeList(stack);
}
void push(Stack *stack, void *data)
{
    addHead(stack, data);
}
void *pop(Stack *stack)
{
    Node *node = stack->head;
    if (node == NULL)  // if stack is empty
    {
        return NULL;
    }
    else if (node == stack->tail)  // if just one element
    {
        stack->head = stack->tail->next;  // assing head to the next one
        void *data = node->data;
        free(node);
        return data;
    }
    else
    {
        stack->head = stack->head->next;
        void *data = node->data;
        free(node);
        return data;
    }
}
