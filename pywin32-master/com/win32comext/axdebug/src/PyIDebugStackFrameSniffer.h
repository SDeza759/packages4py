// This file declares the IDebugStackFrameSniffer Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIDebugStackFrameSniffer : public PyIUnknown {
   public:
    MAKE_PYCOM_CTOR_ERRORINFO(PyIDebugStackFrameSniffer, IID_IDebugStackFrameSniffer);
    static IDebugStackFrameSniffer *GetI(PyObject *self);
    static PyComTypeObject type;

    // The Python methods
    static PyObject *EnumStackFrames(PyObject *self, PyObject *args);

   protected:
    PyIDebugStackFrameSniffer(IUnknown *pdisp);
    ~PyIDebugStackFrameSniffer();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGDebugStackFrameSniffer : public PyGatewayBase, public IDebugStackFrameSniffer {
   protected:
    PyGDebugStackFrameSniffer(PyObject *instance) : PyGatewayBase(instance) { ; }
    PYGATEWAY_MAKE_SUPPORT(PyGDebugStackFrameSniffer, IDebugStackFrameSniffer, IID_IDebugStackFrameSniffer)

    // IDebugStackFrameSniffer
    STDMETHOD(EnumStackFrames)(IEnumDebugStackFrames __RPC_FAR *__RPC_FAR *ppedsf);
};
