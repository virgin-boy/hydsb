#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define L sizeof(cx)
struct cx{
	char v1[50];
	char v2[50];
	char v3[50];
	char v4[50];
	char v5[50];
	char v6[50];
	char v7[50];
	char v8[50];
	char v9[50];
	char v10[50];
	//编号v1 名称v2单价v3入库数量v4库存数量v5出库数量v6保管人v7进货时间v8出货时间v9和备注v10
	cx*next;
};
void pd(cx*head,cx*now);//判断
void sr(cx*head,cx*now);//输入
void tj(cx*head,cx*now);//添加
void cz(cx*head,cx*now);//查找
void xg(cx*head,cx*now);//修改
void bc(cx*head,cx*now);//保存
void tc(cx*head,cx*now);//退出
int main(){
	cx*head=(cx*)malloc(L);
	cx*now;
	now=head;
	pd(head,now);
	return 0;
}
void pd(cx*head,cx*now){

	printf("输入信息：1\n");
	printf("查找信息：2\n");
	printf("修改信息：3\n");
	printf("添加信息：4\n");
	printf("保存信息：5\n");
	printf("退出：6\n");
	int n=0;
	scanf("%d",&n);
	if(n==1)
		sr(head,now);
	if(n==2)
		cz(head,now);
	if(n==3)
		xg(head,now);
	if(n==4)
		tj(head,now);
	if(n==5)
		bc(head,now);
	if(n==6)
		tc(head,now);
}
void sr(cx*head,cx*now){
	printf("请按照以下顺序输入:\n");
	printf("以-1结束输入\n");
	now=head;
	strcpy(head->v1,"编号");
	strcpy(head->v2,"名称");
	strcpy(head->v3,"单价");
	strcpy(head->v4,"入库数量");
	strcpy(head->v5,"库存数量");
	strcpy(head->v6,"出库数量");
	strcpy(head->v7,"保管人");
	strcpy(head->v8,"进货时间");
	strcpy(head->v9,"出货时间");
	strcpy(head->v10,"备注");
	printf("%s %s %s %s %s ",head->v1,head->v2,head->v3,head->v4,head->v5);
	printf("%s %s %s %s %s\n",head->v6,head->v7,head->v8,head->v9,head->v10);
	int i1=1;
	char l[20];
	cx*la;
	while(true){
		now->next=0;
		if(now->next==0){
			la=(cx*)malloc(L);
			scanf("%s",l);
			if(!strcmp(l,"-1")){
				now->next=0;
				free(la);
				break;
			}
			now=now->next=la;
			strcpy(now->v1,l);
			scanf("%s%s%s%s",now->v2,now->v3,now->v4,now->v5);
			scanf("%s%s%s%s%s",now->v6,now->v7,now->v8,now->v9,now->v10);
		}
	}
	now=head;
	pd(head,now);
}
void cz(cx*head,cx*now){
	printf("输入编号查找信息(以回车结束输入):\n");
	char cz1[50];
	scanf("%s",cz1);
	now=head;
	for(int j=0;;j++){
		now=now->next;
		if(strcmp(now->v1,cz1)==0){
			printf("%s %s %s %s %s ",now->v1,now->v2,now->v3,now->v4,now->v5);
			printf("%s %s %s %s %s\n",now->v6,now->v7,now->v8,now->v9,now->v10);
			break;
		}
	}
	
	now=head;
	pd(head,now);
	return;
}
void xg(cx*head,cx*now){
xg:
	printf("输入需要修改的信息的编号:\n");
	char bian[50]={0};
	scanf("%s",bian);
	now=head;
	for(int i=0;;i++){
		
		if(!strcmp(now->v1,bian)){
			printf("%s %s %s %s %s ",now->v1,now->v2,now->v3,now->v4,now->v5);
			printf("%s %s %s %s %s\n",now->v6,now->v7,now->v8,now->v9,now->v10);
			break;
		}
		now=now->next;
	}
	printf("输入修改的信息:\n");
	scanf("%s%s%s%s%s",now->v1,now->v2,now->v3,now->v4,now->v5);
	scanf("%s%s%s%s%s",now->v6,now->v7,now->v8,now->v9,now->v10);
	now=head;
	pd(head,now);
	return;
}
void tj(cx*head,cx*now){
	printf("请按照以下顺序输入:\n");
	printf("以0结束输入\n");
	printf("%s %s %s %s %s ",head->v1,head->v2,head->v3,head->v4,head->v5);
	printf("%s %s %s %s %s\n",head->v6,head->v7,head->v8,head->v9,head->v10);
	int i1=1;
	char l[20];
	cx*la;
	while(true){
		now->next=0;
		if(now->next==0){
			la=(cx*)malloc(L);
			scanf("%s",l);
			if(!strcmp(l,"-1")){
				now->next=0;
				free(la);
				break;
			}
			now=now->next=la;
			strcpy(now->v1,l);
			scanf("%s%s%s%s",now->v2,now->v3,now->v4,now->v5);
			scanf("%s%s%s%s%s",now->v6,now->v7,now->v8,now->v9,now->v10);
		}
	}
	pd(head,now);
}
void bc(cx*head,cx*now){
	FILE*f=fopen("date.txt","w");
	now=head;
	while(now->next)
		fprintf(f,"%s %s %s %s %s ",now->v1,now->v2,now->v3,now->v4,now->v5),
		fprintf(f,"%s %s %s %s %s\n",now->v6,now->v7,now->v8,now->v9,now->v10);
	fclose(f);
}
void tc(cx*head1,cx*now1){
	return;
}