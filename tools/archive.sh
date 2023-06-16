#!/bin/bash

#set -x
set -e

function usage()
{
    echo ""
    echo "$(basename ${0}) <dir>"
    echo ""
    echo "Archive a solved problem from the 'working' directory into"
    echo "the 'solutions' directory and git commit it."
    echo ""
    echo ""
    echo "e.g."
    echo " $(basename ${0}) 1585-Score"
    echo ""
}

if [ $# -ne 1 ]
then
    usage ${0}
    exit 1
fi

problem=${1}
source=../working/${problem}

if [ ! -d ${source} ]
then
    echo "ERROR: Directory not found: ${source}"
    exit 2
fi

target=../solutions/${problem}

git diff-index --quiet --cached HEAD --

if [ $? -ne 0 ]
then
    echo "ERROR: There are staged changes in git, please check/correct."
    exit 4
fi

if [ -d ${target} ]
then
    echo "ERROR: ${problem} is already archived."
    exit 5
fi

cd ${source} && ./judge.sh && cd -

if [ $? -ne 0 ]
then
    echo "ERROR: Did not pass all test input, please check/correct."
    exit 3
fi

number=$(echo $(basename ${problem}) | grep -o -E "[0-9]+")

mkdir -p ${target}
cp -a ${source}/judge.sh ${target}
cp -a ${source}/notes.md ${target}
cp -a ${source}/input*.txt ${target}
cp -a ${source}/expected*.txt ${target}
cp -a ${source}/$number.cpp ${target}

git add ${target}
git commit -m "Added solution ${problem}"

echo "Archived ${problem}. Please check and if you're happy, run: rm -rf ${source}"
