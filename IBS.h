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
	//IBS签名算法

	void  sign_server();          //服务端签名
	void  KeyGen_server();        //服务端生成私钥
	int verify_server( );           //服务端验证
	void sign();                     //客户端签名
	void KeyGen();                  //客户端私钥
	int verify( );                  //客户端验证
	//int pairing_init_set_buf_w(pairing_t pairing, const char *s, size_t len);

	/*void element_random_w(void* e) ;
	void element_clear_w(void* e) ;
	void pbc_param_init_a_gen_w(void* par, void* rbits,	void*qbits);
	void pairing_init_pbc_param_w(void  *pairing, void* p);
	void pbc_param_clear_w(void* p);*/
	

	



	

}

#endif