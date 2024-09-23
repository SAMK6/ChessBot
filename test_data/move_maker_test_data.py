import chess.pgn
import random

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
    
    if piece.color == chess.WHITE:
        if piece.piece_type == chess.KING:
            return 'K'
        elif piece.piece_type == chess.QUEEN:
            return 'Q'
        elif piece.piece_type == chess.ROOK:
            return 'R'
        elif piece.piece_type == chess.BISHOP:
            return 'B'
        elif piece.piece_type == chess.KNIGHT:
            return 'N'
        elif piece.piece_type == chess.PAWN:
            return 'P'
    elif piece.color == chess.BLACK:
        if piece.piece_type == chess.KING:
            return 'k'
        elif piece.piece_type == chess.QUEEN:
            return 'q'
        elif piece.piece_type == chess.ROOK:
            return 'r'
        elif piece.piece_type == chess.BISHOP:
            return 'b'
        elif piece.piece_type == chess.KNIGHT:
            return 'n'
        elif piece.piece_type == chess.PAWN:
            return 'p'
        
    return None

with open("Seb_Fens.txt") as f:
    for line in f:

        # strip the bad stuff off the FENs
        FEN = line.strip('\ufeff')
        FEN = FEN.strip('\n')

        print(FEN)

        # set the board state
        board = chess.Board()
        board.set_fen(FEN)

        # unwrap the moves generator
        moves = [i for i in board.legal_moves]
        
        # choose a random move
        move = random.choice(moves)

        # calculate the move code
        fromSquare = square_translator(move.from_square)
        toSquare = square_translator(move.to_square)
        misc = classify_move(board, move)

        moveCode = fromSquare + toSquare * pow(2,6) + misc * pow(2,12)

        # what piece is being moved
        piece = get_moved_piece(board, move)

        #print(fromSquare, toSquare, misc)
        print(moveCode, piece)

        board.push(move)
        newFEN = board.fen(en_passant='fen')
        print(newFEN)
        # print()
            
