#pragma once

#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <string>
#include "Callbacks.h"

class TitleBar
{
	Fl_Box *title = nullptr;
	Fl_Button *close = nullptr;
public:
	TitleBar() : title{ new Fl_Box(0,0,800,30,"") }, close{ new Fl_Button(999,0,25,25,"X") }
	{
		close->callback(CloseCallback);
		title->hide();
		close->hide();
	}
	void Show()
	{
		title->show();
		close->show();
	}
	void Hide()
	{
		title->hide();
		close->hide();
	}
	Fl_Box* getTitle() { return title; }
	~TitleBar();
};

