#ifndef HASHMAP_INTERNAL_H_LINKEDLIST_H_
    #define HASHMAP_INTERNAL_H_LINKEDLIST_H_

struct linkedlist {
    void *data;
    struct linkedlist *prev;
    struct linkedlist *next;
};

#endif
