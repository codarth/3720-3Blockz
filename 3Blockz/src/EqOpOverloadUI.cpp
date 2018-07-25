#include "../include/EqOpOverloadUI.h"

//(*InternalHeaders(EqOpOverloadUI)
#include <wx/button.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(EqOpOverloadUI)
const long EqOpOverloadUI::ID_STATICTEXT1 = wxNewId();
const long EqOpOverloadUI::ID_TEXTCTRL1 = wxNewId();
const long EqOpOverloadUI::ID_PANEL1 = wxNewId();
const long EqOpOverloadUI::ID_PANEL2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(EqOpOverloadUI,wxDialog)
	//(*EventTable(EqOpOverloadUI)
	//*)
END_EVENT_TABLE()

EqOpOverloadUI::EqOpOverloadUI()
{
	BuildContent();
}

void EqOpOverloadUI::BuildContent()
{
	//(*Initialize(EqOpOverloadUI)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;

	Create(nullptr, wxID_ANY, _("Equality Overload Operator Generator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(400,131));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Class Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("ClassName"), wxDefaultPosition, wxSize(250,33), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(FlexGridSizer2);
	FlexGridSizer2->Fit(Panel1);
	FlexGridSizer2->SetSizeHints(Panel1);
	FlexGridSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
	StdDialogButtonSizer1->AddButton(new wxButton(Panel2, wxID_OK, wxEmptyString));
	StdDialogButtonSizer1->AddButton(new wxButton(Panel2, wxID_CANCEL, wxEmptyString));
	StdDialogButtonSizer1->Realize();
	Panel2->SetSizer(StdDialogButtonSizer1);
	StdDialogButtonSizer1->Fit(Panel2);
	StdDialogButtonSizer1->SetSizeHints(Panel2);
	FlexGridSizer1->Add(Panel2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();
	//*)
}

EqOpOverloadUI::~EqOpOverloadUI()
{
	//(*Destroy(EqOpOverloadUI)
	//*)
}


void EqOpOverloadUI::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void EqOpOverloadUI::OnButton1Click(wxCommandEvent& event)
{
}

void EqOpOverloadUI::OnButton2Click(wxCommandEvent& event)
{
}
