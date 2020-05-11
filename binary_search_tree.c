#include <Python.h>

static PyObject *find_root(PyObject *self, PyObject *args){
    PyObject *tree;
    PyObject *temp;
    int i;
    int comp;

    if (!PyArg_ParseTuple(args,"O", &tree)){
        return NULL;
    }
    else{
        i = 0;
        temp = PyList_GetItem(PyList_GetItem(tree, i),3);
        comp = PyLong_AsLong(temp);
        while(comp != -1){
            i++;
            temp = PyList_GetItem(PyList_GetItem(tree, i),3);
            comp = PyLong_AsLong(temp);
            }
        return Py_BuildValue("i", i);
        }
    }

static PyObject *min_key(PyObject *self, PyObject *args){
    PyObject *tree;
    PyObject *l_key;
    int root;
    int i;
    int comp;

    if (!PyArg_ParseTuple(args,"Oi", &tree, &root)){
        return NULL;
    }
    else{
        i = root;
        l_key = PyList_GetItem(PyList_GetItem(tree, i),1);
        comp = PyLong_AsLong(l_key);
        while(comp != -1){
            i = comp;
            l_key = PyList_GetItem(PyList_GetItem(tree, i),1);
            comp = PyLong_AsLong(l_key);
        }
    return Py_BuildValue("i", i);
    }
}

static PyObject *max_key(PyObject *self, PyObject *args){
    PyObject *tree;
    PyObject *r_key;
    int root;
    int i;
    int comp;

    if (!PyArg_ParseTuple(args,"Oi", &tree, &root)){
        return NULL;
    }
    else{
        i = root;
        r_key = PyList_GetItem(PyList_GetItem(tree, i),2);
        comp = PyLong_AsLong(r_key);
        while(comp != -1){
            i = comp;
            r_key = PyList_GetItem(PyList_GetItem(tree, i),2);
            comp = PyLong_AsLong(r_key);
        }
    return Py_BuildValue("i", i);
    }
}

static PyObject *search_key(PyObject *self, PyObject *args){
    PyObject *tree;
    PyObject *r_key;
    PyObject *l_key;
    PyObject *m_key;
    int root;
    int key;
    int n;
    int left, right, comp;

    if (!PyArg_ParseTuple(args,"Oii", &tree, &root, &key)){
        return NULL;
    }
    else{
        n = root;

        r_key = PyList_GetItem(PyList_GetItem(tree, n),2);
        right = PyLong_AsLong(r_key);

        l_key = PyList_GetItem(PyList_GetItem(tree, n),1);
        left = PyLong_AsLong(l_key);

        m_key = PyList_GetItem(PyList_GetItem(tree, n),0);
        comp = PyLong_AsLong(m_key);

        while (n != -1){
            if (key < comp){
                n = left;
                r_key = PyList_GetItem(PyList_GetItem(tree, n),2);
                right = PyLong_AsLong(r_key);

                l_key = PyList_GetItem(PyList_GetItem(tree, n),1);
                left = PyLong_AsLong(l_key);

                m_key = PyList_GetItem(PyList_GetItem(tree, n),0);
                comp = PyLong_AsLong(m_key);
            }
            else{
                n = right;
                r_key = PyList_GetItem(PyList_GetItem(tree, n),2);
                right = PyLong_AsLong(r_key);

                l_key = PyList_GetItem(PyList_GetItem(tree, n),1);
                left = PyLong_AsLong(l_key);

                m_key = PyList_GetItem(PyList_GetItem(tree, n),0);
                comp = PyLong_AsLong(m_key);
            };
            if (key == comp) break;
        }
        m_key = PyList_GetItem(PyList_GetItem(tree, n),0);
        comp = PyLong_AsLong(m_key);

        if (key == comp) return Py_BuildValue("i", n);
        else return NULL;
    }
}

static PyObject *inorder_traversal(PyObject *self, PyObject *args){


}


/* Module methods */
static PyMethodDef bst_methods[] = {
{
    "findRoot",          /* python function name */
     find_root,        /* C function */
     METH_VARARGS,   /* macros, describing that function has arguments */
     "Finds root of the BST" /* python documentation */
},
{
    "min_key",
     min_key,
     METH_VARARGS,
     "Finds min key of the BST"
},
{
    "max_key",
     max_key,
     METH_VARARGS,
     "Finds max key of the BST"
},
{
    "search_key",
     search_key,
     METH_VARARGS,
     "Search given key of the BST"
},
{NULL, NULL, 0, NULL}
};

/* describing our module */
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT,   /* essential macros */
    "bst",               /* module.__name__ */
    "amazing documentation", /* module.__doc__ */
    -1,
    bst_methods           /* module methods goes here */
};

/* has to be prefix PyInit at the name of the function */
PyMODINIT_FUNC PyInit_bst(void) {
      PyObject* m;
      /* creating module */
      m = PyModule_Create(&simple_module);
      /* if everything is correct, check is passed */
      if (m == NULL)
          return NULL;
      return m;
}
