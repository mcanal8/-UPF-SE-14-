#include <fstream>
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"


class converterGroupTests : public TestFixture<converterGroupTests>
{
public:
	TEST_FIXTURE( converterGroupTests )
	{
		TEST_CASE( testConvert_withoutHtmlConverter );
		//TEST_CASE( testConvert_generateContent );
		//TEST_CASE( testConvert_withInexistentOriginal );
		//TEST_CASE( testConvert_polymorphicCall );
		
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
	/**
	 * This method creates files used in tests
	 */
	void createOriginalFile( const std::string & name )
	{
		std::string fullname( "originals/" );
		fullname += name;
		std::ofstream os( fullname.c_str() );
		os << "An original file" << std::endl;
		os.close();
	}
	
	void testConvert_withoutHtmlConverter()
	{
		Author author;
		
		ASSERT_EQUALS(
			"",
			author.catalogue()
		)
	}


	
	
};

REGISTER_FIXTURE(  converterGroupTests )


