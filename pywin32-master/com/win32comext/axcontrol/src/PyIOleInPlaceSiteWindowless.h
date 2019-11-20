// This file declares the IOleInPlaceSiteWindowless Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIOleInPlaceSiteWindowless : public PyIOleInPlaceSiteEx {
   public:
    MAKE_PYCOM_CTOR(PyIOleInPlaceSiteWindowless);
    static IOleInPlaceSiteWindowless *GetI(PyObject *self);
    static PyComTypeObject type;

    // The Python methods
    static PyObject *CanWindowlessActivate(PyObject *self, PyObject *args);
    static PyObject *GetCapture(PyObject *self, PyObject *args);
    static PyObject *SetCapture(PyObject *self, PyObject *args);
    static PyObject *GetFocus(PyObject *self, PyObject *args);
    static PyObject *SetFocus(PyObject *self, PyObject *args);
    static PyObject *GetDC(PyObject *self, PyObject *args);
    static PyObject *ReleaseDC(PyObject *self, PyObject *args);
    static PyObject *InvalidateRect(PyObject *self, PyObject *args);
    static PyObject *InvalidateRgn(PyObject *self, PyObject *args);
    static PyObject *ScrollRect(PyObject *self, PyObject *args);
    static PyObject *AdjustRect(PyObject *self, PyObject *args);
    static PyObject *OnDefWindowMessage(PyObject *self, PyObject *args);

   protected:
    PyIOleInPlaceSiteWindowless(IUnknown *pdisp);
    ~PyIOleInPlaceSiteWindowless();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGOleInPlaceSiteWindowless : public PyGOleInPlaceSiteEx, public IOleInPlaceSiteWindowless {
   protected:
    PyGOleInPlaceSiteWindowless(PyObject *instance) : PyGOleInPlaceSiteEx(instance) { ; }
    PYGATEWAY_MAKE_SUPPORT2(PyGOleInPlaceSiteWindowless, IOleInPlaceSiteWindowless, IID_IOleInPlaceSiteWindowless,
                            PyGOleInPlaceSiteEx)

    // IOleWindow
    STDMETHOD(GetWindow)(HWND __RPC_FAR *phwnd) { return PyGOleInPlaceSiteEx::GetWindow(phwnd); }

    STDMETHOD(ContextSensitiveHelp)(BOOL fEnterMode) { return PyGOleInPlaceSiteEx::ContextSensitiveHelp(fEnterMode); }

    // IOleInPlaceSite
    STDMETHOD(CanInPlaceActivate)(void) { return PyGOleInPlaceSiteEx::CanInPlaceActivate(); }

    STDMETHOD(OnInPlaceActivate)(void) { return PyGOleInPlaceSiteEx::OnInPlaceActivate(); }

    STDMETHOD(OnUIActivate)(void) { return PyGOleInPlaceSiteEx::OnUIActivate(); }

    STDMETHOD(GetWindowContext)
    (IOleInPlaceFrame __RPC_FAR *__RPC_FAR *ppFrame, IOleInPlaceUIWindow __RPC_FAR *__RPC_FAR *ppDoc,
     LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo)
    {
        return PyGOleInPlaceSiteEx::GetWindowContext(ppFrame, ppDoc, lprcPosRect, lprcClipRect, lpFrameInfo);
    }

    STDMETHOD(Scroll)(SIZE scrollExtant) { return PyGOleInPlaceSiteEx::Scroll(scrollExtant); }

    STDMETHOD(OnUIDeactivate)(BOOL fUndoable) { return PyGOleInPlaceSiteEx::OnUIDeactivate(fUndoable); }

    STDMETHOD(OnInPlaceDeactivate)(void) { return PyGOleInPlaceSiteEx::OnInPlaceDeactivate(); }

    STDMETHOD(DiscardUndoState)(void) { return PyGOleInPlaceSiteEx::DiscardUndoState(); }

    STDMETHOD(DeactivateAndUndo)(void) { return PyGOleInPlaceSiteEx::DeactivateAndUndo(); }

    STDMETHOD(OnPosRectChange)(LPCRECT lprcPosRect) { return PyGOleInPlaceSiteEx::OnPosRectChange(lprcPosRect); }

    // OleInPlaceSiteEx
    STDMETHOD(OnInPlaceActivateEx)(BOOL __RPC_FAR *pfNoRedraw, DWORD dwFlags)
    {
        return PyGOleInPlaceSiteEx::OnInPlaceActivateEx(pfNoRedraw, dwFlags);
    }

    STDMETHOD(OnInPlaceDeactivateEx)(BOOL fNoRedraw) { return PyGOleInPlaceSiteEx::OnInPlaceDeactivateEx(fNoRedraw); }

    STDMETHOD(RequestUIActivate)(void) { return PyGOleInPlaceSiteEx::RequestUIActivate(); }

    // IOleInPlaceSiteWindowless
    STDMETHOD(CanWindowlessActivate)(void);

    STDMETHOD(GetCapture)(void);

    STDMETHOD(SetCapture)(BOOL fCapture);

    STDMETHOD(GetFocus)(void);

    STDMETHOD(SetFocus)(BOOL fFocus);

    STDMETHOD(GetDC)(LPCRECT pRect, DWORD grfFlags, HDC __RPC_FAR *phDC);

    STDMETHOD(ReleaseDC)(HDC hDC);

    STDMETHOD(InvalidateRect)(LPCRECT pRect, BOOL fErase);

    STDMETHOD(InvalidateRgn)(HRGN hRGN, BOOL fErase);

    STDMETHOD(ScrollRect)(INT dx, INT dy, LPCRECT pRectScroll, LPCRECT pRectClip);

    STDMETHOD(AdjustRect)(LPRECT prc);

    STDMETHOD(OnDefWindowMessage)(UINT msg, WPARAM wParam, LPARAM lParam, LRESULT __RPC_FAR *plResult);
};
