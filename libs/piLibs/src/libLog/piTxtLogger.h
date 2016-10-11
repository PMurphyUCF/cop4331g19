#pragma once

#include <stdio.h>

#include "piLog.h"

namespace piLibs {

class piTxtLogger: public piLogger
{
public:
	piTxtLogger();
	~piTxtLogger();

	virtual bool Init( const wchar_t *path, const piLogStartInfo *info );
    virtual void End( void );
	virtual void Printf( int messageId, int threadId, const wchar_t *file, const wchar_t *func, int line, int type, const wchar_t *str );

private:
    FILE *mFp;
};


} // namespace piLibs
