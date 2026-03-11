#ifndef SOURCE_H 
#define SOURCE_H
// Header guard, prevending the same header being included more than once

#include <string>

class Source
{
private:
// Define type, acquistion date, activity and unique identifiers
    std::string source_type;
    std::string source_acquisition_date;
    double source_activity;
    long long source_ID;
public:
    Source(); // Define default constructor, this is the house special, containing default (but validated ingredients)
    Source(std::string type, std::string date, double activity); // Define parameterised constructor, this is a source, created with custom toppings
    ~Source(); // Define destructor, defines what to do when a source needs to be removed (like cleaning up the table)
// Define getters, for each member
    std::string get_source_type() const; 
    std::string get_source_acquisition_date() const;
    double get_source_activity() const;
    long long get_source_ID() const;
// Define setters, for each member
    void set_source_type(std::string type);
    void set_source_acquisition_date(std::string date);
    void set_source_activity(double activity);
    void set_source_ID(long long ID);
// Define any other function used
    void display_information() const;
};

#endif // Ends header guard