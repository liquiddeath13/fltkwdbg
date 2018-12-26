#pragma once
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <Windows.h>

static void CloseCallback(Fl_Widget*, void*)
{
	exit(0);
}

static void HideCallback(Fl_Widget *w, void*)
{
	if (w->parent() != nullptr)
	{
		reinterpret_cast<Fl_Window*>(w->parent())->hide();
		//ShowWindow(*(reinterpret_cast<HWND*>((reinterpret_cast<Fl_Window*>(w->parent())))), SW_SHOWMINIMIZED);
	}
}

static void RunCallback(Fl_Widget*, void*)
{
	//write here code for run prog
}

static void StopCallback(Fl_Widget*, void*)
{
	//write here code for handling programm stopping
}

static void NextCallback(Fl_Widget*, void*)
{
	//write here code for handling code with breakpoints
}