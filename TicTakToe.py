def printboard(board, r):
    for i in range(r):
        for j in range(r):
            if board[i][j] == 0:
                print("_ ", end="")
            elif board[i][j] == 1:
                print("0 ", end="")
            else:
                print("X ", end="")
        print()

def checkwinner(board, r):
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] != 0:
            return board[i][0]
        if board[0][i] == board[1][i] == board[2][i] != 0:
            return board[0][i]
    if board[0][0] == board[1][1] == board[2][2] != 0:
        return board[0][0]
    if board[0][2] == board[1][1] == board[2][0] != 0:
        return board[0][2]
    return 0

def calcposition(board, opp):
    who, winner = 0, 0
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:
                board[i][j] = 2
                winner = checkwinner(board, 3)
                board[i][j] = 0
                if winner != 0:
                    return i, j
    if board[1][1] == 0:
        return 1, 1

def main():
    board = [[0] * 3 for _ in range(3)]
    player = 1
    printboard(board, 3)
    for _ in range(9):
        if player == 1:
            r, c = calcposition(board, 2)
            board[r][c] = 1
            player = 2
        else:
            r = int(input("\nEnter coordinates\n"))
            c = int(input())
            while board[r][c] != 0:
                print("\nTAKEN Re Enter\n")
                r = int(input())
                c = int(input())
            board[r][c] = 2
            player = 1
        printboard(board, 3)
        winner = checkwinner(board, 3)
        if winner != 0:
            print("Winner is player:", winner)
            break

if __name__ == "__main__":
    main()
