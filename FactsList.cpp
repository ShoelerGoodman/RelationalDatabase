#include "FactsList.h"

FactsList::FactsList()
{
    int listSize = 0;
}

FactsList::~FactsList()
{

}

void FactsList::addFact(Fact* inputFact)
{
    facts.push_back(inputFact);
    ++listSize;
    return;
}

int FactsList::getSize()
{
    return listSize;
}

std::string FactsList::toString()
{
    std::string out;
    for(int i = 0; i < listSize; ++i)
    {
        out += facts[i]->toString();
    }
    return out;
}

vector<Fact*>* FactsList::getFacts()
{
    vector<Fact*>* facsh = new vector<Fact*>();
    for(int i = 0; i < facts.size(); i++)
    {
        facsh->push_back(facts[i]);
    }
    return facsh;
}
