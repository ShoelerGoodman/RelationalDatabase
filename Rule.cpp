#include "Rule.h"

Rule::Rule()
{
    HeadPredicate = 0;
    predicateList = 0;
}

Rule::~Rule()
{

}

void Rule::setHeadPredicate(Scheme* inputHeadPredicate)
{
    HeadPredicate = inputHeadPredicate;
    return;
}

void Rule::setPredicateList(PredicateList* inputPredicateList)
{
    predicateList = inputPredicateList;
    return;
}

int Rule::getSize()
{
    return predicateList->getSize() + 1;
}

std::string Rule::toString()
{
    std::string out;
    out += "\n  " + HeadPredicate->toString();
    out += " :-";
    out += predicateList->toString();
    out += ".";
    return out;
}

Scheme* Rule::getHeadPredicate()
{
    return HeadPredicate;
}

PredicateList* Rule::getPredicateList()
{
    return predicateList;
}

Token* Rule::getHeadPredicateID()
{
    return HeadPredicate->getSchemeID();
}

vector<Token> Rule::getHeadPredicateParameters()
{
    vector<Token> newVec;
    vector<Token*>* parameters = HeadPredicate->getIDList()->getIDs();
    for(int i = 0; i < parameters->size(); i++)
    {
        newVec.push_back((*(*parameters)[i]));
    }
    return newVec;
}

vector<Token>* Rule::getParametersAt(int index)
{
    if(index > (predicateList->getSize()))
    {
        return 0;
    }
    else
    {
        vector<Token>* newVec = new vector<Token>();
        vector<Parameter*>* parameters = (*predicateList->getPredicates())[index]->getParameterList()->getParameters();
        for(int i = 0; i < parameters->size(); i++)
        {
            newVec->push_back((*(*parameters)[i]->getParameterToken()));
        }
        return newVec;
    }
}

Token* Rule::getParameterIDAt(int index)
{
    if(index > (predicateList->getSize()))
    {
        return 0;
    }
    else
    {
        Token* newToken = (*predicateList->getPredicates())[index]->getPredicateID();
        return newToken;
    }
}
