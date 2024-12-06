#include<stdio.h>  
#include<string.h>
#define N strlen(div)  
char data[28];
char rem[28];    
char div[10];  
int data_length,i,j;    
void XOR(){  
for(j = 1;j < N; j++)  
rem[j] = ((rem[j] == div[j])?'0':'1');            
}  
    void crc(){    
        for(i=0;i<N;i++)  
            rem[i]=data[i];  
        do{    
            if(rem[0]=='1')  
                XOR();  
            for(j=0;j<N-1;j++)  
                rem[j]=rem[j+1];  
            rem[j]=data[i++];  
        }while(i<=data_length+N-1);  
    }  
    int main()  
    {
        printf("\nEnter data : ");  
        scanf("%s",data);  
        printf("\n Enter the divisor: ");    
        scanf("%s",div);  
        data_length=strlen(data);  
        for(i=data_length;i<data_length+N-1;i++)  
            data[i]='0';    
        printf("\n Data padded with n-1 zeros : %s",data);    
        crc();    
        printf("\nreminder : %s",rem);    
        for(i=data_length;i<data_length+N-1;i++)  
            data[i]=rem[i-data_length];  
        printf("\n sender side data code: %s",data);  
            return 0;  
    }  