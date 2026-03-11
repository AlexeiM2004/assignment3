// 
// 
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

    std::cout << "\nLoaded " << sources.size() << " sources successfully.\n";
    std::cout << "\nLoaded " << detectors.size() << " detectors successfully.\n";

    Source default_source_constructor_test;
    default_source_constructor_test.display_information();
    std::cout << "\n";

    Source default_source_constructor_test_again;
    default_source_constructor_test_again.display_information();
    std::cout << "\n";


    Detector default_detector_constructor_test;
    default_detector_constructor_test.display_information();
    std::cout << "\n";

    std::cout << "\nSOURCE TYPES\n";
    for(const Source& source : sources)
    {
        source.display_information();
        Source();
        std::cout << "\n";
    }
    std::cout << "\nDETECTOR TYPES\n";
    for(const Detector& detector : detectors)
    {
        detector.display_information();
        std::cout << "\n";
    }

    return 0;
}