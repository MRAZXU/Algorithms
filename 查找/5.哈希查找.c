#include<stdio.h>
#include<stdlib.h>
 
#define HASHSIZE 12
#define NULLKEY -32768
typedef struct
{
	int *elem;
	int count;
}HashTable;
int m=0;
 
//初始化散列表
int InitHashTable(HashTable *H)
{
	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int*)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		H->elem[i]=NULLKEY;
	return 1;
 }
 //散列函数
 int Hash(int key)
 {
 	return (3*key)%m;
  } 
  //插入关键字进入散列表
  void InsertHash(HashTable *H,int key)
  {
  	int addr=Hash(key);
  	while(H->elem[addr]!=NULLKEY)
  		addr=(addr+1)%m;
  	H->elem[addr]=key;
   } 
   
//散列表查找关键字
int SearchHash(HashTable H,int key,int *addr)
{
	*addr=Hash(key);
	while(H.elem[*addr]!=key)
	{
		*addr=(*addr+1)%m;
		if(H.elem[*addr]==NULLKEY||*addr==Hash(key))
		{
			return -1;
		}
	}
	return *addr;
 } 
//解决冲突的函数还没写
int main()
{
	int a[12]={12,67,56,16,25,37,22,29,15,47,48,34};//16的位置
	HashTable H;
	int i;
	InitHashTable(&H);
	for(i=0;i<m;i++)
		InsertHash(&H,a[i]);
	printf("插入之后的哈希表为：");
	for(i=0;i<m;i++)
		printf("%d,",H.elem[i]);
	int addr,j;
	j=SearchHash(H,a[3],&addr);
	printf("搜索到a[3]的地址是：%d\n",j);
}