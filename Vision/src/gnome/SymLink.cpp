// BSymLink-like class
//
// see License at the end of file

#include "Directory.h"
#include "SymLink.h"
#include "Path.h"


FSymLink::FSymLink()
	:	fStatus(B_NO_INIT)
{
}


FSymLink::FSymLink(const FDirectory *dir, const char *name)
{
	fStatus = SetTo(dir, name);
}

status_t 
FSymLink::SetTo(const FDirectory *directory, const char *name)
{
	EntryRef ref;
	fStatus = directory->GetRef(&ref);	
	if (fStatus == B_OK) {
		FPath path(ref.Path());
		if (name) {
			path.Append(name);
			ref.SetTo(path.Path());

		}
		if (fStatus == B_OK)
			fRef = ref;
	}
	return fStatus;
}

/*
License

Terms and Conditions

Copyright (c) 1999-2001, Pavel Cisler

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met: 

Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer. 

Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution. 

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF TITLE,
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF, OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE. 
*/