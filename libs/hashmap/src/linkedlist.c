#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkedlist_internal.h"
#include "linkedlist.h"

ll_t ll_new(void)
{
    // yes, it is a double linkedlist, there is only nodes in it,
    // we lie to the user.
    // ll_append to null will point the list to the first created.
    return NULL;
}

ll_node_t ll_append(ll_t *list, void *data)
{
    struct linkedlist *list_i = NULL;
    struct linkedlist *new = NULL;

    // if the pointer on a ll_t is null.
    // the user will give us the pointer on the node pointer
    // so we can modify his value.
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
        // it is a new list
        new->prev = new;
        new->next = new;
        *list = new;
    } else {
        // append the node at the end
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
        return 0;
    }
    node_i = node;
    if (node_i->next) {
        // be sure to not crash if set to null (?)
        node_i->next->prev = node_i->prev;
    }
    if (node_i->prev) {
        // be sure to not crash if set to null (?)
        node_i->prev->next = node_i->next;
    }
    tmp = node_i->next;
    free(node_i);
    if (list && *list == node) {
        // if the value of the list in user is the one we remove
        if (tmp == node) {
            // if the next item is the one we remove (only one item in the list)
            *list = NULL;
        } else {
            // set to the next item
            *list = tmp;
        }
    }
    return 1;
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

int ll_assign(ll_node_t node, void *data)
{
    struct linkedlist *node_i = NULL;

    if (!node) {
        return 0;
    }
    node_i = node;
    node_i->data = data;
    return 1;
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
        // while there is at least one item, remove it.
        // this can potentialy do a endless loop if it can't remove (
        // I don't know why it would not remove)
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
        // ll_at need to iterate on all item until the index is found
        list_i = list_i->next;
        if (list_i == init_i) {
            // we looped back to the first element
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
    // only node in the list, if we remove all nodes,
    // nothing else need to be removed
    ll_clear(list);
}
