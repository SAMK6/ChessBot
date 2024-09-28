hellomake:
	gcc -o test main.c Translator.c BitBoard.c MoveGenerator.c BitMasks.c
	g++ -o magic GenerateMagics.cpp BitBoard.c BitMasks.c

debug:
	gcc -g -o test main.c Translator.c BitBoard.c MoveGenerator.c BitMasks.c

clean:
	rm test magic