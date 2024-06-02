CC = clang++

DBG_DEF = -D SG_DEBUG
REL_DEF = -D SG_RELEASE

DF = -g -Wall -m64 -std=c++23 $(DBG_DEF)
RF = -O2 -m64 -std=c++23 $(REL_DEF)

SRC = src/*.cc src/food/*.cc src/snake/*.cc src/fileIO/*.cc
INC = -Iinc
LIB = -Llib -lraylibdll -lopengl32 -lgdi32 -lwinmm

BIN_REL = bin/SnakeGame.exe
BIN_DBG = bin/SnakeGame-Debug.exe

PCH = src/global.hh.pch
CH = src/global.hh


clean:
	rm -rf *.o $(BIN_DBG)

debugPrecompile:
	$(CC) $(DF) $(CH) -o $(PCH) $(INC)

debugCompile:
	$(CC) $(DF) -c $(SRC) $(INC)
	$(CC) $(DF) *.o -o $(BIN_DBG) $(LIB)
	$(BIN_DBG)
	make clean

debug:
	make debugPrecompile
	make debugCompile


releasePrecompile:
	$(CC) $(RF) $(CH) -o $(PCH) $(INC)

releaseCompile:
	$(CC) $(RF) -c $(SRC) $(INC)
	$(CC) $(RF) -Wl,--subsystem,windows *.o -s -o $(BIN_REL) $(LIB)
	$(BIN_REL)
	make clean

release:
	make releasePrecompile
	make releaseCompile
