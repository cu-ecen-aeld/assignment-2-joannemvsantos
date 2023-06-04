# Cross-compiler prefix, empty by default (native build platform)
CC := $(if $(CROSS_COMPILE), /opt/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc,gcc)
CFLAGS := -Wall -Wextra

# Source files
SRCS := writer.c

# Object files
OBJS := $(SRCS:.c=.o)

# Output executable
TARGET := writer

# Default target
all: $(TARGET)

# Build target for native platform
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Build target for cross compilation
ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
endif

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)