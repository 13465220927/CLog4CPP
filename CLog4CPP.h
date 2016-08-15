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
*/
#ifndef CLOG4CPP_H
#define CLOG4CPP_H

#include<string>

class CLog4CPP
{
public:

	CLog4CPP();
	~CLog4CPP();

	//��ʼ��
	void Init(std::string stringpOutputFilename = "CLog4CPP_itas109.log");

	//������֣�������TRACE��printf
	BOOL LogOut(std::string text);

	//����ʹ��
	void IsEnable(BOOL bEnable);

	//�Ƿ���ÿ�м���ʱ���
	void IsPrintTime(BOOL b) {m_bPrintTime = b;}

protected:
	//������
	enum {TBUF_SIZE = 3000};
	std::string m_tBuf[TBUF_SIZE];

	std::string m_csFileName;
	

	//�ٽ���
	CRITICAL_SECTION  m_crit;

	//ʹ��
	BOOL m_bEnable;
	BOOL m_bPrintTime;

	//�ַ�����
	std::string GetBaseDir(std::string & path);
	std::string GetFileExtensions(std::string & fileName);

};

#endif CLOG4CPP_H