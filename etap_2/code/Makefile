CPPFLAGS=-Wall -pedantic -std=c++17 -iquote inc
LDFLAGS=-Wall
BIN=bin
OBJ=obj
OBJS=$(OBJ)/main.o $(OBJ)/xmlinterp.o
PROGNAME=interp

__start__: obj bin __lines_for_space__ $(BIN)/$(PROGNAME) __plugin__
	export LD_LIBRARY_PATH="./libs"; ./$(BIN)/$(PROGNAME) | less

obj:
	mkdir obj

bin:
	mkdir bin

__lines_for_space__:
	@echo
	@echo
	@echo
	@echo
	@echo


__plugin__:
	cd plugin; make

obj/xmlinterp.o: src/xmlinterp.cpp inc/xmlinterp.hh inc/Configuration.hh
	g++ -c ${CPPFLAGS} -o obj/xmlinterp.o src/xmlinterp.cpp

obj/main.o: src/main.cpp inc/Interp4Command.hh inc/LibInterface.hh inc/xmlinterp.hh inc/Configuration.hh inc/xmlinterp.hh
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

# main function
$(BIN)/$(PROGNAME): $(OBJS)
	g++ ${LDFLAGS} -o $@ $^ -ldl -lxerces-c

clean:
	rm -f obj/* bin/*

clean_plugin:
	cd plugin; make clean

cleanall: clean
	cd plugin; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	rm -f bin/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
 
