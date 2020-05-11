import bst

binST = [
    [16, -1, -1, 3],
    [27, 2, 7, 9],
    [1, -1, 3, 1],
    [17, 0, 5, 2],
    [46, 6, -1, 9],
    [24, -1, -1, 3],
    [39, 8, -1, 4],
    [30, -1, -1, 1],
    [33, -1, -1, 6],
    [31, 1, 4, -1]
]
print(binST)
root = bst.findRoot(binST)
print(root)
print(binST[root])

minK = bst.min_key(binST, root)
print(minK)
print(binST[minK])

maxK = bst.max_key(binST, root)
print(maxK)
print(binST[maxK])

key_index = bst.search_key(binST, root, 55)
print(key_index)
print(binST[key_index])


