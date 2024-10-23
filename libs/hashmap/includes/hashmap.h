#ifndef HASHMAP_H_
    #define HASHMAP_H_

    #define HM_MAX_KEY_SIZE 254

    #include <stddef.h>

typedef void* hm_t;
typedef void* hm_node_t;
typedef size_t (*hash_fn_t)(const char*);

// Create a new hash map.
// Return: a new hash map
hm_t hm_new(size_t capacity, hash_fn_t hash);

// Free all resources allocated for the map.
// Return: nothing
void hm_free(hm_t *hm)


#endif
