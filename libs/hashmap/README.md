# HashMap

HashMap in C:
- {access,modify} value by a string key.
- iterrate over all keys / values.

## Usage

### Compil

```bash
# this will create a static archive libhashmap.a
make
```

You can now link it with your program.

```bash
# example:
gcc -o main main.c -Lpath/to/this/directory -lhashmap
```

### Run Tests

#### Unit Tests

```bash
make unit_test
```

#### Functional Tests

```bash
make functional_test
```

## References

- [hash function (rewrited in asm)](http://www.cse.yorku.ca/~oz/hash.html)
- [hashmap in java (for a basic idea of what is a hashmap)](https://www.turing.com/kb/implementing-hashmap-in-java)
