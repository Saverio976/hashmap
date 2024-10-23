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
