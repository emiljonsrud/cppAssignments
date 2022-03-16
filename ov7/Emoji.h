#pragma once
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji {
protected:
    int radius;
public:
    Point centre;

    Face(Point c, int r) : centre{c}, radius{r} {};
    virtual void draw(AnimationWindow& win) override;    
    virtual ~Face(){}; 
       
};

class EmptyFace : public Face {
protected:
    bool oneEye;
public:
    EmptyFace(Face f, bool oneEyeInp = false) : Face{f}, oneEye{oneEyeInp} {}
    void draw(AnimationWindow& win) override;
};

//      5 Different emojies
//  Happy
class HappyFace : public EmptyFace {
public:
    HappyFace(EmptyFace f) : EmptyFace{f} {}
    void draw(AnimationWindow& win) override;
    
};
//  Sad
class SadFace : public EmptyFace {
public:
    SadFace(EmptyFace emptyFace) : EmptyFace{emptyFace} {}
    void draw(AnimationWindow& win) override;

};
//  Angry
class AngryFace : public SadFace {
public:
    AngryFace(SadFace sad) : SadFace{sad} {};
    void draw(AnimationWindow& win) override;
};
//  Winky
class WinkFace : public HappyFace {
public:
    // Spørsmål til studass: Er det dårlig skikk å ha initialiseringslisten i headerfilen?
    // om ikke, er det dårlig å ha denne initialieringen her:
    WinkFace(HappyFace happy) : HappyFace{happy} {
        oneEye = true;
    };
    void draw(AnimationWindow& win) override;  
};
//  Surprised
class SurprisedFace : public EmptyFace {
public:
    SurprisedFace(EmptyFace emptyFace) : EmptyFace{emptyFace} {};
    void draw(AnimationWindow& win) override;
};

