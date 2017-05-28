#include <fstream>
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "Channel.hxx"




class channelTests : public TestFixture<channelTests>
{
public:
	TEST_FIXTURE( channelTests )
	{
		TEST_CASE( testDescription );
		TEST_CASE( testName );
		TEST_CASE( testLink );
		
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

	
	void testDescription()
	{
		Channel channel;

		channel.addChannel("Rivendel", "Rivendel: The MeltingPot fantasy channel");

		ASSERT_EQUALS(
			"Rivendel: The MeltingPot fantasy channel",
			channel.getDescription()
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

	void testLink()
	{
		Channel channel;

		channel.addChannel("Rivendel", "Rivendel: The MeltingPot fantasy channel");

		ASSERT_EQUALS(
			"http://www.meltingpotonline.com/Rivendel",
			channel.getLink()
		)
	}



	
	
};

REGISTER_FIXTURE(  channelTests )


