#include <stdio.h>
#include <stdlib.h>
#include "linked list.c"


int main()
{
    linked_list *ll = new_linked_list();
    // append(ll, 1);
    
    print_linked_list(ll);
    printf("\n");
    
    append(ll, 2);
    append(ll, 3);
    print_linked_list(ll);
    preppend(ll, 4);
    printf("\n");
    print_linked_list(ll);
    
    
    printf("\n");
    print_linked_list(ll);

    delete_last(ll);

    printf("\n");
    print_linked_list(ll);
    

    int n = 1;
    delete_node(ll, n);

    printf("\nAFTER DELETE NODE WITH %d\n", n);

    print_linked_list(ll);
    
    return 0;
}
