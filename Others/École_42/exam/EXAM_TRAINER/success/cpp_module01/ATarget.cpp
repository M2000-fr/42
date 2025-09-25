#include "ATarget.hpp"

ATarget::ATarget(const std::string& _type)
{
    this->type = _type;
}

const std::string& ATarget::getType() const
{
    return(this->type);
}

void ATarget::getHitBySpell(const ASpell& spell) const
{
    std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}