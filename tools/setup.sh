#!/bin/bash

#set -x

function usage()
{
    echo ""
    echo "$(basename ${0}) <Name> <UVA PDF URL>"
    echo ""
    echo "Quick setup tool for a given UVA problem. Downloads"
    echo "PDF problem and creates template solution files."
    echo ""
    echo ""
    echo "e.g."
    echo " $(basename ${0}) Score https://onlinejudge.org/external/15/p1585.pdf"
    echo ""
}

if [ $# -ne 2 ]
then
    usage ${0}
    exit 1
fi

name=${1}
pdfurl=${2}

if [[ $pdfurl != *.pdf ]]
then
    echo "ERROR: ${pdfurl} must end in .pdf please"
    exit 2
fi

number=$(echo $(basename ${pdfurl}) | grep -o -E "[0-9]+")

echo "Downloading problem ${number} PDF: ${pdfurl}"

wget --quiet -r ${pdfurl} -O $(basename ${pdfurl})

target=../working/${number}-${name}

echo "Setting up ${TARGET}"

if [ -d ${target} ]
then
    echo "ERROR: Directory ${target} already exists!"
    exit 2
fi

mkdir -p ${target}

mv $(basename ${pdfurl}) ${target}
cp ./judge.sh ${target}
cp ../src/competitive.cpp ${target}/${number}.cpp
touch ${target}/input1.txt
touch ${target}/expected1.txt
cat > ${target}/notes.md <<EOF
# UVa ${number} ${name}

   * ${pdfurl}

## Categories

   *

## Approach

## Hints

   *

## Optimisations

   * None attempted.
EOF

cd ${target}
