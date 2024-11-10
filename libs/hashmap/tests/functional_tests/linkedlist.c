#include <stddef.h>

#include "linkedlist.h"

int test1(void)
{
    ll_t list = ll_new();
    ll_append(&list, (void *) 1);
    ll_append(&list, (void *) 3);
    ll_append(&list, (void *) 5);
    ll_clear(&list);
    return 0;
}

int test2(void)
{
    ll_t list = ll_new();
    ll_node_t node1 = NULL;
    ll_node_t node2 = NULL;
    ll_node_t node3 = NULL;

    list = ll_new();
    node1 = ll_append(&list, (void *) 1);
    node2 = ll_append(&list, (void *) 3);
    node3 = ll_append(&list, (void *) 5);
    ll_remove(&list, node2);
    ll_remove(&list, node1);
    ll_remove(&list, node3);
    return 0;
}

int test3(void)
{
    ll_t list = ll_new();
    ll_append(&list, (void *) 1);
    ll_append(&list, (void *) 3);
    ll_append(&list, (void *) 5);
    ll_assign(ll_at(list, 0), (void *) 10);
    ll_clear(&list);
    return 0;
}

int test4(void)
{
    ll_t list = ll_new();
    ll_append(&list, (void *) 1);
    void *abc = ll_at(list, 0);
    abc = (void *) (((char *) abc) + 1);
    return 0;
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();
}
