#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "23";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2010";
	static const char UBUNTU_VERSION_STYLE[] = "10.11";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 0;
	static const long BUILD = 250;
	static const long REVISION = 1482;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1371;
	#define RC_FILEVERSION 0,0,250,1482
	#define RC_FILEVERSION_STRING "0, 0, 250, 1482\0"
	static const char FULLVERSION_STRING[] = "0.0.250.1482";
	
	//SVN Version
	static const char SVN_REVISION[] = "19";
	static const char SVN_DATE[] = "2010-11-19T16:20:40.444701Z";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 26;
	

}
#endif //VERSION_H
