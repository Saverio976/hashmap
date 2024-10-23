#ifndef HASHMAP_H_
    #define HASHMAP_H_

    #define HM_MAX_KEY_SIZE 254

    #include <stddef.h>

typedef void* hm_t;
typedef void* hm_node_t;
typedef size_t (*hash_fn_t)(const char*);

// Create a new hash map.
// Return: a new hash map.
hm_t hm_new(size_t capacity, hash_fn_t hash);

// Free all resources allocated for the map.
// Return: nothing.
void hm_free(hm_t *hm);

// Get the node for the key (created if it does not exist).
// Return: the new node.
hm_node_t hm_at(hm_t hm, const char key[HM_MAX_KEY_SIZE]);

// Assign a value to the node.
// Return: 1: OK; 0: The value can't be modified.
int hm_assign(hm_node_t node, void *data);

// Get the data from a node.
// Return: the data.
void *hm_get(hm_node_t node);

// Remove a node from the hash map.
// Return: number of node remove (1: OK; 0: BAD).
int hm_remove(hm_t hm, hm_node_t node);

// Remove all node from a map.
// Return: number of node removed.
int hm_clear(hm_t hm);

#endif
