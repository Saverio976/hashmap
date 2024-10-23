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
