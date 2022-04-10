#include "Menu.h"
#include "LinkedList.h"
#include "utilities.h"
#include "Person.h"


int main(){
    //  Create a menu
    Menu menu;
	std::srand(unsigned(time(nullptr)));


    //#     Assignment 1
    menu.addItem(MenuItem{
        "String vector iterators",
        []() {
            // Create a vector containing strings, and add some strings
            std::vector<std::string> stringVec {
                "Lorem",
                "Ipsum",
                "Dolor",
                "Sit",
                "Lorem",
                "Amet",
                "Consectetur",
                "Lorem"
            };
            
            std::cout << "String vector:" << std::endl;
            print(stringVec);

            std::cout << "\nString vector revesed:" << std::endl;
            printReversed(stringVec);


            std::cout << "\n";
            std::string old = "Lorem";
            std::string rep = "Modern english word";
            
            std::cout << "Repacing <<" << old << ">> with <<" << rep << ">> :" << std::endl;
            replace(stringVec, old, rep);
            // Print the changed stringVec
            print(stringVec);
        }
    });
    
    //##    Doing the same porcedure for sets
    menu.addItem(MenuItem{
        "String set iterators",
        []() {
            //Create a set of strings
            std::set<std::string> strSet{
                "Lorem",
                "Ipsum",
                "Dolor",
                "Sit",
                "Lorem",
                "Amet",
                "Consectetur",
                "Lorem"
            };
            std::cout << "String set:" << std::endl;
            print(strSet);

            std::cout << "\nReversed string set:" << std::endl;
            printReversed(strSet);


            std::cout << "\n";
            std::string old = "Lorem";
            std::string rep = "Modern english word";
            
            std::cout << "Repacing <<" << old << ">> with <<" << rep << ">> :" << std::endl;
            replace(strSet, old, rep);
            // Print the changed stringVec
            print(strSet);
        }        
    });


    //#     Assignment 2

    menu.addItem({
        "Name sets",
        []() {
            std::list<Person> people;
            Person p1{"Per", "Person"};
            Person p2{"Navn", "Navnesen"};
            Person p3{"Gauss", "Newmann"};
            Person p4{"Albert", "Einstein"};
            Person p5 {"Lars", "Monsen"};
            insertOrdered(people, p1);
            insertOrdered(people, p2);
            insertOrdered(people, p3);
            insertOrdered(people, p4);
            insertOrdered(people, p5);

            print(people);
        }
    });


    //#     Assignment 3

    menu.addItem({
        "Linked list",
        []() {
            LinkedList::LinkedList list;
            list.insert(list.end(), "Item 1");
            // if(insertedNode->getNext() == nullptr) {std::cout << "Next is null\n";}
            // if(insertedNode->getPrev() == nullptr) {std::cout << "Prev is null\n";}

            // delete insertedNode;
            
            // std::cout << *insertedNode->getNext() << std::endl;
            // list.insert(list.find("Item 1"), "Item 2");
            // list.insert(list.end(), "Item 3");
            
            std::cout << list;
        }
    });
    
    
    //#     Assignment 4

    menu.addItem({
        "Template maximum",
        []() {
            int a = 1;
            int b = 2;
            int c = maximum(a, b);
            std::cout << "Max of " << std::to_string(a) << " and " << std::to_string(b)
            << ": " << std::to_string(c) << std::endl;

            double d = 2.4;
            double e = 3.2;
            double f = maximum(d, e);
            std::cout << "Max of " << std::to_string(d) << " and " << std::to_string(e)
            << ": " << std::to_string(f) << "\n" << std::endl;
            
        }
    });

    menu.addItem({
        "Template shuffle",
        []() {
            //#     Part 1
            std::vector<int> a{1, 2, 3, 4, 5, 6, 7};
            std::cout << "Original:"<< std::endl;
            print(a);
            std::cout << "\nShuffled:" << std::endl;
            shuffle(a);
            print(a);

            //#     Part 2
            std::vector<double> b{1.2, 2.2, 3.2, 4.2};
            std::cout << "Original:"<< std::endl;
            print(b);
            std::cout << "\nShuffled:" << std::endl;
            shuffle(b);
            print(b);

            //#     Part 3
            std::vector<std::string> c{"one", "two", "three", "four"};
            std::cout << "Original:"<< std::endl;
            print(c);
            std::cout << "\nShuffled:" << std::endl;
            shuffle(c);
            print(c);
            
            
            
        }
    });

    

    menu.activateMenu();
}