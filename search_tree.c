
int findRoot(int tree[][4])
{
    int i = 0;

    while (tree[i][3] != -1){
        i++;
    }

    return i;
}


int minKey(int tree[][4], int root)
{
    int i = root;

    while (tree[i][1] != -1){
        i = tree[i][1];
    }

    return i;
}


int maxKey(int tree[][4], int root)
{
    int i = root;

    while (tree[i][2] != -1){
        i = tree[i][2];
    }

    return i;
}

int searchKey(int tree[][4], int root, int key)
{
    int n = root;

    while (n != -1)
    {
        if (key < tree[n][0])
            n = tree[n][1];
        else
            n = tree[n][2];

        if (key == tree[n][0])
            break;
    }

    return n;
}


int main()
{
    int binarySearchTree[10][4] = {
    {16, -1, -1, 3},
    {27, 2, 7, 9},
    {1, -1, 3, 1},
    {17, 0, 5, 2},
    {46, 6, -1, 9},
    {24, -1, -1, 3},
    {39, 8, -1, 4},
    {30, -1, -1, 1},
    {33, -1, -1, 6},
    {31, 1, 4, -1}
    };
    int root = findRoot(binarySearchTree);
    printf("Root of the binary search tree: %d or {%d, %d, %d, %d}\n\n", root,
            *binarySearchTree[root],
            *(binarySearchTree[root]+1),
            *(binarySearchTree[root]+2),
            *(binarySearchTree[root]+3)
            );

    int minK = minKey(binarySearchTree, root);
    printf("Min key of binary search tree: %d or {%d, %d, %d, %d}\n\n", minK,
           *binarySearchTree[minK],
           *(binarySearchTree[minK]+1),
           *(binarySearchTree[minK]+2),
           *(binarySearchTree[minK]+3)
           );

    int maxK = maxKey(binarySearchTree, root);
    printf("Max key of binary search tree: %d or {%d, %d, %d, %d}\n\n", maxK,
           *binarySearchTree[maxK],
           *(binarySearchTree[maxK]+1),
           *(binarySearchTree[maxK]+2),
           *(binarySearchTree[maxK]+3)
           );

    int key = 33;
    int sKey = searchKey(binarySearchTree, root, key);
    if (sKey != -1)
        printf("Key of the searched %d: %d or {%d, %d, %d, %d}\n\n", key, sKey,
               *binarySearchTree[sKey],
               *(binarySearchTree[sKey]+1),
               *(binarySearchTree[sKey]+2),
               *(binarySearchTree[sKey]+3)
               );
    else
        printf("The searched key %d can not be found\nTry again with another key\n", key);

    return 0;
}
