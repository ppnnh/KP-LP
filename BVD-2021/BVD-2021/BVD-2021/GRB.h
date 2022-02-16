#pragma once
#include "stdafx.h" 
//#include "MFST.h"

typedef short GRBALPHABET;	// ������� �������� ���������� ��������� > 0,����������� < 0

#define BOTTOM_STACK_GBR '$' // ��� �����
#define START_SYMBOL_GBR 'S' // ��������� ������
#define SEQUENCE_OF_OPERATORS_GBR 'N' // ������������������ ����������
#define EXPRESSION_GBR 'E' // ���������
#define PARMS_GBR 'F' // ���������
#define UNDER_EXPRESSION_GBR 'W' // ������������
#define CONDITION_GBR 'C' // �������
#define MRULE_GBR 'M'

namespace GRB
{
	struct Rule //������� � ���������� 
	{
		GRBALPHABET nn; // ����������(����� ������ �������) 
		int iderror; //  ������������� �����������
		short size; // ���������� �������

		struct Chain
		{
			short size; // ����� �������
			GRBALPHABET* chainOfTerm_nTerm; // ������� ����������(>0) � ������������(<0)

			Chain()
			{
				this->size = 0;
				this->chainOfTerm_nTerm = 0;
			};

			Chain(short symbolCount, GRBALPHABET s, ...);

			char* getCChain(char* b);		//�������� ������ ������� �������
			static GRBALPHABET T(char t) { return GRBALPHABET(t); } // �������� ��������
			static GRBALPHABET N(char n) { return -GRBALPHABET(n); } // �������� ����������
			static bool isT(GRBALPHABET s) { return s > 0; } // ��� ��������?
			static bool isN(GRBALPHABET s) { return s < 0; } // ��� ����������?
			static char alphabet_to_char(GRBALPHABET s) { return (isT(s) ? char(s) : char(-s)); } // ������� � ������
		}*chains;

		Rule()
		{
			this->nn = 0x00;
			this->size = 0;
			this->chains = nullptr;
			this->iderror = -1;
		}
		Rule(GRBALPHABET pnn, int iderror, short psize, Chain c, ...);

		char* getCRule(char* b, short nchain); // �������� ������� ��� ������
		short getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j); // �������� ��������� �� j ���������� �������, ������� �����, ���� ��� ����� -1
	};

	struct Greibach // ���������� �������
	{
		short size; //���������� ������
		GRBALPHABET startN;		//��������� ������
		GRBALPHABET stbottomT;  //��� �����
		Rule* rules; // ��������� ������

		Greibach()
		{
			this->size = 0;
			this->startN = 0;
			this->stbottomT = 0;
			this->rules = 0;
		};
		Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottomT, short psize, Rule r, ...);

		short getRule(GRBALPHABET pnn, Rule& prule); // �������� ����� �������, ���� ��� -1
		Rule getRule(short n); // �������� ������� �� ������
	};

	Greibach getGreibach(); // �������� ���������� �������
}
