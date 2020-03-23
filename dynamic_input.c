#include <Python.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* reads from keypress, doesn't echo */
char _getch(void)
{
    struct termios oldattr, newattr;
    char ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

/* gets a char and builds a Python bytes class */
static PyObject *
get(PyObject *self, PyObject *args)
{
    char c = _getch();
    return Py_BuildValue("c", c);
}

/*
    list of module methods and their metadata
    only one needed here, but can expand
    just add another {} after the {} with get's data
*/
static PyMethodDef dynamicInputMethods[] = {
    {
        "get",
        get,
        METH_VARARGS,
        "Method allows to silently read a character without user having to press enter."
    }
};


/* definition of the module */
static struct PyModuleDef dynamicInputModule = {
    PyModuleDef_HEAD_INIT,
    "dynamic_input",
    "Python module for dynamic command line input, written in C.",
    -1,
    dynamicInputMethods
};

/* module export */
PyMODINIT_FUNC PyInit_dynamic_input(void) {
    return PyModule_Create(&dynamicInputModule);
}
