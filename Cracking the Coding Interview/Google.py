__author__ = 'ruben'

"""
A boggle board has 4x4 fields each holding a dice. The dices are marked with
letters. To play, you shake the board and try to find as many as possible words
on it. Words are created from the letters of sequentially adjacent cubes, where
"adjacent" cubes are those horizontally, vertically, or diagonally neighboring. Each word may
only use a field at most once.


Example:

a a f o
a o o a
a b a a
r a a a

fooboo would not work
How would you design an algorithm which finds all words in a boggle board?
"""

from copy import copy

def findWords(matrix, dict, visited=None):
	# matrix is 2-dimensional
	# dict could be a trie
	if visited is None:
		visited = [[False for i in len(matrix[0]] for j in len(matrix)]
	found = []
	# todo optimize
	for row in matrix:
		for col in rol:
current = matrix[row][col]
			subtree = dict[current]
			found += [word.path() for word in subtree if word.isLeaf()]
			# should look like (x,y) pairs
			neighbors = getNeighbors(matrix, (row, col), visited, subtree)
			visited[row][col] = True # make a copy of visited
			words = findWords(matrix, neighbors, subtree, visited)
			visited[row][col] = False
			found += list(words)

	return found




def findWords(matrix, cells, dict, visited):
	for cell in cells:
		x, y = cell
current = matrix[x][y]
		subtree = dict[current]
		found += [word.path() for word in subtree if word.isLeaf()]
		visited[x][y] = True
		neighbors = getNeighbors(matrix, x, y, visited)
		found += findWords(matrix, neighbors, subtree, visited)
		visited[row][col] = False

def getNeighbors(matrix, current, visited, dict):
	# root of dict is current
	x, y = current
	w, h = len(matrix[0]), len(matrix)
	neighbors = []
	# forgot two
	if x > 0:
		neighbors.append((x-1, y))
if y > 0:
			neighbors.append((x-1, y-1))
		if y < h-1:
			neighbors.append((x-1, y+1))

	if x < w-1:
		neighbors.append((x+1, y))
		if y > 0:
			neighbors.append((x+1, y-1))
		if y < h-1:
			neighbors.append((x+1, y+1))

	# x, y-1  x, y+1

	# filter out already visited
	neighbors = filter(lambda x: visited[x[0]][y[0]], neighbors)
	result = []
nextLetters = [node.value() for node in dict.children()]
for neighbor in neighbors:
		if matrix[neighbor[0]][neighbor[1]] in nextLetters:
			result.append(neighbor)
	return result
