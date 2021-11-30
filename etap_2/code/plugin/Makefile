CPP=g++
CPPFLAGS=-Wall -fPIC -pedantic -std=c++17 -iquote inc -iquote ../inc
LDFLAGS=-Wall -shared
SRC=src
INC=inc
OBJ=obj
LIB=../libs
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
LIBS=$(patsubst $(SRC)/%.cpp, $(LIB)/lib%.so, $(SRCS))

__start__: obj __lines_for_space__ $(LIBS)
	@echo "  Tworzenie wtyczki zakonczone."
	@echo

$(OBJ):
	mkdir $@

__lines_for_space__:
	@echo
	@echo
	@echo
	@echo
	@echo

$(OBJ)/%.o: $(SRC)/*.cpp $(INC)/*.hh
	$(CPP) -c $< -o $@ $(CPPFLAGS)

$(LIB)/%.so: $(OBJ)/%.o
	$(CPP) $(LDFLAGS) -o $@ $<
	@echo
	@echo "Wtyczka '$@' została wygenerowana."
	@echo

clean:
	rm -f $(OBJ)/* $(LIB)/*

cleanall: clean
	find . -name \*~ -print -exec rm {} \;
