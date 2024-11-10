TARGET	=	libhashmap.a

SRC		=	src/linkedlist.c		\
			src/hashmap.c			\
			src/hash.c				\
			src/hash_badhash.s		\
			src/hash_djb2.s			\
			src/hash_sdbm.s			\
			src/linkedlist_free.s	\
			src/linkedlist_at.s		\
			src/hashmap_free.s		\
			src/hash_custm.s

OBJ		=	$(subst .s,.o,$(subst .c,.o,$(SRC)))

CFLAGS	+=	-Iincludes -Wall -Wextra -Wpedantic

AFLAGS	=	-f elf64

# UNIT TESTS

TARGET_UNIT_TEST	=	hashmap_unit_tests

SRC_UNIT_TEST	=	tests/unit_tests/linkedlist.c	\
					tests/unit_tests/hashmap.c		\
					tests/unit_tests/hash.c

OBJ_UNIT_TEST	=	$(SRC_UNIT_TEST:.c=.o)

CFLAGS_UNIT_TEST	=	-g

AFLAGS_UNIT_TEST	=	-g

LDFLAGS_UNIT_TEST	=	-lcriterion

# FUNCTIONAL TESTS

SRC_FUNCTIONAL_TEST	=	tests/functional_tests/hashmap.c		\
						tests/functional_tests/hashmap_guide.c	\
						tests/functional_tests/linkedlist.c		\
						tests/functional_tests/hash_badhash.c	\
						tests/functional_tests/hash_djb2.c		\
						tests/functional_tests/hash_sdbm.c

CFLAGS_FUNCTIONAL_TEST	=	-g

AFLAGS_FUNCTIONAL_TEST	=	-g

all:	$(TARGET)

$(TARGET):	$(OBJ)
	ar rcs $(TARGET) $(OBJ)

%.o:	%.c
	gcc $(CFLAGS) -c $< -o $@

%.o:	%.s
	nasm $(AFLAGS) $< -o $@

unit_test:	CFLAGS	+=	$(CFLAGS_UNIT_TEST)
unit_test:	AFLAGS	+=	$(AFLAGS_UNIT_TEST)
unit_test:	$(OBJ) $(OBJ_UNIT_TEST)
	gcc $(LDFLAGS_UNIT_TEST) -o $(TARGET_UNIT_TEST) $(OBJ) $(OBJ_UNIT_TEST)
	./$(TARGET_UNIT_TEST)

functional_test:	CFLAGS	+=	$(CFLAGS_FUNCTIONAL_TEST)
functional_test:	AFLAGS	+=	$(AFLAGS_FUNCTIONAL_TEST)
functional_test:	$(OBJ)
	$(foreach prog_src,$(SRC_FUNCTIONAL_TEST), \
		(gcc $(CFLAGS) -o $(prog_src:.c=) $(OBJ) $(prog_src) && \
			cd $(dir $(prog_src)) && ./$(notdir $(prog_src:.c=.sh))); \
	)

clean:
	rm -f $(OBJ) $(OBJ_UNIT_TEST) $(TARGET) $(TARGET_UNIT_TEST) $(SRC_FUNCTIONAL_TEST:.c=)
