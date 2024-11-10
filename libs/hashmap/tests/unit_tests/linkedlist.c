#include <criterion/criterion.h>
#include <criterion/assert.h>

#include "linkedlist.h"
#include "../../src/linkedlist_internal.h"

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

    cr_assert_eq(ll_at_c(list, 0), node1);
    cr_assert_eq(ll_at_c(list, 1), node2);
    cr_assert_eq(ll_at_c(list, 2), node3);
    cr_assert_eq(ll_at_c(list, 3), NULL);

    cr_assert_eq(ll_at(list, 0), ll_at_c(list, 0));
    cr_assert_eq(ll_at(list, 1), ll_at_c(list, 1));
    cr_assert_eq(ll_at(list, 2), ll_at_c(list, 2));
    cr_assert_eq(ll_at(list, 3), ll_at_c(list, 3));

    cr_assert_eq(ll_assign(ll_at(list, 1), (void *) 10), 1);
    cr_assert_eq(ll_get(node2), (void *) 10);
    cr_assert_eq(ll_assign(ll_at(list, 3), (void *) 11), 0);

    cr_assert_eq(ll_remove(&list, node2), 1);
    cr_assert_not_null(list);
    cr_assert_eq(list, node1);
    cr_assert_eq(ll_remove(&list, node1), 1);
    cr_assert_not_null(list);
    cr_assert_eq(list, node3);
    cr_assert_eq(ll_remove(&list, node3), 1);
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
    cr_assert_eq(ll_clear(&list), 3);
    cr_assert_null(list);
}
