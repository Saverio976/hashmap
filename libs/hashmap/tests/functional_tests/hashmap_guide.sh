#!/bin/bash

echo "-------------------------------------------------------"
echo "FUNCTIONAL TESTS: hashmap_guide"
valgrind -- ./hashmap_guide
valgrind -- ./hashmap_guide --myflag 1
