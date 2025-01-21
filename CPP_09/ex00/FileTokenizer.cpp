
#include "FileTokenizer.hpp"

FileTokenizer::FileTokenizer(const char & separator ) : _separator(separator)
{

}

FileTokenizer::~FileTokenizer()
{
	if (file.is_open())
		file.close();
}

std::list<t_token_info>	FileTokenizer::tokenize_file(const std::string & file, const char & separator)
{
	FileTokenizer	tokenizer(separator);

	tokenizer.open_file(file);
	tokenizer.start_tokenization();
	return	tokenizer.tokens_list;
}

std::string	FileTokenizer::build_err(const std::string & file_name)
{
	std::string	err_msg;

	err_msg += "Error: Unable to open file. Please ensure the file exists and you have the necessary permissions: ";
	err_msg += '[';
	err_msg += file_name;
	err_msg += "].";

	return err_msg;
}

void	FileTokenizer::open_file(const std::string & file_name)
{
	file.open(file_name.c_str());

	if (!file.is_open())
		throw build_err(file_name);

	this->file_name = file_name;
}

void	FileTokenizer::start_tokenization()
{
	line_num = 1;
	while (std::getline(file, line))
    {
        streamed_line.clear();
        streamed_line.str(line);

        remove_leading_spaces(); 		// Ensures the line is stripped of leading whitespace, making it easier to detect and handle lines that are empty or contain only whitespace.
		next_token_type = YEAR;
		if (!streamed_line.str().empty())
			process_line_tokens();
			
        line_num++;
    }
}


void	FileTokenizer::remove_leading_spaces()
{
    char ch;

	while ((streamed_line.tellg() != -1)
			&& ((size_t) streamed_line.tellg() != streamed_line.str().length())
			&& (streamed_line.peek() == 32 || (streamed_line.peek() >= 9 && streamed_line.peek() <= 13)))
    {
        streamed_line.get(ch);
    }
}

void	FileTokenizer::process_line_tokens()
{
	// here we will only have one line
	while ((streamed_line.tellg() != -1) && ((size_t) streamed_line.tellg() != streamed_line.str().length())) // TODO :
	{
		remove_leading_spaces();
		streamed_line >> token;
		append_token_to_list();

		token = "";
	}
}

void	FileTokenizer::append_token_to_list()
{
	std::string chunk;

    while (token.length())
    {
		if (next_token_type == RATE)
			chunk = token;
		else
        	chunk = get_next_chunk();

        token.erase(0, chunk.length());

		t_token_info	info;

        info.token = chunk;
		info.line_num = line_num;
		info.type = next_token_type;
		tokens_list.push_back(info);
		next_token_type = static_cast<token_type> (static_cast<int> (next_token_type) + 1);
    }
}

std::string	FileTokenizer::get_next_chunk()
{
	for (size_t i = 0; i < token.length(); i++)
    {
		if (token[i] == '-' || token[i] == _separator)
		{
			if (!i)
                return token.substr(0, 1);
            else
                return token.substr(0, i);
		}
	}
	return token;
}