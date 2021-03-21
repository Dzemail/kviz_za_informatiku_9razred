#include "in_game.h"
#include<iostream>
#include<algorithm>
#include<random>
#include<list>
#include<vector>
#include<chrono>
#include <sstream>
#include <string>
#include "zavrsnica.h"
#include <wx/sound.h>
#include <fstream>
using namespace std;
BEGIN_EVENT_TABLE(game_frame,wxFrame)
EVT_BUTTON(123,OnButtonClicked1)
EVT_BUTTON(1234,OnButtonClicked2)
EVT_BUTTON(12345,OnButtonClicked3)
EVT_BUTTON(321,OnButtonClicked4)
END_EVENT_TABLE()
 


mt19937 gen( chrono::system_clock::now().time_since_epoch().count() );

//============================



//============================

template <class T > void listShuffle( vector<T> &L )
{
   vector<T> V( L.begin(), L.end() );
   shuffle( V.begin(), V.end(), gen );
   L.assign( V.begin(), V.end() );
}


game_frame::game_frame() : wxFrame(nullptr,wxID_ANY,"Kviz",wxDefaultPosition,wxSize(1200,700)){
  
 int wowo[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
               21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
int numbers[] = { 1,2,3,4};
    for(int i : numbers){
        random.push_back(i);
        

    }
    for(int o : wowo){
        reading_machine.push_back(o);
    }
     listShuffle(random);
     listShuffle(reading_machine);

    wxPNGHandler *handler1 = new wxPNGHandler;
    wxImage::AddHandler(handler1);

     vertical_panel_sizer = new wxBoxSizer(wxVERTICAL);
     horizontal_panel_sizer = new wxBoxSizer(wxHORIZONTAL);


    wxBitmap photo("images\\start_button.png",wxBITMAP_TYPE_PNG); 
     
     



    
    main_panel1 = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    main_panel2 = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    main_panel3 = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    main_panel1->SetBackgroundColour(wxColour(0,255,0));
    main_panel2->SetBackgroundColour(wxColour(0,0,255));
    main_panel3->SetBackgroundColour(wxColour(255,0,0));

    horizontal_panel_sizer->Add(main_panel2,3,wxEXPAND);
    horizontal_panel_sizer->Add(main_panel3,2,wxEXPAND);
    
    
    vertical_panel_sizer->Add(horizontal_panel_sizer,1,wxEXPAND);
    vertical_panel_sizer->Add(main_panel1,1,wxEXPAND);


    label1 = new wxStaticText(main_panel2,wxID_ANY,"",wxDefaultPosition,wxSize(700,300),wxTE_CENTRE|wxTE_MULTILINE);

    label_sizer = new wxBoxSizer(wxVERTICAL);

    wxFont myFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    label1->SetFont(myFont);

    label_sizer ->Add(label1,0,wxALIGN_CENTRE|wxTOP,150);

    question_reader();
    
  
    





    btn = new wxBitmapButton(main_panel3,wxID_ANY,photo,wxDefaultPosition,wxSize(200,100),wxBORDER_NONE);   

    btn_sizer = new wxBoxSizer(wxVERTICAL);
    btn_sizer -> Add(btn,0,wxALIGN_CENTER|wxTOP,118);

    Button1Making();
    Button2Making();
    Button3Making();
    Button4Making();





   main_panel3->SetSizer(btn_sizer);
   main_panel2->SetSizer(label_sizer);

    this->SetSizer(vertical_panel_sizer);
    vertical_panel_sizer->Layout();
  
   btn_sizer->Layout();
   label_sizer->Layout();
  horizontal_panel_sizer->Layout();
 
    




}


void game_frame::question_reader(){    
    detector++;
   static int detector2 = 0;
   detector2++;
   
   if(detector2 == 10){
      ofstream object("imena.dat",ios::app);
        static int ocjena = 0;
    ocjena = points - points2;
    if(ocjena == 0 || ocjena < 0){
        string ocj1 = "Vasa ocjena je: 1 ";
        wxMessageBox(wxString(ocj1));
        object<<"ocjena: 1 " <<endl;
        this->Destroy();
        object.close();
       
    }else{
        string ocj = "Vasa ocjena je: " + to_string(ocjena);
        wxMessageBox(wxString(ocj));
       object<<"ocjena: " <<ocjena<<endl;
        this->Destroy();
        object.close();
        
    }
    object.close();
   }

    string read1;
   
   
       ifstream object("database\\pitanja.dat");
     
while (selector!= reading_machine.at(detector) && getline(object, read1)) {
    ++selector;
}

if (selector == reading_machine.at(detector)) {
    
    label1->SetLabel(read1);
} else {
    label1->SetLabel("error");
    // The file contains fewer than two lines.
}
    
}

   void game_frame::bla(string answer){
       
          
  
        string read1;
        int hello = 0;
       ifstream object("database\\odgovori.dat");
     while (hello!= selector && getline(object, read1)) {
    ++hello;
}

if (answer == read1) {
   
 
 
    static int pointss = 0;
     pointss++;
     if(pointss == 6){
         this->Close();
     }else{
     points = pointss;
     stringstream ss;
     ss<<pointss;
     
   wxMessageBox(wxT("tacno"));
   this->Close();

   game_frame::returnall();

   game_frame *frame = new game_frame();
   frame->Center();
   frame->Show(true);
    
  
   
                                                                                                                         
     }
    

     
} else {

      static int pointsss = 0;
     pointsss++;
     if(pointsss == 6){
         this->Close();
     }else{
     points2 = pointsss;
     stringstream ss;
     ss<<pointsss;
     
   wxMessageBox(wxT("Netacno"));
   this->Close();

   game_frame::returnall();

   game_frame *frame = new game_frame();
   frame->Center();
   frame->Show(true);
    
     }
   
       
  
}

   }


void game_frame::Button1Making(){
   
    int bla = 0;
     
      
     int ss;
    ss = reading_machine.at(detector);
    
    
    ifstream object("database\\" + to_string(ss) + ".dat");

    while(bla != random.at(0) && getline(object,rading1)){
        ++bla;
    }
    if(bla ==  random.at(0)){
        button1 = new wxButton(main_panel1,123,rading1,wxPoint(200,50),wxSize(150,50),wxBORDER_NONE);
    }else{
        button1 = new wxButton(main_panel1,123,"Error",wxPoint(200,50),wxSize(150,50));
    }
 

    
  
   
}
void game_frame::Button2Making(){
   
    int bla = 0;

    
    int ss;
    ss = reading_machine.at(detector);

    ifstream object("database\\" + to_string(ss) + ".dat");

    while(bla != random.at(1) && getline(object,rading2)){
        ++bla;
    }
    if(bla ==  random.at(1)){
        button2 = new wxButton(main_panel1,1234,rading2,wxPoint(400,50),wxSize(150,50),wxBORDER_NONE);
    }else{
        button2 = new wxButton(main_panel1,1234,"Error",wxPoint(400,50),wxSize(150,50));
    }

   
  
   
}
void game_frame::Button3Making(){
   
    int bla = 0;
    
    
     int ss;
    ss = reading_machine.at(detector);
    
   

    ifstream object("database\\" + to_string(ss) + ".dat");

    while(bla !=  random.at(2) && getline(object,rading3)){
        ++bla;
    }
    if(bla ==  random.at(2)){
        button3 = new wxButton(main_panel1,12345,rading3,wxPoint(600,50),wxSize(150,50),wxBORDER_NONE);
    }else{
        button3 = new wxButton(main_panel1,12345,"Error",wxPoint(600,50),wxSize(150,50));
    }
   

  
   
}
void game_frame::Button4Making(){
   
    int bla = 0;
     
    int ss;
    ss = reading_machine.at(detector);
    

     ifstream object("database\\" + to_string(ss) + ".dat");

    while(bla !=  random.at(3) && getline(object,rading4)){
        ++bla;
    }
    if(bla ==  random.at(3) ){
        button4 = new wxButton(main_panel1,321,rading4,wxPoint(800,50),wxSize(150,50),wxBORDER_NONE);
     
    }else{
        button4 = new wxButton(main_panel1,321,"Error",wxPoint(800,50),wxSize(150,50));
   }
}


void game_frame::OnButtonClicked1(wxCommandEvent &evt){
    bla(rading1);
    evt.Skip();
} 

void game_frame::OnButtonClicked2(wxCommandEvent &evt){
    bla(rading2);
    evt.Skip();
} 
void game_frame::OnButtonClicked3(wxCommandEvent &evt){
    bla(rading3);
    evt.Skip();
} 
void game_frame::OnButtonClicked4(wxCommandEvent &evt){
    bla(rading4);
    evt.Skip();
} 


void game_frame::returnall(){
  

    
    return question_reader();
    return Button1Making();
    return Button2Making();
    return Button3Making();
    return Button4Making();
    
}

