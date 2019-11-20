// This file declares the IOleControlSite Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIOleControlSite : public PyIUnknown {
   public:
    MAKE_PYCOM_CTOR(PyIOleControlSite);
    static IOleControlSite *GetI(PyObject *self);
    static PyComTypeObject type;

    // The Python methods
    static PyObject *OnControlInfoChanged(PyObject *self, PyObject *args);
    static PyObject *LockInPlaceActive(PyObject *self, PyObject *args);
    static PyObject *GetExtendedControl(PyObject *self, PyObject *args);
    static PyObject *TransformCoords(PyObject *self, PyObject *args);
    static PyObject *TranslateAccelerator(PyObject *self, PyObject *args);
    static PyObject *OnFocus(PyObject *self, PyObject *args);
    static PyObject *ShowPropertyFrame(PyObject *self, PyObject *args);

   protected:
    PyIOleControlSite(IUnknown *pdisp);
    ~PyIOleControlSite();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGOleControlSite : public PyGatewayBase, public IOleControlSite {
   protected:
    PyGOleControlSite(PyObject *instance) : PyGatewayBase(instance) { ; }
    PYGATEWAY_MAKE_SUPPORT2(PyGOleControlSite, IOleControlSite, IID_IOleControlSite, PyGatewayBase)

    // IOleControlSite
    STDMETHOD(OnControlInfoChanged)(void);

    STDMETHOD(LockInPlaceActive)(BOOL fLock);

    STDMETHOD(GetExtendedControl)(IDispatch **ppDisp);

    STDMETHOD(TransformCoords)(POINTL *pPtlHimetric, POINTF *pPtfContainer, DWORD dwFlags);

    STDMETHOD(TranslateAccelerator)(MSG *pMsg, DWORD grfModifiers);

    STDMETHOD(OnFocus)(BOOL fGotFocus);

    STDMETHOD(ShowPropertyFrame)(void);
};