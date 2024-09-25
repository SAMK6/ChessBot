import chess.pgn
import sys


if len(sys.argv) < 2:
    print("No parameter was passed!")
    exit
else:
    input_file = sys.argv[1]

with open(input_file) as f:
    for line in f:
        # strip the bad stuff off the FENs
        FEN = line.strip('\ufeff')
        FEN = FEN.strip('\n')

        # set the board state
        board = chess.Board()
        board.set_fen(FEN)

        print(FEN)
        print(board.legal_moves.count())

        