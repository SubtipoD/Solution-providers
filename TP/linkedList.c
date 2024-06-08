#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next_node;
} node;

typedef struct linked_list {
    node *head;
    node *tail;
} linked_list;

node* new_node(int);

linked_list* new_linked_list();
void append(linked_list*, int);
void preppend(linked_list*, int);
void print_linked_list(linked_list*);
void delete_first(linked_list*);
void delete_last(linked_list*);
void delete_node(linked_list*, int);


node* new_node(int data)
{
    node* n      = malloc(sizeof(node*));
    n->data      = data;
    n->next_node = NULL;
    return n;
}

linked_list* new_linked_list()
{
    linked_list *ll = malloc(sizeof(linked_list*));
    ll->head = NULL;
    ll->tail = NULL;
    return ll;
}

int is_empty(linked_list* ll) {
    return ll->head == NULL;
}

// Appends node to linked list
void append(linked_list* ll, int data)
{
    node *n = new_node(data);
    if (is_empty(ll)) {
        ll->head = n;
        ll->tail = n;

        return;
    }
    
    ll->tail->next_node = n;
    ll->tail = n;
}

// Preppends node to linked list
void preppend(linked_list* ll, int data)
{
    node *n = new_node(data);
    if (is_empty(ll)) {
        ll->head = n;
        ll->tail = n;
        
        return;
    }

    n->next_node = ll->head;
    ll->head = n;
}

void delete_first(linked_list* ll)
{
    if (is_empty(ll)) {
        return;
    }

    node *new_head = ll->head->next_node;
    free(ll->head);
    ll->head = new_head;

    if (is_empty(ll)) {
        ll->tail = NULL;
    }
}

void delete_last(linked_list* ll)
{
    if (is_empty(ll)) { // la lista esta vacia
        return;
    }

    if (ll->head == ll->tail) { // la lista tiene un solo nodo
        ll->head = NULL;
        ll->tail = NULL;
        return;
    }

    node *current_node = ll->head;

    while (current_node->next_node != ll->tail) {   // termina cuando current_node sea el anteultimo nodo, por lo que su siguiente es tail
        current_node = current_node->next_node;
    }

    node *node_to_delete = current_node->next_node;
    ll->tail = current_node;
    free(node_to_delete);   // librar la memoria que ocupaba el nodo que era el ultimo
    current_node->next_node = NULL; // setear el next del ultimo nodo de la lista a NULL para que termine ahi, sino desborda todo
}

void delete_node(linked_list* ll, int data)
{
    // Lista vacia
    if (is_empty(ll)) {
        return;
    }

    // Caso especial borrar el primer elemento
    if (ll->head->data == data) {
        delete_first(ll);
        return;
    }

    // El nodo que hay que borrar no esta en la head ni en la tail
    node *n = ll->head;
    while(n->next_node != NULL) {
        if (n->next_node->data == data) {   // hay que borrar el next del nodo actual
           // n = nodo actual
            node *node_to_delete = n->next_node;
            if (n->next_node == ll->tail) {
                ll->tail = n;
                free(node_to_delete);
                ll->tail->next_node = NULL;
                
                return;
            }

            node *new_next_node = n->next_node->next_node;
            free(node_to_delete);
            n->next_node = new_next_node;

            return;           
        }

        n = n->next_node;
    }
}

void print_linked_list(linked_list *ll)
{
    node* n = ll->head;
    
    printf("{ ");
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next_node;
    }
    printf("}");
}