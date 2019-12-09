CC	= g++
INCLDIR	= inc/

BINDIR	= bin/
OBJDIR	= obj/
SRCDIR	= src/

_BIN	= barberShop 

BIN	= $(addprefix $(BINDIR), $(_BIN))

SRC	= $(wildcard src/*.cpp)
_OBJS	= $(patsubst src/%.cpp, %.o, $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(_OBJS))

CFLAGS = -std=c++17 -g -I$(INCLDIR)
OFLAGS = -pthread

.PHONY: all
all: $(BIN) 

$(BIN): $(BINDIR) $(OBJS)
	$(CC) $(OFLAGS) $(OBJS) -o $(BIN)

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJS): $(OBJDIR) $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean 
clean:
	- rm -rf $(BINDIR) $(OBJDIR) 
# check code quality
.PHONY: cppcheck memcheck
cppcheck:
	cppcheck --enable=all --language=c++ --inconclusive --suppress=missingInclude $(SRC) -i $(INCLDIR)
memcheck: all
	valgrind -v --show-leak-kinds=all --leak-check=full --track-origins=yes ./$(BIN)
