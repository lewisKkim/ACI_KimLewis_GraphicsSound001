//
//  Particle.hpp
//  ParticleNParcel
//
//  Created by lawsos2 on 9/17/19.
//

#ifndef Particle_hpp
#define Particle_hpp

#include "ofMain.h"

class Particle {
public:
	ofColor color;
	float speed;
	ofVec3f velocity;
	ofVec3f scale;
	ofVec3f position;
	float period;
	float offset;

	float lifespan;

	Particle();
	Particle(ofColor c,
		ofVec3f s,
		float v,
		ofVec3f p,
		float o
	);

	void update(float deltaTime, int time);
	void draw();
	//a shape drawable
};

#endif /* Particle_hpp */