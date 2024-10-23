#include <string.h>
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
    int res_len = 4;
    size_t res[4] = {5, 6, 7, 9};
    char res_key[4][20] = {"ok", "ok1", "ok2", "password"};
    int tmp_i = 0;
    hm_t hm = hm_new(10, djb2);

    for (int i = 0; i < res_len; i++) {
        hm_node_t node = hm_at(hm, res_key[i]);
        hm_assign(node, (void *) res[i]);
    }
    int countor = 0;
    for (hm_node_t cursor = hm_next(hm, NULL); \
            cursor != NULL; \
            cursor = hm_next(hm, cursor)) {
        for (int i = 0; i < res_len; i++) {
            if (!strcmp(hm_key(cursor), res_key[i])) {
                tmp_i = i;
            }
        }
        hm_assign(cursor, (void *) res[tmp_i]);
        countor++;
    }
    res_len = countor;
    for (int i = 0; i < res_len; i++) {
        countor += res[i];
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
