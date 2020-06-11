#include "version.h"

#define __BDATE__      "2020-06-11 18:01:49"
#define __BVERSION__   "1.0.002"

const char * getVersion()
{
    return __BVERSION__;
}

const char * getBuildDate()
{
    return __BDATE__;
}
