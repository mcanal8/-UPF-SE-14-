#include <fstream>
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "Channel.hxx"




class channelTests : public TestFixture<channelTests>
{
public:
	TEST_FIXTURE( channelTests )
	{
		TEST_CASE( testChannel_withOneChannel );
		TEST_CASE( testName );
		
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

	
	void testChannel_withOneChannel()
	{
		Channel channel;

		channel.addChannel("Rivendel", "Rivendel: The MeltingPot fantasy channel");

		ASSERT_EQUALS(
			"Rivendel\n"
			"\tRivendel: The MeltingPot fantasy channel\n",
			channel.getChannel()
		)
	}

	void testName()
	{
		Channel channel;

		channel.addChannel("Rivendel", "Rivendel: The MeltingPot fantasy channel");

		ASSERT_EQUALS(
			"Rivendel",
			channel.getName()
		)
	}



	
	
};

REGISTER_FIXTURE(  channelTests )


