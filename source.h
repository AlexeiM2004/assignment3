#ifndef SOURCE_H 
#define SOURCE_H
// Header guard

#include <string>

class Source
{
private:
    std::string source_type;
    std::string source_acquisition_date;
    double source_activity;
    long long source_ID;
    // valid_flag is an input validator, allowing the program to exit gracefully if an error is detected
    bool valid_flag;
public:
    Source(); // Default constructor
    Source(std::string type, std::string date, double activity); // Parameterised constructor
    ~Source(); // Destructor
// Getters for each member
    std::string get_source_type() const; 
    std::string get_source_acquisition_date() const;
    double get_source_activity() const;
    long long get_source_ID() const;
    bool is_valid() const {return valid_flag;}
// Setters for each member
    void set_source_type(std::string type);
    void set_source_acquisition_date(std::string date);
    void set_source_activity(double activity);
    void set_source_ID(long long ID);
// Helper function for displaying source information
    void display_information() const;
};

#endif // Ends header guard