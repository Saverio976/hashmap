#include <stddef.h>

#include <criterion/criterion.h>
#include <criterion/assert.h>

#include "hash.h"
#include "../../src/hash_internal.h"

#define MAX_NB_WORDS 11

static const char *basic_words[MAX_NB_WORDS] = {
    "key",
    "value",
    "map",
    "1",
    "2",
    "abc",
    "def",
    "foo",
    "bar",
    "password",
    NULL,
};

Test(djb2, some) {
    size_t hashed[MAX_NB_WORDS] = {0};
    size_t hashed_res[MAX_NB_WORDS] = {0};
 
    for (int i = 0; i < MAX_NB_WORDS; i++) {
        hashed_res[i] = djb2_c(basic_words[i]);
        hashed[i] = djb2(basic_words[i]);
    }
    for (int i = 0; i < MAX_NB_WORDS; i++) {
        cr_assert_eq(hashed[i], hashed_res[i], "%d: Expected: %zu | Got: %zu", i, hashed_res[i], hashed[i]);
        for (int j = i + 1; j < MAX_NB_WORDS; j++) {
            cr_assert_neq(hashed[i], hashed[j]);
        }
    }
}

Test(sdbm, some) {
    size_t hashed[MAX_NB_WORDS] = {0};
    size_t hashed_res[MAX_NB_WORDS] = {0};

    for (int i = 0; i < MAX_NB_WORDS; i++) {
        hashed_res[i] = sdbm_c(basic_words[i]);
        hashed[i] = sdbm(basic_words[i]);
    }
    for (int i = 0; i < MAX_NB_WORDS; i++) {
        cr_assert_eq(hashed[i], hashed_res[i], "%d: Expected: %zu | Got: %zu", i, hashed_res[i], hashed[i]);
        for (int j = i + 1; j < MAX_NB_WORDS; j++) {
            cr_assert_neq(hashed[i], hashed[j]);
        }
    }
}

Test(badhash, some) {
    size_t hashed[MAX_NB_WORDS] = {0};
    size_t hashed_res[MAX_NB_WORDS] = {0};

    for (int i = 0; i < MAX_NB_WORDS; i++) {
        hashed_res[i] = badhash_c(basic_words[i]);
        hashed[i] = badhash(basic_words[i]);
    }
    for (int i = 0; i < MAX_NB_WORDS; i++) {
        cr_assert_eq(hashed[i], hashed_res[i], "%d: Expected: %zu | Got: %zu", i, hashed_res[i], hashed[i]);
        for (int j = i + 1; j < MAX_NB_WORDS; j++) {
            cr_assert_neq(hashed[i], hashed[j]);
        }
    }
}
