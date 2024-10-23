#include <criterion/criterion.h>
#include <criterion/assert.h>

#include "linkedlist.h"

Test(ll_new, basic) {
    cr_assert_eq(ll_new(), NULL);
}

Test(ll_append, to_empty_list) {
    ll_t list = ll_new();
    ll_node_t node = ll_append(&list, (void *) 5);
    cr_assert_not_null(node);
    cr_assert_eq(ll_get(node), (void *) 5);
    cr_assert_eq(list, node);
    ll_remove(&list, node);
    cr_assert_null(list);
}

Test(ll_append, to_one_item) {
    ll_t list = ll_new();
    ll_node_t node1 = ll_append(&list, (void *) 1);
    cr_assert_not_null(node1);
    cr_assert_eq(ll_get(node1), (void *) 1);
    cr_assert_eq(list, node1);
    ll_node_t node2 = ll_append(&list, (void *) 3);
    cr_assert_not_null(node2);
    cr_assert_eq(ll_get(node2), (void *) 3);
    cr_assert_eq(list, node1);
    ll_node_t node3 = ll_append(&list, (void *) 5);
    cr_assert_not_null(node3);
    cr_assert_eq(ll_get(node3), (void *) 5);
    cr_assert_eq(list, node1);

    cr_assert_eq(ll_next(node1), node2);
    cr_assert_eq(ll_next(ll_next(node1)), node3);
    cr_assert_eq(ll_next(node3), node1);
    cr_assert_eq(ll_next(node2), node3);

    cr_assert_eq(ll_prev(node1), node3);
    cr_assert_eq(ll_prev(ll_prev(node1)), node2);
    cr_assert_eq(ll_prev(node2), node1);
    cr_assert_eq(ll_prev(node3), node2);

    cr_assert_eq(ll_at(list, 0), node1);
    cr_assert_eq(ll_at(list, 1), node2);
    cr_assert_eq(ll_at(list, 2), node3);
    cr_assert_eq(ll_at(list, 3), NULL);

    ll_remove(&list, node2);
    cr_assert_not_null(list);
    cr_assert_eq(list, node1);
    ll_remove(&list, node1);
    cr_assert_not_null(list);
    cr_assert_eq(list, node3);
    ll_remove(&list, node3);
    cr_assert_null(list);
}

Test(ll_clear, basic) {
    ll_t list = ll_new();
    ll_node_t node1 = ll_append(&list, (void *) 1);
    cr_assert_not_null(node1);
    cr_assert_eq(ll_get(node1), (void *) 1);
    cr_assert_eq(list, node1);
    ll_node_t node2 = ll_append(&list, (void *) 3);
    cr_assert_not_null(node2);
    cr_assert_eq(ll_get(node2), (void *) 3);
    cr_assert_eq(list, node1);
    ll_node_t node3 = ll_append(&list, (void *) 5);
    cr_assert_not_null(node3);
    cr_assert_eq(ll_get(node3), (void *) 5);
    cr_assert_eq(list, node1);
    ll_clear(&list);
    cr_assert_null(list);
}
