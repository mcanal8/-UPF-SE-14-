#include <fstream>
#include "LibFileSystem.hxx"
#include "MiniCppUnit.hxx"
#include "PdfConverter.hxx"



class pdfConverterTests : public TestFixture<pdfConverterTests>
{
public:
	TEST_FIXTURE( pdfConverterTests )
	{
		TEST_CASE( testConvert_generateFile );
		TEST_CASE( testConvert_generateContent );
		TEST_CASE( testConvert_withInexistentOriginal );
		TEST_CASE( testConvert_polymorphicCall );
		
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
		PdfConverter converter;
		createOriginalFile( "Original.odt" );
		converter.convert( "originals/Original.odt", "generated/Prefix" );
		converter.activateWatermark( "watermark" );
		converter.convert( "originals/Original.odt", "generated/Prefix" );

		ASSERT_EQUALS(
			"generated/Prefix [printable].pdf\n"
			"generated/Prefix [watermark].pdf\n",
			LibFileSystem::listDirectoryInOrder( "generated" )
			);
	}

	void testConvert_generateContent()
	{
		PdfConverter converter;
		createOriginalFile( "Original.odt" );
		converter.convert( "originals/Original.odt", "generated/Prefix" );
		converter.activateWatermark( "watermark" );
		converter.convert( "originals/Original.odt", "generated/Prefix" );
		
		
		ASSERT_EQUALS("PDF generated from 'originals/Original.odt'. Watermark: 'watermark'\n", LibFileSystem::fileContent("generated/Prefix [watermark].pdf"));
		
	}
	
	void testConvert_withInexistentOriginal()
	{
		PdfConverter converter;
		
		try
		{
			converter.convert( "originals/Original.odt", "generated/Prefix" );
			FAIL( "An exception should be caught!" );		
		}
		catch ( std::exception & e )
		{
			ASSERT_EQUALS(
				"The original file does not exist",
				e.what()
			)
		}	
	}

	void testConvert_polymorphicCall()
	{
		createOriginalFile( "Original.odt" );
		Converter *converter1;
		converter1 = new  PdfConverter();

		
		createOriginalFile( "Original.odt" );
		converter1->convert( "originals/Original.odt", "generated/Prefix" );
		converter1->activateWatermark( "watermark" );
		converter1->convert( "originals/Original.odt", "generated/Prefix" );
		

		ASSERT_EQUALS(
			"generated/Prefix [printable].pdf\n"
			"generated/Prefix [watermark].pdf\n",
			LibFileSystem::listDirectoryInOrder( "generated" )
			);
		delete (converter1);

	}
	
	
};

REGISTER_FIXTURE(  pdfConverterTests )


