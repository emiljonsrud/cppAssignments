#include "std_lib_facilities.h"
#include "MenuItem.h"
#include "Menu.h"
#include "Temps.h"

#include "exersize1.h"
#include "exersize2.h"
#include "exersize3.h"
#include "exersize4.h"

int main()
{
	Menu menu;
	
	/* Testing the menu
	MenuItem testItem;
	testItem.setName("This option is a test");
	function<void()> testFunction = []() {
		cout << "This is a test" << endl;
		cout << "this is also a test" << endl;
	};
	testItem.setFunction(testFunction);
	menu.addItem(testItem);
	*/

	
// Exersize 1a
	MenuItem ex1;
	ex1.setName("Write words to a file");
	function<void()> ex1func = [](){
		wordsToFile();
	};
	ex1.setFunction(ex1func);
	menu.addItem(ex1);
	
	
// Exersize 1a
	MenuItem ex1b;
	ex1b.setName("Add line numbers to file");
	function<void()> ex1bfunc = [](){
		addLineNumbers();
	};
	ex1b.setFunction(ex1bfunc);
	menu.addItem(ex1b);
	



// Exersize 2
	MenuItem ex2a;
	ex2a.setName("View character stats for a file");
	
	function<void()> ex2afunc = []() {
		charStat();
	};
	ex2a.setFunction(ex2afunc);
	menu.addItem(ex2a);

	MenuItem ex2b;
	ex2b.setName("View some capitols");
	
	function<void()> ex2bfunc = []() {
		cout << "Capitals:\n";
		for (auto elem : capitalsMap) {
			cout << getCapital(elem.first) << endl;
		}
	};
	ex2b.setFunction(ex2bfunc);
	menu.addItem(ex2b);
	/*
		Her ble det forsøkt å returnere capitolMap[country], men dette 
		funker ikke med map, siden vi ikke har overloaded [] operatoren. Dette
		kan løses med å bruke .find() til maps.
	*/



// Exersize 3
	MenuItem ex3;
	ex3.setName("View some courses");
	function<void()> ex3func = []() {
		testCourseCatalog();
	};
	ex3.setFunction(ex3func);
	menu.addItem(ex3);

	MenuItem ex4;
	ex4.setName("Read temperatures and stuff");
	function<void()> ex4func = []() {
		vector<Temp> temps = readTemps("temperatures.txt");
		tempStats(temps);

	};
	ex4.setFunction(ex4func);
	menu.addItem(ex4);


	
	menu.activateMenu();


}
