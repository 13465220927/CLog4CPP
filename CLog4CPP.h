/*
**************************************************************************************
**
**	FILENAME			CLog4CPP.h
**
**	PURPOSE				����һ��C++����־������,����ASNI��UINCODE����
**
**	CREATION DATE		2016-08-12
**
**	AUTHOR				itas109
**
**  Blog                http://blog.csdn.net/itas109
**
**  Git                 https://github.com/itas109
**
**************************************************************************************
**  author: itas109  date:2016-08-15
**  Blog��blog.csdn.net/itas109
**  �Ľ�
**  1�� Init��������Ĭ�ϳ�ʼ������
**  2�� �������
**  3�� �Ż����������
**************************************************************************************
**  author: itas109  date:2016-08-17
**  Blog��blog.csdn.net/itas109
**  �Ľ�
**  1�� Init�������أ���ʱ�������ļ���
**  2�� ��־�ļ�Ĭ�Ϸŵ�Log�ļ�����
**  3�� ����int2string�����������������ַ���ת��
**************************************************************************************
**  author: itas109  date:2016-08-18
**  Blog��blog.csdn.net/itas109
**  �Ľ�
**  1�� ȡ��MFC������
**  2�� ����C++ͨ����������
*/
#pragma once

#include <string>
#include <sstream>
#include <direct.h>
#include "atltime.h"

class CLog4CPP
{
public:

	CLog4CPP();
	~CLog4CPP();

	//��ʼ��
	void Init(std::string stringpOutputFilename);
	void Init();//���յ�������������־�ļ�

	//������֣�������TRACE��printf
	bool LogOut(std::string text);

	//����ʹ��
	void IsEnable(bool bEnable);

	//�Ƿ���ÿ�м���ʱ���
	void IsPrintTime(bool b) {m_bPrintTime = b;}

protected:
	//������
	enum {TBUF_SIZE = 3000};
	std::string m_tBuf[TBUF_SIZE];

	std::string m_csFileName;
	
	//�ٽ���
	CRITICAL_SECTION  m_crit;

	//ʹ��
	bool m_bEnable;
	bool m_bPrintTime;

	//�ַ�����
	std::string GetBaseDir(std::string & path);
	std::string GetFileExtensions(std::string & fileName);
	std::string int2string(int in);

};