#include "hash.h"
#include "hash_internal.h"

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
