#include "detector.h"
#include <iostream>
#include <vector>
#include <random>

// Default constructor

Detector::Detector() : detector_type("Unspecified"), on_off_status(false), counts(0), valid_flag(true) {}

// Paramaterzied constructor,

Detector::Detector(std::string type, std::string status) : valid_flag(true)
{
    set_detector_type(type);
    set_on_off_status(status);
    counts = 0;
}

// Destructor 

Detector::~Detector() {}

// Getters

std::string Detector::get_detector_type() const {return detector_type;}
bool Detector::get_on_off_status() const {return on_off_status;}
int Detector::get_counts() const {return counts;}

// Setters

// Detector type setter with validation

void Detector::set_detector_type(std::string type)
{
    if(type == "Germanium" || type == "Scintillator" || type == "Geiger")
    {
        detector_type = type;       
    }else{
        std::cout << "\nInvalid detector input, please use a valid detector type.\n";
        std::cout << "\nValid detector types are;";
        std::cout << "\nGermanium";
        std::cout << "\nScintillator";
        std::cout << "\nGeiger";
        std::cout << "\nNote that, input is case sensitive and 'Detector' is not required.\n";
        detector_type = type;
        valid_flag = false;
    }

}

// Detector status setter with validation

void Detector::set_on_off_status(std::string status)
{
    if(status == "ON")
    {
        on_off_status = true;
    }else if(status == "OFF")
    {
        on_off_status = false;
    }else{
        std::cout << "\nInvalid on/off status input, please use a valid status input.\n";
        std::cout << "\nValid input types are;";
        std::cout << "\nON";
        std::cout << "\nOFF";
        std::cout << "\nNote that, input is case sensitive.\n";
        on_off_status = false;
        valid_flag = false;
    }

}

// Generate counts function

int Detector::generate_counts(const Source& source)
{
    // Uses the random package to generate a random number from 1 to 10000 using the uniform distribution (all equally likely)
    static std::default_random_engine generate_random_number(std::random_device{}());
    static std::uniform_int_distribution<> uniform_number_distribution(1, 10000);
    if(on_off_status == true)
    {
        counts = uniform_number_distribution(generate_random_number);
        return counts;
    }else{
        counts = 0;
    }
    return 0;
}  

// Display all relevant detector information function

void Detector::display_information() const
{
    std::cout << "\nDetector Information;";
    std::cout << "\nDetector type - " << detector_type <<",";
    std::cout << "\nDetector status, " << on_off_status <<", (0 = OFF, 1 = ON).";
}
