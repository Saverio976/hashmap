TARGET	=	libhashmap.a

SRC		=	src/linkedlist.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-Iincludes

# UNIT TESTS

TARGET_UNIT_TEST	=	hashmap_unit_tests

SRC_UNIT_TEST	=	tests/unit_tests/linkedlist.c

OBJ_UNIT_TEST	=	$(SRC_UNIT_TEST:.c=.o)

CFLAGS_UNIT_TEST	=	-g

LDFLAGS_UNIT_TEST	=	-lcriterion

# FUNCTIONAL TESTS

SRC_FUNCTIONAL_TEST	=	tests/functional_tests/linkedlist.c

CFLAGS_FUNCTIONAL_TEST	=	-g

all:	$(TARGET)

$(TARGET):	$(OBJ)
	ar rcs $(TARGET) $(OBJ)

%.o:	%.c
	gcc $(CFLAGS) -c $< -o $@

%.o:	%.s
	nasm $(AFLAGS) $< -o $@

unit_test:	CFLAGS	+= $(CFLAGS_UNIT_TEST)
unit_test:	$(OBJ) $(OBJ_UNIT_TEST)
	gcc $(LDFLAGS_UNIT_TEST) -o $(TARGET_UNIT_TEST) $(OBJ) $(OBJ_UNIT_TEST)
	./$(TARGET_UNIT_TEST)

functional_test: CFLAGS	+= $(CFLAGS_FUNCTIONAL_TEST)
functional_test: $(OBJ)
	$(foreach prog_src,$(SRC_FUNCTIONAL_TEST), \
		gcc $(CFLAGS) -o $(prog_src:.c=) $(OBJ) $(prog_src) && \
			cd $(dir $(prog_src)) && ./$(notdir $(prog_src:.c=.sh)) \
	)

clean:
	rm -f $(OBJ) $(OBJ_UNIT_TEST) $(TARGET)
