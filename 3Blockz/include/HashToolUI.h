#ifndef HASHTOOLUI_H
#define HASHTOOLUI_H

//(*Headers(HashFunctionGenerator)
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class HashToolUI: public wxDialog
{
public:

    HashToolUI();
    virtual ~HashToolUI();

protected:

    //(*Declarations(HashToolUI)
    wxPanel* Panel1;
    wxPanel* Panel2;
    wxPanel* Panel3;
    wxStaticText* StaticText1;
    wxStaticText* StaticText2;
    wxTextCtrl* TextCtrl1;
    wxTextCtrl* TextCtrl2;
    //*)

    //(*Identifiers(HashToolUI)
    static const long ID_STATICTEXT1;
    static const long ID_TEXTCTRL1;
    static const long ID_STATICTEXT2;
    static const long ID_TEXTCTRL2;
    static const long ID_PANEL2;
    static const long ID_PANEL3;
    static const long ID_PANEL1;
    //*)

private:

    //(*Handlers(HashToolUI)
    //*)

protected:

    void BuildContent();

    DECLARE_EVENT_TABLE()
};

#endif
