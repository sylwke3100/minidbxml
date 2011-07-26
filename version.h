#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char  _STATUS[] = "Alpha";
	static const char  _STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long  _MAJOR = 0;
	static const long  _MINOR = 0;
	static const long  _BUILD = 8;
	static const long  _REVISION = 0;
	
	//Miscellaneous Version Types
	static const long  _BUILDS_COUNT = 126;
	#define  _RC_FILEVERSION 0,0,8,0
	#define  _RC_FILEVERSION_STRING "0, 0, 8, 0\0"
	static const char  _FULLVERSION_STRING[] = "0.0.8.0";
	
	//SVN Version
	static const char  _SVN_REVISION[] = "103";
	static const char  _SVN_DATE[] = "2011-07-24T11:59:07.287144Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long  _BUILD_HISTORY = 0;
	

}
#endif //VERSION_H
