####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -O2 -Wall -W -fPIE $(DEFINES)
CXXFLAGS      = -pipe -Wall -O2 -Wall -W -fPIE $(DEFINES)
INCPATH       = -I. -I/opt/local/include -I/usr/include
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS) -L/opt/local/lib/ -L/usr/lib64/ -lboost_regex  
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/main.cpp \
		src/interfaces/abstractstate.cpp \
		src/interfaces/abstractstatemachine.cpp \
		src/interfaces/abstractexpression.cpp \
		src/expression/variable.cpp \
		src/expression/number.cpp \
		src/expression/binaryexpression.cpp \
		src/program_statemachine/programstatemachine.cpp \
		src/expression_statemachine/expressionstatemachine.cpp \
		src/expression_statemachine/states/es0.cpp \
		src/program_statemachine/states/ps0.cpp \
		src/expression_statemachine/states/es1.cpp \
		src/expression_statemachine/states/es2.cpp \
		src/expression_statemachine/states/es3.cpp \
		src/expression_statemachine/states/es4.cpp \
		src/expression_statemachine/states/es5.cpp \
		src/expression_statemachine/states/es6.cpp \
		src/expression_statemachine/states/es7.cpp \
		src/expression_statemachine/states/es8.cpp \
		src/expression_statemachine/states/es9.cpp \
		src/expression_statemachine/states/es10.cpp \
		src/expression_statemachine/states/es11.cpp \
		src/expression_statemachine/states/es12.cpp \
		src/expression_statemachine/states/es13.cpp \
		src/expression_statemachine/states/es14.cpp \
		src/expression_statemachine/states/es15.cpp \
		src/expression_statemachine/states/es16.cpp \
		src/expression_statemachine/states/es17.cpp \
		src/program_statemachine/states/ps1.cpp \
		src/program_statemachine/states/ps2.cpp \
		src/program_statemachine/states/ps3.cpp \
		src/program_statemachine/states/ps4.cpp \
		src/program_statemachine/states/ps5.cpp \
		src/program_statemachine/states/ps6.cpp \
		src/program_statemachine/states/ps7.cpp \
		src/program_statemachine/states/ps8.cpp \
		src/program_statemachine/states/ps9.cpp \
		src/program_statemachine/states/ps10.cpp \
		src/program_statemachine/states/ps11.cpp \
		src/program_statemachine/states/ps12.cpp \
		src/program_statemachine/states/ps13.cpp \
		src/program_statemachine/states/ps14.cpp \
		src/program_statemachine/states/ps15.cpp \
		src/program_statemachine/states/ps16.cpp \
		src/program_statemachine/states/ps17.cpp \
		src/program_statemachine/states/ps18.cpp \
		src/program_statemachine/states/ps19.cpp \
		src/program_statemachine/states/ps20.cpp \
		src/program_statemachine/states/ps21.cpp \
		src/program_statemachine/states/ps22.cpp \
		src/program_statemachine/states/ps23.cpp \
		src/program_statemachine/states/ps24.cpp \
		src/program_statemachine/states/ps25.cpp \
		src/program_statemachine/states/ps26.cpp \
		src/program_statemachine/states/ps27.cpp \
		src/program_statemachine/states/ps28.cpp \
		src/program_statemachine/states/ps29.cpp \
		src/types/datamap.cpp \
		src/types/instructionlist.cpp \
		src/lexer/lexer.cpp \
		src/optionsManager.cpp \
		src/unit_tests/abstractexpressiontests.cpp \
		src/unit_tests/lexertests.cpp \
		src/unit_tests/instructionlisttests.cpp \
		src/unit_tests/datamaptests.cpp \
		src/expression/expressionfactory.cpp \
		src/unit_tests/expressionfactorytests.cpp 
OBJECTS       = main.o \
		abstractstate.o \
		abstractstatemachine.o \
		abstractexpression.o \
		variable.o \
		number.o \
		binaryexpression.o \
		programstatemachine.o \
		expressionstatemachine.o \
		es0.o \
		ps0.o \
		es1.o \
		es2.o \
		es3.o \
		es4.o \
		es5.o \
		es6.o \
		es7.o \
		es8.o \
		es9.o \
		es10.o \
		es11.o \
		es12.o \
		es13.o \
		es14.o \
		es15.o \
		es16.o \
		es17.o \
		ps1.o \
		ps2.o \
		ps3.o \
		ps4.o \
		ps5.o \
		ps6.o \
		ps7.o \
		ps8.o \
		ps9.o \
		ps10.o \
		ps11.o \
		ps12.o \
		ps13.o \
		ps14.o \
		ps15.o \
		ps16.o \
		ps17.o \
		ps18.o \
		ps19.o \
		ps20.o \
		ps21.o \
		ps22.o \
		ps23.o \
		ps24.o \
		ps25.o \
		ps26.o \
		ps27.o \
		ps28.o \
		ps29.o \
		datamap.o \
		instructionlist.o \
		lexer.o \
		optionsManager.o \
		abstractexpressiontests.o \
		lexertests.o \
		instructionlisttests.o \
		datamaptests.o \
		expressionfactory.o \
		expressionfactorytests.o

DESTDIR       = #avoid trailing-slash linebreak
TARGET        = lut



first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

test: $(TARGET)
	cp ./lut tests/lut
	cd tests ; ./mktest.sh
clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Compile

main.o: src/main.cpp src/config.h \
		src/lexer/lexer.h \
		src/program_statemachine/programstatemachine.h \
		src/optionsManager.h \
		src/types/datamap.h \
		src/types/instructionlist.h \
		src/unit_tests/abstractexpressiontests.h \
		src/unit_tests/lexertests.h \
		src/unit_tests/instructionlisttests.h \
		src/unit_tests/datamaptests.h \
		src/unit_tests/expressionfactorytests.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o src/main.cpp

abstractstate.o: src/interfaces/abstractstate.cpp src/interfaces/abstractstate.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o abstractstate.o src/interfaces/abstractstate.cpp

abstractstatemachine.o: src/interfaces/abstractstatemachine.cpp src/interfaces/abstractstatemachine.h \
		src/debug.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o abstractstatemachine.o src/interfaces/abstractstatemachine.cpp

abstractexpression.o: src/interfaces/abstractexpression.cpp src/interfaces/abstractexpression.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o abstractexpression.o src/interfaces/abstractexpression.cpp

variable.o: src/expression/variable.cpp src/expression/variable.h \
		src/expression/number.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o variable.o src/expression/variable.cpp

number.o: src/expression/number.cpp src/expression/number.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o number.o src/expression/number.cpp

binaryexpression.o: src/expression/binaryexpression.cpp src/expression/binaryexpression.h \
		src/config.h \
		src/debug.h \
		src/expression/number.h \
		src/expression/variable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o binaryexpression.o src/expression/binaryexpression.cpp

programstatemachine.o: src/program_statemachine/programstatemachine.cpp src/program_statemachine/programstatemachine.h \
		src/program_statemachine/states/ps0.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o programstatemachine.o src/program_statemachine/programstatemachine.cpp

expressionstatemachine.o: src/expression_statemachine/expressionstatemachine.cpp src/expression_statemachine/expressionstatemachine.h \
		src/expression_statemachine/states/es0.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o expressionstatemachine.o src/expression_statemachine/expressionstatemachine.cpp

es0.o: src/expression_statemachine/states/es0.cpp src/expression_statemachine/states/es0.h \
		src/expression_statemachine/states/es9.h \
		src/expression_statemachine/states/es10.h \
		src/expression_statemachine/states/es11.h \
		src/expression_statemachine/states/es1.h \
		src/expression_statemachine/states/es16.h \
		src/expression_statemachine/states/es12.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es0.o src/expression_statemachine/states/es0.cpp

ps0.o: src/program_statemachine/states/ps0.cpp src/program_statemachine/states/ps0.h \
		src/program_statemachine/states/ps1.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps0.o src/program_statemachine/states/ps0.cpp

es1.o: src/expression_statemachine/states/es1.cpp src/expression_statemachine/states/es1.h \
		src/expression_statemachine/states/es2.h \
		src/expression_statemachine/states/es3.h \
		src/expression_statemachine/states/es17.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es1.o src/expression_statemachine/states/es1.cpp

es2.o: src/expression_statemachine/states/es2.cpp src/expression_statemachine/states/es2.h \
		src/expression_statemachine/states/es9.h \
		src/expression_statemachine/states/es10.h \
		src/expression_statemachine/states/es11.h \
		src/expression_statemachine/states/es12.h \
		src/expression_statemachine/states/es4.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es2.o src/expression_statemachine/states/es2.cpp

es3.o: src/expression_statemachine/states/es3.cpp src/expression_statemachine/states/es3.h \
		src/expression_statemachine/states/es9.h \
		src/expression_statemachine/states/es10.h \
		src/expression_statemachine/states/es11.h \
		src/expression_statemachine/states/es13.h \
		src/expression_statemachine/states/es12.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es3.o src/expression_statemachine/states/es3.cpp

es4.o: src/expression_statemachine/states/es4.cpp src/expression_statemachine/states/es4.h \
		src/expression_statemachine/states/es5.h \
		src/expression_statemachine/states/es6.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es4.o src/expression_statemachine/states/es4.cpp

es5.o: src/expression_statemachine/states/es5.cpp src/expression_statemachine/states/es5.h \
		src/expression_statemachine/states/es9.h \
		src/expression_statemachine/states/es10.h \
		src/expression_statemachine/states/es11.h \
		src/expression_statemachine/states/es7.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es5.o src/expression_statemachine/states/es5.cpp

es6.o: src/expression_statemachine/states/es6.cpp src/expression_statemachine/states/es6.h \
		src/expression_statemachine/states/es8.h \
		src/expression_statemachine/states/es9.h \
		src/expression_statemachine/states/es10.h \
		src/expression_statemachine/states/es11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es6.o src/expression_statemachine/states/es6.cpp

es7.o: src/expression_statemachine/states/es7.cpp src/expression_statemachine/states/es7.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es7.o src/expression_statemachine/states/es7.cpp

es8.o: src/expression_statemachine/states/es8.cpp src/expression_statemachine/states/es8.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es8.o src/expression_statemachine/states/es8.cpp

es9.o: src/expression_statemachine/states/es9.cpp src/expression_statemachine/states/es9.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es9.o src/expression_statemachine/states/es9.cpp

es10.o: src/expression_statemachine/states/es10.cpp src/expression_statemachine/states/es10.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es10.o src/expression_statemachine/states/es10.cpp

es11.o: src/expression_statemachine/states/es11.cpp src/expression_statemachine/states/es11.h \
		src/expression_statemachine/states/es9.h \
		src/expression_statemachine/states/es10.h \
		src/expression_statemachine/states/es12.h \
		src/expression_statemachine/states/es14.h \
		src/expression_statemachine/states/es16.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es11.o src/expression_statemachine/states/es11.cpp

es12.o: src/expression_statemachine/states/es12.cpp src/expression_statemachine/states/es12.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es12.o src/expression_statemachine/states/es12.cpp

es13.o: src/expression_statemachine/states/es13.cpp src/expression_statemachine/states/es13.h \
		src/expression_statemachine/states/es5.h \
		src/expression_statemachine/states/es6.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es13.o src/expression_statemachine/states/es13.cpp

es14.o: src/expression_statemachine/states/es14.cpp src/expression_statemachine/states/es14.h \
		src/expression_statemachine/states/es15.h \
		src/expression_statemachine/states/es2.h \
		src/expression_statemachine/states/es3.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es14.o src/expression_statemachine/states/es14.cpp

es15.o: src/expression_statemachine/states/es15.cpp src/expression_statemachine/states/es15.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es15.o src/expression_statemachine/states/es15.cpp

es16.o: src/expression_statemachine/states/es16.cpp src/expression_statemachine/states/es16.h \
		src/expression_statemachine/states/es5.h \
		src/expression_statemachine/states/es6.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es16.o src/expression_statemachine/states/es16.cpp

es17.o: src/expression_statemachine/states/es17.cpp src/expression_statemachine/states/es17.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o es17.o src/expression_statemachine/states/es17.cpp

ps1.o: src/program_statemachine/states/ps1.cpp src/program_statemachine/states/ps1.h \
		src/program_statemachine/states/ps18.h \
		src/program_statemachine/states/ps11.h \
		src/program_statemachine/states/ps6.h \
		src/program_statemachine/states/ps5.h \
		src/program_statemachine/states/ps9.h \
		src/program_statemachine/states/ps17.h \
		src/program_statemachine/states/ps2.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps1.o src/program_statemachine/states/ps1.cpp

ps2.o: src/program_statemachine/states/ps2.cpp src/program_statemachine/states/ps2.h \
		src/program_statemachine/rules.h \
		src/program_statemachine/states/ps3.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps2.o src/program_statemachine/states/ps2.cpp

ps3.o: src/program_statemachine/states/ps3.cpp src/program_statemachine/states/ps3.h \
		src/program_statemachine/states/ps6.h \
		src/program_statemachine/states/ps5.h \
		src/program_statemachine/states/ps9.h \
		src/program_statemachine/states/ps4.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps3.o src/program_statemachine/states/ps3.cpp

ps4.o: src/program_statemachine/states/ps4.cpp src/program_statemachine/states/ps4.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps4.o src/program_statemachine/states/ps4.cpp

ps5.o: src/program_statemachine/states/ps5.cpp src/program_statemachine/states/ps5.h \
		src/program_statemachine/states/ps29.h \
		src/expression_statemachine/expressionstatemachine.h \
		src/debug.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps5.o src/program_statemachine/states/ps5.cpp

ps6.o: src/program_statemachine/states/ps6.cpp src/program_statemachine/states/ps6.h \
		src/program_statemachine/states/ps7.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps6.o src/program_statemachine/states/ps6.cpp

ps7.o: src/program_statemachine/states/ps7.cpp src/program_statemachine/states/ps7.h \
		src/program_statemachine/states/ps8.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps7.o src/program_statemachine/states/ps7.cpp

ps8.o: src/program_statemachine/states/ps8.cpp src/program_statemachine/states/ps8.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps8.o src/program_statemachine/states/ps8.cpp

ps9.o: src/program_statemachine/states/ps9.cpp src/program_statemachine/states/ps9.h \
		src/program_statemachine/states/ps10.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps9.o src/program_statemachine/states/ps9.cpp

ps10.o: src/program_statemachine/states/ps10.cpp src/program_statemachine/states/ps10.h \
		src/program_statemachine/states/ps28.h \
		src/expression_statemachine/expressionstatemachine.h \
		src/debug.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps10.o src/program_statemachine/states/ps10.cpp

ps11.o: src/program_statemachine/states/ps11.cpp src/program_statemachine/states/ps11.h \
		src/program_statemachine/states/ps12.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps11.o src/program_statemachine/states/ps11.cpp

ps12.o: src/program_statemachine/states/ps12.cpp src/program_statemachine/states/ps12.h \
		src/program_statemachine/states/ps13.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps12.o src/program_statemachine/states/ps12.cpp

ps13.o: src/program_statemachine/states/ps13.cpp src/program_statemachine/states/ps13.h \
		src/program_statemachine/states/ps14.h \
		src/program_statemachine/states/ps16.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps13.o src/program_statemachine/states/ps13.cpp

ps14.o: src/program_statemachine/states/ps14.cpp src/program_statemachine/states/ps14.h \
		src/program_statemachine/states/ps15.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps14.o src/program_statemachine/states/ps14.cpp

ps15.o: src/program_statemachine/states/ps15.cpp src/program_statemachine/states/ps15.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps15.o src/program_statemachine/states/ps15.cpp

ps16.o: src/program_statemachine/states/ps16.cpp src/program_statemachine/states/ps16.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps16.o src/program_statemachine/states/ps16.cpp

ps17.o: src/program_statemachine/states/ps17.cpp src/program_statemachine/states/ps17.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps17.o src/program_statemachine/states/ps17.cpp

ps18.o: src/program_statemachine/states/ps18.cpp src/program_statemachine/states/ps18.h \
		src/program_statemachine/states/ps19.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps18.o src/program_statemachine/states/ps18.cpp

ps19.o: src/program_statemachine/states/ps19.cpp src/program_statemachine/states/ps19.h \
		src/program_statemachine/states/ps20.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps19.o src/program_statemachine/states/ps19.cpp

ps20.o: src/program_statemachine/states/ps20.cpp src/program_statemachine/states/ps20.h \
		src/program_statemachine/states/ps21.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps20.o src/program_statemachine/states/ps20.cpp

ps21.o: src/program_statemachine/states/ps21.cpp src/program_statemachine/states/ps21.h \
		src/program_statemachine/states/ps22.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps21.o src/program_statemachine/states/ps21.cpp

ps22.o: src/program_statemachine/states/ps22.cpp src/program_statemachine/states/ps22.h \
		src/program_statemachine/states/ps23.h \
		src/program_statemachine/states/ps27.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps22.o src/program_statemachine/states/ps22.cpp

ps23.o: src/program_statemachine/states/ps23.cpp src/program_statemachine/states/ps23.h \
		src/program_statemachine/states/ps24.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps23.o src/program_statemachine/states/ps23.cpp

ps24.o: src/program_statemachine/states/ps24.cpp src/program_statemachine/states/ps24.h \
		src/program_statemachine/states/ps25.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps24.o src/program_statemachine/states/ps24.cpp

ps25.o: src/program_statemachine/states/ps25.cpp src/program_statemachine/states/ps25.h \
		src/program_statemachine/states/ps26.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps25.o src/program_statemachine/states/ps25.cpp

ps26.o: src/program_statemachine/states/ps26.cpp src/program_statemachine/states/ps26.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps26.o src/program_statemachine/states/ps26.cpp

ps27.o: src/program_statemachine/states/ps27.cpp src/program_statemachine/states/ps27.h \
		src/program_statemachine/rules.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps27.o src/program_statemachine/states/ps27.cpp

ps28.o: src/program_statemachine/states/ps28.cpp src/program_statemachine/states/ps28.h \
		src/program_statemachine/rules.h \
		src/expression_statemachine/expressionstatemachine.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps28.o src/program_statemachine/states/ps28.cpp

ps29.o: src/program_statemachine/states/ps29.cpp src/program_statemachine/states/ps29.h \
		src/program_statemachine/rules.h \
		src/expression_statemachine/expressionstatemachine.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ps29.o src/program_statemachine/states/ps29.cpp

datamap.o: src/types/datamap.cpp src/types/datamap.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o datamap.o src/types/datamap.cpp

instructionlist.o: src/types/instructionlist.cpp src/types/instructionlist.h \
		src/expression/expressionfactory.h \
		src/debug.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o instructionlist.o src/types/instructionlist.cpp

lexer.o: src/lexer/lexer.cpp src/lexer/lexer.h \
		src/debug.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lexer.o src/lexer/lexer.cpp

optionsManager.o: src/optionsManager.cpp src/optionsManager.h \
		src/types/types.h \
		src/interfaces/abstractexpression.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o optionsManager.o src/optionsManager.cpp

abstractexpressiontests.o: src/unit_tests/abstractexpressiontests.cpp src/unit_tests/abstractexpressiontests.h \
		src/unit_tests/test_macros.h \
		src/expression/variable.h \
		src/expression/number.h \
		src/expression/binaryexpression.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o abstractexpressiontests.o src/unit_tests/abstractexpressiontests.cpp

lexertests.o: src/unit_tests/lexertests.cpp src/unit_tests/lexertests.h \
		src/unit_tests/test_macros.h \
		src/lexer/lexer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lexertests.o src/unit_tests/lexertests.cpp

instructionlisttests.o: src/unit_tests/instructionlisttests.cpp src/unit_tests/instructionlisttests.h \
		src/unit_tests/test_macros.h \
		src/types/instructionlist.h \
		src/expression/binaryexpression.h \
		src/expression/number.h \
		src/expression/variable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o instructionlisttests.o src/unit_tests/instructionlisttests.cpp

datamaptests.o: src/unit_tests/datamaptests.cpp src/unit_tests/datamaptests.h \
		src/unit_tests/test_macros.h \
		src/types/datamap.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o datamaptests.o src/unit_tests/datamaptests.cpp

expressionfactory.o: src/expression/expressionfactory.cpp src/expression/expressionfactory.h \
		src/debug.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o expressionfactory.o src/expression/expressionfactory.cpp

expressionfactorytests.o: src/unit_tests/expressionfactorytests.cpp src/unit_tests/expressionfactorytests.h \
		src/expression/expressionfactory.h \
		src/unit_tests/test_macros.h \
		src/debug.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o expressionfactorytests.o src/unit_tests/expressionfactorytests.cpp

