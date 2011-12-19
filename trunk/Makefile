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

OBJS_DEBUG=SessionsStorage.o ./DbLayer/DbPos.o ./DbLayer/DbControl.o ./DbLayer/DbConnections.o ./DbLayer/DbSearch.o Prefs.o ./DbLayer/DbExport.o ./Ui/UiCommandParser.o ./XmlParser/XmlParser.o ./XmlParser/XmlParserTags.o ./XmlParser/XmlParserDebug.o main.o

Debug: minidbxml

minidbxml: $(OBJS_DEBUG)
	@echo [100%] Building console executable minidbxml
	
	g++  -o minidbxml $(OBJS_DEBUG)


SessionsStorage.o: SessionsStorage.cpp
	@echo [5%] Compiling: SessionsStorage.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c SessionsStorage.cpp -o SessionsStorage.o

./DbLayer/DbPos.o: ./DbLayer/DbPos.cpp
	@echo [7%] Compiling: ./DbLayer/DbPos.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./DbLayer/DbPos.cpp -o ./DbLayer/DbPos.o


./DbLayer/DbControl.o: ./DbLayer/DbControl.cpp
	@echo [10%] Compiling: ./DbLayer/DbControl.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./DbLayer/DbControl.cpp -o ./DbLayer/DbControl.o

./DbLayer/DbConnections.o: ./DbLayer/DbConnections.cpp
	@echo [20%] Compiling: ./DbLayer/DbConnections.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./DbLayer/DbConnections.cpp -o ./DbLayer/DbConnections.o

./DbLayer/DbSearch.o: ./DbLayer/DbSearch.cpp
	@echo [30%] Compiling: ./DbLayer/DbSearch.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./DbLayer/DbSearch.cpp -o ./DbLayer/DbSearch.o

Prefs.o: Prefs.cpp
	@echo [40%] Compiling: Prefs.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c Prefs.cpp -o Prefs.o
./DbLayer/DbExport.o: ./DbLayer/DbExport.cpp
	@echo [50%] Compiling: ./DbLayer/DbControl.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./DbLayer/DbExport.cpp -o ./DbLayer/DbExport.o
./Ui/UiCommandParser.o: ./Ui/UiCommandParser.cpp
	@echo [60%] Compiling: ./Ui/UiCommandParser.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./Ui/UiCommandParser.cpp -o ./Ui/UiCommandParser.o

./XmlParser/XmlParser.o: ./XmlParser/XmlParser.cpp
	@echo [70%] Compiling: ./XmlParser/XmlParser.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./XmlParser/XmlParser.cpp -o ./XmlParser/XmlParser.o

./XmlParser/XmlParserTags.o: ./XmlParser/XmlParserTags.cpp
	@echo [75%] Compiling: ./XmlParser/XmlParserTags.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./XmlParser/XmlParserTags.cpp -o ./XmlParser/XmlParserTags.o


./XmlParser/XmlParserDebug.o: ./XmlParser/XmlParserDebug.cpp
	
	@echo [80%] Compiling: ./XmlParser/XmlParserDebug.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c ./XmlParser/XmlParserDebug.cpp -o ./XmlParser/XmlParserDebug.o

main.o: main.cpp
	
	@echo [90%] Compiling: main.cpp
	
	g++ -O3 -O2 -O1   -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g  -fexpensive-optimizations -Os -O3 -O2 -O1 -O -g     -c main.cpp -o main.o

SessionStorage.cpp: SessionStorage.h

./DbLayer/DbControl.cpp: ./DbLayer/DbControl.h version.h ./DbLayer/DbControl.h

./DbLayer/DbPos.cpp: ./DbLayer/DbPos.h

./DbLayer/DbControl.h: ./XmlParser/XmlParser.h

./XmlParser/XmlParser.h: ./XmlParser/XmlParserDebug.h

./XmlParser/XmlParser.cpp: ./XmlParser/XmlParser.h

main.cpp:  ./XmlParser/XmlParser.h ./DbLayer/DbSearch.h ./Ui/UiCommandParser.h

./DbLayer/DbSearch.cpp: ./DbLayer/DbSearch.h

./DbLayer/DbSearch.h: ./DbLayer/DbControl.h

Prefs.cpp: Prefs.h

./XmlParser/XmlParserDebug.cpp: ./XmlParser/XmlParserDebug.h

./Ui/UiCommandParser.cpp: ./Ui/UiCommandParser.h

./Ui/UiCommandParser.h: ./DbLayer/DbControl.h


clean:
	rm -r *.o 
	rm -r ./Ui/*.o 
	rm -r ./DbLayer/*.o 
	rm -r ./XmlParser/*.o 
	rm minidbxml

