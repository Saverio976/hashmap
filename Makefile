TARGET	=	hasmap_main

SRC		=	src/main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	$(CFLAGS)	\
			-Ilibs/hashmap/includes

LDFLAGS	=	$(LDFLAGS)	\
			-Libs/hashmap \
			-lhashmap

all:	$(TARGET)

$(TARGET):	libs/hashmap/libhashmap.a $(OBJ)
	gcc $(LDFLAGS) -o $(TARGET) $(OBJ)

src/%.o: src/%.c
	gcc $(CFLAGS) -c $<

libhashmap.a:
	$(MAKE) -C libs/hashmap

clean:
	rm -f $(OBJ) $(TARGET)
