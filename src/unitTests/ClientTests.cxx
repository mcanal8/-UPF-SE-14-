#include <fstream>
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "Client.hxx"





class clientTests : public TestFixture<clientTests>
{
public:
	TEST_FIXTURE( clientTests )
	{
		TEST_CASE(client_withNoData);
		TEST_CASE(client_Description);
		
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

	
	
	void client_withNoData()
	{
		Client client;

		ASSERT_EQUALS( "", client.description() );
	}
	void client_Description()
	{
		Client client;
		client.setName("A client");
		client.setEmail("a@mail.org");

		ASSERT_EQUALS( "A client <a@mail.org>\n", client.description() );

	}
	
	
};

REGISTER_FIXTURE( clientTests )


