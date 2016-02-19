TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/interfaces/abstractstate.cpp \
    src/interfaces/abstractstatemachine.cpp \
    src/interfaces/abstractsymbole.cpp \
    src/interfaces/abstractexpression.cpp \
    src/expression/variable.cpp \
    src/expression/number.cpp \
    src/expression/binaryexpression.cpp \
    src/program_statemachine/programstatemachine.cpp \
    src/expression_statemachine/expressionstatemachine.cpp \
    src/expression_statemachine/abstractes.cpp \
    src/program_statemachine/abstractps.cpp \
    src/expression_statemachine/states/es0.cpp \
    src/program_statemachine/states/ps0.cpp

HEADERS += \
    src/interfaces/abstractstate.h \
    src/interfaces/abstractstatemachine.h \
    src/interfaces/abstractsymbole.h \
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
    src/program_statemachine/states/ps0.h

DISTFILES += \
    src/make_states.sh
