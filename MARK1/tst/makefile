hellomake:
	gcc -o BitBoardTest BitBoardTest.c ../src/BitBoard.c
	gcc -o TranslatorTest TranslatorTest.c ../src/BitBoard.c ../src/Translator.c
	gcc -o BitMaskTest BitMaskTests.c ../src/BitMasks.c
	gcc -o MoveGeneratorTest MoveGeneratorTests.c ../src/MoveGenerator.c ../src/BitBoard.c ../src/Translator.c
	gcc -o PerftTest PerftTest.c ../src/MoveGenerator.c ../src/BitBoard.c ../src/Translator.c
	gcc -o perft6 perft6.c ../src/MoveGenerator.c ../src/BitBoard.c ../src/Translator.c
	gcc -o MagicTests MagicTests.c ../src/BitBoard.c ../src/BitMasks.c ../src/Translator.c

optimize:
	gcc -O3 -o PerftTest PerftTest.c ../src/MoveGenerator.c ../src/BitBoard.c ../src/Translator.c
	gcc -O3 -o perft6 perft6.c ../src/MoveGenerator.c ../src/BitBoard.c ../src/Translator.c
	
clean:
	rm BitBoardTest TranslatorTest BitMaskTest MoveGeneratorTest PerftTest perft6 MagicTests