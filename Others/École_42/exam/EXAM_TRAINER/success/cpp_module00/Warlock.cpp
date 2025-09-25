#include "Warlock.hpp"

Warlock::Warlock(const std::string& _name, const std::string& _title)
{
    this->name = _name;
    this->title = _title;

    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const
{
    return(this->name);
}

const std::string& Warlock::getTitle() const
{
    return(this->title);
}

void Warlock::setTitle(const std::string& str)
{
    this->title = str;
}

void Warlock::introduce() const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}
