__author__ = 'ruben'


def rotate(img):
    n = len(img)
    for layer in range(n//2):
        first = layer
        last = n - 1 - layer
        for i in range(first, last):
            offset = i - first
            top = img[first][i]
            img[first][i] = img[last-offset][first]
            img[last-offset][first] = img[last][last-offset]
            img[last][last-offset] = img[i][last]
            img[i][last] = top


if __name__ == '__main__':
    image = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 8, 7, 6],
        [5, 4, 3, 2],
    ]
    rotate(image)
    for row in image:
        print(row)