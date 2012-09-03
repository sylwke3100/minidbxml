#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion
{

//Software Status
static const char  _STATUS[] = "Beta1";
static const char  _STATUS_SHORT[] = "b";

//Standard Version Type
static const long  _MAJOR = 0;
static const long  _MINOR = 0;
static const long  _BUILD = 8;
static const long  _REVISION = 0;

//Miscellaneous Version Types
static const long  _BUILDS_COUNT = 300;
#define  _RC_FILEVERSION 0,0,8,0
#define  _RC_FILEVERSION_STRING "0, 0, 8, 0\0"
static const char  _FULLVERSION_STRING[] = "0.0.8.0";

//These values are to keep track of your versioning state, don't modify them.
static const long  _BUILD_HISTORY = 1;


}
#endif //VERSION_H
