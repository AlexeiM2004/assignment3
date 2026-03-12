# Assignment 3 - Nuclear Physics Simulation Experiment

## Program Brief

This program simulates a 2nd year nuclear physics laboratory experiment by modelling multiple radioactive source types and their interactions with different detector types. The program; 

- Loads source information from “source.txt” containing source type, source acquisition date and source activity. 
- Loads detector information from “detector.txt” containing detector type and “ON / OFF”. 
- Validates all given inputs in their respective setter functions. 
- Generates an identification number for each source using the <chrono> package’s nanosecond timestamps on a monotonic clock to ensure all IDs are unique. 
- Simulates count measurements using the <random> package to generate random radiation counts for each source-detector pair, provided the detector is in an “ON” state. 
- Displays the results for each source detector combination and all information of each source and each detector. 
- Handles errors gracefully by flagging invalid inputs and exiting the program with detailed reasons for each error. 

## Compilcation code

For windows;
-g++ main.cpp source.cpp detector.cpp -o assignment-3.exe -std=gnu++17 
Then run,
- assignment-3.exe 

For Mac/Lindux;
g++-11 main.cpp source.cpp detector.cpp -o assignment-3.o -std=gnu++17 
Then run,
Assignment-3.o 
- Note: please ensure the "sources.txt" and "detectors.txt" files are in the same directory as the created executable.

## Program Structure

## Development Process

## Decleration of AI usage

AI tools were utilized in this coding process to;
- Debug and provide solutions to code errors.
- Provide feedback to code quality, and suggestions for improvement.

The core program logic, strutures and algorithms were developed independently by the student (11022726). With AI tools serving as an invaluable tool for debugging and review purposes.
