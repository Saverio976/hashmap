NB		?=	submit

TARGET	=	hashmap_main

SRC		=	src/main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-Ilibs/hashmap/includes -Wall -Wextra -Wpedantic

LDFLAGS	+=	-Llibs/hashmap \
			-lhashmap

all:	$(TARGET)

$(TARGET):	libs/hashmap/libhashmap.a $(OBJ)
	gcc -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

libs/hashmap/libhashmap.a:
	$(MAKE) -C libs/hashmap

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: submit
submit:
	rm -rf "$(NB)"
	mkdir -p "$(NB)"
	cp -r src libs "$(NB)"
	cp Makefile README.md "$(NB)"
	tar -czf "$(NB).tar.gz" "$(NB)"
	cd "$(NB)" && make -C libs/hashmap unit_test
