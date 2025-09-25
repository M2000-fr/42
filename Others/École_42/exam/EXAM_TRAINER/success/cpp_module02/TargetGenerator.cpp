#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if(target)
    {
        targets.insert(make_pair(target->getType(), target->clone()));
    }
}

void TargetGenerator::forgetTargetType(const string& type)
{
    map<string, ATarget*>::iterator it = targets.find(type);

    if(it != targets.end())
    {
       delete it->second;
       targets.erase(type);
    }
}

ATarget* TargetGenerator::createTarget(const string& type)
{
    map<string, ATarget*>::iterator it = targets.find(type);

    if(it != targets.end())
        return(it->second);
    else
        return(NULL);
}
