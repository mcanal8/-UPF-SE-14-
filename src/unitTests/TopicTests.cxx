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
		TEST_CASE( testNotify_topic );
		
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

	void testNotify_topic()
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
	}


	
	
};

REGISTER_FIXTURE(  topicTests )


