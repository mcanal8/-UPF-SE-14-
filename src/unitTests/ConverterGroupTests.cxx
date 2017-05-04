#include <fstream>
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "ConverterGroup.hxx"


class converterGroupTests : public TestFixture<converterGroupTests>
{
public:
	TEST_FIXTURE( converterGroupTests )
	{
		TEST_CASE( testConvert_withHtmlConverter );
		TEST_CASE( testConvert_withoutHtmlConverter );
		//TEST_CASE( testConvert_withPrintablePdfConverter );
		//TEST_CASE( testConvert_polymorphicCall );
		//TEST_CASE( testConvert_polymorphicCall );
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
	
	void testConvert_withHtmlConverter()
	{
		ConverterGroup converterGroup;
		converterGroup.add( "html" );

		createOriginalFile( "Original.odt" );
		converterGroup.convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"generated/Prefix [multiple HTML files].war\n",
			LibFileSystem::listDirectoryInOrder( "generated" )
		)
	}

	void testConvert_withoutHtmlConverter()
	{
		ConverterGroup converterGroup;

		createOriginalFile( "Original.odt" );
		converterGroup.convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"",
			LibFileSystem::listDirectoryInOrder( "generated" )
		)
	}
	void testConvert_withPrintablePdfConverter()
	{
	
		ConverterGroup converterGroup;
		converterGroup.add( "pdf_print" );

		createOriginalFile( "Original.odt" );
		converterGroup.convert( "originals/Original.odt", "generated/Prefix" );
		

		ASSERT_EQUALS(
			"generated/Prefix [printable].pdf\n",
			LibFileSystem::listDirectoryInOrder( "generated" )
			);


	}



	
	
};

REGISTER_FIXTURE(  converterGroupTests )


