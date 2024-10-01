hellomake:
	gcc -O3 -o GreedyBot GreedyBot.c Translator.c MoveGenerator.c BitBoard.c Search.c Evaluate.c Magics.c

test:
	gcc -o test main.c Translator.c BitBoard.c MoveGenerator.c Magics.c

debug:
	gcc -g -o test main.c Translator.c BitBoard.c MoveGenerator.c Magics.c

clean:
	rm test GreedyBot