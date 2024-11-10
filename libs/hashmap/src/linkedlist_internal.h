#ifndef HASHMAP_INTERNAL_H_LINKEDLIST_H_
    #define HASHMAP_INTERNAL_H_LINKEDLIST_H_

    #include "linkedlist.h"

struct linkedlist {
    void *data;
    struct linkedlist *prev;
    struct linkedlist *next;
};

ll_node_t ll_at_c(ll_t list, size_t index);

#endif
