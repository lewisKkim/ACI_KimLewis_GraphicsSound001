//
//  Particle.cpp
//  ParticleNParcel
//
//  Created by lawsos2 on 9/17/19.
//

#include "Particle.h"

Particle::Particle() {
	Particle(ofColor::hotPink,
		ofVec3f(1, 1, 1),
		10,
		ofVec3f(ofGetWidth() / 2, ofGetHeight() / 2, 0),
		10);
}

Particle::Particle(ofColor c,
	ofVec3f s,
	float v,
	ofVec3f p,
	float o
) {
	color = c;
	scale = s;
	position = p;
	speed = v;
	period = o;
	lifespan = 0.0;
	offset = ofRandom(-25.0, 25.0);
}

void Particle::update(float deltaTime,int time) {
	lifespan += deltaTime;
	velocity = ofVec3f(sin((float(time) + offset)/ period) * speed,-speed,0.0);
	velocity.limit(50);
	position += velocity;
}

void Particle::draw() {
	ofSetColor(color);
	ofPushMatrix();
	ofTranslate(position);
	ofDrawBox(scale.x, scale.y, scale.z);
	ofPopMatrix();
}