CC = gcc
CFLAGS = -Wall -Wextra

SRC = main.c grade_card.c
OBJ = $(SRC:.c=.o)

all: grade_card

grade_card: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o grade_card
