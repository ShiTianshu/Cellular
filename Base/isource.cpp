#include "isource.h"

ISource::ISource()
{
}

ISource::~ISource()
{
    
}

ICursor::ICursor()
{
    
}

ICursor::~ICursor()
{
    
}

bool ICursor::hasNext() const
{
    return _hasNext;
}

void ICursor::setHasNext(bool hasNext)
{
    _hasNext = hasNext;
}
