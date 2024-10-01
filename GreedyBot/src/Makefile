hellomake:
	gcc -O3 -o GreedyBot GreedyBot.c MoveGenerator.c Translator.c BitBoard.c Search.c Evaluate.c

test:
	gcc -o test main.c Translator.c BitBoard.c MoveGenerator.c BitMasks.c

magics:
	g++ -o magic GenerateMagics.cpp BitBoard.c BitMasks.c

debug:
	gcc -g -o test main.c Translator.c BitBoard.c MoveGenerator.c BitMasks.c

clean:
	rm test magic GreedyBot