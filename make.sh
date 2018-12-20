#!/bin/bash
echo "Generating map..."
python src/mapreader.py $1
ret=$?
if [ $ret -ne 0 ]; then
  echo "Skipping compliation..."
  exit
fi
echo "Map generated!"
echo "Compiling test program..."
if g++ -o testMap src/testMap.cpp; then 
  echo "Test program compiled!";
else 
  echo "Test program compilation resulted in error :(";
  echo "Likely that the generated map was the wrong size."
  exit
fi
echo "Testing map.h..."
if ./testMap; then
  echo "map.h is good to go!"
  rm -f testMap
else
  echo "map.h resulted in errors, panic (likely something else has manipulated map.h, this shouldn't be possible if compilation succeeded, which it apparently did."
  rm -f testMap
  exit
fi
echo "Compiling main program..."
if g++ -pthread -o flow src/main.cpp; then 
  echo "Program compiled!";
else 
  echo "Program compilation resulted in error :(";
  exit
fi