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
    constexpr int xmax = 1000;
    constexpr int ymax = 600;
    constexpr int emojiRadius = 50;

    const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

    Face baseFace {
        Point {300, 400},
        100        
    };
    
    //  Create empty vector that will contain emojis
    vector<unique_ptr<Face>> emojis;
    
    //  Create emojies
    HappyFace happy {baseFace};
	SadFace sad {baseFace};
    AngryFace angry {sad};
    WinkFace wink {happy};
    SurprisedFace surprise {baseFace};

    //  Add emojis to the vector of emojis
    emojis.emplace_back(happy);
	emojis.emplace_back(sad);
    emojis.emplace_back(angry);
    emojis.emplace_back(wink);
    emojis.emplace_back(surprise);
    //  Spørsmål til studass: kan du forlkare litt om 
    // "default contructor does not exis"? 

    //  Iterate through the emojis
    int position = 200;
    for (auto const &emoji : emojis) {
        emoji -> centre = {position, emoji -> centre.y};
        emoji -> draw(win);

        position += 250;
    }
    
	win.wait_for_close();
}

