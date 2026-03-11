#include "source.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include <chrono>
#include <cmath>
#include <sstream>

// Default constructor, essentially just the most primitive initialisation
Source::Source() : source_type("Unspecified"), source_acquisition_date("Unspecified"), source_activity(0), source_ID(0), valid_flag(true) {}

// Paramaterzied constructor, 
Source::Source(std::string type, std::string date, double activity) : valid_flag(true)
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
    // A static vector containing all valid source types. 
    static std::vector<std::string> valid_isotope_list = {
        "Na-22","Cs-136","Co-92","Eu-152","Cs-137","I-131","Am-241","Sr-90","Pt-239","U-235","C-14"
    };
    // Checks the type against the static vector
    if(std::find(valid_isotope_list.begin(), valid_isotope_list.end(), type) != valid_isotope_list.end())
    {
        source_type = type;
    }else{
        std::cout << "\nInvalid source type input, please use a valid source type.\n";
        std::cout << "\nValid input types are;\n";
        for(const auto& isotope : valid_isotope_list)
        {
            std::cout << isotope << "\n";
        }
        std::cout << "\nNote that, input is case sensitive and follows the format ELEMENT-MASS No.\n";
        source_type = type;
        valid_flag = false;
    }
}

// This function takes the date read off the file, splits it into 3 variables, then validates each one individually
// If the DD/MM/YYYY format isnt followed then it is flagged invalid

void Source::set_source_acquisition_date(std::string date)
{
    source_acquisition_date = date;

    std::stringstream ss(date);
    std::string day_string, month_string, year_string;

    // The string into 3 parts using the given '/' delimiter
    if(std::getline(ss, day_string, '/') && std::getline(ss, month_string, '/') && std::getline(ss, year_string, '/'))
    {
        int day = std::stoi(day_string);
        int month = std::stoi(month_string);
        int year = std::stoi(year_string);
        if(day <= 0 || day > 31 ||
            month <= 0 || month > 12 ||
            year < 1898 || year > 2026)
        {
            std::cout << "\nInvalid date, month or year input.";
            std::cout << "\nValid input types are, DD (1-31), MM (1-12), YYYY(1898-2026)";
            valid_flag = false;
        } 
    }else{
        std::cout << "\nInvalid DD/MM/YYY input format.";
        std::cout << "\nPlease use the DD/MM/YYYY format.";
        valid_flag = false;
    }
}

void Source::set_source_activity(double activity)
{
    if(activity <= 0 || activity > 1e9){
        std::cout << "\nInvalid activity, please input an activity within the range of 1-1x10^9";
        valid_flag = false;
    }
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
