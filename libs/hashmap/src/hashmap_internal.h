#ifndef HASHMAP_INTERNAL_H_
    #define HASHMAP_INTERNAL_H_

    #include <stddef.h>

    #include "linkedlist.h"
    #include "hashmap.h"

struct hashmap {
    size_t capacity;
    ll_t *array; // it is an array of list to handle collision in hash function (and % capacity)
    hash_fn_t hash;
};

struct hashmap_node {
    char key[HM_MAX_KEY_SIZE + 1];
    ll_node_t ll_node; // get the container where the node is
    size_t index;
    void *data;
};

#endif
