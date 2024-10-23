#include <stddef.h>

#include <criterion/criterion.h>
#include <criterion/assert.h>

#include "hash.h"

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
    size_t hashed_res[MAX_NB_WORDS] = {
        193496974,
        210731095874,
        193499011,
        177622,
        177623,
        193485963,
        193489332,
        193491849,
        193487034,
        7572787954113592,
        0,
    };

    for (int i = 0; i < MAX_NB_WORDS; i++) {
        hashed[i] = djb2(basic_words[i]);
    }
    for (int i = 0; i < MAX_NB_WORDS; i++) {
        cr_assert_eq(hashed[i], hashed_res[i], "Expected: %zu | Got: %zu", hashed_res[i], hashed[i]);
        for (int j = i + 1; j < MAX_NB_WORDS; j++) {
            cr_assert_neq(hashed[i], hashed[j]);
        }
    }
}

Test(sdbm, some) {
    size_t hashed[MAX_NB_WORDS] = {0};
    size_t hashed_res[MAX_NB_WORDS] = {
        460452107327,
        8409399078318541425,
        469058302524,
        49,
        50,
        417419622498,
        430329505701,
        438936619302,
        421722785715,
        14720992370332425563,
        0,
    };

    for (int i = 0; i < MAX_NB_WORDS; i++) {
        hashed[i] = sdbm(basic_words[i]);
    }
    for (int i = 0; i < MAX_NB_WORDS; i++) {
        cr_assert_eq(hashed[i], hashed_res[i], "Expected: %zu | Got: %zu", hashed_res[i], hashed[i]);
        for (int j = i + 1; j < MAX_NB_WORDS; j++) {
            cr_assert_neq(hashed[i], hashed[j]);
        }
    }
}

Test(badhash, some) {
    size_t hashed[MAX_NB_WORDS] = {0};
    size_t hashed_res[MAX_NB_WORDS] = {
        329,
        541,
        318,
        49,
        50,
        294,
        303,
        324,
        309,
        883,
        0,
    };

    for (int i = 0; i < MAX_NB_WORDS; i++) {
        hashed[i] = badhash(basic_words[i]);
    }
    for (int i = 0; i < MAX_NB_WORDS; i++) {
        cr_assert_eq(hashed[i], hashed_res[i], "%d: Expected: %zu | Got: %zu", i, hashed_res[i], hashed[i]);
        for (int j = i + 1; j < MAX_NB_WORDS; j++) {
            cr_assert_neq(hashed[i], hashed[j]);
        }
    }
}
