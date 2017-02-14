#include <pbc.h>
#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#include"TEST.h"


void EXPORT KeyGen_server()                   //�����������Կ������˵���S_1
{
  pairing_t pairing;
  char param[1024];
  char store[100]="E:\\��վ\\vote\\Download\\aparam.txt";
  char filenamev[100]="E:\\��վ\\vote\\Download\\ID.txt";
  FILE * in;
  if((in=fopen(filenamev,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str2[100];int t=0;
  while(!feof(in))
  {
	  str2[t]=fgetc(in);
	  t++;

  }
  str2[t]='\0';
  strcat(str2,".txt");
  fclose(in);


  FILE * out1;
  if((out1=fopen(store,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
 size_t count = fread(param, 1, 1024, out1);
 //if (!count) pbc_die("input error");
 pairing_init_set_buf(pairing, param, count);
 fclose(out1);
  
  char filename5[100]="E:\\��վ\\vote\\Download\\a_1";
  strcat(filename5,str2);
  char filename2[100]="E:\\��վ\\vote\\Download\\g_1";
  strcat(filename2,str2);
  char filename3[100]="E:\\��վ\\vote\\Download\\g1_1";
  strcat(filename3,str2);
  char filename4[100]="E:\\��վ\\vote\\Download\\h_1";
  strcat(filename4,str2);

	element_t a_1;                                          //zr��ʼ��   \\˽Կ
	element_t g_1;                                     //G1��ʼ��
	element_t g1_1,h_1;                                      //G2��ʼ��


	element_init_G1(g1_1,pairing);
	element_init_G2(h_1,pairing);
	element_init_G1(g_1,pairing);

	element_init_Zr(a_1,pairing);


	element_random(a_1);
	element_random(g_1);
	element_random(h_1);
	element_pow_zn(g1_1,g_1,a_1);

   if((out1=fopen(filename5,"wt"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
     element_out_str(out1,10,a_1);
	 fclose(out1);
  


  
  if((out1=fopen(filename2,"wt"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
    element_out_str(out1,10,g_1);
	fclose(out1);


  if((out1=fopen(filename3,"wt"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
   element_out_str(out1,10,g1_1);
   fclose(out1);


  if((out1=fopen(filename4,"wt"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
    element_out_str(out1,10,h_1);
	fclose(out1);


}




void  EXPORT  KeyGen()                  //�ͻ���������Կ
{
  pairing_t pairing;
  char param[1024];
  char store[100]="E:\\��վ\\vote\\Download\\aparam.txt";
  FILE * out1;
  if((out1=fopen(store,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
 size_t count = fread(param, 1, 1024, out1);
 //if (!count) pbc_die("input error");
 pairing_init_set_buf(pairing, param, count);
 fclose(out1);
  
 
  char filename5[100]="E:\\��վ\\vote\\Download\\a.txt";
  char filename2[100]="E:\\��վ\\vote\\Download\\g.txt";
  char filename3[100]="E:\\��վ\\vote\\Download\\g1.txt";
  char filename4[100]="E:\\��վ\\vote\\Download\\h.txt";

	element_t a;                                          /*\\zr��ʼ��*/   //˽Կ
	element_t g;                                     //G1��ʼ��
	element_t g1,h;                                      //G2��ʼ��


	element_init_G1(g1,pairing);
	element_init_G2(h,pairing);
	element_init_G1(g,pairing);

	element_init_Zr(a,pairing);

	element_random(a);
	element_random(g);
	element_random(h);
	element_pow_zn(g1,g,a);

   if((out1=fopen(filename5,"wt"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
     element_out_str(out1,10,a);
	 fclose(out1);
  


  
  if((out1=fopen(filename2,"wt"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
    element_out_str(out1,10,g);
	fclose(out1);


  if((out1=fopen(filename3,"wt"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
   element_out_str(out1,10,g1);
   fclose(out1);


  if((out1=fopen(filename4,"wt"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
    element_out_str(out1,10,h);
	fclose(out1);
}

void  EXPORT sign_server()
{
  char filenamev[100]="E:\\��վ\\vote\\Download\\ID.txt";
  FILE * in10;
  if((in10=fopen(filenamev,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char strv[100];int yy=0;
  while(!feof(in10))
  {
	  strv[yy]=fgetc(in10);
	  yy++;

  }
  strv[yy]='\0';
  strcat(strv,".txt");
  fclose(in10);

  pairing_t pairing;
  char param[1024];
  char filename9[100]="E:\\��վ\\vote\\Download\\r_1";
  strcat(filename9,strv);
  char filename10[100]="E:\\��վ\\vote\\Download\\HID_1";
  strcat(filename10,strv);
  
  
  
  
  char  store[100]="E:\\��վ\\vote\\Download\\aparam.txt";
  FILE * out1;
  if((out1=fopen(store,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  size_t count = fread(param, 1, 1024, out1);
  //if (!count) pbc_die("input error");
  pairing_init_set_buf(pairing, param, count);
  fclose(out1);
  element_t h,a,g,ID,hID_1,m,tmpz;
  element_init_Zr(tmpz,pairing);
  element_init_G1(h,pairing);
  element_init_G2(hID_1,pairing);
  element_init_Zr(a,pairing);
  element_init_Zr(ID,pairing);
  element_init_Zr(m,pairing);
  element_init_G1(g,pairing);

 

  char filename3[100]="E:\\��վ\\vote\\Download\\g1_1";
  strcat(filename3,strv);
  char filename4[100]="E:\\��վ\\vote\\Download\\h_1";
  strcat(filename4,strv);
  char filename5[100]="E:\\��վ\\vote\\Download\\a_1";
  strcat(filename5,strv);
  char filename2[100]="E:\\��վ\\vote\\Download\\g_1";
  strcat(filename2,strv);
  char filename1[100]="E:\\��վ\\vote\\Download\\ID.txt";
  char filename6[100]="E:\\��վ\\vote\\Download\\rs.txt";
  

  FILE * in;
  if((in=fopen(filename4,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str[1000];int i=0;
  while(!feof(in))
  {
	  str[i]=fgetc(in);
	  i++;

  }
  str[i]='\0';
  fclose(in);              
  element_set_str(h,str,10);
;



   
   if((in=fopen(filename5,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str1[1000];int j=0;
  while(!feof(in))
  {
	  str1[j]=fgetc(in);
	  j++;

  }
  str1[j]='\0';
  fclose(in);
  element_set_str(a,str1,10);       //��ȡa




  if((in=fopen(filename1,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str2[1000];int t=0;
  while(!feof(in))
  {
	  str2[t]=fgetc(in);
	  t++;

  }
  str2[t]='\0';
  element_set_str(ID,str2,10);     //��ȡID
  fclose(in);
  //ID
 // element_printf("ID��ֵ%B\n",ID);


   if((in=fopen(filename2,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str3[1000];int p=0;
  while(!feof(in))
  {
	  str3[p]=fgetc(in);
	  p++;

  }
  str3[p]='\0';
  fclose(in);
  element_set_str(g,str3,10);    //��ȡg
  //element_printf("g��ֵ��%B",g);


  if((in=fopen(filename6,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }

  char str4[500000];int sc=0;
  while(!feof(in))
  {
	  str4[sc]=fgetc(in);
	  sc++;

  }
  str4[sc]='\0';
  fclose(in);
  //printf("%s",str4);          
  
  element_from_hash(m,str4,sizeof(str4));
  //element_printf("m��ֵ��%B\n",m);



  
  

 



  //--------------------------����hID_1------------------------------------------------//


    //element_t rID;
  element_t rID;
  element_t temp;
  element_t r1_1;

  
  element_init_Zr(rID,pairing);
  element_init_Zr(r1_1,pairing);
  element_init_G1(temp,pairing);
  element_random(r1_1);
  element_mul(rID,ID,m);
  //element_printf("rID��ֵ%B\n",rID);	
  element_sub(tmpz,a,rID);
  //element_printf("tmpz:%B\n",tmpz);
  element_invert(tmpz,tmpz); //tmpz Ϊ1/a-ID;
  element_pow_zn(temp,g,r1_1);   //glrltΪG1���͡�
  //element_printf("temp:%B\n",temp);
  element_invert(temp,temp);
  element_mul(hID_1,h,temp); //�õ�hID_1
  element_pow_zn(hID_1,hID_1,tmpz);
  //element_printf("hID_1:%B\n",hID_1);//



   if((out1=fopen(filename9,"w"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }  
   element_out_str(out1,10,r1_1);//��r1д���ļ�����
   fclose(out1);

   if((out1=fopen(filename10,"w"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
   element_out_str(out1,10,hID_1);
   fclose(out1);
   

}

void  EXPORT  sign() {
  pairing_t pairing;
  char param[1024];
  char filename9[100]="E:\\��վ\\vote\\Download\\r.txt";
  char filename10[100]="E:\\��վ\\vote\\Download\\HID.txt";
  
  
  char  store[100]="E:\\��վ\\vote\\Download\\aparam.txt";
  FILE * out1;
  if((out1=fopen(store,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  size_t count = fread(param, 1, 1024, out1);
  //if (!count) pbc_die("input error");
  pairing_init_set_buf(pairing, param, count);
  fclose(out1);
  element_t h,a,g,ID,hID,m,tmpz;
  element_init_Zr(tmpz,pairing);
  element_init_G1(h,pairing);
  element_init_G2(hID,pairing);
  element_init_Zr(a,pairing);
  element_init_Zr(ID,pairing);
  element_init_Zr(m,pairing);
  element_init_G1(g,pairing);

  //element_init_G2(b,pairing);

  char filename3[100]="E:\\��վ\\vote\\Download\\g1.txt";
  char filename4[100]="E:\\��վ\\vote\\Download\\h.txt";
  char filename5[100]="E:\\��վ\\vote\\Download\\a.txt";
  char filename2[100]="E:\\��վ\\vote\\Download\\g.txt";
  char filename1[100]="E:\\��վ\\vote\\Download\\ID.txt";
  char filename6[100]="E:\\��վ\\vote\\Download\\c.txt";

  FILE * in;
  if((in=fopen(filename4,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str[1000];int i=0;
  while(!feof(in))
  {
	  str[i]=fgetc(in);
	  i++;

  }
  str[i]='\0';
  fclose(in);               //��ȡh
  element_set_str(h,str,10);
  //element_printf("h��ֵ%B",h);
   if((in=fopen(filename5,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str1[1000];int j=0;
  while(!feof(in))
  {
	  str1[j]=fgetc(in);
	  j++;

  }
  str1[j]='\0';
  fclose(in);
  element_set_str(a,str1,10);       //��ȡa
  //element_printf("a��ֵ%B\n",a);
  if((in=fopen(filename1,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str2[1000];int t=0;
  while(!feof(in))
  {
	  str2[t]=fgetc(in);
	  t++;

  }
  str2[t]='\0';
  element_set_str(ID,str2,10);     //��ȡID
  fclose(in);
  //ID
 // element_printf("ID��ֵ%B\n",ID);
   if((in=fopen(filename2,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str3[1000];int p=0;
  while(!feof(in))
  {
	  str3[p]=fgetc(in);
	  p++;

  }
  str3[p]='\0';
  fclose(in);
  element_set_str(g,str3,10);    //��ȡg
  //element_printf("g��ֵ��%B",g);
  if((in=fopen(filename6,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }

  char str4[500000];int sc=0;
  while(!feof(in))
  {
	  str4[sc]=fgetc(in);
	  sc++;

  }
  str4[sc]='\0';
  fclose(in);
  //printf("%s",str4);          
  
  element_from_hash(m,str4,sizeof(str4));
  //element_printf("m��ֵ��%B\n",m);

  //--------------------------����hID------------------------------------------------//


    //element_t rID;
  element_t rID;
  element_t temp;
  element_t r1;

  
  element_init_Zr(rID,pairing);
  element_init_Zr(r1,pairing);
  element_init_G1(temp,pairing);
  element_random(r1);
  element_mul(rID,ID,m);
  //element_printf("rID��ֵ%B\n",rID);	
  element_sub(tmpz,a,rID);
  //element_printf("tmpz:%B\n",tmpz);
  element_invert(tmpz,tmpz); //tmpz Ϊ1/a-ID;
  element_pow_zn(temp,g,r1);   //glrltΪG1���͡�
  //element_printf("temp:%B\n",temp);
  element_invert(temp,temp);
  element_mul(hID,h,temp); //�õ�hID
  element_pow_zn(hID,hID,tmpz);
  //element_printf("hID:%B\n",hID);//
   if((out1=fopen(filename9,"w"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }  
   element_out_str(out1,10,r1);//��r1д���ļ�����
   fclose(out1);

   if((out1=fopen(filename10,"w"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
   element_out_str(out1,10,hID);
   fclose(out1);
   }
   
//----------------------------------------------------	Sign-------------------------------------------------

   //----------------------------------------------------Verify---------------------------------------------------
int  EXPORT verify( )
{
	  char filenamev[100]="E:\\��վ\\vote\\Download\\ID.txt";
	  FILE * in10;
	  if((in10=fopen(filenamev,"rb"))==NULL)
	  {
		  printf("�޷����ļ�\n");
		  exit(0);
	  }
	  char strv[100];int yy=0;
	  while(!feof(in10))
	  {
		  strv[yy]=fgetc(in10);
		  yy++;

	  }
	  strv[yy]='\0';
	  strcat(strv,".txt");
	  fclose(in10);

	  char filename9[100]="E:\\��վ\\vote\\Download\\r_1";
	  strcat(filename9,strv);
      char filename10[100]="E:\\��վ\\vote\\Download\\HID_1";
	   strcat(filename10,strv);

	  pairing_t pairing;
	  char param[1024];
	  char  store[100]="E:\\��վ\\vote\\Download\\aparam.txt";
	  FILE * out1;
	  if((out1=fopen(store,"rb"))==NULL)
	  {
		  printf("�޷����ļ�\n");
		  exit(0);
	  }
	  size_t count = fread(param, 1, 1024, out1);
	  //if (!count) pbc_die("input error");
	  pairing_init_set_buf(pairing, param, count);
	  fclose(out1);

	  char filename3[100]="E:\\��վ\\vote\\Download\\g1_1";
	   strcat(filename3,strv);
      char filename4[100]="E:\\��վ\\vote\\Download\\h_1";
	   strcat(filename4,strv);
	  char filename2[100]="E:\\��վ\\vote\\Download\\g_1";
	   strcat(filename2,strv);
      char filename1[100]="E:\\��վ\\vote\\Download\\ID.txt";
      char filename6[100]="E:\\��վ\\vote\\Download\\rs.txt";
	 
	element_t h,g,ID,m,rID,r1,hID;
	element_init_Zr(r1,pairing);
	element_init_G1(h,pairing);
	element_init_G1(g,pairing);
	element_init_Zr(ID,pairing);
	element_init_Zr(m,pairing);
	element_init_Zr(rID,pairing);
	element_init_G2(hID,pairing);

	FILE * in;
	if((in=fopen(filename4,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str[1000];int i=0;
  while(!feof(in))
  {
	  str[i]=fgetc(in);
	  i++;

  }
  str[i]='\0';
  fclose(in);               //��ȡh
  element_set_str(h,str,10);
  //element_printf("h��ֵ%B",h);

  if((in=fopen(filename1,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str2[1000];int t=0;
  while(!feof(in))
  {
	  str2[t]=fgetc(in);
	  t++;

  }
  str2[t]='\0';
  element_set_str(ID,str2,10);     //��ȡID
  fclose(in);
  //ID
 // element_printf("ID��ֵ%B\n",ID);
   if((in=fopen(filename2,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str3[1000];int p=0;
  while(!feof(in))
  {
	  str3[p]=fgetc(in);
	  p++;

  }
  str3[p]='\0';
  fclose(in);
  element_set_str(g,str3,10);    //��ȡg
  //element_printf("g��ֵ��%B",g);

   if((in=fopen(filename9,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }  
  char str13[1000];int jt=0;
  while(!feof(in))
  {
	  str13[jt]=fgetc(in);
	  jt++;

  }
  str13[jt]='\0';
  
  element_set_str(r1,str13,10);             //��ȡr1
  fclose(in);

  if((in=fopen(filename6,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }

  char str4[500000];int sc=0;
  while(!feof(in))
  {
	  str4[sc]=fgetc(in);
	  sc++;

  }
  str4[sc]='\0';
  fclose(in);
  //printf("%s",str4);          
  
  element_from_hash(m,str4,sizeof(str4));  //��ȡm
  element_mul(rID,ID,m);
  //element_printf("m��ֵ��%B\n",m);
  if((in=fopen(filename10,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str12[1000];int jq=0;
  while(!feof(in))
  {
	  str12[jq]=fgetc(in);
	  jq++;

  }
  str12[jq]='\0';
  fclose(in);
  element_set_str(hID,str12,10);
  fclose(in);                               //��ȡhID
   element_t s,res1,res3,res2,u,g_G2,e_res1,v,h1,e_res2,temp2,w,mex,max,bzy,res4,res5;
   element_init_G2(h1,pairing);

   element_init_Zr(s,pairing);
   element_init_Zr(res3,pairing);
   element_init_G1(res1,pairing);
   element_init_GT(e_res1,pairing);
   element_init_GT(v,pairing);
   element_init_GT(e_res2,pairing);
   element_init_G1(res2,pairing);
   element_init_G2(g_G2,pairing);
   element_init_G1(u,pairing);
   element_init_GT(temp2,pairing);
   element_init_GT(w,pairing);
   element_init_GT(mex,pairing);
   element_init_GT(max,pairing);
   element_init_GT(bzy,pairing);
   element_init_GT(res4,pairing);
   element_init_GT(res5,pairing);
   //element_rintf("mex: %B\n",mex) ;
   element_random(s);
   element_t g1;
   element_init_G1(g1,pairing);
  if((in=fopen(filename3,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str8[1000];int z=0;
  while(!feof(in))
  {
	  str8[z]=fgetc(in);
	  z++;
  }
  str8[z]='\0';
  fclose(in);
  //printf("%s",str8);//��ȡg1
  element_set_str(g1,str8,10);
  //element_printf("g1: %B\n",g1) ;
  element_pow_zn(res1,g1,s);
  element_mul(res3,s,rID);
  element_pow_zn(res2,g,res3);
  element_invert(res2,res2);
  element_mul(u,res1,res2);
  //element_printf("u=:%B\n",u);   //-----------�õ�U
  element_set(g_G2,g);
  pairing_apply(e_res1,g,g_G2,pairing);
  //element_printf("dsad %B",e_res1);
  element_pow_zn(v,e_res1,s);
  //element_printf("v= %B\n",v);//--------------�õ�V
  element_random(mex);
  //element_printf("mex:%B\n",mex);
  pairing_apply(e_res2,g,h,pairing);
  element_pow_zn(temp2,e_res2,s);
  //element_printf("w:%B\n",temp2);
  element_invert(temp2,temp2);
  element_mul(w,mex,temp2);
  //element_printf("w:%B\n",w); //-------------------�õ�W
  pairing_apply(bzy,u,hID,pairing);
  element_pow_zn(res4,v,r1);
  element_mul(res5,w,bzy);
  element_mul(max,res5,res4);
  //element_printf("max:%B\n",max);
   if(! element_cmp( max,  mex))
  {
	 //return 1;
	  printf("ok");
  }
  else
  {
	  
	  return 0;
	 
  }
 
}

int    EXPORT  verify_server()
{
	  char filename9[100]="E:\\��վ\\vote\\Download\\r.txt";
      char filename10[100]="E:\\��վ\\vote\\Download\\HID.txt";
	  pairing_t pairing;
	  char param[1024];
	  char  store[100]="E:\\aparam.txt";
	  FILE * out1;
	  if((out1=fopen(store,"rb"))==NULL)
	  {
		  printf("�޷����ļ�\n");
		  exit(0);
	  }
	  size_t count = fread(param, 1, 1024, out1);
	  //if (!count) pbc_die("input error");
	  pairing_init_set_buf(pairing, param, count);
	  fclose(out1);

	  char filename3[100]="E:\\��վ\\vote\\Download\\g1.txt";
      char filename4[100]="E:\\��վ\\vote\\Download\\h.txt";
	  char filename2[100]="E:\\��վ\\vote\\Download\\g.txt";
      char filename1[100]="E:\\��վ\\vote\\Download\\ID.txt";
      char filename6[100]="E:\\��վ\\vote\\Download\\c.txt";
	element_t h,g,ID,m,rID,r1,hID;
	element_init_Zr(r1,pairing);
	element_init_G1(h,pairing);
	element_init_G1(g,pairing);
	element_init_Zr(ID,pairing);
	element_init_Zr(m,pairing);
	element_init_Zr(rID,pairing);
	element_init_G2(hID,pairing);
	FILE * in;
	if((in=fopen(filename4,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str[1000];int i=0;
  while(!feof(in))
  {
	  str[i]=fgetc(in);
	  i++;

  }
  str[i]='\0';
  fclose(in);               //��ȡh
  element_set_str(h,str,10);
  //element_printf("h��ֵ%B",h);
  if((in=fopen(filename1,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str2[1000];int t=0;
  while(!feof(in))
  {
	  str2[t]=fgetc(in);
	  t++;
  }
  str2[t]='\0';
  element_set_str(ID,str2,10);     //��ȡID
  fclose(in);
  //ID
 // element_printf("ID��ֵ%B\n",ID);
   if((in=fopen(filename2,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str3[1000];int p=0;
  while(!feof(in))
  {
	  str3[p]=fgetc(in);
	  p++;

  }
  str3[p]='\0';
  fclose(in);
  element_set_str(g,str3,10);    //��ȡg
  //element_printf("g��ֵ��%B",g);

   if((in=fopen(filename9,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }  
  char str13[1000];int jt=0;
  while(!feof(in))
  {
	  str13[jt]=fgetc(in);
	  jt++;

  }
  str13[jt]='\0';
  
  element_set_str(r1,str13,10);             //��ȡr1
  fclose(in);

  if((in=fopen(filename6,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }

  char str4[500000];int sc=0;
  while(!feof(in))
  {
	  str4[sc]=fgetc(in);
	  sc++;

  }
  str4[sc]='\0';
  fclose(in);
  //printf("%s",str4);          
  
  element_from_hash(m,str4,sizeof(str4));  //��ȡm
  element_mul(rID,ID,m);
  //element_printf("m��ֵ��%B\n",m);
  if((in=fopen(filename10,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str12[1000];int jq=0;
  while(!feof(in))
  {
	  str12[jq]=fgetc(in);
	  jq++;

  }
  str12[jq]='\0';
  fclose(in);
  element_set_str(hID,str12,10);
  fclose(in);                               //��ȡhID
   
   element_t s,res1,res3,res2,u,g_G2,e_res1,v,h1,e_res2,temp2,w,mex,max,bzy,res4,res5;
   element_init_G2(h1,pairing);

   element_init_Zr(s,pairing);
   element_init_Zr(res3,pairing);
   element_init_G1(res1,pairing);
   element_init_GT(e_res1,pairing);
   element_init_GT(v,pairing);
   element_init_GT(e_res2,pairing);
   element_init_G1(res2,pairing);
   element_init_G2(g_G2,pairing);
   element_init_G1(u,pairing);
   element_init_GT(temp2,pairing);
   element_init_GT(w,pairing);
   element_init_GT(mex,pairing);
   element_init_GT(max,pairing);
   element_init_GT(bzy,pairing);
   element_init_GT(res4,pairing);
   element_init_GT(res5,pairing);
   //element_printf("mex: %B\n",mex) ;

   element_random(s);
   element_t g1;
   element_init_G1(g1,pairing);
  if((in=fopen(filename3,"rb"))==NULL)
  {
	  printf("�޷����ļ�\n");
	  exit(0);
  }
  char str8[1000];int z=0;
  while(!feof(in))
  {
	  str8[z]=fgetc(in);
	  z++;

  }
  str8[z]='\0';
  fclose(in);
  //printf("%s",str8);//��ȡg1
  element_set_str(g1,str8,10);
  //element_printf("g1: %B\n",g1) ;
  element_pow_zn(res1,g1,s);
  element_mul(res3,s,rID);
  element_pow_zn(res2,g,res3);
  element_invert(res2,res2);
  element_mul(u,res1,res2);
  //element_printf("u=:%B\n",u);   //-----------�õ�U


  element_set(g_G2,g);
  pairing_apply(e_res1,g,g_G2,pairing);
  //element_printf("dsad %B",e_res1);
  element_pow_zn(v,e_res1,s);
  //element_printf("v= %B\n",v);//--------------�õ�V

  element_random(mex);
  //element_printf("mex:%B\n",mex);
  pairing_apply(e_res2,g,h,pairing);
  
  element_pow_zn(temp2,e_res2,s);
  //element_printf("w:%B\n",temp2);
  element_invert(temp2,temp2);
  element_mul(w,mex,temp2);
  //element_printf("w:%B\n",w); //-------------------�õ�W



  pairing_apply(bzy,u,hID,pairing);
  element_pow_zn(res4,v,r1);
  element_mul(res5,w,bzy);
  element_mul(max,res5,res4);
  //element_printf("max:%B\n",max);
  if(! element_cmp( max,  mex))
  {
	  //return 1;
	  printf("ok");
  }
  else
  {
	  
	 return 0;
	 
  }


}


int main()
{
	KeyGen_server();

	sign_server();
	verify();
	/*KeyGen();
	sign();
	verify_server();*/
	
}










































  















  	












