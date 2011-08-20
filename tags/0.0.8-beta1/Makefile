# A simple makefile generator by KiSoft, 2010. mailto: kisoft@rambler.ru
# version: 0.3.12.5

# Project Variables start
CPP=g++
CC=gcc
LD=g++
LIB=ar
WINDRES=
# Project Variables end

# Target: Debug

OBJS_DEBUG=./DbControl.o ./DbConnections.o ./DbSearch.o ./Prefs.o ./UiCommandParser.o ./XmlParser.o ./XmlParserDebug.o ./main.o

Debug: minidbxml

minidbxml: $(OBJS_DEBUG)
	echo Building console executable ./minidbxml
	g++  -o ./minidbxml $(OBJS_DEBUG)   

./DbControl.o: ./DbControl.cpp
	echo Compiling: ./DbControl.cpp
	g++ -O3 -O2 -O1 -Wall  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./DbControl.cpp -o ./DbControl.o

./DbConnections.o: ./DbConnections.cpp
	echo Compiling: ./DbConnections.cpp
	g++ -O3 -O2 -O1 -Wall  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./DbConnections.cpp -o ./DbConnections.o
	
./DbSearch.o: ./DbSearch.cpp
	echo Compiling: ./DbSearch.cpp
	g++ -O3 -O2 -O1 -Wall  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./DbSearch.cpp -o ./DbSearch.o

./Prefs.o: ./Prefs.cpp
	echo Compiling: ./Prefs.cpp
	g++ -O3 -O2 -O1 -Wall  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./Prefs.cpp -o ./Prefs.o

./UiCommandParser.o: ./UiCommandParser.cpp
	echo Compiling: ./UiCommandParser.cpp
	g++ -O3 -O2 -O1 -Wall  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./UiCommandParser.cpp -o ./UiCommandParser.o

./XmlParser.o: ./XmlParser.cpp
	echo Compiling: ./XmlParser.cpp
	g++ -O3 -O2 -O1 -Wall  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./XmlParser.cpp -o ./XmlParser.o

./XmlParserDebug.o: ./XmlParserDebug.cpp
	echo Compiling: ./XmlParserDebug.cpp
	g++ -O3 -O2 -O1 -Wall  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./XmlParserDebug.cpp -o ./XmlParserDebug.o

./main.o: ./main.cpp
	echo Compiling: ./main.cpp
	g++ -O3 -O2 -O1 -Wall  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./main.cpp -o ./main.o

./DbControl.cpp: DbControl.h version.h DbControl.h

./DbControl.h: XmlParser.h

./XmlParser.h: XmlParserDebug.h

./XmlParser.cpp: XmlParser.h

./main.cpp: DbControl.h XmlParser.h DbSearch.h UiCommandParser.h

./DbSearch.cpp: DbSearch.h

./DbSearch.h: DbControl.h

./Prefs.cpp: Prefs.h

./XmlParserDebug.cpp: XmlParserDebug.h

./UiCommandParser.cpp: UiCommandParser.h

./UiCommandParser.h: DbControl.h




clean:
	rm *.o 
	rm minidbxml


