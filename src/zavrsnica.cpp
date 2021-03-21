#include "zavrsnica.h"

end_frame::end_frame() : wxFrame(nullptr,wxID_ANY,"Kraj",wxDefaultPosition,wxSize(300,500),wxFD_DEFAULT_STYLE){

    this->SetBackgroundColour(wxColour(151,121,150));
    

  button6 = new wxCustomButton(this,122,"EXIT",wxPoint(150,460),wxSize(150,40));
  label4 = new wxStaticText(this,wxID_ANY,"",wxPoint(50,250),wxSize(200,50),wxTE_CENTER);
 
  



}