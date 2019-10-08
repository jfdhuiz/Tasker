/***************************************************************
 * Name:      New_Project_LinuxApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2019-10-07
 * Copyright:  ()
 * License:
 **************************************************************/

#include "New_Project_LinuxApp.h"

//(*AppHeaders
#include "New_Project_LinuxMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(New_Project_LinuxApp);

bool New_Project_LinuxApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	New_Project_LinuxFrame* Frame = new New_Project_LinuxFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
        