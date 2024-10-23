#ifndef HASHMAP_H_LINKEDLIST_H_
    #define HASHMAP_H_LINKEDLIST_H_

    #include <stddef.h>

typedef void* ll_t;
typedef void* ll_node_t;

// Create a new linked list.
// Return: a new linked list.
ll_t ll_new(void);

// Free all resources allocated for the list.
// Return: nothing.
void ll_free(ll_t *list);

// Create a new node and append it to the last item of the linked list.
// Return: the new node.
ll_node_t ll_append(ll_t *list, void *data);

// Remove a node from the linked list.
// Return: number of node removed (1: OK; 0: BAD).
int ll_remove(ll_t *list, ll_node_t node);

// Get the data from a node.
// Return: the data.
void *ll_get(ll_node_t node);

// Assign a value to the node
// Return: 1: OK; 0: The value can't be modified.
int ll_assign(ll_node_t node, void *data);

// Remove all node from a list.
// Return: number of node removed.
int ll_clear(ll_t *list);

// Get node at index.
// Return: the node.
ll_node_t ll_at(ll_t list, size_t index);

// Get next node.
// Return: next node.
ll_node_t ll_next(ll_node_t node);

// Get prev node.
// Return: prev node.
ll_node_t ll_prev(ll_node_t node);

#endif
