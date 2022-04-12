#include "Emoji.h"

// Face::Face(Point c, int r) : centre{c}, radius{r} {}
void Face::draw(AnimationWindow& win) {
    win.draw_circle(centre, radius, Color::black);
}

void EmptyFace::draw(AnimationWindow& win) {
    Face::draw(win);
    int eyeSize = 5;
    int horOffset = 20;
    int verOffset = 25;

    Point leftEye   =    {centre.x - horOffset, centre.y -  verOffset};
    Point rightEye  =    {centre.x + horOffset, centre.y -  verOffset};
    if (!oneEye) {
        win.draw_circle(rightEye, eyeSize, Color::white);
    }
    win.draw_circle(leftEye, eyeSize, Color::white);
}

//      5 different emojis
//  Happyface
void HappyFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);

    int verOffset = 20;
    Point mouthCenter = {centre.x, centre.y + verOffset};

    int mouthWidth  = 40;
    int mouthHeigh  = 20;
    int startDegree = 180;  // [deg]
    int endDegree   = 360;    // [deg]

    win.draw_arc(
        mouthCenter,
        mouthWidth,
        mouthHeigh,
        startDegree,
        endDegree,
        Color::white
    );
}
//  Sadface
void SadFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);

    int verOffset = 40;
    Point mouthCenter = {centre.x, centre.y + verOffset};

    int mouthWidth  = 40;
    int mouthHeigh  = 20;
    int startDegree = 0;  // [deg]
    int endDegree   = 180;    // [deg]

    win.draw_arc(
        mouthCenter,
        mouthWidth,
        mouthHeigh,
        startDegree,
        endDegree,
        Color::white
    );
}
//  Angryface
void AngryFace::draw(AnimationWindow& win) {
    SadFace::draw(win);

    int horOffset   = 30;
    int verOffset   = 30;
    int browHeight  = 15;

    Point endpoint0 {centre.x - horOffset, centre.y - (verOffset + browHeight)};
    Point endpoint1 {centre.x + horOffset, centre.y - (verOffset + browHeight)};
    Point midpoint  {centre.x, centre.y - verOffset};

    win.draw_line(endpoint0, midpoint, Color::white);
    win.draw_line(endpoint1, midpoint, Color::white);    
}
//  Winkface
void WinkFace::draw(AnimationWindow& win) {
    HappyFace::draw(win);

    int horOffset   = 20;
    int verOffset   = 23;

    Point winkEye {centre.x + horOffset, centre.y - verOffset};

    win.draw_arc(
        winkEye,
        10,
        6,
        0,      // [deg]
        180,    // [deg]
        Color::white
    );
}
//  Surprisedface
void SurprisedFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);

    int verOffset = 25;
    int mouthRadius = 15;

    Point mouthPoint {centre.x, centre.y + verOffset};


    win.draw_circle(
        mouthPoint,
        mouthRadius,
        Color::white
    );
}
