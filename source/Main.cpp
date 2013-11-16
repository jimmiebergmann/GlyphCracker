#include <Dictionary.hpp>
#include <iostream>

// Global variables
static Dictionary * g_pDict = NULL;
static const char g_pDictionaryPath[ ] = "swedish-word-list.txt";

// Help function for closing
int CloseApplication( int p_Code )
{
	if( g_pDict )
	{
		delete g_pDict;
		g_pDict = NULL;
	}

	return 0;
}

int main( )
{
	// Open the dictionary
	g_pDict = new Dictionary( );
	if( g_pDict->ReadFile( g_pDictionaryPath ) == false )
	{
		std::cout << "Can not open the dictionary file: \"" << g_pDictionaryPath << "\"" << std::endl;
		CloseApplication( 0 );
	}
	std::cout << "Successfully read the dictionary file." << std::endl;



	return 0;
}