// Assignment 3 - Nuclear Physics Experiment.
// Practicing with classes by simulating a detector source system. 
// Passing a source with a uniquely generated ID into a detector and generating a random count number.
// Alexei Maiorov, Student ID: [11022726]
// Date: [11/03/2026]

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "source.h"
#include "detector.h"
#include <sstream>
#include <fstream>

int main()
{
    //Read in the sources file

    std::ifstream source_file("sources.txt");
    std::string source_data;

    std::vector<Source> sources;

    while(std::getline(source_file,source_data))
    {
        std::stringstream ss(source_data);
        std::string type,date,activity_string;
        if(std::getline(ss, type, ',') && std::getline(ss, date, ',') && std::getline(ss, activity_string, ','))
        {
            try
            {
                // Convert strings into double
                double activity = std::stod(activity_string);
                //This converts the string from the file into a double
                Source s(type, date, activity);
                sources.push_back(s);
            } catch(...) {}
        }
    }
    source_file.close();

    //Read in the detectors file

    std::ifstream detector_file("detectors.txt");
    std::string detector_data;

    std::vector<Detector> detectors;

    while(std::getline(detector_file,detector_data))
    {
        std::stringstream ss(detector_data);
        std::string type,status_string;
        if(std::getline(ss, type, ',') && std::getline(ss, status_string, ','))
        {
            try
            {
                Detector d(type, status_string);
                detectors.push_back(d);
                
            } catch(...) {}
        }
    }
    detector_file.close();


    // If an invalid input was flagged in the detector.cpp, the program exits gracefully by returning 1
    for(const Detector& detector : detectors)
    {
        if(detector.is_valid() == false)
        {
            std::cout << "\nExiting program.";
            return 1;
        }
    }

    // If an invalid input was flagged in the source.cpp, the program exits gracefully by returning 1
    for(const Source& source : sources)
    {
        if(source.is_valid() == false)
        {
            std::cout << "\nExiting program.";
            return 1;
        }
    }

    // Informs the user how many sources / detectors were read in. If an issue is detected in the file, the source / detector wont be read in 

    std::cout << "\nLoaded " << sources.size() << " sources successfully.\n";
    std::cout << "\nLoaded " << detectors.size() << " detectors successfully.\n";

    // Default source constructor, uncomment to test if a valid default constructor is created
    // Source default_source_constructor_test;
    // default_source_constructor_test.display_information();
    // std::cout << "\n";

    // Default detector constructor, uncomment to test if a valid default constructor is created
    // Detector default_detector_constructor_test;
    // default_detector_constructor_test.display_information();
    // std::cout << "\n";

    // This loops through each detector with each source and its randomly generated counts

    for(Detector& detector : detectors)
    {
        for(const Source& source : sources)
        {
            int counts = detector.generate_counts(source);
            std::cout << "\nDetector type: " << detector.get_detector_type() << ", with source: " << source.get_source_type() << ", Counts detected: " << detector.get_counts();
        }
    }

    std::cout << "\n";

    // Loops through all the source types, with their respective information

    std::cout << "\nSOURCE TYPES\n";
    for(const Source& source : sources)
    {
        source.display_information();
        Source();
        std::cout << "\n";
    }

    // Loops through all the detector types, with their respective information

    std::cout << "\nDETECTOR TYPES\n";
    for(const Detector& detector : detectors)
    {
        detector.display_information();
        std::cout << "\n";
    }

    return 0;
}