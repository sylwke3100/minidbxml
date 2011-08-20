#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "13";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2010";
	static const char UBUNTU_VERSION_STYLE[] = "10.11";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 0;
	static const long BUILD = 4;
	static const long REVISION = 353;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 940;
	#define RC_FILEVERSION 0,0,4,353
	#define RC_FILEVERSION_STRING "0, 0, 4, 353\0"
	static const char FULLVERSION_STRING[] = "0.0.4.353";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 26;
	

}
#endif //VERSION_H
