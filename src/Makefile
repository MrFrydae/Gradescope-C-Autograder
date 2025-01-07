SOURCE = $(wildcard *.c)
OBJS = $(SOURCE:.c=.o)
HEADER = $(wildcard *.h)
OUT = runner
ZIP = submission.zip
ZIP_INC = Makefile $(HEADER) $(SOURCE)
CC = gcc
FLAGS = -g -Wall -std=c99 -O3

all: $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(OUT)

clean:
		rm -f $(OBJS) $(OUT) $(ZIP)

zip:
		zip $(ZIP) $(ZIP_INC)

