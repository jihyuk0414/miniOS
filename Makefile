# Compiler and Compiler Flags
CC=gcc
CFLAGS=-Wall -g -Iinclude
# Linker flags
LDFLAGS=-lreadline

# The build target executable:
TARGET=minios

# Source, Object files
<<<<<<< HEAD
SRCS=kernel/20192628/kerneljihyuk.c kernel/20192628/rr.c kernel/system.c kernel/20192628/ipc.c kernel/kernel.c kernel/20192628/estimate.c
=======
<<<<<<< HEAD
SRCS=kernel/20192628/kerneljihyuk.c kernel/system.c kernel/20192628/ipc.c kernel/kernel.c kernel/20192628/estimate.c
=======
SRCS=kernel/20192628/kerneljihyuk.c kernel/system.c kernel/20192628/ipc.c kernel/kernel.c

>>>>>>> 9695c1dc0dead2fea92ca9eac0734aba2e138e02
>>>>>>> f3d19e93f21a93bea4058dc3f8830d0e58f06ffd
OBJS=$(SRCS:.c=.o) 

# Include directory
INCLUDE_DIR=include

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# To obtain object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up:
clean:
	rm -f $(OBJS) $(TARGET)
