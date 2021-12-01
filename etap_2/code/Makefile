CPPFLAGS=-Wall -pedantic -std=c++17 -iquote inc -ldl -lxerces-c
BIN=bin
PROGNAME=interp
SRCS=src/main.cpp inc/Interp4Command.hh inc/LibInterface.hh \
	src/LibInterface.cpp inc/xmlinterp.hh src/xmlinterp.cpp \
	inc/Configuration.hh src/Configuration.cpp inc/Scene.hh \
	src/Scene.cpp inc/Sender.hh src/Sender.cpp inc/AccessControl.hh
CMDPROG=plik.cmd

__start__: bin __lines_for_space__ $(BIN)/$(PROGNAME) __plugin__
	export LD_LIBRARY_PATH="./libs"; ./$(BIN)/$(PROGNAME) $(CMDPROG)

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

# main function
$(BIN)/$(PROGNAME): $(SRCS)
	g++ -o $@ $^ $(CPPFLAGS)

clean:
	rm -f bin/*

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
 
