#include "source.h"
#include <iostream>
#include <vector>
// Include any more useful libraries 

// Default constructor, essentially just the most primitive initialisation
Source::Source() : source_type("Unspecified"), source_acquisition_date("Unspecified"), source_activity(0), source_ID(0) {}

// Paramaterzied constructor, 
Source::Source(std::string type, std::string date, double activity, int ID)
{
    set_source_type(type);
    set_source_acquisition_date(date);
    set_source_activity(activity);
    set_source_ID(ID);
    //Create a random number generator, potentially linking to the time
}
// Destructor 
Source::~Source() {}

// Getter
std::string Source::get_source_type() const {return source_type;}
std::string Source::get_source_acquisition_date() const {return source_acquisition_date;}
double Source::get_source_activity() const {return source_activity;}
int Source::get_source_ID() const {return source_ID;}

// Setters (validation required)

void Source::set_source_type(std::string type)
{

}

void Source::set_source_acquisition_date(std::string date)
{

}

void Source::set_source_activity(double activity)
{

}

void Source::set_source_ID(int ID)
{

}

// Display info 

void Source::display_information() const
{
    
}