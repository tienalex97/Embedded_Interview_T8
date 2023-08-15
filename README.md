# Embedded_Interview_T8 🥰🥰🥰
## C PROGRAMMING LANGUAGE
<details>
	
<summary>C cơ bản </summary>

### Data types
- Một số datatype thông dụng:
    | Name | Type | Range |
  |:------:|:--------:|:--------:|
  |int8|1 byte signed|-128 to 127|
	|uint8_t |1 byte unsgined|0 to 255|
	|int16_t |2 bytes signed|-32768 to 32767|
    |uint16_t|2 byte unsigned|0 to 65535|
    |int32_t |2 byte unsigned|-2147483648 to 2147483647|
    |uint32_t|4 bytes unsigned|0 to 4294967295|
    |int64_t |8 bytes signed|-9223372036854775808 to 9223372036854775807|
    |uint64_t|8 bytes unsigned|0 to 18446744073709551615|
- uint8_t/int8_t có độ lớn 8 bits = 1 byte. Bit là đơn vị lưu trữ nhỏ nhất.

### Sử dụng typedef
- Typedef sử dụng để redefine kiểu dữ liệu
` typedef int songuyen; `
- Sau khi đã redefine, ta có thể sử dụng songuyen thay cho int
```
#include"stdio.h:
typedef int so_nguyen;
int main()
{
  so_nguyen n= 9;
  printf("So nguyen la: %d\n", n);
}
```
### Fucntions:
- Functions are a group of statements used to perform cerion actions, and they are important for reusing code.
#### Ví dụ:
```c
#include <stdio.h>
void tich(int a, int b){  //Đây là hàm tich()
    printf("Tich %d va %d la %d",a, b, a*b);
}
int tong(int c, int d){ //Hàm này có kiểu trả về là int
    return c+d;
}
int main(){
    tich(2,3); // tich 2 va 3 la 6
    printf("Tong c va d la %d",tong(4,5)); //Tong c va d la 9
    return 0;
}
```

### Loops:

#### - For loop:
- When you know exactly how many times you want to loop through your code, use the `for` loop insted of a `while` loop.
```c
for (khởi tạo giá trị biến lặp; điều kiện lặp; cập nhật biến sau mỗi vòng lặp)
{
	// Statements
}
```
#### - While loop:
- Loops can execut a block of code as long as a specifed condition is reached.
```c
while(condition)
{
	// code block
}
```
#### - Do...While loop:
- Do...while loop is similar to a while loop, except the fact that it is guaranteed to execute at least one time.
```c
do
{
	// code block
} while(condition)
```
### Conditional branching:
	It is also called as `branching` as a program decides which statement to excecute based on the result of the evaluated condition. 
 #### If...else statement:
 - If statement is used to specify  block of code to be executed if a condition is `true`.
 - Else statement is used to specify a block of code to be executed if a condition is `false`.
 - Read more about `If - Elseif - Else`.
 #### Enum & Switch case:
 - Enum(enumeration) is used to assigned names to integral constants, the names make a programe `easy to read and maintain`.
   - Khai báo:
     ```
     enum _varname { A, B, C};
     ```
     ##### Ví dụ:
     ```c
     enum days_of_week { MON=0, TUE, WED, THU, FRI, SAT, SUN};
     ```
   - Khởi tạo:
     ```
     enum _varname _objetname;
     ```
     ##### Ví dụ:
     ```c
     enum days_of_week day = MON;
     ```
- Switch case : Selects one of many code blocks to be executed insted of many `if...else`
  - Syntax
  ```c
  switch(expression) {
  case x:
    // code block
    break;
  case y:
    // code block
    break;
  default:
    // code block
	}
  ```
  - Ví dụ:
  ```c
  switch(day)
  {
	case MON:
		// code block
		break;
	case TUE:
		// code block
		break;
	default:
		// code block
  }
  ```
</details>

<details>
<summary>POINTERS</summary> 
 
### Pointer
- Pointer is a variable that stores address of another object(var, func, ...).
`int a=0;`
`int* ptr = &a;` 
==> *ptr is variable, ptr is value
- Get the memory addres of a variable : using `&`
```c
int a=0;
printf("the memory address of a is: %p", &a);
```
- Get the from the memory address(depointer): using `*`
```c
int *ptr= &a;
printf("the value of address %p is %d", ptr, *ptr);
```
### RAM architecture
- Chứa rất nhiều ô nhớ, mỗi ô nhớ có kích thước 1byte = 8bits.
	vd: RAM 8GB ~ 8 tỷ ô nhớ
- Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu CPU 64 bit thì RAM có tối đa 2^64 
địa chỉ ô nhớ. 
0x0000000000000000
0x0000000000000001
0x0000000000000002
0x0000000000000003
..................
0xffffffffffffffff
- Khi khai báo biến, compiler sẽ dành riêng một vùng nhớ với địa chỉ duy nhất để lưu biến. Compiler có nhiệm vụ liên
địa chỉ các ô nhớ đó với tên biến. Khi ta gọi tên biến, nó sẽ tự động truy xuất đến vùng nhớ đã liên kết với tên biến
để lấy dữ liệu. Ví dụ: 
```c 
uint32_t a=0;
```
- Biến a 4 bytes sẽ cần 4 ô nhớ. Giả sử địa chỉ của a là 0x0000
Nó sẽ sử dụng 4 ô nhớ có địa chỉ là 0x0000 0x0001 0x0002 0x0003

### Syntax of pointer
`datatype* nameofpointer= nullptr;`
- Ví du:
```c
	int* ptr;
	float* ptr;
	void* arr[];
```
### There are several types of pointers in C
#### 1. Null pointer
- Value NULL is assigend a the time of declaration. 
- Khi ta khai báo pointer mà không gán giá trị( `Wild Pointer` or `Uninitialized Pointer` by the way), nó có thể trỏ đến 
một địa chỉ nhớ bất kỳ. So if we still no use pointer yet, we should assign nulll value to it to avoid to crash or behave badly.
#### 2. Void pointer
- Là kiểu con trỏ chưa khai báo kiểu dữ liệu liên kết với nó. Nó có thể chứa địa chỉ của bất kỳ kiểu dữ liệu nào. 
- Nó có chuyển chuyển kiểu dữ liệu của địa chỉ nó đang chứa thành bất cứ kiểu gì bằng việc sử dụng `type casting`.
```c
#include"stdio.h"
void cal(int a, int b)
{
    printf("%d+%d=%d\n", a, b, a+b);
}
int main()
{
    int a=9;
    void* ptr = NULL;
    ptr= &a;
    printf("the value of ptr is: %d\n", *(int*)ptr);
    ptr= &cal;
    ((void(*)(int,int))ptr)(6,9);
}
```
<h3 align="center"> ===Khi casting các hàm phức tạp cần lưu ý các dấu ngoặc=== </p>

#### 3. Function pointer
- Dùng để trỏ đến địa chỉ các hàm
- Cú pháp: datatype(*nameofptr)(input_parameter);
- Ví dụ:
```c
int(*ptr)(int, int);
void(*ptr)(int, int)= &cal; 
```
- Có thể sử dụng function pointer as a input parameter
```c
#include<stdio.h>
void tong (int a, int b){
    printf("Tong %d va %d la: %d",a ,b, a+b);
}
void tinhtoan(void(*ptrTinhToan)(int,int), int a, int b){
    printf("Tinh toan\n");
    ptrTinhToan(a,b);
}
int main(){
    tinhtoan(&tong, 3, 4); //Tong 3 va 4 la: 7
    return 0;
}
```
- Hoặc có thể sử dụng nó trong một mảng:
```c#include<stdio.h>
void tong (int a, int b){
    printf("Tong %d va %d la: %d",a ,b, a+b);
}
void hieu (int a, int b){
    printf("Hieu %d va %d la: %d", a, b, a-b);
}
int main(){
    
    void *ptr[]={&tong, &hieu};
    ((void(*)(int ,int))ptr[0])(2,3); // Tong 2 va 3 la 5
    ((void(*)(int ,int))ptr[1])(5,2); // Hieu 5 va 2 la 3
    return 0;
}
``` 
#### 4. Pointer to pointer
- A pointer is a variable that stores the address of another pointer.
- Ứng dụng: Linked list, dynamic allocation of multi-dimensional arrays...
- Ví dụ.
```c
int **ptp= NULL;
int a= 9;
int *ptr= &a;
ptp = &ptr;
printf("ptp address - value: %p - %p\n", ptp, *ptp);
printf("ptr address - value: %p - %d\n", ptr, **ptp);
```
#### 5. Size of pointers
- Size of pointers depend on architecture of OS:
	|MS-DOS|WIN32|WIN64|
	|:----:|:----:|:----:|
	| 2 bytes | 4 bytes | 8 bytes |
- Kích thước của biến con trỏ cho bất kì kiểu dữ liệu nào đều bằng nhau. Ví dụ:
```c
#include <stdio.h>

int main() {
	char *p1;
	int *p2;
	float *p3;
	double *p4;
	printf("Size of char type pointer: %lu\n bytes",sizeof(char *));   // 8 bytes
    printf("Size of int type pointer: %lu\n bytes",sizeof(int *));     // 8 bytes
    printf("Size of float type pointer: %lu\n bytes",sizeof(float *)); // 8 bytes
    printf("Size of double type pointer: %lu\n bytes",sizeof(double *));// 8 bytes
	return 0;
}
```


</details>
<details>
<summary>MEMORY ZONES</summary>
<h3  align="center">
STACK<br>
___________<br>
^^^^^^<br>
^^^^^^<br>

^^^^^^<br>
HEAP<br>
___________<br>
BSS<br>
___________<br>
DATA<br>
___________<br>
TEXT<br>
</h3>

### 1. TEXT(READ ONLY)
- Read only
- Chứa khai báo hằng số. 
### 2. DATA - Initialized data
- Chứa biến global, static với giá trị khởi tạo khác 0
- Giải phóng sau khi kết thúc chương trình.
`c int a= 0;`
### 3. BSS - Uinitialized data
- Chứ biến global, static với giá trị khởi tạo bằng 0 hoặc chưa khởi tạo.
`c int a;`
- Giải  phóng sau khi kết thúc chương trình.
- Sau khi khởi tạo giá trị khác 0 cho nó. biến này vẫn thuộc vùng BSS***
### 4. STACK
- R/W nhanh hơn, được khởi tạo khi compiling.
- Vùng nhớ có kích thước cố định, phụ thuộc vào kiến trúc OS.
- Chứa biến local, input parameters
- Giải phóng sau khi go out of scope.
- Lỗi stack overflow : Khi khởi tạo quá nhiều local variables hoặc đệ quy vô tận.
```c
int foo(int x)
{
	printf("de quy khong gioi han\n");
	return foo(x);
}
```
### 5. HEAP
- Kích thước có thể thay đổi.
- Chứa các biến global khi sử dụng dynamically allocation như malloc, realloc, calloc...
- Tồn tại hết chương trình. Chỉ giải phóng khi gọi hàm free(); `It may cause memory leak`
- Nếu cấp phát động quá nhiều mà không giải phóng sẽ bị `heap overflow`
- Nếu khởi vùng nhớ quá lớn mà heap không thể lưu trữ 1 lần được cũng sẽ bị lỗi:
```c
int *A = (int *)malloc(sizeof(int)*18446744073709551615); // Khỏi tạo mảng động có kích thước quá lớn.
```

### ARRAY
- Mảng dùng để lưu trữ nhiều giá trị vào một biến thay vì phải tạo nhiều biến riêng lẻ cho từng giá trị một.
- Cú pháp:
`c typedata name_array[] = {};
- Ví dụ:
```c
uint8_t arr[]= {1,2,3,4,5};
void *ptr[]={};
```
- Gía trị của mảng chính là địa chỉ của ô nhớ ddauf tiên. Ta có thể di chuyển điến địa chỉ của biến thứ 2 bằng cách (arr+1)
```c
uint8_t arr[5]= {1,2,3,4,5};
    uint32_t arr1[2]= {6,7};
    for(int i=0; i<5; i++)
        printf("Dia chi cac phan tu cua arr lan luot la: %p\n", arr+i);
    printf("==============\n");
    for(int i=0; i<2; i++)
        printf("Dia chi cac phan tu cua arr1 lan luot la: %p\n", arr1+i);
/*
Dia chi thu 0 cua arr la: 0000002e3fbff893
Dia chi thu 1 cua arr la: 0000002e3fbff894
Dia chi thu 2 cua arr la: 0000002e3fbff895
Dia chi thu 3 cua arr la: 0000002e3fbff896
Dia chi thu 4 cua arr la: 0000002e3fbff897
==============
Dia chi thu 0 cua arr1 la: 0000002e3fbff888
Dia chi thu 1 cua arr1 la: 0000002e3fbff88c
*/
```

### Dynamically Allocation
- Khởi tạo mảng mà kích thước của nó có thể thay đổi trong quá trình chương trình đang chạy (runtime).
#### 1. malloc() or memory allocation
- Khởi tạo động một mảng động với kích thước chỉ định.
```c
datatype *arr_name= (casttype*)malloc(sizeof(datatype)*n);
```
#### 2. calloc() or contiguos allocation
Calloc giống với malloc nhưng có 2 diểm khác biệt:
 - Nó khởi tạo giá trị mặc định là 0.
 - Cú pháp truyền vào 2 thông số : kích thước mảng và kích thước của kiểu dữ liệu
 ```c
 datatype *arr_name= (casttype*)calloc(n, sizeof(datatype));
```
#### 3. free() - deallocate the memory
- Dùng để thu hồi vùng nhớ. Avoid memory leaks.
  ```c
  int *arr= (int*)malloc(n*sizedof(int));
  free(ptr);
  ```
#### 4. realloc() or re-allocation
- Dùng để thay đổi kích thước của mảng động
- Ví dụ:
  ```c
  int *arr= (int*)malloc(n*sizedof(int));
  arr= realloc(arr, m*sizeof(int));
  ```

</details>
<details>
<summary>VARIABLES</summary>
</details>
<details>
<summary>COMPILER</summary>
</details>
<details>
<summary>MACROS</summary>
</details>





