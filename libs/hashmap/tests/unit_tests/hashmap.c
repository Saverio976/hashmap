#include <criterion/criterion.h>
#include <criterion/assert.h>

#include "hash.h"
#include "hashmap.h"

Test(hm_new, basic) {
    cr_assert_not_null(hm_new(10, djb2));
    cr_assert_not_null(hm_new(5, djb2));
}

Test(hm_at, to_empty_map) {
    hm_t hm = hm_new(10, djb2);
    hm_node_t node = hm_at(hm, "ok");
    cr_assert_not_null(node);
    hm_assign(node, (void *) 5);
    cr_assert_eq(hm_get(node), (void *) 5);
    hm_free(&hm);
    cr_assert_null(hm);
}

Test(hm_at, multiple) {
    hm_t hm = hm_new(10, djb2);
    hm_node_t node1 = hm_at(hm, "ok");
    cr_assert_not_null(node1);
    hm_assign(node1, (void *) 5);
    cr_assert_eq(hm_get(node1), (void *) 5);
    cr_assert_eq(hm_get(hm_at(hm, "ok")), (void *) 5);
    hm_node_t node2 = hm_at(hm, "ok1");
    cr_assert_not_null(node1);
    hm_assign(node2, (void *) 6);
    cr_assert_eq(hm_get(node2), (void *) 6);
    cr_assert_eq(hm_get(hm_at(hm, "ok1")), (void *) 6);
    hm_remove(hm, hm_at(hm, "ok"));
    cr_assert_neq(hm_get(hm_at(hm, "ok")), (void *) 5);
    hm_free(&hm);
    cr_assert_null(hm);
}

Test(hm_next, multiple) {
    const int res_len = 4;
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
        cr_assert_eq(hm_get(cursor), (void *) res[tmp_i]);
        countor++;
    }
    cr_assert_eq(countor, res_len, "Expected: %d | Got %d", res_len, countor);
    hm_free(&hm);
}
