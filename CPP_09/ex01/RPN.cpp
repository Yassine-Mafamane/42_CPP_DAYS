
#include "RPN.hpp"

RPNCalculator::RPNCalculator(){}

RPNCalculator::~RPNCalculator(){}

float	RPNCalculator::calculate(const std::string & expression)
{
	RPNCalculator		calculator;
	std::stringstream	strm(expression);
	std::string			token;
	token_type			type;

	while (strm >> token)
	{
		type = RPNCalculator::find_token_type(token);

		switch (type)
		{
			case OPERAND :
				calculator.push_operand(token);
				break ;
			case ADDITION :
			case SUBTRACTION :
			case MULTIPLICATION :
			case DIVISION :
				calculator.operate(type);
				break ;
			case UNKNOWN :
				throw std::invalid_argument("Error : Invalid token \"" + token + "\".");
		}
	}
	return calculator.getResult();
}

float	RPNCalculator::getResult()
{
	if (operands.size() != 1)
		throw std::invalid_argument("Invalid result: More than one operand remains in the stack.");
	
	return operands.top();
}

token_type	RPNCalculator::find_token_type(const std::string & token)
{
	if (token == "+")
		return ADDITION;
	else if (token == "-")
		return SUBTRACTION;
	else if (token == "*")
		return MULTIPLICATION;
	else if (token == "/")
		return DIVISION;
	else if (RPNCalculator::is_num(token))
		return OPERAND;
	else
		return UNKNOWN;
}

bool	RPNCalculator::is_num(const std::string & token)
{
	size_t	i = 0;

	if (token[i] == '-' || token[i] == '+')
	{
		if (token.length() == 1)
			return false;
		i++;
	}

	while (i < token.length())
	{
		if (token[i] < '0' || token[i] > '9')
			return false;
		i++;
	}
	return true;
}

void	RPNCalculator::push_operand(std::string & token)
{
	std::stringstream	strm(token);
	int					operand;

	strm >> operand;

	if (strm.fail())
		throw std::invalid_argument("Invalid operand : '" + token + "'.");

	operands.push(static_cast<float>(operand));
}

void	RPNCalculator::operate(const token_type & type)
{
	float	operand1, operand2;

	if (operands.size() < 2)
		throw std::invalid_argument("Operation cannot be performed: insufficient operands in the stack.");

	operand2 = operands.top();
	operands.pop();
	operand1 = operands.top();
	operands.pop();

	switch (type)
	{
		case ADDITION :
			operands.push(operand1 + operand2);
			break ;
		case SUBTRACTION :
			operands.push(operand1 - operand2);
			break ;
		case MULTIPLICATION :
			operands.push(operand1 * operand2);
			break ;
		case DIVISION :
			operands.push(RPNCalculator::divide(operand1, operand2));
			break ;
		default :
			return ;
	}
}

float	RPNCalculator::divide(float a, float b)
{
	if (!b)
		throw std::invalid_argument("Invalid operation: Division by zero encountered.");
	return (a / b);
}