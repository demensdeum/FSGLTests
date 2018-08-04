#include <iostream>
#include <memory>
#include <FSGL/Controller/FSGLController.h>

using namespace std;

int main()
{
	cout << "FSGL: Window Initialize Test" << endl;

        auto controller = make_shared<FSGLController>();
        auto window = controller->initialize();

	if (!window) {
		throw runtime_error("Null window - initialize failed or logic was changed, which is bad for this test anyway . Failed.");
	}
	else {
		cout << "Window is not null. Which is good. Test Passed." << endl;
		return 0;
	}
}