#include <fstream>
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "MeltingPotOnline.hxx"


class ConverterTests : public TestFixture<ConverterTests>
{
public:
	TEST_FIXTURE( ConverterTests )
	{
		//TEST_CASE( testConvertersByDefault_withoutOriginals );
		TEST_CASE(testConvert_generateFile);

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
	
	void testConvert_generateFile()
	{
		HtmlConverter converter;
		createOriginalFile( "Original.odt" );
		converter.convert( "originals/Original.odt", "generated/Prefix" );
	}
	/*void testConvertersByDefault_withoutOriginals()
	{
		MeltingPotOnline business;
		business.addAuthor( "An author", false );

		ASSERT_EQUALS(
			"", 
			LibFileSystem::listDirectoryInOrder( "generated" )
		);
	}*/
	
};

REGISTER_FIXTURE( HtmlConverterTests )


