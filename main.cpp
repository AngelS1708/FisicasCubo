#include <iostream>
#include "reactphysics3d/reactphysics3d.h"

using namespace std;
using namespace reactphysics3d;

int main()
{
	PhysicsCommon physicCommon; //Se necesita para crear un mundo de fisicas
	PhysicsWorld* world = physicCommon.createPhysicsWorld(); //mundo de fisicas

	Vector3 position(0, 20, 0);
	Quaternion	orientacion = Quaternion::identity();//Todas las rotaciones trabajan a partir de Quaterniones

	Transform transform(position, orientacion);
	RigidBody* body = world->createRigidBody(transform);

	const decimal timeStep = 1.0f / 60.0f;

	for (int i = 0; i < 100; i++)
	{
		world->update(timeStep);

		const Transform& transform = body->getTransform();
		const Vector3& position = transform.getPosition(); 

		cout << "Body position (" << position.x << " ," <<
			position.y << " ," << position.z << ")" << endl;
	}

	world->destroyRigidBody(body);
	physicCommon.destroyPhysicsWorld(world);
}