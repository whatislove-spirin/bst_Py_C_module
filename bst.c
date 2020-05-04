#include <Python.h>

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


static PyObject *py_findRoot(PyObject *self, PyObject *args){
  PyObject list;
  int result;

  if(!PyArg_ParseTuple(args,"O!", &list))
    return NULL;

  /* mem = (int*)malloc(sizeof(list) * sizeof(list[0]) * sizeof(list[0][0]));*/
  result = findRoot(list);

  /* free(mem);*/
  return Py_BuildValue("O", result);
}

/* Описывает методы модуля */
static PyMethodDef ownmod_methods[] = {
{
    "findRoot",          // название функции внутри python
     py_findRoot,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "Finds root of the BST" // документация для функции внутри python
},/*
{
    "minKey",          // название функции внутри python
     py_minKey,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "Finds min key of the BST" // документация для функции внутри python
},
{
    "maxKey",          // название функции внутри python
     py_maxKey,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "Finds max key of the BST" // документация для функции внутри python
},
{
    "searchKey",          // название функции внутри python
     py_searchKey,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "Tries to find the key of the BST by the given value" // документация для функции внутри python
},*/
{ NULL, NULL, 0, NULL }
};

/* Описываем наш модуль */
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT,   // обязательный макрос
    "bst",               // my_plus.__name__
    "amazing documentation", // my_plus.__doc__
    -1,
    ownmod_methods           // сюда передаем методы модуля
};

// в названии функции обязательно должен быть префикс PyInit
PyMODINIT_FUNC PyInit_my_plus(void) {
      PyObject* m;
      // создаем модуль
      m = PyModule_Create(&simple_module);
      // если все корректно, то эта проверка не проходит
      if (m == NULL)
          return NULL;
      return m;
}
