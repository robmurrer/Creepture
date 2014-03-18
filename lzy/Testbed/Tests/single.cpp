#include "single.h"

Single::Single() 
{ 
    // floor
    b2BodyDef myBodyDef;
    b2FixtureDef myFixtureDef;
    b2EdgeShape edgeShape;
    edgeShape.Set( b2Vec2(-15,0), b2Vec2(15,0) );
    myFixtureDef.shape = &edgeShape;

    myBodyDef.position.Set(0,0); //middle, bottom
    //polygonShape.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,0) ); //ends of the line
    b2Body* floor = m_world->CreateBody(&myBodyDef);
    floor->CreateFixture(&myFixtureDef); //add a fixture to the body

} //do nothing, no scene yet
