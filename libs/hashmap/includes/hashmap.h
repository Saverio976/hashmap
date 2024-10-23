#ifndef HASHMAP_H_
    #define HASHMAP_H_

    #define HM_MAX_KEY_SIZE 254

    #include <stddef.h>

/*
 * Guide
 *
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "hash.h"
#include "hashmap.h"

int main(int ac, const char **av)
{
    int assigned = 0;
    hm_t map = NULL;
    hm_node_t node = NULL;
    const char *mflag = NULL;

    if (ac % 2 == 0) {
        printf("You need to pass a even number of parameters\n");
    }
    map = hm_new(100, djb2);
    if (map == NULL) {
        printf("Error when initializing map\n");
        return 1;
    }
    for (int i = 1; i < ac -1; i += 2) {
        node = hm_at(map, av[i]);
        if (node == NULL) {
            printf("the node for %s can't be created.\n", av[i]);
            continue;
        }
        assigned = hm_assign(node, (void *) av[i + 1]);
        if (assigned == 0) {
            printf("the value %s can't be assigned to node\n", av[i + 1]);
        }
    }
    mflag = hm_get(hm_at(map, "--myflag"));
    if (mflag && !strcmp(mflag, "1")) {
        printf("You have set '--myflag 1'\n");
    } else {
        printf("Try executing with the parameters: --myflag 1\n");
    }
    hm_free(&map);
    return 0;
}
 */

typedef void* hm_t;
typedef void* hm_node_t;
typedef size_t (*hash_fn_t)(const char *);

// Create a new hash map.
// Return: a new hash map.
hm_t hm_new(size_t capacity, hash_fn_t hash);

// Free all resources allocated for the map.
// Return: nothing.
void hm_free(hm_t *hm);

// Get the node for the key (created if it does not exist).
// !WARNING! Key can only be of max size HM_MAX_KEY_SIZE (without the \0)
// !WARNING! the characters left will be trucated.
// Return: the new node.
hm_node_t hm_at(hm_t hm, const char *key);

// Assign a value to the node.
// Return: 1: OK; 0: The value can't be modified.
int hm_assign(hm_node_t node, void *data);

// Get the data from a node.
// Return: the data.
void *hm_get(hm_node_t node);

// Get the key of a node.
// Return: the key.
const char *hm_key(hm_node_t node);

// Iterrate over all key / value of the map.
// Return: the next after the node.
hm_node_t hm_next(hm_t hm, hm_node_t node);

// Remove a node from the hash map.
// Return: number of node remove (1: OK; 0: BAD).
int hm_remove(hm_t hm, hm_node_t node);

// Remove all node from a map.
// Return: number of node removed.
int hm_clear(hm_t hm);

#endif
