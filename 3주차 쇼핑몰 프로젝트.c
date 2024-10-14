#include <stdio.h>

int total_receive[100] = {0};
int total_sale[100] = {0};
int selectMenu(){
    int menu;
    printf("\n원하는 메뉴를 선택하세요.(1.입고,2.판매,3.상품현황,4.종료)\n>");
    scanf("%d", &menu);
    return menu;
}
void exec1(){
    int type = 5;
    int op;
    int receive;
    int id;
    printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n>");
    scanf("%d", &op);
    switch(op){
        case 1 :
            for(int i = 0; i<type; i++){
                scanf("%d", &receive);
                total_receive[i] = receive;
            }   break;
        case 2 :
                printf("상품 ID: ");
                scanf("%d", &id);
                printf("입고수량: ");
                scanf("%d", &receive);
                total_receive[id - 1] = receive;
                break;
    }
}
void exec2(){
    int type = 5;
    int op;
    int sale;
    int id;
    printf("판매수량 입력: 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n>");
    scanf("%d", &op);
    switch(op){
        case 1 :
            for(int i = 0; i<type; i++){
                scanf("%d", &sale);
                total_sale[i] = sale;
            }   break;
        case 2 :
                printf("상품 ID: ");
                scanf("%d", &id);
                printf("판매수량: ");
                scanf("%d", &sale);
                total_sale[id - 1] = sale;
                break;
            
    }
}
void exec3(){
    int total =0;
    int sum_receive = 0;
    int type = 5;
    int id;
    int most = 0;
    int min = total_sale[0];
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
    
}
int main(){
    int menu;
    while(1){
        menu = selectMenu();
        switch(menu){
            case 1 :
                exec1();
                break;
            case 2 :
                exec2();
                break;
            case 3 :
                exec3();
                break;
            case 4 :
                return 0;
        }
    }

}
