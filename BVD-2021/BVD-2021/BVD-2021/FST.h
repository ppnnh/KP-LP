#pragma once
#include "stdafx.h"
//#include "Error.h"
//#include "Parm.h"
//#include "In.h"
//#include "Log.h"
//#include "Out.h"
//#include "LT.h"
//#include "IT.h"


namespace FST
{
	struct RELATION //�����:������ -> ������� ����� ��������� ��
	{
		unsigned char symbol; //������ ��������
		short nnode; //����� ������� �������
		RELATION(
			unsigned char c = 0x00, // ������ ��������
			short ns = NULL //����� ���������
		);
	};
	struct NODE	//������� ����� ���������
	{
		short n_relation;	//���������� ������������ ����� 
		RELATION* relations; //����������� �����
		NODE();
		NODE(
			short n,		//���������� ������������ �����
			RELATION rel, ... //������ �����
		);
	};
	struct FST	//������������������� �������� �������
	{
		unsigned char* string; //������� (������, ����������� 0�00)
		short position; //������� ������� � �������
		short nstates; //���������� ��������� ��������
		NODE* nodes;	//���� ���������: [0] - ��������� ���������, [nstate-1] - ��������
		short* rstates; //��������� ��������� �������� �� ������ �������
		FST(
			unsigned char* s, //�������(������, ����������� 0�00)
			short ns, //���������� ��������� ��������
			NODE n, ...	//������ ��������� (���� ���������)
		);
		FST() {
			this->string = nullptr;
			this->position = -1;
			this->nstates = -1;
			this->nodes = nullptr;
			this->rstates = nullptr;
		}

	};
	bool execute(FST& fst);
}