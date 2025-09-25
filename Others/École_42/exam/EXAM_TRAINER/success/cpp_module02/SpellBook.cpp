#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
}

void SpellBook::learnSpell(ASpell* spell)
{
    if(spell)
    {
        spells.insert(make_pair(spell->getName(), spell->clone()));
    }
}

void SpellBook::forgetSpell(const string& name)
{
    map<string, ASpell*>::iterator it = spells.find(name);

    if(it != spells.end())
    {
       delete it->second;
       spells.erase(name);
    }
}

ASpell* SpellBook::createSpell(const string& name)
{
    map<string, ASpell*>::iterator it = spells.find(name);

    if(it != spells.end())
        return(it->second);
    else
        return(NULL);
}
