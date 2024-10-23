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
        cr_assert_eq(hm_get(cursor), (void *) res[i]);
        i++;
    }
    hm_free(&hm);
}
