#!/bin/bash

# --------------------------------------- VARS --------------------------------------

CLASS_NAME="${1}"
CLASS_NAME_LW=$(echo "${CLASS_NAME}" | tr '[:upper:]' '[:lower:]')
CLASS_NAME_UP=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')
TARGET_NAME="${CLASS_NAME:8}"
TARGET_NAME_LW=$(echo "${TARGET_NAME}" | tr '[:upper:]' '[:lower:]')
TARGET_NAME_UP=$(echo "${TARGET_NAME}" | tr '[:lower:]' '[:upper:]')
DIR="${2}"
STATE_COUNT=${3}

# ------------------------------------ FUNCTIONS ------------------------------------

function generate_file {
    # - first status echo
    echo -n "Generating couple (${TARGET_NAME_LW}${1}.h,${TARGET_NAME_LW}${1}.cpp)..."
    # - retrieve templates
    HEADER_CONTENT=$(cat "${DIR}/${CLASS_NAME_LW}.h")
    SOURCE_CONTENT=$(cat "${DIR}/${CLASS_NAME_LW}.cpp")
    # - substitute in templates
    # -- in header
    HEADER_CONTENT=${HEADER_CONTENT//"${CLASS_NAME}"/"${TARGET_NAME}${1}"}
    HEADER_CONTENT=${HEADER_CONTENT//"interfaces/abstractstate.h"/"${DIR}/${CLASS_NAME_LW}.h"}
    HEADER_CONTENT=${HEADER_CONTENT//"AbstractState"/"${CLASS_NAME}"}
    HEADER_CONTENT=${HEADER_CONTENT//"(const string & name)"/"()"}
    HEADER_CONTENT=${HEADER_CONTENT//"${CLASS_NAME_UP}"/"${TARGET_NAME_UP}${1}"}
    HEADER_CONTENT=${HEADER_CONTENT//"#include \"programstatemachine.h\""/""}
    HEADER_CONTENT=${HEADER_CONTENT//"#include \"expressionstatemachine.h\""/""}
    # -- in source
    SOURCE_CONTENT=${SOURCE_CONTENT//"${CLASS_NAME}"/"${TARGET_NAME}${1}"}
    SOURCE_CONTENT=${SOURCE_CONTENT//"AbstractState"/"${CLASS_NAME}"}
    SOURCE_CONTENT=${SOURCE_CONTENT//"(const string & name)"/"()"}
    SOURCE_CONTENT=${SOURCE_CONTENT//"(name)"/"(\"${CLASS_NAME}\")"}
    SOURCE_CONTENT=${SOURCE_CONTENT//"${CLASS_NAME_LW}.h"/"${TARGET_NAME_LW}${1}.h"}
    # - create files
    echo "${HEADER_CONTENT}" > "${DIR}/states/${TARGET_NAME_LW}${1}.h"
    echo "${SOURCE_CONTENT}" > "${DIR}/states/${TARGET_NAME_LW}${1}.cpp"
    # - final status echo
    echo "done !"
}

# --------------------------------------- SCRIPT --------------------------------------

# - check user inputs
if [ "${CLASS_NAME}" == "" ] || [ "${DIR}" == "" ] || [ "${STATE_COUNT}" == "" ]; then
    echo "Missing at least one argument."
    echo "Usage : ./make_states.sh <class_name> <dir> <state_count>"
    echo "Example : ./make_states.sh AbstractES expression_statemachine 12"
    exit
else
    echo "--------------- params ------------------"
    echo "Class name    :   ${CLASS_NAME}"
    echo "Class name lw :   ${CLASS_NAME_LW}"
    echo "Destination   :   ${DIR}"
    echo "State count   :   ${STATE_COUNT}"
fi

# -
read -p "Are you sure you want to erase old states ? " -n 1 -r
echo    # (optional) move to a new line
if [[ $REPLY =~ ^[Yy]$ ]]; then
    # - generate states
    echo "--------------- running ------------------"
    # -- make state directory if inexistant
    if [ ! -d "${DIR}/states" ]; then
        echo -n "Creating missing directory (${DIR}/states)..."
        mkdir "${DIR}/states"
        echo "done !"
    fi
    # -- run creation loop
    for (( c=1; c<=${STATE_COUNT}; c++ ))
    do
        generate_file $[${c} - 1]
    done
    echo "--------------- stopped ------------------"
else
    exit
fi


