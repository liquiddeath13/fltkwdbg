#define WIN32
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Display.H>
#include <FL/fl_utf8.H>
#include "TitleBar.h"
#include "FunctionalBar.h"
#include "TextOutput.h"

#pragma comment(lib, "fltk")

void SetLabel(Fl_Widget *w, const std::string& label)
{
	if (w != nullptr) w->copy_label(fl_locale_to_utf8(label.c_str(), label.length(), 1251));
}

Fl_Window* CreateFltkWindowPtr(int w, int h, const std::string& label = "", int x = 0, int y = 0)
{
	Fl_Window *t = new Fl_Window(x, y, w, h);
	SetLabel(t, label);
	return t;
}

Fl_Button* CreateFltkButtonPtr(int x, int y, int w, int h, const std::string& label = "")
{
	Fl_Button *t = new Fl_Button(x, y, w, h);
	SetLabel(t, label);
	return t;
}

std::string getCode(const std::string& filename)
{
	std::ifstream prog(filename);
	if (prog.bad()) return std::string("");
	std::stringstream ss;
	std::string t = "";
	while (!prog.eof())
	{
		std::getline(prog, t);
		std::cout << t << std::endl;
		ss << t << std::endl;
	}
	t = fl_locale_to_utf8(ss.str().c_str(), ss.str().length(), 1251);
	return t;
}

void TechInformation()
{
	//ICONS LEGEND:
	
	//[EXEC] - run without stop
	//[RUN] - run to next bp
	//[STOP] - stop programm debugging
	//[X] - close programm
	//[-] - hide programm
	
	//TERMIN LEGEND:
	
	//IP: current instruction pointer
	//ERRSTATUS: last error status
	//STACK CALLS: stack of calls in programm
	//REG VALUES: current register values
	//MEM VALUES: mem value, which used on resources

	//FORM:

	//==title========================[-]=[x]==//
	//========================================//
	// | [run] [stop] [next] |                //
	//========================================//
	// BP |   PROG COMMAND   |  IP:           //
	// BP |   PROG COMMAND   |  ERRSTATUS:    //
	// BP |   PROG COMMAND   |  FLAGS:        //
	// BP |   PROG COMMAND   |----------------//
	// BP |   PROG COMMAND   |  REG VALUES    //
	// BP |   PROG COMMAND   |  MEM VALUES    //
	// BP |   PROG COMMAND   | STACK OF CALLS //
	//========================================//
	//CUSTOM WIDGETS:

	//TITLE BAR:
	//==title========================[-]=[x]==//

	//TEXT OUTPUT:
	// BP |   PROG COMMAND   |
	// BP |   PROG COMMAND   |
	// BP |   PROG COMMAND   |
	// BP |   PROG COMMAND   |
	// BP |   PROG COMMAND   |
	// BP |   PROG COMMAND   |

	//| IP:            //
	//| ERRSTATUS :    //
	//| FLAGS:         //

	//|  REG VALUES    //
	//|  MEM VALUES    //
	//| STACK OF CALLS //

	//PSEUDO BAR:
	// | [run] [stop] [next] |                //

	//FUNCTIONAL:

	//should highlight current programm command line on text display widget
	//should turn on/off breakpoints on left column
	//should go through commands by 'step-to-step' mode, execute without stopping, run to next breakpoint
	//should print register values on different modes, memory values on different modes
	//should print current instruction pointer value, error status, list of calls (stack of calls)
}

int main()
{
	Fl_Window *MainWindow = CreateFltkWindowPtr(1024, 768, "");
	MainWindow->border(0);
	MainWindow->begin();
	TitleBar *bar = new TitleBar();
	SetLabel(bar->getTitle(), "Оконный отладчик виртуальной машины");
	bar->Show();
	FunctionalBar *functions = new FunctionalBar();
	functions->Show();
	TextOutput *codeView = new TextOutput(20, 80, 600, 650);
	std::string cppcode = getCode("main.cpp");
	if (cppcode == "") cppcode = "error occured";
	codeView->SetText(cppcode);
	codeView->Show();
	TextOutput *psw = new TextOutput(640, 80, 280, 300);
	psw->SetText("IP:\nERRSTATUS:\nFLAGS:");
	psw->Show();
	TextOutput *processorValues = new TextOutput(640, 400, 280, 300);
	processorValues->SetText("REG VALUES:\nMEM VALUES:\nSTACK OF CALLS:");
	processorValues->Show();
	MainWindow->end();
	MainWindow->show();
	return Fl::run();
}