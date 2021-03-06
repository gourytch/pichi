/*
    Pichi XMPP (Jabber) Bot.
    Copyright (C) 2011  Alexey Kasyanchuk (deg@uruchie.org)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <time.h>
#include <vector>


namespace pichi
{

class Helper
{
  protected:
	static inline std::string codePointToUTF8(unsigned int cp);
	static inline bool decodeUnicodeEscapeSequence( const std::string& str, 
	                                     size_t current, 
	                                     size_t end, 
	                                     unsigned int &unicode );
	//static bool decodeUnicodeCodePoint( const std::string& str, 
	//                                     size_t current, 
	//                                     size_t end, 
	//                                     unsigned int &unicode );
  public:
	Helper();
	~Helper();
	
	static std::string pichiHeader(void);
	static std::vector< std::string > explode(std::string seperator, std::string str);
	static std::string implode(std::string, std::vector< std::string >);
	static std::string timeToString(time_t, std::string);
	static std::string stringTime(time_t);
	static std::string itoa(int);
	static std::vector< std::string > splitBySize(const std::string& str, size_t size);
	static int atoi(std::string);
	static size_t atot(std::string);
	static std::string ttoa(size_t);
	static const std::string getFullPath(const std::string& dir);
	static bool fileExists(const std::string& file);
	template<typename compT> static bool in_array(compT&, std::vector<compT>&);
	static std::vector< std::string > getDirFiles(const std::string& path);
	static bool createDirectory(const std::string& path, const int mask = 0775);
	static bool removeDirectory(const std::string& path);
	static bool removeFile(const std::string& path);
	static std::string getShareFile(const std::string& file, bool isThrowEx = true);
	static double microtime(void);
	static std::string md5sum(const std::string& tomd5);
	
	static std::string decodeUnicodeString( const std::string& str );

};

}

#endif // SYSTEM_H
