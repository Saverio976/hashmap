#include "hash.h"
#include "hash_internal.h"

// from: http://www.cse.yorku.ca/~oz/hash.html
size_t djb2_c(const char *key)
{
    size_t hash = 5381;

    if (key == NULL) {
        return 0;
    }
    for (size_t i = 0; key[i] != '\0'; i++) {
        hash = ((hash << 5) + hash) + key[i];
    }
    return hash;
}

// from: http://www.cse.yorku.ca/~oz/hash.html
size_t sdbm_c(const char *key)
{
    size_t hash = 0;

    if (key == NULL) {
        return 0;
    }
    for (size_t i = 0; key[i] != '\0'; i++) {
        hash = key[i] + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}

// from: http://www.cse.yorku.ca/~oz/hash.html
size_t badhash_c(const char *key)
{
    size_t hash = 0;

    if (key == NULL) {
        return 0;
    }
    for (size_t i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash;
}

static size_t custm_c_do_calc(size_t c, size_t old_value)
{
    c = c << 3;
    c = c + old_value;
    return c;
}

size_t custm_c(const char *key)
{
    size_t hash = 0;

    if (key == NULL) {
        return 0;
    }
    for (size_t i = 0; key[i] != '\0'; i++) {
        hash = custm_c_do_calc(key[i], hash);
    }
    return hash;
}
