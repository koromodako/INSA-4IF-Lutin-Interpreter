TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lboost_regex

SOURCES += \
    src/main.cpp \
    src/interfaces/abstractstate.cpp \
    src/interfaces/abstractstatemachine.cpp \
    src/interfaces/abstractexpression.cpp \
    src/expression/variable.cpp \
    src/expression/number.cpp \
    src/expression/binaryexpression.cpp \
    src/program_statemachine/programstatemachine.cpp \
    src/expression_statemachine/expressionstatemachine.cpp \
    src/expression_statemachine/abstractes.cpp \
    src/program_statemachine/abstractps.cpp \
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
    src/lexer/lexer.cpp

HEADERS += \
    src/interfaces/abstractstate.h \
    src/interfaces/abstractstatemachine.h \
    src/interfaces/abstractexpression.h \
    src/types.h \
    src/expression/variable.h \
    src/expression/number.h \
    src/expression/binaryexpression.h \
    src/program_statemachine/programstatemachine.h \
    src/expression_statemachine/expressionstatemachine.h \
    src/expression_statemachine/abstractes.h \
    src/program_statemachine/abstractps.h \
    src/expression_statemachine/states/es0.h \
    src/program_statemachine/states/ps0.h \
    src/expression_statemachine/states/es1.h \
    src/expression_statemachine/states/es2.h \
    src/expression_statemachine/states/es3.h \
    src/expression_statemachine/states/es4.h \
    src/expression_statemachine/states/es5.h \
    src/expression_statemachine/states/es6.h \
    src/expression_statemachine/states/es7.h \
    src/expression_statemachine/states/es8.h \
    src/expression_statemachine/states/es9.h \
    src/expression_statemachine/states/es10.h \
    src/expression_statemachine/states/es11.h \
    src/expression_statemachine/states/es12.h \
    src/expression_statemachine/states/es13.h \
    src/expression_statemachine/states/es14.h \
    src/expression_statemachine/states/es15.h \
    src/expression_statemachine/states/es16.h \
    src/expression_statemachine/states/es17.h \
    src/program_statemachine/states/ps1.h \
    src/program_statemachine/states/ps2.h \
    src/program_statemachine/states/ps3.h \
    src/program_statemachine/states/ps4.h \
    src/program_statemachine/states/ps5.h \
    src/program_statemachine/states/ps6.h \
    src/program_statemachine/states/ps7.h \
    src/program_statemachine/states/ps8.h \
    src/program_statemachine/states/ps9.h \
    src/program_statemachine/states/ps10.h \
    src/program_statemachine/states/ps11.h \
    src/program_statemachine/states/ps12.h \
    src/program_statemachine/states/ps13.h \
    src/program_statemachine/states/ps14.h \
    src/program_statemachine/states/ps15.h \
    src/program_statemachine/states/ps16.h \
    src/program_statemachine/states/ps17.h \
    src/program_statemachine/states/ps18.h \
    src/program_statemachine/states/ps19.h \
    src/program_statemachine/states/ps20.h \
    src/program_statemachine/states/ps21.h \
    src/program_statemachine/states/ps22.h \
    src/program_statemachine/states/ps23.h \
    src/program_statemachine/states/ps24.h \
    src/program_statemachine/states/ps25.h \
    src/program_statemachine/states/ps26.h \
    src/program_statemachine/states/ps27.h \
    src/program_statemachine/states/ps28.h \
    src/program_statemachine/states/ps29.h \
    src/lexer/lexer.h

DISTFILES += \
    src/make_states.sh
