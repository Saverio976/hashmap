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
        list_i->prev = new;
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
    if (node_i->next) {
        node_i->next->prev = node_i->prev;
    }
    if (node_i->prev) {
        node_i->prev->next = node_i->next;
    }
    tmp = node_i->next;
    free(node_i);
    if (list && *list == node) {
        if (tmp == node) {
            *list = NULL;
        } else {
            *list = tmp;
        }
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

int ll_clear(ll_t *list)
{
    size_t countor = 0;
    struct linkedlist *list_i = NULL;

    if (list == NULL || *list == NULL) {
        return countor;
    }
    list_i = *list;
    while (*list != NULL) {
        countor += ll_remove(list, list_i);
        list_i = *list;
    }
    return countor;
}

ll_node_t ll_at(ll_t list, size_t index)
{
    struct linkedlist *init_i = NULL;
    struct linkedlist *list_i = NULL;

    if (!list) {
        return NULL;
    }
    init_i = list;
    list_i = list;
    for (size_t i = 0; i < index; i++) {
        list_i = list_i->next;
        if (list_i == init_i) {
            return NULL;
        }
    }
    return list_i;
}

ll_node_t ll_next(ll_node_t node)
{
    struct linkedlist *node_i = NULL;

    if (!node) {
        return NULL;
    }
    node_i = node;
    return node_i->next;
}

ll_node_t ll_prev(ll_node_t node)
{
    struct linkedlist *node_i = NULL;

    if (!node) {
        return NULL;
    }
    node_i = node;
    return node_i->prev;
}

void ll_free(ll_t *list)
{
    ll_clear(list);
}
