#include <Dictionary.hpp>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>

// Constructors/Destructors
Dictionary::Dictionary( )
{
}

Dictionary::~Dictionary( )
{
}


// Public general functions
void Dictionary::AddWord( const char * p_pWord )
{
	WordSet::iterator it = m_Words.find( p_pWord );

	if( it == m_Words.end( ) )
	{
		m_Words.insert( p_pWord );
	}
}

bool Dictionary::CheckWord( const char * p_pWord )
{
	// Find the word
	WordSet::iterator it = m_Words.find( p_pWord );

	// Did we find the word?
	if( it != m_Words.end( ) )
	{
		return true;
	}

	return false;
}

void Dictionary::Clear( )
{
	m_Words.clear( );
}

bool Dictionary::ReadFile( const char * p_pFilePath )
{
	// Open the file
	std::ifstream fin( p_pFilePath );
	if( !fin.is_open( ) )
	{
		return false;
	}

/*	// Check the file size
	fin.seekg( 0, fin.end );
	const unsigned int FileSize = static_cast<unsigned int>( fin.tellg( ) );
	fin.seekg( 0, fin.beg );
*/

	// Read all the words
	std::string Word;
	while( !fin.eof( ) )
	{
		fin >> Word;
		m_Words.insert( Word.c_str( ) );
	}
	

	// Close the file
	fin.close( );

	return true;
}
