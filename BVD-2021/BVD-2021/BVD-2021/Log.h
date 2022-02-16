#pragma once 
//#include "stdafx.h"

#include <iostream>


#define Null_str ""
#define Zero_t '\0'
#define WNull_str L""
#define CODE_ENDL "\n"
#define STR_MAX_SIZE 500
#define BUFFER_MAX_SIZE 100
#define N_LOG "\n-log: "
#define N_OUT "\n-out: "
#define N_IN "\n-in: "

namespace Log						// ������ � ���������� 
{
	struct LOG
	{
		wchar_t logfile[PARM_MAX_SIZE]; // ��� ����� ������
		std::ofstream* stream;			// �������� ����� ��������� 
	};


	static const LOG INITLOG = { L"", NULL };			// ��������� ��� ��������� ������������� LOG
	LOG getlog(wchar_t* logfile);						 // ������������ ��������� LOG 
	void WriteLine(LOG log_info, const char* str, ...);		 // ������� � �������� ������������ ����� 
	void WriteLine(LOG log_info, const wchar_t* str, ...);		 // ������� � �������� ������������ ����� 
	void WriteLog(LOG log_info);								// ������� � �������� ��������� 
	void WriteParm(LOG log_info, Parm::PARM parms);			// ������� � �������� ���������� � ������� ���������� 
	void WriteIn(LOG log_info, In::IN in);					 // ������� � �������� ���������� � ������� ������ 
	void WriteError(LOG log_info, Error::ERROR error);		// ������� � �������� ���������� �� ������ 
	/*void WriteLtTable(LOG log_info, LT::LexTable lextable);*/
	void Close(LOG log_info);								// ������� �������� 
};

