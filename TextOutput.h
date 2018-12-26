#pragma once
#define WIN32
#include <FL/Fl_Text_Display.H>
#include <string>
#include <FL/fl_utf8.H>
class TextOutput
{
	Fl_Text_Display *disp = nullptr;
	Fl_Text_Buffer *buf = nullptr;
// if need highlight code look at: https://www.fltk.org/doc-1.3/editor.html
public:
	TextOutput(int x, int y, int w, int h) : disp{ new Fl_Text_Display(x,y,w,h) }
	{
		disp->hide();
		buf = new Fl_Text_Buffer();
		disp->buffer(buf);
	}
	void SetText(const std::string& text) noexcept
	{
		buf->text(fl_locale_to_utf8(text.c_str(), text.length(), 1251));
	}
	void Show()
	{
		disp->show();
	}
	void Hide()
	{
		disp->hide();
	}
	~TextOutput()
	{
		delete disp, buf;
	}
};