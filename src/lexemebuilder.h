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

#ifndef LEXEMES_H
#define LEXEMES_H

#include <string>
#include <vector>
#include <list>
#include <time.h>
#include <stdio.h>
#include <limits.h>

namespace pichi
{

class SQLite;
  
class LexemeBuilder
{
  public:
	LexemeBuilder(SQLite** s);
	bool is_answer_limit;
	size_t word_size_limit;
	size_t message_size_limit;
	size_t query_limit;
	void parseText(std::string text);
	inline std::string addLexema(const std::vector<std::string>& lex);
	
	std::string genFullRandom();
	std::string genFromWord(const std::string& word);
	void addNick(const std::string& nick);
  protected:
	SQLite **sql;
	std::string user_text;
	std::string send_text;
	
	void buildArray(void);
	std::vector<std::string> choiseWords(void);
	std::string wToString(const std::vector<std::string>& msg, bool f = true, bool s = true, bool t = true);
	void clean(void);
	void cleanString(std::string& string);

  private:
	std::vector< std::pair< int, std::vector<std::string> > > answers;
	std::string sqlquery;
	std::list<std::string> nicks;
};

}

#endif // LEXEMES_H
