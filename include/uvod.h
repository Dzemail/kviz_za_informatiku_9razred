#include <wx/wx.h>
#include "custombitmapbutton.h"
#include <wx/radiobut.h>
class myframe : public wxFrame {
    public:
    myframe();
    private:
    wxPanel *panel = nullptr;
    wxBitmapButton *button = nullptr;
    wxTextCtrl *name = nullptr;
    wxTextCtrl *username = nullptr;
    wxRadioButton *deveti_b = nullptr;
    wxRadioButton *deveti_a = nullptr;
    wxBoxSizer *sizer = nullptr;
    wxBoxSizer *sizer_button = nullptr;
    On_MouseEnter(wxMouseEvent& event);



   

    void OnButtonClicked1(wxCommandEvent &evt);

    DECLARE_EVENT_TABLE();
};