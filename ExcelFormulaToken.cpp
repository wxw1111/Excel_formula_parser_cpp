#include "ExcelFormulaToken.h"

namespace ExcelFormulaParser
{

	ExcelFormulaToken::ExcelFormulaToken():
		m_value(),
		m_type(Unknown),
		m_subtype(Nothing){}

	ExcelFormulaToken::ExcelFormulaToken(const char* szValue, ExcelFormulaTokenType type): 
	m_value(szValue),
	m_type(type),
	m_subtype(Nothing) {}


	ExcelFormulaToken::ExcelFormulaToken(const char* szValue, ExcelFormulaTokenType type, ExcelFormulaTokenSubtype subtype):
		m_value(szValue),
		m_type(type),
		m_subtype(subtype) {} 

	bool ExcelFormulaToken::operator==(ExcelFormulaToken& token) {
		if (token.getType() == getType()
				&& token.getSubtype() == getSubtype()
				&& token.getValue() == getValue())
			return true;
		else
			return false;
	}

	//! return printable string
	string ExcelFormulaToken::getPrintableString()
	{
		string printableStr = m_value + " ";

		switch(m_type)
		{
			case Operand:
				printableStr += "<Operand>";
				break;
			case Function:
				printableStr += "<Function>";
				break;
			case Subexpression:
				printableStr += "<Subexpression>";
				break;
			case Argument:
				printableStr += "<Argument>";
				break;
			case OperatorPrefix:
				printableStr += "<OperatorPrefix>";
				break;
			case OperatorInfix:
				printableStr += "<OperatorInfix>";
				break;
			case OperatorPostfix:
				printableStr += "<OperatorPostfix>";
				break;
			case Whitespace:
				printableStr += "<Whitespace>";
				break;
			case Unknown:
				printableStr += "<Unknown>";
				break;
		}//token type switch

		printableStr += " ";

		switch(m_subtype)
		{
			case Nothing:
				printableStr += "<Nothing>";
				break;
			case Start:
				printableStr += "<Start>";
				break;
			case Stop:
				printableStr += "<Stop>";
				break;
			case Text:
				printableStr += "<Text>";
				break;
			case Number:
				printableStr += "<Number>";
				break;
			case Logical:
				printableStr += "<Logical>";
				break;
			case Error:
				printableStr += "<Error>";
				break;
			case Range:
				printableStr += "<Range>";
				break;
			case Math:
				printableStr += "<Math>";
				break;
			case Concatenation:
				printableStr += "<Concatenation>";
				break;
			case Intersection:
				printableStr += "<Intersection>";
				break;
			case Union:
				printableStr += "<Union>";
				break;
		}//token subtype switch
		return printableStr;
	} //func  getPrintableStr
}//namespace 









