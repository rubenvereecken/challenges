__author__ = 'ruben'

def set_zeroes(matrix):
    rows = [False for _ in range(len(matrix))]
    cols = [False for _ in range(len(matrix[0]))]

    for r, row in enumerate(matrix):
        for c, el in enumerate(row):
            if el == 0:
                rows[r] = True
                cols[c] = True

    for r, row in enumerate(matrix):
        for c in range(len(row)):
            if rows[r] or cols[c]:
                row[c] = 0


if __name__ == '__main__':
    matrix = [
        [1, 2, 3, 4],
        [5, 0, 7, 8],
        [9, 8, 7, 6],
        [5, 4, 3, 0],
        [5, 4, 3, 3],
    ]
    set_zeroes(matrix)
    for row in matrix:
        print(row)