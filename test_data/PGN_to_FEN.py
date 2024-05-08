import chess.pgn

def add_en_passant_to_fen(fen, ep_square):

    parts = fen.split()

    if len(parts) != 6:
        return fen
    
    parts[3] = ep_square
    return " ".join(parts)

def extract_fen_from_pgn(pgn_file, numGames):

    with open(pgn_file) as f:

        game = chess.pgn.read_game(f)

        count = 0

        while game is not None and count < numGames:

            board = game.board()
            # print("Game:", game.headers["Event"])

            for move in game.mainline_moves():

                board.push(move)
                fen = board.fen()

                if board.ep_square:
                    fen = add_en_passant_to_fen(fen, chess.square_name(board.ep_square))

                print(fen)

            count = count + 1

            # print("\n")
            game = chess.pgn.read_game(f)

# Example usage
pgn_file = "lichess_jan_2013.pgn"
extract_fen_from_pgn(pgn_file, 10000)