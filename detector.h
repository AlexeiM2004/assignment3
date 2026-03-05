#ifndef DETECTOR_H 
#define DETECTOR_H
// Header guard, prevending the same header being included more than once

#include <string>
#include "source.h"

class Detector
{
private:
// Define type, on/off status and counts
    std::string detector_type;
    bool on_off_status;
    int counts;
public:
    Detector(); // Define default constructor
    Detector(std::string type, bool status); // Define parameterised constructor
    ~Detector(); // Define destructor
// Define getters for each member
    std::string get_detector_type() const;
    bool get_on_off_status() const;
    int get_counts() const;
// Define setters for each member (except counts, as that requires a seperate function to generate)
    void set_detector_type(std::string detector_type);
    void set_on_off_status(bool on_off_status);
// Define any other function used
    int generate_counts(const Source& source);
    const void display_information();
// Define any other functions  
};

#endif //Ends header guard
