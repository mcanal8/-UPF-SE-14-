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
		//TEST_CASE( testChannel_withInexistentChannel );
		
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

	/*void testNotify_topic()
	{
		Topic topic;

		topic.setName("Topic 1\n");
		topic.notify("A work", "An author");

		ASSERT_EQUALS(
			"To: A client <a@mail.org>\n"
			"Subject: new work A work by An author\n"
			"\n",
			MailStub::theInstance().sentMails()
		);
	}*/


	
	
};

REGISTER_FIXTURE(  channelTests )


