#include <stdio.h>

#define MAX 1000
//Implement queue
typedef struct Queue_type{
    int head, tail;
    int a[MAX];
} Queue;

void init(Queue* q)
{
    q->head = 0;
    q->tail = -1;
}

int isEmpty(Queue* q) {
    if(q->tail < q->head){
        return 1;
    }
    else return 0;
}
int isFull(Queue* q) { 
    if(q->tail == MAX - 1){
        return 1;
    }
    else return 0;
}
//thêm 1 người dùng vào hàng đợi
void put(Queue* q, int value)
{
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    (q->tail)++;
    q->a[q->tail] = value;
}
//Lấy thông tin người dùng đầu hàng đợi và xóa khỏi hàng đợi
int get(Queue* q)
{
    if(isEmpty(q)){
        return -1;
    }
    int element = q->a[q->head];
    (q->head)++;
    return element;
}
//Hủy đăng ký của 1 người dùng khỏi hàng đợi
void cancelRegistration(Queue *q, int unRegistUser){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    //tim vi tri cua nguoi can huy dang ky
    int l = q->head, r = q->tail;
    int indexToUnRegist = 0;
    while(l <= r){
        int m = (l + r)/2;
        if(q->a[m] < unRegistUser){
            l = m + 1;
        }
        else if(q->a[m] > unRegistUser){
            r = m - 1;
        }
        else{
            indexToUnRegist = m;
            break;
        }
    }
    //thuc hien viec huy dang ky
    for(int i = indexToUnRegist; i < q->tail; i++){
        q->a[i] = q->a[i + 1];
    }
    (q->tail)--;
    return;
}
//Hiển thị danh sách toàn bộ người dùng đã đăng ký tham gia sự kiện
void displayQueue(Queue* q)
{
    if(isEmpty(q)){
        printf("Queue is Empty!!");
        return;
    }
    for(int i = q->head; i <= q->tail; i++){
        printf("%d ", q->a[i]);
    }
    return;
}
int main(){
    int choice; 
    Queue registEventSystem;
    init(&registEventSystem);
    while(1){
        printf("\n");
        printf("1. Dang ky nguoi dung moi.\n");
        printf("2. Huy dang ky cua 1 nguoi dung.\n");
        printf("3. Lay thong tin nguoi dung dau hang doi(nguoi dang ky som nhat).\n");
        printf("4. Hien thi danh sach toan bo nguoi dung da dang ky.\n");
        printf("5. Thoat he thong.\n");
        printf("Chon chuc nang (1,2,3,4,5): ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Nhap so nguyen dai dien nguoi dung: ");
            int number1; scanf("%d", &number1);
            put(&registEventSystem, number1);
        }
        else if(choice == 2){
            printf("Nhap so nguyen dai dien cua nguoi dung muon huy dang ky: ");
            int number2; scanf("%d", &number2);
            cancelRegistration(&registEventSystem, number2);
        }
        else if(choice == 3){
            printf("Thong tin cua nguoi dang ky som nhat la: ");
            int number3 = get(&registEventSystem);
            printf("%d", number3);
            printf("\n");
        }
        else if(choice == 4){
            printf("Danh sach toan bo nguoi dang ky: ");
            displayQueue(&registEventSystem);
            printf("\n");
        }
        else break;
    }
    return 0;
}