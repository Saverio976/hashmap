#ifndef HASHMAP_INTERNAL_H_
    #define HASHMAP_INTERNAL_H_

    #include <stddef.h>

    #include "linkedlist.h"
    #include "hashmap.h"

struct hashmap {
    size_t capacity;
    ll_t *array;
    hash_fn_t hash;
};

struct hashmap_node {
    char key[HM_MAX_KEY_SIZE + 1];
    ll_node_t ll_node;
    size_t index;
    void *data;
};

#endif
