#include <wx/wx.h>
#include <wx/splitter.h>
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include<algorithm>
#include<random>
#include<list>
#include<vector>
#include<chrono>








class game_frame : public wxFrame{
    
    public:
    game_frame();

    private:
    
    wxPanel *main_panel1 = nullptr;
    wxPanel *main_panel2 = nullptr;
    wxPanel *main_panel3 = nullptr;
    wxSplitterWindow *splitter1 = nullptr;
    wxBoxSizer *horizontal_panel_sizer = nullptr;
   wxBoxSizer *vertical_panel_sizer = nullptr;
   wxBoxSizer *btn_sizer = nullptr;
   wxStaticText *label1 = nullptr;
   wxBoxSizer *label_sizer = nullptr;
  std::vector<int> random;
   wxImage img;
   wxBitmapButton *btn = nullptr;

   wxButton *button1 = nullptr;
   wxButton *button2 = nullptr;
   wxButton *button3 = nullptr;
   wxButton *button4 = nullptr;


   std::string rading1;
   std::string rading2;
   std::string rading3;
   std::string rading4;


    
  


   int points2 = 0;
   int points = 0;
   int detector = 0;
   

   std::vector<int> reading_machine;

  


   
   int selector = 0;

   void question_reader();
   void bla(std::string answer);
   void Button1Making();
   void Button2Making();
   void Button3Making();
   void Button4Making();
   void OnButtonClicked1(wxCommandEvent &evt);
   void OnButtonClicked2(wxCommandEvent &evt);
   void OnButtonClicked3(wxCommandEvent &evt);
   void OnButtonClicked4(wxCommandEvent &evt);
   void returnall();
   void refreshall();
   void ocjenjivanje(int tacno,int netacno);
   

   DECLARE_EVENT_TABLE();

  


  
};