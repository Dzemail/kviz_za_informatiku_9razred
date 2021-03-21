#ifndef CUSTOMBITMAPBUTTON_H
#define CUSTOMBITMAPBUTTON_H

#include <wx/wx.h>

#include <wx/bitmap.h>


class wxCustomBitmapButton : public wxBitmapButton
{
public:
  wxCustomBitmapButton() : wxBitmapButton()
  {
  };

  wxCustomBitmapButton(wxWindow *parent, wxWindowID id,  const wxBitmap &bitmap, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize, long style=0, const wxValidator &validator=wxDefaultValidator, const wxString &name=wxButtonNameStr):
    wxBitmapButton( parent, id, bitmap, pos, size, style, validator, name ),
    m_default_color( *wxRED ),
    m_hover_color( *wxBLUE )
  {
    Bind(wxEVT_ENTER_WINDOW, &wxCustomBitmapButton::OnMouseEnter, this );
    Bind(wxEVT_LEAVE_WINDOW, &wxCustomBitmapButton::OnMouseLeave, this );
    Bind(wxEVT_SIZE, &wxCustomBitmapButton::OnSize, this );

    UpdateMouseInside();
  };

  void SetDefaultBackgroundColor( const wxColor &color ) { 
    m_default_color = color;
    UpdateBackgroundColor();
  }
  void SetHoverBackgroundColor( const wxColor &color ) { 
    m_hover_color = color;
    UpdateBackgroundColor();
  }

protected:
  void OnSize( wxSizeEvent &event )
  {
    UpdateMouseInside();
    event.Skip();
  }

  void OnMouseEnter( wxMouseEvent &event )
  {
    m_mouse_inside = true;
    UpdateBackgroundColor();
    event.Skip();
  }

  void OnMouseLeave( wxMouseEvent &event )
  {
    m_mouse_inside = false;
    UpdateBackgroundColor();
    event.Skip();
  }

  void UpdateMouseInside()
  {
    bool new_mouse_inside = GetScreenRect().Contains( ::wxGetMousePosition() );
    if( new_mouse_inside != m_mouse_inside )
    {
      m_mouse_inside = new_mouse_inside;
      UpdateBackgroundColor();
    }
  }

  void UpdateBackgroundColor()
  {
    SetBackgroundColour( m_mouse_inside ? m_hover_color : m_default_color );
    Refresh();
    Update();
  };


  bool m_mouse_inside;
  wxColor m_default_color;
  wxColor m_hover_color;
};


#endif