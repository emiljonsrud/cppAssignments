#include "exersizeFunctions.h"
#include "std_lib_facilities.h"

#include "Animal.h"

#include "AnimationWindow.h"
#include "Emoji.h"

//      Oppgave 1
void testAnimal() {
    // Create an empty vector of Animal types and fill it 
    // cats and dogs 
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Dog("Terry", 35));
    animals.emplace_back(new Cat("Jerry", 35));
    animals.emplace_back(new Cat("Garfield", 40));
    animals.emplace_back(new Cat("Spot", 2));
    animals.emplace_back(new Dog("Tucker", 12));
    animals.emplace_back(new Cat("Max", 6));
    animals.emplace_back(new Dog("Toby", 4));
    animals.emplace_back(new Dog("Tank", 14));

    for (auto const& animal : animals) {
        cout << animal -> toString() << endl;
    }    
}


//      Oppgave 2
void testEmoji() {
    // Definer størrelse på vindu og emoji
    constexpr int xmax = 1300;
    constexpr int ymax = 300;
    // constexpr int emojiRadius = 50;

    const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

    Face baseFace {
        Point {300, 400},
        100        
    };
    

    //  Create emojies
    // HappyFace happy = {baseFace};
	// SadFace sad {baseFace};
    // AngryFace angry {sad};
    // WinkFace wink {happy};
    // SurprisedFace surprise {baseFace};

    /*
        Spørsmål til studass:   Hvorfor kan jeg ikke hive en face inn i alle 
        kontruktørene? De har samme input-argumenter, og kaller på kontruktørene
        oppåver i familietreet.
            Se Angry i h-filen, jeg endret til 
                    AngryFace(Face sad) : SadFace{sad} {};
                fra
                    AngryFace(SadFace sad) : SadFace{sad} {};
            er dette noe man må gjøre når man lager subklasser?
    */

    //  Create empty vector that will contain emojis
    vector<unique_ptr<Emoji>> emojis;

    //  Add emojis to the vector of emojis
    emojis.emplace_back(new HappyFace       {Face {Point{300, 150}, int{100}}});
	emojis.emplace_back(new SadFace         {Face {Point{300, 150}, int{100}}});
    emojis.emplace_back(new SurprisedFace   {Face {Point{300, 150}, int{100}}});
    emojis.emplace_back(new AngryFace       {Face {Point{300, 150}, int{100}}});
    emojis.emplace_back(new WinkFace        {Face {Point{300, 150}, int{100}}});

    //  Iterate through the emojis
    int position = 150;
    for (auto const &emoji : emojis) {
        // Point newPoint {position, 200};
        emoji.get() ->setCentreX(position);

        emoji.get() ->draw(win);
        position += 250;
    }
    
	win.wait_for_close();
}