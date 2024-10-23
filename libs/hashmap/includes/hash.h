#ifndef HASHMAP_H_HASH_H_
    #define HASHMAP_H_HASH_H_

    #include <stddef.h>


// from: http://www.cse.yorku.ca/~oz/hash.html
size_t djb2(const char *key);

// from: http://www.cse.yorku.ca/~oz/hash.html
size_t sdbm(const char *key);

// from: http://www.cse.yorku.ca/~oz/hash.html
size_t badhash(const char *key);

#endif
