# Assignment 3 - Nuclear Physics Simulation Experiment

## Program Brief

This program simulates a 2nd year nuclear physics laboratory experiment by modelling multiple radioactive source types and their interactions with different detector types. The program; 

- Loads source information from “source.txt” containing source type, source acquisition date and source activity. 
- Loads detector information from “detector.txt” containing detector type and “ON / OFF”. 
- Validates all given inputs in their respective setter functions. 
- Generates an identification number for each source using the ```<chrono>``` package’s nanosecond timestamps on a monotonic clock to ensure all IDs are unique. 
- Simulates count measurements using the ```<random>``` package to generate random radiation counts for each source-detector pair, provided the detector is in an “ON” state. 
- Displays the results for each source detector combination and all information of each source and each detector. 
- Handles errors gracefully by flagging invalid inputs and exiting the program with detailed reasons for each error. 

## Compilation code

For Windows;
- g++ main.cpp source.cpp detector.cpp -o assignment-3.exe -std=gnu++17   
- Then run assignment-3.exe 

For Mac/Linux;
- g++-11 main.cpp source.cpp detector.cpp -o assignment-3.o -std=gnu++17  
- Then run Assignment-3.o

Note: please ensure the "sources.txt" and "detectors.txt" files are in the same directory as the created executable.

## Program Structure

This program is split into 7 files,  

Main.cpp;
- Entry point of program. 
- Reads in sources.txt and detectors.txt using stringstream parsing, utilising try catch encase an input is invalid. If an input is invalid (such as a string in place of an int) the error is  caught and the line is skipped. 
- Creates vectors to store both Source and Detector objects. 
- Validates inputs using the valid_flag members of the source and detector class, if any inputs are flagged invalid, this is the exit point of the code. 
- Simulates via an iterated loop, each source is run through each detector generating a randomised count rate. 
- Calls display functions to output the source and detector information.

Detector.h; 
- Defines detector class, with private members, detector_type, on_off_status, counts and valid_flag.
- Declares public methods; default constructor, parameterised constructor, destructor, getters and setters (for each member respectively).
- Declares the core functions, generate counts and display information. 
- Utilises header guards to prevent multiple inclusions.

Detector.cpp;
- Implements a valid default constructor. 
- Implements the parameterised constructor. 
- Implements getters for all private members.
- Implements setters and validates each member of the detector class.
  - set_detector_type validates by matching the detector input to one of the 3 available detector types (Scintillator, Germanium, Geiger)
  - set_on_off_status validates by converting the "ON/OFF" strings into a boolean values.
- Generate counts function uitilises the ```<random>``` library to create a uniform distribution and select a random value to assign to counts (provided detector is in an ON state)
- Display function show the detector type, status and counts.

Detector.txt;
- Configures data in a csv format, "type,status" for each detector. 
- Examples entries are shown in the file, including invalid entries.

Source.h 
- Defines source class with private members, source_type, source_acquisition_date, source_activity, source_ID and valig_flag. 
- Declares public methods; default constructor, parameterised constructor, detectors, getters and setters (for each member respectively) 
- Declares the core function display information.
- Utilises header guards to prevent multiple inclusions.

Source.cpp;
- Implements a valid default constructor.
- Implements the parameterised constructor. 
- Implements getters for all private members.
- Implements setters and validates each member of the source class.
  - set_source_type validates by matching to a predefined isotope list.
    - "Na-22","Cs-136","Co-92","Eu-152","Cs-137","I-131","Am-241","Sr-90","Pt-239","U-235" & "C-14".
  - set_source_acquisition _date parses the date into individual day, month, year and validates each individually.
  - set_source_activity validates the activity within 0 - 1x10^9 Bq / kg.
- Generates a unique ID using the ```<chrono>``` package to take a nanosecond timestamp on a monotonic clock, this ensures all IDs aren't duplicated. 
- Display function to show the source types, acquisition dates, activity and identification number.

Source.txt 
- Configures data in a csv format, "type,date,activity" 
- Example entries are shown in file, including invalid entries

## Development Process

This code was developed in 6 phases,  

Phase 1 – Code skeleton and class foundation; 

- Created Source and Detector class skeletons. 
- Implemented private members and public declarations (constructors, destructors, getters, setters and core functions) 
- Created header files with associated guards.
- Created the main and source + detector text files.

Phase 2 – Input validation; 

- Added validation logic to the respective setter functions. 
- Added an isotope checklist for the source isotopes. 
- Added a detector checklist for valid detectors. 
- Parsed data for formatting and validation (acquisition dates) 
- Integrated valid_flag for error tracking (This was not my first idea and was later implemented as a suggestion from “DeepSeek”) 

Phase 3 – Unique identification; 

- Utilised the ```<chrono>``` library to create a nanosecond timestamp. 
- First used the high-resolution clock and switched to steady clock after research that the steady clock is monotonic. 

Phase 4 – File reading; 

- Added stringstream to parse both the Source and Detector input files in main. 
- Implemented try-catch error handling for invalid lines (This code was taken from my previous assignment and modified to fit this assignment) 
- Created vector storage for the loaded source and detector objects. 

Phase 5 – Core Simulation; 

- Utilised the ```<random>``` library to randomly generate a number from a uniform distribution. 
- Implemented a generate counts function. 
- Created an iterative loop in the main to simulate each source detector pair. 

Phase 6 – Testing; 

- Tested input validation extensively. 
- Created README. 

Note that, due to an issue with my laptop. I can only create new repositories by first duplicating a previous one, then deleting everything contained inside it, and renaming it to a new repository. There seems to have been an issue with this commit's history displaying Assignment 2 commits. 

## Decleration of AI usage

AI tools were utilized in this coding process to;
- Debug and provide solutions to code errors.
- Provide feedback to code quality, and suggestions for improvement.

The core program logic, strutures and algorithms were developed independently by the student (11022726). With AI tools serving as an invaluable tool for debugging and review purposes.
