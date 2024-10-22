TARGET	=	libhashmap.a

SRC		=

OBJ		=	$(SRC:.c=.o)

all:	$(TARGET)

$(TARGET):	$(OBJ)
	ar rcs $(TARGET) $(OBJ)

src/%.o:	src/%.c
	gcc $(CFLAGS) -c $<

%.o:	%.s
	nasm $(AFLAGS) $<

clean:
	rm -f $(OBJ) $(TARGET)
