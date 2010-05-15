#include "body.h"
#include "globals.h"

void Body::update() {}
void Body::draw() {
	s.SetPosition(b2s( 100.0f * b->GetPosition() ));
	s.SetRotation(r2d(b->GetAngle()));
	G::window.Draw(s);
}
