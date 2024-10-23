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

int main(void)
{
    test1();
    test2();
}
