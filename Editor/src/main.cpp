#include <Sonic.h>


class Application : public Sonic::Application
{
public:

};


int main()
{
	Application app;
	app.run();

	USER_INFO("Hello form User!");

	return 0;
}