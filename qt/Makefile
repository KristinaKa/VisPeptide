CCX=g++
CC=gcc
# includes

INCDIRS=-I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore
INC=-I ../src/ini -I ../src/spc
CFLAGS=$(INC) -g
# Ajout 
LIBS=-lQtCore -lQtGui 


# deps
DEPS = speptide.h ms1ms2.h iniparser.h dictionary.h spectra.h mparser.h result.h scoring.h
OBJ = speptide.o ms1ms2.o iniparser.o dictionary.o spectra.o mparser.o result.o scoring.o main.o 
VPATH = ../src/ini:../src/spc

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
%.o: %.cpp $(DEPS)
	$(CCX) $(CFLAGS) $(INCDIRS) -c -o $@ $<

speptide: $(OBJ) 
	$(CCX) $(CFLAGS) $(LIBS) -o $@ $^
	rm -f $(OBJ)
clean:
	rm *.o
