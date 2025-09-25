#include "ASpell.hpp"

ASpell::ASpell(const std::string& _name, const std::string& _effects)
{
    this->name = _name;
    this->effects = _effects;
}


const std::string& ASpell::getName() const
{
    return(this->name);
}

const std::string& ASpell::getEffects() const
{
    return(this->effects);
}


void ASpell::launch(const ATarget& target) const
{
    target.getHitBySpell(*this);
}
