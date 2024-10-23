#include "hash.h"
#include "hashmap.h"

int test1(void)
{
    hm_t hm = hm_new(10, djb2);
    hm_node_t node = hm_at(hm, "ok");
    hm_assign(node, (void *) 5);
    hm_free(&hm);
    return 0;
}

int test2(void)
{
    hm_t hm = hm_new(10, djb2);
    hm_node_t node1 = hm_at(hm, "ok");
    hm_assign(node1, (void *) 5);
    hm_node_t node2 = hm_at(hm, "ok1");
    hm_assign(node2, (void *) 6);
    hm_remove(hm, hm_at(hm, "ok"));
    hm_at(hm, "ok");
    hm_free(&hm);
    return 0;
}

int test3(void)
{
    size_t res[3] = {5, 6, 7};
    hm_t hm = hm_new(10, djb2);
    hm_node_t node1 = hm_at(hm, "ok");
    hm_assign(node1, (void *) res[0]);
    hm_node_t node2 = hm_at(hm, "ok1");
    hm_assign(node2, (void *) res[1]);
    hm_node_t node3 = hm_at(hm, "ok2");
    hm_assign(node3, (void *) res[2]);
    int i = 0;
    for (hm_node_t cursor = hm_next(hm, NULL); \
            cursor != NULL; \
            cursor = hm_next(hm, cursor)) {
        if (hm_get(cursor) != (void *) res[i]) {
            hm_assign(cursor, (void *) res[i]);
        }
        i++;
    }
    hm_free(&hm);
    return 0;
}

int main(void)
{
    test1();
    test2();
    test3();
}
