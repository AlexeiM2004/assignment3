#include "detector.h"
#include <iostream>
#include <vector>
//Include any more useful libraries 

// Default constructor, essentially just the most primitive initialisation
Detector::Detector() : detector_type("Unspecified"), on_off_status(false), counts(0), valid_flag(true) {}

// Paramaterzied constructor, 
Detector::Detector(std::string type, std::string status) : valid_flag(true)
{
    set_detector_type(type);
    set_on_off_status(status);
    counts = 0;
    //Create a random number generator, potentially linking to the time
}
// Destructor 
Detector::~Detector() {}

// Getter
std::string Detector::get_detector_type() const {return detector_type;}
bool Detector::get_on_off_status() const {return on_off_status;}
bool Detector::is_valid() const {return valid_flag;}
int Detector::get_counts() const {return counts;}

// Setters (validation required)

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
void Detector::set_on_off_status(std::string status)
{
    if(status == "ON")
    {
        on_off_status = true;
    }else if(status == "OFF")
    {
        on_off_status = false;
    }else{
        std::cout << "\nInvalid on/off status input, please use a valid status inpit.\n";
        std::cout << "\nValid input types are;";
        std::cout << "\nON";
        std::cout << "\nOFF";
        std::cout << "\nNote that, input is case sensitive.\n";
        valid_flag = false;
    }

}

// Main functionality function, is detector on? what source is used, generate a random number

int Detector::generate_counts(const Source& source)
{
    return 0;
}  

// Display info 

void Detector::display_information() const
{
    std::cout << "\nDetector Information;";
    std::cout << "\nDetector type - " << detector_type <<",";
    std::cout << "\nDetector status, (0 = OFF, 1 = ON), " << on_off_status <<".";
}
