#include "main.h"
#include "in_game.h"
#include "uvod.h"


wxIMPLEMENT_APP(myapp);

bool myapp::OnInit(){
    srand(time(NULL));
   myframe *frame = new myframe();
    frame->Center();
   
    frame->Show(true);
    return true;
}