
#ifndef TOKENIZER_HPP
# define TOKENIZER_HPP

#include <string>
#include <sstream>
#include <fstream>
#include <list>

typedef unsigned short	ushort;

typedef enum	e_token_type
{
	YEAR,
	SEPARATOR1,
	MONTH,
	SEPARATOR2,
	DAY,
	SEPARATOR3,
	RATE
}	token_type;

typedef struct	s_token_info
{
	std::string		token;
	unsigned short	line_num;
	token_type		type;
}	t_token_info;

typedef enum	e_err_level
{
	FILE_ERR,
	DATE,
	PRICE,
	OTHER
}	err_level;


class FileTokenizer
{
	public :

		~FileTokenizer();

		static std::list<t_token_info>	tokenize_file( const std::string & file, const char & separator );

	private :

		FileTokenizer( const FileTokenizer& ref );
		FileTokenizer( const char & separator );

		void							open_file( const std::string & file_name );
		std::string						build_err( const std::string & file_name );
		void							start_tokenization();
		void							remove_leading_spaces();
		void							process_line_tokens();
		void							append_token_to_list();
		std::string						get_next_chunk();

		std::list<t_token_info>	tokens_list;

		char					_separator;
		std::ifstream			file;
		std::string				file_name;

		std::string				line;
		std::string				token;
		ushort					line_num;

		std::stringstream		streamed_line;
		token_type				next_token_type;
};








#endif