from random import randint

board = [
    ['1', '2', '3'],
    ['4', '5', '6'],
    ['7', ' ', '8']
]

for i in range(len(board)):
    print(board[i])

tmp = input('Enter number: ')

index = []

for i in range(len(board)):
    for j in range(len(board[i])):
        if board[i][j] == ' ':
            index.append(i)
            index.append(j)

moves = [[],[]]
for i in range(3):
    moves[0].append(board[index[0]][i])

for i in range(3):
    moves[1].append(board[i][index[1]])

axis = 0
for i in range(len(moves)):
    if tmp in moves[i]:
        axis = i
        break

position = moves[axis].index(tmp)
position2 = moves[axis].index(' ')
diff = position - position2

if axis == 0:
    if diff < 0:
        for i in range(abs(diff)):
            board[index[0]][position2 - i] = board[index[0]][position2 - i - 1]
            board[index[0]][position2 - i - 1] = ' '
    else:
        for i in range(diff):
            board[index[0]][position2 + i] = board[index[0]][position2 + i + 1]
            board[index[0]][position2 + i + 1] = ' '
else:
    if diff < 0:
        for i in range(abs(diff)):
            board[position2 - i][index[1]] = board[position2 - i - 1][index[1]]
            board[position2 - i - 1][index[1]] = ' '
    else:
        for i in range(diff):
            board[position2 + i][index[1]] = board[position2 + i + 1][index[1]]
            board[position2 + i + 1][index[1]] = ' '
for i in range(len(board)):
    print(board[i])