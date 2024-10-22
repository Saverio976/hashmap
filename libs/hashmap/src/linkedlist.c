#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkedlist_internal.h"
#include "linkedlist.h"

ll_t ll_new(void)
{
    return NULL;
}

ll_node_t ll_append(ll_t *list, void *data)
{
    struct linkedlist *list_i = NULL;
    struct linkedlist *new = NULL;

    if (!list) {
        return NULL;
    }
    list_i = *list;
    new = malloc(sizeof(struct linkedlist) * 1);
    if (!new) {
        return NULL;
    }
    new->data = data;
    if (!list_i) {
        new->prev = new;
        new->next = new;
        *list = new;
    } else {
        new->prev = list_i->prev;
        new->next = list_i;
        list_i->prev->next = new;
    }
    return new;
}

int ll_remove(ll_t *list, ll_node_t node)
{
    struct linkedlist *tmp = NULL;
    struct linkedlist *node_i = NULL;

    if (!node) {
        return 1;
    }
    node_i = node;
    tmp = node_i->next;
    if (node_i->next) {
        node_i->next->prev = node_i->prev;
    }
    if (node_i->prev) {
        node_i->prev->next = tmp;
    }
    free(node_i);
    if (list && *list == node) {
        *list = NULL;
    }
    return 0;
}

void *ll_get(ll_node_t node)
{
    struct linkedlist *node_i = NULL;

    if (!node) {
        return NULL;
    }
    node_i = node;
    return node_i->data;
}
