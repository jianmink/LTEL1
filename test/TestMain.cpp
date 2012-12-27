#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestPlugin.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupportPlugin.h"

class MyDummyComparator : public MockNamedValueComparator
{
public:
	virtual bool isEqual(void* object1, void* object2)
	{
		return object1 == object2;
	}

	virtual SimpleString valueToString(void* object)
	{
		return StringFrom(object);
	}
};

int main(int ac, char** av)
{
	MyDummyComparator dummyComparator;
	MockSupportPlugin mockPlugin;

	mockPlugin.installComparator("MyDummyType", dummyComparator);
	TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
	return CommandLineTestRunner::RunAllTests(ac, av);
}



