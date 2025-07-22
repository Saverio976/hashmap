# Systems Programming

__Problem__: HashMap

The hashmap is put on a separate folder distributed as a static library.

__Implementation__: [./libs/hashmap](./libs/hashmap/)

## Dependencies

- `nasm`
- C compiler

## API

- HashMap : [./libs/hashmap/includes/hashmap.h](./libs/hashmap/includes/hashmap.h)

- HashFunction : [./libs/hashmap/includes/hash.h](./libs/hashmap/includes/hash.h)

## Example

1. [./src/main.c](./src/main.c)

2. Create/Assign/Get/Delete:

```c
#include "hash.h"
#include "hashmap.h"

int main(int ac, char **av)
{
    hm_t map = NULL;
    hm_node_t node = NULL;
    int result = 0;

    map = hm_new(100, &djb2); // Create. The hash function is specified.
    if (map == NULL) { return 1; }
    node = hm_at(map, "foo"); // Access. It will create the node because it does not exist yet.
    if (node == NULL) { hm_free(&map); return 1; }
    result = hm_assign(node, (void *) &(av[0])); // Assign value to node. The pointer is not 'owned'.
    if (result == 0) { hm_free(&map); return 1; }
    node = hm_at(map, "foo"); // Access. It will only retrieve the node.
    if (node == NULL) { hm_free(&map); return 1; }
    char *value = hm_get(node); // Get the value of the node.
    //
    hm_free(&map); // Cleanup.
    return 0;
}
```
