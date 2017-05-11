#include <fstream>
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "Topic.hxx"




class topicTests : public TestFixture<topicTests>
{
public:
	TEST_FIXTURE( topicTests )
	{
		TEST_CASE( testName_withOneName );
		
	}

	/**
	 * The setUp method is automatically called before each test
	 */
	void setUp()
	{
		LibFileSystem::createNetDirectory( "config" );
		LibFileSystem::createNetDirectory( "generated" );
		LibFileSystem::createNetDirectory( "originals" );
	}
	/**
	 * The tearDown method is automatically called after each test
	 */
	void tearDown()
	{
		LibFileSystem::cleanupDirectory( "config" );
		LibFileSystem::cleanupDirectory( "generated" );
		LibFileSystem::cleanupDirectory( "originals" );
	}

	
	void testName_withOneName()
	{
		Topic topic;

		topic.setName("Topic 1\n");

		ASSERT_EQUALS( "Topic 1\n", topic.getName() );
	}


	
	
};

REGISTER_FIXTURE(  topicTests )


