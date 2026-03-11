#include "detector.h"
#include <iostream>
#include <vector>
//Include any more useful libraries 

// Default constructor, essentially just the most primitive initialisation
Detector::Detector() : detector_type("Unspecified"), on_off_status(false), counts(0) {}

// Paramaterzied constructor, 
Detector::Detector(std::string type, bool status)
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
        std::cout << "\nNote that, input is case sensitive and 'Detector' is not required";
        int invalid_detector_input = 0;
        detector_type = invalid_detector_input;
    }

}
void Detector::set_on_off_status(bool status)
{
    on_off_status = status;
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
    std::cout << "\nDetector status, (0 = OFF, 1 = ON) - " << on_off_status <<".";
}
