// 
// 
// Alexei Maiorov, Student ID: [11022726]
// Date: [05/03/2026]

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
                // Converting status string into a bool
                bool status;
                if (status_string == "ON")
                {
                    status = true;
                }else{
                    status = false; 
                }

                Detector d(type, status);

                if(d.get_detector_type() == "0")
                {
                    std::cout << "\nExiting program.";
                    return 1;
                }

                detectors.push_back(d);
                
            } catch(...) {}
        }
    }
    detector_file.close();

    std::cout << "Loaded " << sources.size() << " sources successfully.\n";
    std::cout << "Loaded " << detectors.size() << " detectors successfully.\n";

    std::cout << "\nSOURCE TYPES\n";
    for(const Source& source : sources)
    {
        source.display_information();
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