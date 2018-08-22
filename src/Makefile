CC = gcc 				# compiler
CFLAGS = -Wall -g 		# compile flags
LIBS = -lm 				# libs

SRCS = Node.c test.c	# source files
OBJS = $(SRCS:.c=.o) 	# object files

TARG = test

all: $(TARG)

# generates the target executable
$(TARG):$(OBJS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS)

# generates the object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# cleans stuff
clean:
	rm -f $(OBJS) $(TARG) *~
