#include "uvod.h"
#include "in_game.h"
#include <wx/bitmap.h>
#include "custombitmapbutton.h"

using namespace std;
wxBEGIN_EVENT_TABLE(myframe,wxFrame)
EVT_BUTTON(1001,OnButtonClicked1)
wxEND_EVENT_TABLE()

myframe::myframe() : wxFrame(nullptr,wxID_ANY,"Kviz",wxDefaultPosition,wxDefaultSize,wxFD_DEFAULT_STYLE){
    
    wxPNGHandler *handler2 = new wxPNGHandler;

    wxImage::AddHandler(handler2);
  
    wxBitmap bit("images\\start_button.png",wxBITMAP_TYPE_PNG);
    wxImage img;
    img = bit.ConvertToImage();
    wxBitmap bit2(img);
   

    panel = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(300,500));
    panel->SetBackgroundColour(wxColour(151,121,150));

    button = new wxBitmapButton(panel,1001,bit2,wxDefaultPosition,wxSize(150,40));
    
    
  
    deveti_b = new wxRadioButton(panel,123,"9b",wxPoint(10,250),wxSize(100,20));
    deveti_a = new wxRadioButton(panel,124,"9a",wxPoint(10,270),wxSize(100,20));
    name = new wxTextCtrl(panel,wxID_ANY,"Ime",wxPoint(10,200),wxSize(100,20),wxBORDER_SIMPLE |wxTE_CENTRE);
    username = new wxTextCtrl(panel,wxID_ANY,"Prezime",wxPoint(150,200),wxSize(100,20),wxBORDER_SIMPLE|wxTE_CENTRE);
   
  
name->SetBackgroundColour(wxColour(151,121,150));
username->SetBackgroundColour(wxColour(151,121,150));


    sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(panel,0,wxALIGN_LEFT|wxEXPAND);

    sizer_button = new wxBoxSizer(wxHORIZONTAL);

    sizer_button->Add(button,0,wxALIGN_BOTTOM|wxBOTTOM|wxLEFT,70);

    panel->SetSizer(sizer_button);
    sizer_button->Layout(); 

    this->SetSizerAndFit(sizer);
    sizer->Layout();
}


void myframe::OnButtonClicked1(wxCommandEvent &evt){
    if(deveti_b->GetValue()== true){
        ofstream objects("9b.dat",ios::app);
    objects<<name->GetValue()<<" "<<username->GetValue()<<endl;
    objects.close();
    this->Close();
    game_frame *newframe = new game_frame();
   newframe->Centre();
   newframe->Show(true);

    }else if(deveti_a->GetValue() == true){

    ofstream objects("9a.dat",ios::app);
    objects<<name->GetValue()<<" "<<username->GetValue()<<endl;
    objects.close();
    this->Close();
    game_frame *newframe = new game_frame();
   newframe->Centre();
   newframe->Show(true);
    }

    


   
    




}
