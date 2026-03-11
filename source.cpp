#include "source.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> 
#include <chrono>
#include <cmath>

// Default constructor, essentially just the most primitive initialisation
Source::Source() : source_type("Unspecified"), source_acquisition_date("Unspecified"), source_activity(0), source_ID(0) {}

// Paramaterzied constructor, 
Source::Source(std::string type, std::string date, double activity)
{
    set_source_type(type);
    set_source_acquisition_date(date);
    set_source_activity(activity);

    // Calculates the current time since epoch (the system boot) using the steady clock (one of the three clocks in the chrono namespace)
    // Steady clock is monotonic, it will never go backwards in time, each moment in time therefore has a unique time duration since the epoch. 
    // The time is then extracted as an integer and set as the source ID
    auto current_time = std::chrono::steady_clock::now();
    auto duration = current_time.time_since_epoch();
    source_ID = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();

}
// Destructor 
Source::~Source() {}

// Getter
std::string Source::get_source_type() const {return source_type;}
std::string Source::get_source_acquisition_date() const {return source_acquisition_date;}
double Source::get_source_activity() const {return source_activity;}
long long Source::get_source_ID() const {return source_ID;}

// Setters (validation required)

void Source::set_source_type(std::string type)
{
    source_type = type;
}

void Source::set_source_acquisition_date(std::string date)
{
    source_acquisition_date = date;
}

void Source::set_source_activity(double activity)
{
    source_activity = activity;
}


// Display all relevant source information

void Source::display_information() const
{
    std::cout << "\nSource Information;";
    std::cout << "\nSource type - " << source_type <<",";
    std::cout << "\nSource acquisition date - " << source_acquisition_date <<",";
    std::cout << "\nSource activity - " << source_activity <<" Bq,";
    std::cout << "\nUnique source ID - " << source_ID <<".";
}
