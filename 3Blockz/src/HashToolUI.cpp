#include "../include/HashToolUI.h"

//(*InternalHeaders(HashToolUI)
#include <wx/button.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(HashToolUI)
const long HashToolUI::ID_STATICTEXT1 = wxNewId();
const long HashToolUI::ID_TEXTCTRL1 = wxNewId();
const long HashToolUI::ID_STATICTEXT2 = wxNewId();
const long HashToolUI::ID_TEXTCTRL2 = wxNewId();
const long HashToolUI::ID_PANEL2 = wxNewId();
const long HashToolUI::ID_PANEL3 = wxNewId();
const long HashToolUI::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(HashToolUI, wxDialog)
    //(*EventTable(HashToolUI)
    //*)
END_EVENT_TABLE()

HashToolUI::HashToolUI()
{
    BuildContent();
}

void HashToolUI::BuildContent()
{
    //(*Initialize(HashToolUI)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxStdDialogButtonSizer* StdDialogButtonSizer1;

    Create(nullptr, wxID_ANY, _("Hash Function Generator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(492,449));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(337,187), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Hash Struct Name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("HashStruct"), wxDefaultPosition, wxSize(200,33), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Object Type Name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("ClassName"), wxDefaultPosition, wxSize(200,33), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer2->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxSize(1,1), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    FlexGridSizer2->Add(Panel2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3 = new wxPanel(Panel1, ID_PANEL3, wxDefaultPosition, wxSize(75,20), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
    StdDialogButtonSizer1->AddButton(new wxButton(Panel3, wxID_OK, wxEmptyString));
    StdDialogButtonSizer1->AddButton(new wxButton(Panel3, wxID_CANCEL, wxEmptyString));
    StdDialogButtonSizer1->Realize();
    Panel3->SetSizer(StdDialogButtonSizer1);
    SetSizer(StdDialogButtonSizer1);
    Layout();
    FlexGridSizer2->Add(Panel3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer2);
    SetSizer(FlexGridSizer2);
    Layout(); // This line results in a seg fault
    FlexGridSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    SetSizer(FlexGridSizer1);
    Layout();
    //*)
}

HashToolUI::~HashToolUI()
{
    //(*Destroy(HashToolUI)
    //*)
}

