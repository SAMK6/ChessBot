hellomake:
	gcc -o BitBoardTest BitBoardTest.c ../src/core/BitBoard.c ../src/core/Magics.c
	gcc -o TranslatorTest TranslatorTest.c ../src/core/BitBoard.c ../src/core/Translator.c ../src/core/Magics.c ../src/core/MoveGenerator.c
	gcc -o BitMaskTest BitMaskTests.c ../src/generators/BitMasks.c ../src/core/Magics.c
	gcc -o MoveGeneratorTest MoveGeneratorTests.c ../src/core/MoveGenerator.c ../src/core/BitBoard.c ../src/core/Translator.c ../src/core/Magics.c
	gcc -o PerftTest PerftTest.c ../src/core/MoveGenerator.c ../src/core/BitBoard.c ../src/core/Translator.c ../src/core/Magics.c
	gcc -o perft6 perft6.c ../src/core/MoveGenerator.c ../src/core/BitBoard.c ../src/core/Translator.c ../src/core/Magics.c
	gcc -o MagicTests MagicTests.c ../src/core/BitBoard.c ../src/generators/BitMasks.c ../src/core/Translator.c ../src/core/Magics.c
	gcc -o SearchTest SearchTests.c ../src/core/MoveGenerator.c ../src/core/BitBoard.c ../src/core/Translator.c ../src/core/Magics.c ../src/core/Search.c ../src/core/Evaluate.c


optimize:
	gcc -O3 -o perft6 perft6.c ../src/core/MoveGenerator.c ../src/core/BitBoard.c ../src/core/Translator.c ../src/core/Magics.c
	gcc -O3 -o PerftTest PerftTest.c ../src/core/MoveGenerator.c ../src/core/BitBoard.c ../src/core/Translator.c ../src/core/Magics.c
	gcc -O3 -o SearchTest SearchTests.c ../src/core/MoveGenerator.c ../src/core/BitBoard.c ../src/core/Translator.c ../src/core/Magics.c ../src/core/Search.c ../src/core/Evaluate.c

clean:
	rm BitBoardTest TranslatorTest BitMaskTest MoveGeneratorTest PerftTest perft6 MagicTests SearchTest