#!/bin/bash

function usage()
{
    echo ""
    echo "$(basename ${0}) [options]"
    echo ""
    echo "UVA test harness/mock judge."
    echo ""
    echo "Options:"
    echo ""
    echo " -c        Run under cachegrind (not compatible with -r)."
    echo " -d        Debug. Do not define -DONLINE_JUDGE"
    echo " -i <n>    Only run input n."
    echo " -r <n>    Time n test runs."
    echo " -s <file> Override source file to test (default: ${SOURCE})"
    echo " -t <sec>  Time limit in seconds (default: ${TIME_LIMIT_SECS} second(s))"
    echo " -m <kb>   Memory limit in Kb (default: ${MEM_LIMIT_KB}Kb)"
    echo ""
}

function build()
{
    EXTENSION=$(basename ${SOURCE} | cut -d "." -f 2)

    if [ "${EXTENSION}" == "cpp" ]
    then
        COMMAND="g++ -Wall -g -O2 -lm -lcrypt -pipe ${DEFINES} ${SOURCE}"
    elif [ "${EXTENSION}" == "java" ]
    then
        cp ${SOURCE} Main.java
        COMMAND="javac Main.java"
    else
        echo "ERROR: File extension unknown, cannot build: ${SOURCE}"
        exit 1
    fi

    echo "${COMMAND}"
    ${COMMAND}
    check $? "CE"
    if [ "${EXTENSION}" == "java" ]
    then
        rm Main.java 2> /dev/null
    fi
}

function detect_source()
{
    if [ -f ${1} -a "${SOURCE}" == "none" ]
    then
        SOURCE=${1}
    fi
}

function check_source()
{
    if [ "${SOURCE}" == "none" ]
    then
        echo "ERROR: No source file specified. Please specify -s."
        exit 1
    fi

    if [ ! -f ${SOURCE} ]
    then
        echo "ERROR: Cannot find source file: ${SOURCE}"
        exit 1
    fi
}

function run_test()
{
    INPUT=${file}
    EXPECTED=$(echo ${file} | sed -s "s/input/expected/g")
    ACTUAL=$(echo ${file} | sed -s "s/input/actual/g")

    if [ "${EXTENSION}" == "cpp" ]
    then
        ulimit -S -t ${TIME_LIMIT_SECS} -v ${MEM_LIMIT_KB}
    fi
    
    if [ "${EXTENSION}" == "cpp" ]
    then
        if [ "${PRECMD}" == "none" ]
        then
            ./a.out < ${INPUT} > ${ACTUAL}
        else
            ${PRECMD} ./a.out < ${INPUT} > ${ACTUAL}
        fi
    elif [ "${EXTENSION}" == "java" ]
    then
        java Main < ${INPUT} > ${ACTUAL}
    else
        echo "ERROR: File extension unknown, cannot build: ${SOURCE}"
        exit 1
    fi
        
    check $? "RE"

    if [ ! -f ${EXPECTED} ]
    then
        touch ${EXPECTED}
    fi

    if [ "${EXTENSION}" == "cpp" ]
    then
        ulimit -S -v ${TOOL_MEM_LIMIT_KB}
    fi

    # Be verbose and show diffs for untimed runs
    if [ "${TIMED}" = "no" ]
    then
        diff_output -y
    else
        diff_output -q
    fi

    if [ "${CGPOSTCMD}" != "none" ]
    then
        ${CGPOSTCMD} $(/bin/ls -t cachegrind.out.* | head -1) ${SOURCE}
    fi
}

#
# $1 should be diff flag (e.g. -y or -q).
#
function diff_output()
{
    diff ${EXPECTED} ${ACTUAL} > /dev/null
    differences=$?

    diff -w ${EXPECTED} ${ACTUAL} > /dev/null
    space=$?
    
    diff ${1} ${EXPECTED} ${ACTUAL}
    
    if [ $differences -ne 0 ]
    then
        if [ $space -eq 0 ]
        then
            check $differences "PE"
        else
            check $differences "WA"
        fi
    fi
}

function timed_test()
{ 
    for i in $(seq 1 ${TIMED})
    do
        run_test
    done
}

function check()
{
    if [ ${1} -eq 137 ]
    then
        echo "=============================="
        echo "FAILED: TLE (${1})"
        exit 1
    fi
    if [ ${1} -ne 0 ]
    then
        echo "=============================="
        echo "FAILED: ${2} (${1})"
        exit 1
    fi
}


DEFINES=-DONLINE_JUDGE
INPUTS=all
SOURCE=none
TIMED=no
TIME_LIMIT_SECS=1
MEM_LIMIT_KB=16384
# Be more generous for diff/valgrind as these can need more memory
TOOL_MEM_LIMIT_KB=131072
PRECMD=none
CGPOSTCMD=none

ID=$(basename $(readlink -f .) | cut -d - -f 1)

detect_source ${ID}.cpp
detect_source ${ID}.java

while getopts ":cdhs:i:r:t:m:" opt
do
    case $opt in
        c)
            TIME_LIMIT_SECS=30
            PRECMD="valgrind --tool=cachegrind --branch-sim=yes"
            CGPOSTCMD="cg_annotate --auto=yes"
            MEM_LIMIT_KB=${TOOL_MEM_LIMIT_KB}
            ;;
        d)
            DEFINES=
            ;;
        s)
            SOURCE=${OPTARG}
            ;;
        i)
            INPUTS=${OPTARG}
            ;;
        r)
            TIMED=${OPTARG}
            ;;
        t)
            TIME_LIMIT_SECS=${OPTARG}
            ;;
        m)
            MEM_LIMIT_KB=${OPTARG}
            ;;
        h)
            usage
            exit 1
            ;;
        \?)
            echo "ERROR: Invalid option -$OPTARG"
            exit 1
            ;;
        :)
            echo "ERROR: Option -$OPTARG requires an argument."
            exit 1
            ;;
    esac
done

rm -f actual*.txt 2> /dev/null
rm a.out Main.class 2> /dev/null

check_source

build

if [ "${INPUTS}" = "all" ]
then
    INPUT_FILES=$(/bin/ls input*.txt)
else
    INPUT_FILES=input${INPUTS}.txt
fi

for file in ${INPUT_FILES}
do
    if [ ! -f ${file} ]
    then
        echo "ERROR: Failed to find input file: ${file}"
        exit 2
    fi

    echo ""
    echo "${file}"
    echo "=============================="

    if [ "${TIMED}" != "no" ]
    then
        time timed_test
    else
        run_test
    fi

    echo "=============================="
    echo "OK: AC"
done
