#ifndef EQOPOVERLOADUI_H
#define EQOPOVERLOADUI_H

//(*Headers(EqOpOverloadUI)
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class EqOpOverloadUI: public wxDialog
{
	public:

		EqOpOverloadUI();
		virtual ~EqOpOverloadUI();

	protected:

		//(*Declarations(EqOpOverloadUI)
		wxPanel* Panel1;
		wxPanel* Panel2;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		//*)

		//(*Identifiers(EqOpOverloadUI)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_PANEL1;
		static const long ID_PANEL2;
		//*)

	private:

		//(*Handlers(EqOpOverloadUI)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent();

		DECLARE_EVENT_TABLE()
};

#endif
