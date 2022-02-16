#pragma once
#include "stdafx.h"

//#include "LT.h"

#define	ID_MAXSIZE		10			// ������������ ���������� �������� � ��������������
#define	TI_MAXSIZE		500		// ������������ ���������� ����� � ������� ���������������
#define	TI_INT_DEFAULT	0x00	// �������� �� ��������� ��� ���� int
#define	TI_STR_DEFAULT	0x00		// �������� �� ��������� ��� ���� string
#define	TI_NULLIDX		0xffffffff	// ��� �������� ������� ���������������
#define	TI_STR_MAXSIZE	255
#define	TI_BYTE_MAXSIZE	9
#define	TI_PARMS_MAXSIZE	10 // ������������ ����� ���������� �������

#define FUNC_ID_TI -1 // functIdxIt ��� �������
#define NODEF_FUNC_ID_TI -3 // functIdxIt �����������

#define ERROR_ID_NODEF -2 //  ������������� �� ��������� ��� �������� ADD 
#define ID_ENTRY_ENCRYPTION(idx) -idx - 5 //���������� ������ ��������������

namespace IT
{
	enum class IDDATATYPE {
		NDEFD = 'n',
		STR = 's',
		BYTE = 'b',
	};
	enum class IDTYPE
	{
		NDEFT = 0,	//�����������
		V = 1,		//����������
		F = 2,		//�������
		L = 3,		//�������
		P = 4,      //��������
		DF = 5,		//����������� �������
		DFP = 6,	//�������� ����������� �������
	};
	struct Entry // ������ ������� ���������������
	{
		int			idxfirstLE;	// ������ ������ ������ � ������� ������
		int			idxFuncIT = -1; // ������ �������, ������� �����������  �������������(��� ������� -1)
		unsigned char id[ID_MAXSIZE + 1] = "";//  ������������� (������������� ��������� �� ID_MAXSIZE)
		IDDATATYPE	iddatatype;	// ��� ������
		IDTYPE		idtype;   // ��� ��������������
		IDDATATYPE* parmsTypes; // ���� ���������� ��� ������������� ��������
		bool		isdefined = false; // ���� �� ��������� ����� ���� ��������
		Entry();
		Entry(int idxIT); // ���� ������  �������������, �������
		Entry(int& idxfirst, unsigned char* iD, int funcId, IDDATATYPE& iddat, IDTYPE& idtype);
		struct
		{
				short len;
				char* str;
		}	literalValue;
	};

	struct  IdTable	// ��������� ������� ���������������
	{
		int maxsize;// ������� ������� ��������������� < TI_MAXSIZE
		int size;	// ������� ������ ������� ��������������� < maxsize
		Entry* table;// ������ ����� ������� ���������������
		int LastId();
	};
	bool PutLiteral(IdTable& idtable, LT::LexTable& lextable, unsigned char* iD,
		IDDATATYPE iddat);
	bool Putentry(IdTable& idtable, LT::LexTable& lextable,  unsigned char* iD,
		IDDATATYPE iddat, IDTYPE idt);
	bool PutMain(IdTable& idtable, LT::LexTable& lextable);
	IdTable Create(						// ������� ������� ���������������
		int size			// ������� ������� ��������������� < TI_MAXSIZE
	);
	int Add(							// �������� ������ � ������� ���������������
		IdTable& idtable,		// ��������� ������� ���������������
		const Entry& entry			// ������ ������� ���������������
	);
	Entry Getentry(IdTable& idtable, int n);


	void Delete(IdTable& idtable);		// ������� ������� ��������������� ( ���������� ������ );
}