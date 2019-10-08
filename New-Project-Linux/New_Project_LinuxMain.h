/***************************************************************
 * Name:      New_Project_LinuxMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2019-10-07
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef NEW_PROJECT_LINUXMAIN_H
#define NEW_PROJECT_LINUXMAIN_H

//(*Headers(New_Project_LinuxFrame)
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
//*)

class New_Project_LinuxFrame: public wxFrame
{
    public:

        New_Project_LinuxFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~New_Project_LinuxFrame();

    private:

        //(*Handlers(New_Project_LinuxFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(New_Project_LinuxFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(New_Project_LinuxFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // NEW_PROJECT_LINUXMAIN_H
    