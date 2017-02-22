#include "MiniCppUnit.hxx"
#include "Author.hxx"

class AuthorTests : public TestFixture<AuthorTests>
{
public:
	TEST_FIXTURE( AuthorTests )
	{
		TEST_CASE( testAuthorName_byDefault );
		TEST_CASE( testAuthorName_addName );
		TEST_CASE( testContracted_byDefault );
		
	}
	void testAuthorName_byDefault()
	{
		Author author;
		ASSERT_EQUALS( "--A_Name--", author.getName() );
	}
	
	void testAuthorName_addName()
	{
		Author author;
		author.setName("Pol");
		ASSERT_EQUALS( "Pol", author.getName() );
	}
	
	void testContracted_byDefault()
	{
		Author author;
		ASSERT_EQUALS( false, author.isContracted() );
	}
	
};

REGISTER_FIXTURE( AuthorTests )
