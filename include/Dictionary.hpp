#ifndef GC_DICTIONARY_HPP
#define GC_DICTIONARY_HPP

#include <set>

// TODO: Not supporting win32 line endings

class Dictionary
{

public:

	// Constructors/Destructors
	Dictionary( );
	~Dictionary( );

	// Public general functions
	void AddWord( const char * p_pWord );
	bool CheckWord( const char * p_pWord );
	void Clear( );
	bool ReadFile( const char * p_pFilePath );
	
private:

	// Typedefs
	typedef std::set<const char *> WordSet;

	// Private variables
	WordSet m_Words;

};

#endif