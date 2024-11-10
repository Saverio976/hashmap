#ifndef HASHMAP_INTERNAL_H_HASH_H_
    #define HASHMAP_INTERNAL_H_HASH_H_

    #include <stddef.h>

// from: http://www.cse.yorku.ca/~oz/hash.html
size_t djb2_c(const char *key);

// from: http://www.cse.yorku.ca/~oz/hash.html
size_t sdbm_c(const char *key);

// from: http://www.cse.yorku.ca/~oz/hash.html
size_t badhash_c(const char *key);

size_t custm_c(const char *key);

#endif
