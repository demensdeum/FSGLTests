#include <ctime>
#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <FSGL/Controller/FSGLController.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkitFSGL/Data/FSGTIOFSGLSystemFactory.h>

using namespace std;

int main()
{
	cout << "FSGL: Window Initialize Test" << endl;

	auto controller = make_shared<FSGLController>();
      	controller->initialize();

	auto object = FSEGTFactory::makeOnSceneObject(
														            make_shared<string>("Demensdeum Logo"),
														            make_shared<string>("Demensdeum Logo"),
														            shared_ptr<string>(),
														            make_shared<string>("data/models/skinnedCube/skinnedCube.fbx"),
																shared_ptr<string>(),
														            0, 0, -6.2,
														            1, 1, 1,
														            0.4, 0.8, 0,
														            0);	

	auto graphicsObject = FSGTIOFSGLSystemFactory::graphicsObjectFrom(object);

	controller->addObject(graphicsObject);
    
    auto startTime = time(nullptr);
    
	SDL_Event event;
    while(time(nullptr) - startTime < 3) {
        SDL_PollEvent(&event);
        controller->render();    
    }

	return 0;
}
