#ifndef DETECTOR_H 
#define DETECTOR_H
// Header guard

#include <string>
#include "source.h"

class Detector
{
private:
    std::string detector_type;
    bool on_off_status;
    // valid_flag is an input validator, allowing the program to exit gracefully if an error is detected
    bool valid_flag;
    int counts;
public:
    Detector(); // Default constructor
    Detector(std::string type, std::string status); // Parameterised constructor
    ~Detector(); // Destructor
// Getters for each member
    std::string get_detector_type() const;
    bool get_on_off_status() const;
    bool is_valid() const {return valid_flag;}
    int get_counts() const;
// Setters for each member
    void set_detector_type(std::string detector_type);
    void set_on_off_status(std::string on_off_status);
// Helper functions for count generation and displaying information 
    int generate_counts(const Source& source);
    void display_information() const;
};

#endif //End header guard
