#!/bin/bash
while true
do
    # Compile the C++ code
    g++ -o a *.cpp

    # Run the program
    ./a

    # Wait for one second
    sleep 1
done
