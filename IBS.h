#ifndef _TEST_
#define _TEST_
#include <pbc.h>
#include <pbc_test.h>
#include<stdio.h>
// * stdio.h
// * gmp.h
// * utils.h
// * field.h
// * param.h


# define EXPORT __declspec(dllexport)
extern "C"
{
	//IBSǩ���㷨

	void  sign_server();          //�����ǩ��
	void  KeyGen_server();        //���������˽Կ
	int verify_server( );           //�������֤
	void sign();                     //�ͻ���ǩ��
	void KeyGen();                  //�ͻ���˽Կ
	int verify( );                  //�ͻ�����֤
	//int pairing_init_set_buf_w(pairing_t pairing, const char *s, size_t len);

	/*void element_random_w(void* e) ;
	void element_clear_w(void* e) ;
	void pbc_param_init_a_gen_w(void* par, void* rbits,	void*qbits);
	void pairing_init_pbc_param_w(void  *pairing, void* p);
	void pbc_param_clear_w(void* p);*/
	

	



	

}

#endif