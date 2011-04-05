#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char  _STATUS[] = "Alpha";
	static const char  _STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long  _MAJOR = 0;
	static const long  _MINOR = 0;
	static const long  _BUILD = 0;
	static const long  _REVISION = 7;
	
	//Miscellaneous Version Types
	static const long  _BUILDS_COUNT = 2771;
	#define  _RC_FILEVERSION 0,0,0,7
	#define  _RC_FILEVERSION_STRING "0, 0, 0, 7\0"
	static const char  _FULLVERSION_STRING[] = "0.0.0.7";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long  _BUILD_HISTORY = 1;
	

}
#endif //VERSION_H
