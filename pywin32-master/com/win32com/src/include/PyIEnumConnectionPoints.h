// This file declares the IEnumConnectionPoints Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIEnumConnectionPoints : public PyIUnknown {
   public:
    MAKE_PYCOM_CTOR(PyIEnumConnectionPoints);
    static IEnumConnectionPoints *GetI(PyObject *self);
    static PyComEnumTypeObject type;

    // The Python methods
    static PyObject *Next(PyObject *self, PyObject *args);
    static PyObject *Skip(PyObject *self, PyObject *args);
    static PyObject *Reset(PyObject *self, PyObject *args);
    static PyObject *Clone(PyObject *self, PyObject *args);

   protected:
    PyIEnumConnectionPoints(IUnknown *pdisp);
    ~PyIEnumConnectionPoints();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGEnumConnectionPoints : public PyGatewayBase, public IEnumConnectionPoints {
   protected:
    PyGEnumConnectionPoints(PyObject *instance) : PyGatewayBase(instance) { ; }
    PYGATEWAY_MAKE_SUPPORT2(PyGEnumConnectionPoints, IEnumConnectionPoints, IID_IEnumConnectionPoints, PyGatewayBase)

    // IEnumConnectionPoints
    STDMETHOD(Next)(ULONG cConnections, IConnectionPoint **rgcp, ULONG __RPC_FAR *pcFetched);

    STDMETHOD(Skip)(ULONG cConnections);

    STDMETHOD(Reset)(void);

    STDMETHOD(Clone)(IEnumConnectionPoints __RPC_FAR *__RPC_FAR *ppEnum);
};
