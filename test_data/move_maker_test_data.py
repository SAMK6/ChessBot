import chess.pgn
import random
import sys

def square_translator(square):
    file = 7 - chess.square_file(square)
    rank = chess.square_rank(square)

    return file + (8 * rank)

def classify_move(board, move):

    # Check for quiet moves (non-capture, non-promotion, non-special)
    if board.is_castling(move):
        if board.is_kingside_castling(move):
            return 2  # Kingside castle
        else:
            return 3  # Queenside castle

    if board.is_en_passant(move):
        return 5  # En passant capture

    if move.promotion:
        # Promotion moves
        if board.is_capture(move):
            # Promotion captures
            if move.promotion == chess.KNIGHT:
                return 12  # Knight promotion-capture
            elif move.promotion == chess.BISHOP:
                return 13  # Bishop promotion-capture
            elif move.promotion == chess.ROOK:
                return 14  # Rook promotion-capture
            elif move.promotion == chess.QUEEN:
                return 15  # Queen promotion-capture
        else:
            # Regular promotions
            if move.promotion == chess.KNIGHT:
                return 8  # Knight promotion
            elif move.promotion == chess.BISHOP:
                return 9  # Bishop promotion
            elif move.promotion == chess.ROOK:
                return 10  # Rook promotion
            elif move.promotion == chess.QUEEN:
                return 11  # Queen promotion

    if board.is_capture(move):
        return 4  # Capture

    # Check for double pawn push
    if board.piece_at(move.from_square).piece_type == chess.PAWN:
        from_row = chess.square_rank(move.from_square)
        to_row = chess.square_rank(move.to_square)
        if abs(to_row - from_row) == 2:
            return 1  # Double pawn push

    return 0  # Quiet move

def get_moved_piece(board, move):

    piece = board.piece_at(move.from_square)

    if piece.color == chess.BLACK:
        if piece.piece_type == chess.PAWN:
            return 0
        elif piece.piece_type == chess.KNIGHT:
            return 1
        elif piece.piece_type == chess.BISHOP:
            return 2
        elif piece.piece_type == chess.ROOK:
            return 3
        elif piece.piece_type == chess.QUEEN:
            return 4
        elif piece.piece_type == chess.KING:
            return 5
    elif piece.color == chess.WHITE:
        if piece.piece_type == chess.PAWN:
            return 6
        elif piece.piece_type == chess.KNIGHT:
            return 7
        elif piece.piece_type == chess.BISHOP:
            return 8
        elif piece.piece_type == chess.ROOK:
            return 9
        elif piece.piece_type == chess.QUEEN:
            return 10
        elif piece.piece_type == chess.KING:
            return 11

    return None


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

        # unwrap the moves generator
        moves = [i for i in board.legal_moves]
        
        # choose a random move
        if(len(moves) == 0):
            continue
        else:
            move = random.choice(moves)
            
        
        print(FEN)

        # calculate the move code
        fromSquare = square_translator(move.from_square)
        toSquare = square_translator(move.to_square)
        misc = classify_move(board, move)
        piece = get_moved_piece(board, move)

        moveCode = fromSquare + toSquare * pow(2,6) + misc * pow(2,12) + piece * pow(2, 16)

        

        #print(fromSquare, toSquare, misc)
        print(moveCode)

        board.push(move)
        newFEN = board.fen(en_passant='fen')
        print(newFEN)
        # print()
            
