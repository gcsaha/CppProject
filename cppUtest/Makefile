CC	= g++
INCLDIR	= inc/

BINDIR	= bin/
OBJDIR	= obj/
SRCDIR	= src/
TSTDIR	= tst/

_BIN	= AlarmService 

BIN	= $(addprefix $(BINDIR), $(_BIN))

SRC	= $(wildcard src/*.c)
TST	= $(wildcard tst/*.cpp)

_OBJS	= $(patsubst src/%.c, %.o, $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(_OBJS))
_TSTOBJS	= $(patsubst tst/%.cpp, %.o, $(TST))
TSTOBJS	= $(addprefix $(OBJDIR), $(_TSTOBJS))
OBJS += $(TSTOBJS)

CFLAGS = -std=c++17 -g -I$(INCLDIR)
OFLAGS = -pthread 
LFLAGS = -lCppUTest

.PHONY: all
all: dircreation $(BIN) 
	./$(BIN)

$(OBJDIR)%.o: $(SRCDIR)%.c 
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)%.o: $(TSTDIR)%.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJS) 
	$(CC) $(OFLAGS) $(OBJS) $(LFLAGS) -o $(BIN) 


dircreation: 
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)	

.PHONY: clean 
clean:
	- rm -rf $(BINDIR) $(OBJDIR) 
# check code quality
.PHONY: cppcheck memcheck
cppcheck:
	cppcheck --enable=all --language=c++ --inconclusive --suppress=missingInclude $(SRC) -i $(INCLDIR)
memcheck: all
	valgrind -v --show-leak-kinds=all --leak-check=full --track-origins=yes ./$(BIN)
