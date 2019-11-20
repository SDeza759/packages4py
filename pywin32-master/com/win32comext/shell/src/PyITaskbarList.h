// This file declares the ITaskbarList Interface for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyITaskbarList : public PyIUnknown {
   public:
    MAKE_PYCOM_CTOR(PyITaskbarList);
    static ITaskbarList *GetI(PyObject *self);
    static PyComTypeObject type;

    // The Python methods
    static PyObject *HrInit(PyObject *self, PyObject *args);
    static PyObject *AddTab(PyObject *self, PyObject *args);
    static PyObject *DeleteTab(PyObject *self, PyObject *args);
    static PyObject *ActivateTab(PyObject *self, PyObject *args);
    static PyObject *SetActiveAlt(PyObject *self, PyObject *args);

   protected:
    PyITaskbarList(IUnknown *pdisp);
    ~PyITaskbarList();
};
