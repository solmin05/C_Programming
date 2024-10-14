#include <stdio.h>

int main()
{
    int type;
    int receive;
    int sale;
    int id;
    int total_receive[100];
    int total_sale[100];
    int total = 0;
    int sum_receive = 0;
    int most = 0;
    int min = 0;
    
    printf("상품 개수(종류) 입력: ");
    scanf("%d", &type);
    
    printf("상품 별 입고 수량 입력: ");
    for(int i = 0; i < type; i++){
        scanf("%d", &receive);
        total_receive[i] = receive;
    }
    printf("상품 별 판매 수량 입력: ");
    for(int i = 0; i < type; i++){
        scanf("%d", &sale);
        total_sale[i] = sale;
    }
    printf("재고 수량 : ");
    for(int i = 0; i <type; i++){
        printf("%d ", total_receive[i] - total_sale[i]);
    }
    printf("\n총 판매량: ");
    for(int i = 0; i < type; i++){
        total += total_sale[i];
        sum_receive += total_receive[i];
    }
    printf("%d (판매율 %.2f%%)", total, ((double)total/sum_receive) * 100);
    
    printf("\n가장 많이 판매된 상품: ID ");
    for(int i = 0; i < type; i++){
        if(most < total_sale[i]){
            id = i+1; 
            most = total_sale[i];
            
        }
    }
    printf("%d, 판매량 %d", id, most);
    printf("\n가장 적게 판매된 상품: ID ");
    min = total_sale[0];
    for(int i = 0; i < type; i++){
        if(min > total_sale[i]){
            id = i+1;
            min = total_sale[i];
            
        }
    }
    printf("%d, 판매량 %d", id, min);
    for(int i =0; i < type; i++){
        if(total_receive[i] - total_sale[i] <= 2){
            printf("\n상품 ID %d : 재고부족(%d)", i+1, total_receive[i] - total_sale[i]);
        }
    }
    

    return 0;
}
