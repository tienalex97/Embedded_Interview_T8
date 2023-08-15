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





