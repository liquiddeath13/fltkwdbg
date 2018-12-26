#pragma once
#include <FL/Fl_Button.H>
#include "Callbacks.h"
class FunctionalBar
{
	Fl_Button *run, *stop, *next;
public:
	FunctionalBar() : run{ new Fl_Button(20,40,40,30,"run") }, stop{new Fl_Button(140,40,100,30,"stop")}, next{ new Fl_Button(260,40,100,30,"next") }
	{
		run->callback(RunCallback);
		run->callback(StopCallback);
		run->callback(NextCallback);
		run->hide();
		stop->hide();
		next->hide();
	}
	void Show()
	{
		run->show();
		stop->show();
		next->show();
	}
	void Hide()
	{
		run->hide();
		stop->hide();
		next->hide();
	}
	~FunctionalBar()
	{
		delete run, stop, next;
	}
};