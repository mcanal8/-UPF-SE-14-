#include "MiniCppUnit.hxx"
#include "Author.hxx"

class AuthorTests : public TestFixture<AuthorTests>
{
public:
	TEST_FIXTURE( AuthorTests )
	{
		TEST_CASE( testAuthorName_byDefault );
		
	}
	void testAuthorName_byDefault()
	{
		Author author;
		ASSERT_EQUALS( "--A_Name--", author.getName() );
	}
	
};

REGISTER_FIXTURE( AuthorTests )
