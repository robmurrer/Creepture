#ifndef FOOTEST_H
#define FOOTEST_H

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

class Basic : public Test
{
    public:
        b2Body* dynamicBody;
        Basic() 
        { 
            b2BodyDef myBodyDef;
            myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
            myBodyDef.position.Set(-10, 20); //a little to the left

            b2Body* dynamicBody1 = m_world->CreateBody(&myBodyDef);

            b2CircleShape circleShape;
            circleShape.m_p.Set(0, 0); //position, relative to body position
            circleShape.m_radius = 1; //radius

            b2FixtureDef myFixtureDef;
            myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
            dynamicBody1->CreateFixture(&myFixtureDef); //add a fixture to the body

            //set each vertex of polygon in an array
            b2Vec2 vertices[5];
            vertices[0].Set(-1,  2);
            vertices[1].Set(-1,  0);
            vertices[2].Set( 0, -3);
            vertices[3].Set( 1,  0);
            vertices[4].Set( 1,  1);

            b2PolygonShape polygonShape;
            polygonShape.Set(vertices, 5); //pass array to the shape

            myFixtureDef.shape = &polygonShape; //change the shape of the fixture
            myBodyDef.position.Set(0, 20); //in the middle
            b2Body* dynamicBody2 = m_world->CreateBody(&myBodyDef);
            dynamicBody2->CreateFixture(&myFixtureDef); //add a fixture to the body


            polygonShape.SetAsBox(2, 1); //a 4x2 rectangle
            myBodyDef.position.Set(10,20); //a bit to the right

            b2Body* dynamicBody3 = m_world->CreateBody(&myBodyDef);
            dynamicBody3->CreateFixture(&myFixtureDef); //add a fixture to the body

            // floor
            b2EdgeShape edgeShape;
            edgeShape.Set( b2Vec2(-15,0), b2Vec2(15,0) );
            myFixtureDef.shape = &edgeShape;

            myBodyDef.type = b2_staticBody; //change body type
            myBodyDef.position.Set(0,0); //middle, bottom
            //polygonShape.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,0) ); //ends of the line
            b2Body* floor = m_world->CreateBody(&myBodyDef);
            floor->CreateFixture(&myFixtureDef); //add a fixture to the body
        
        } //do nothing, no scene yet

        void Step(Settings* settings)
        {
            //run the default physics and rendering
            Test::Step(settings); 

        }

        static Test* Create()
        {
            return new Basic;
        }
};

#endif
