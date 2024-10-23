#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#include "hashmap_internal.h"
#include "linkedlist.h"
#include "hashmap.h"

hm_t hm_new(size_t capacity, hash_fn_t hash)
{
    struct hashmap *hm = NULL;

    hm = malloc(sizeof(struct hashmap) * 1);
    if (hm == NULL) {
        return NULL;
    }
    hm->array = malloc(sizeof(ll_t) * capacity);
    if (hm->array == NULL) {
        free(hm);
        return NULL;
    }
    for (size_t i = 0; i < capacity; i++) {
        hm->array[i] = ll_new();
    }
    hm->capacity = capacity;
    hm->hash = hash;
    return hm;
}

void hm_free(hm_t *hm)
{
    struct hashmap *hm_i = NULL;

    if (!hm) {
        return;
    }
    hm_i = *hm;
    hm_clear(hm_i);
    for (size_t i = 0; i < hm_i->capacity; i++) {
        ll_free(hm_i->array + i);
    }
    free(hm_i->array);
    free(hm_i);
    *hm = NULL;
}

hm_node_t hm_at(hm_t hm, const char key[HM_MAX_KEY_SIZE])
{
    size_t index = 0;
    struct hashmap *hm_i = NULL;
    ll_node_t node_cursor = NULL;
    ll_node_t node_init = NULL;
    struct hashmap_node *node_i = NULL;
    char key1[HM_MAX_KEY_SIZE + 1] = {0};

    if (hm == NULL) {
        return NULL;
    }
    hm_i = hm;
    strncpy(key1, key, HM_MAX_KEY_SIZE);
    index = hm_i->hash(key1) % hm_i->capacity;
    // Find if exist
    node_init = ll_at(hm_i->array + index, 0);
    if (node_init == NULL) {
        return NULL;
    }
    node_cursor = node_init;
    do {
        node_i = ll_get(node_cursor);
        if (node_i != NULL && strcmp(node_i->key, key1)) {
            return node_i;
        }
        node_cursor = ll_next(node_cursor);
    } while (node_cursor != node_init && node_cursor != NULL);
    // Create if not exist
    node_i = malloc(sizeof(struct hashmap_node) * 1);
    if (node_i == NULL) {
        return NULL;
    }
    strncpy(node_i->key, key, HM_MAX_KEY_SIZE);
    node_i->key[HM_MAX_KEY_SIZE] = '\0';
    node_i->index = index;
    node_i->data = NULL;
    ll_node_t node = ll_append(hm_i->array + index, node_i);
    if (node == NULL) {
        free(node_i);
        return NULL;
    }
    node_i->ll_node = node;
    return node_i;
}

int hm_assign(hm_node_t node, void *data)
{
    struct hashmap_node *node_i = NULL;

    if (node == NULL) {
        return 0;
    }
    node_i = node;
    node_i->data = data;
    return 1;
}

void *hm_get(hm_node_t node)
{
    struct hashmap_node *node_i = NULL;

    if (node == NULL) {
        return NULL;
    }
    node_i = node;
    return node_i->data;
}

int hm_remove(hm_t hm, hm_node_t node)
{
    struct hashmap *hm_i = NULL;
    struct hashmap_node *node_i = NULL;

    if (node == NULL || hm == NULL) {
        return 0;
    }
    hm_i = hm;
    node_i = node;
    if (ll_remove(hm_i->array + node_i->index, node_i->ll_node) != 1) {
        return 0;
    }
    free(node_i);
    return 1;
}

int hm_clear(hm_t hm)
{
    size_t countor = 0;
    struct hashmap *hm_i = NULL;
    struct hashmap_node *node_i = NULL;
    ll_node_t node_cursor = NULL;

    if (hm == NULL) {
        return 0;
    }
    hm_i = hm;
    for (size_t i = 0; i < hm_i->capacity; i++) {
        for (node_cursor = ll_at(hm_i->array + i, 0); \
                node_cursor != NULL; \
                node_cursor = ll_at(hm_i->array + i, 0)) {
            node_i = ll_get(node_cursor);
            countor += hm_remove(hm_i, node_i);
        }
        ll_clear(hm_i->array + i);
    }
    return countor;
}
