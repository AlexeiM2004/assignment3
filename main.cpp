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
        std::string type,date,activity_string,ID_string;
        if(std::getline(ss, type, ',') && std::getline(ss, date, ',') && std::getline(ss, activity_string, ',') && std::getline(ss, ID_string, ','))
        {
            try
            {
                // Convert strings into double and int
                double activity = std::stod(activity_string);
                int ID = std::stoi(ID_string);
  
                //This converts the string from the file into a double
                Source s(type, date, activity, ID);
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
    return 0;
}