/*
**************************************************************************************
**
**	FILENAME			CLog4CPP.h
**
**	PURPOSE				����һ��C++����־������
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
	void Init(std::string stringpOutputFilename);

	//������֣�������TRACE��printf
	BOOL LogOut(std::string text);

	//����ʹ��
	void IsEnable(BOOL bEnable);

	//�Ƿ���ÿ�м���ʱ���
	void IsPrintTime(BOOL b) {m_bPrintTime = b;}

	//�Ƿ���ÿ�м����������
	void IsPrintAppName(BOOL b) {m_bPrintAppName = b;}

	//���ó������� 
	void SetAppName(const char *pName) {m_csAppName = pName;}

protected:
	//������
	enum {TBUF_SIZE = 3000};
	std::string m_tBuf[TBUF_SIZE];

	std::string m_csAppName;
	std::string m_csFileName;
	

	//�ٽ���
	CRITICAL_SECTION  m_crit;

	//ʹ��
	BOOL m_bEnable;
	BOOL m_bPrintTime;
	BOOL m_bPrintAppName;

	//�ַ�����
	std::string GetBaseDir(std::string & path);
	std::string GetBaseName(std::string & path);

};

#endif CLOG4CPP_H