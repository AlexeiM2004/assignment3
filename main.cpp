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
                detectors.push_back(d);
                
            } catch(...) {}
        }
    }
    detector_file.close();

    std::cout << "Loaded " << sources.size() << " sources successfully.\n";
    std::cout << "Loaded " << detectors.size() << " detectors successfully.\n";
    for(const Source& source : sources)
    {
        std::cout << source.get_source_type() << "\n";
        std::cout << source.get_source_acquisition_date() << "\n";
        std::cout << source.get_source_activity() << "\n";
        std::cout << source.get_source_ID() << "\n";
    }
    for(const Detector& detector : detectors)
    {
        std::cout << detector.get_detector_type() << "\n";
        std::cout << detector.get_on_off_status() << "\n";
    }
    return 0;
}