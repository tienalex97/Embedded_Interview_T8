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
    int e = tong(4,5);
    printf("tong c va d la %d", e); 
    //printf("Tong c va d la %d",tong(4,5)); //Tong c va d la 9
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
	
- Biến là một vùng bộ nhớ được đặt tên cho phép dễ dàng lưu trữ và truy xuất dữ liệu. Tùy vào loại kiểu dữ kiệu của biến mà kích thước vùng nhớ này khác nhau. Ví dụ:
	```c
	uint32_t= 0; // 4 bytes
	char c= 's'; // 1 byte
	```
<h3 align="center"> >>>There are several varible types<<<</h3>
<br>
	
### 1. Local variable
- Khởi tạo tại STACK
- Bị hủy giá trị khi thoát ra khỏi local scope. Ví dụ:
	```c
	#include <stdio.h>
	void	foo(void)
	{
		int	a;
		a = 10;
		printf("Foo function: Variable a = %d\n", a);
	} // the variable 'a' ceases to exist in RAM here.
	int	main(void)
	{
		foo();
		printf("Main: Variable a = %d\n", a);
		// ERROR : main does not know any variable named 'a'!
		return (0);
	}
	```
- Tuy nhiên, ta vẫn có cách để thay đổi giá trị của biến local từ bên ngoài bằng cách truyền địa chỉ vùng nhớ của nó làm tham số và truy cập vào địa chỉ để thay đổi.
	```c
	#include <stdio.h>
	void	foo(int *a)
	{
		*a = 145; // Change what is at the address of 'a'
		printf("Foo: Variable a = %d\n", *a); // *a == 145
	}
	int	main(void)
	{
		int a;
		a = 10;
		printf("Main: Variable a = %d\n", a); // a == 10
		foo(&a); // Pass the address of 'a', not the value
		printf("Main: Variable a = %d\n", a); // a == 145
		return (0);
	}
	```
### 2. Global variable - extern keyword
- Khởi tạo trong vùng nhớ DATA hoặc BSS
- Khởi tạo bằng cách khai báo nó ngoài phạm vi của bất kì hàm nào. Điều này có nghĩa là nó có thể được truy cập trong phạm vi của bất kỳ hàm nào.
#### Thứ tự ưu tiên của global>local
  - Khi khai báo hai biến cùng tên với kiểu global và local, thứ tự ưu tiên sẽ khác nhau. Ví dụ:
  ```c
 	#include <stdio.h>
	int	a; // Global variable initialized to 0 by default
	void	foo(void)
	{
		a = 42;
		printf("Foo: a = %d\n", a); // a == 42
	}
	void	global_a(void)
	{
		// Prints the value of the global variable
		printf("-------------- GLOBAL A: a = %d\n", a);
	}
	int	main(void)
	{
		int a; // Local variable with the same name as the global
		a = 100;
		global_a(); // a globale == 0
		printf("Main: a = %d\n", a); // a locale == 100
		foo();
		printf("Main: a = %d\n", a); // a locale == 100
		global_a(); // a globale == 42
		a = 200;
		printf("Main: a = %d\n", a); // a locale == 200
		global_a(); // a globale == 42
		return (0);
	}
```

#### Phạm vi của biến global - extern keyword
- Bất kỳ hàm nào của chương trình đều có thể truy cập vào biến global. Nếu chúng ta muốn sử dụng biến này ở trong một file khác thì chỉ việc thêm keyword `extern` vào trước và reinitialize nó.
- Tuy nhiên, việc truy cập từ bất kỳ đâu có thể dẫn tới vấn đề bảo mật. Khi đó ta sẽ cần sử dụng `static global variable`.
- Ví dụ:
  Trong file lib.c
  ```c
	#include <stdio.h>
	
	int	a = 100; // Global variable declared and defined here
	
	void	foo(void)
	{
		a = 42;
		printf("Foo: a = %d\n", a); // a == 42
	}
  ```
  Trong file main.c
  	```c
  	#include <stdio.h>

	extern int	a; // Global variable, defined elsewhere
	
	void foo(void);	// Foo prototype, defined elsewhere
			// is identical to
			// extern void foo(void);
	
	int	main(void)
	{
		printf("Main: a = %d\n", a); // a == 100
		foo();
		printf("Main: a = %d\n", a); // a == 42
		a = 200;
		printf("Main: a = %d\n", a); // a == 200
		return (0);
	}
  ```
- Terminal sẽ in ra như sau:
  	```c
	Main: a = 100
	Foo: a = 42
	Main: a = 42
	Main: a = 200
  ```
  <h3 align= "center" col="red"> ***Lưu ý: Khi compile phải liệt kê đầy đủ các file liên quan thì mới nhận được biến extern. `c gcc main.c lib.c -o main`</h3>

### 3. Local static
- Khởi tạo trong BSS/DATA.
- Biến này thực chất chả giống gì biến local. Nó tồn tại như biến global, không mất đi khi thoát khỏi scope và được khởi tạo giá trị mặc định là 0.
- Tuy nhiên từ khóa static hạn chế phạm vi của nó thuộc về hàm chứa nó.
- - Ví dụ:
  ```c
	#include <stdio.h>
	void	foo(void)
	{
		int		a = 100;
		static int	b = 100;
		printf("a = %d, b = %d\n", a, b);
		a++;
		b++;
	}
	int	main(void)
	{
		foo();
		foo();
		foo();
		foo();
		foo();
		return (0);
	}
```
- Lúc này, ta thấy rõ sự khác biệt.
	```c
	a = 100, b = 100
	a = 100, b = 101
	a = 100, b = 102
	a = 100, b = 103
	a = 100, b = 104
```
### 4. Global static
- Được khởi tạo tại DATA hoặc BSS
- Biến này chỉ được sử dụng trong phạm vi file.c chứa nó mà thôi, không thể truy cập từ file.c khác kể cả dùng extern.
- Nếu trong file đó có hàm sử dụng biến này, ta vẫn có thể gọi hàm đó sang file khác băng extern keyword. Điều này được ứng dụng trong ` thiết kế thư viện `, chỉ cho phép người dùng sử dụng tính năng chứ không được phép truy cập thay đổi giá trị của biến.
- Ứng dụng: Dùng để thiết kế thư viện.
	- Trong file main.c
   ```c
	#include <stdio.h>
	
	extern void test(); //extern sử dụng để lấy dữ liệu từ file test.c
	
	extern int a;
	// Lỗi vì không thể lấy biến a từ test.c do static toàn cục.Nếu trong test.c thay static int a = 1 thành int a = 1 thì chương trình đúng.
	int main(){
	    test(); // a = 1
	    a = 10  // a = 10
	    test(); // a = 11
	    return 0;
	}
```
	- Trong file lib.c
	```c
	#include <stdio.h>
	
	static int a = 1; //Static toàn cục -> DATA
	//int a=1;
	void test(){
	    printf("a=%d\n", a); 
	    a++;
	}
```
### 5. Register variables
- Khai báo trực tiếp trong thanh ghi register của CPU instead of RAM. Nó sẽ được truy xuất trực tiếp vào ALU từ register nên tốc độ xử lý rất nhanh.
- Ở một số máy tính có RAM xịn và tối ưu hệ thống thì tốc độ cũng khá cao nhưng vấn kém kiểu khai báo này .
- Ứng dụng: Viết firmware cho CPU.
- Ví dụ:
```c
	#include"stdio.h"
	#include"time.h"
	
	int main()
	{
	    clock_t start, end;
	    double test=0;
	    register int a;
	    start= clock();
	    for(int i=0; i<0xFFFFFFFF; i++)
	    {}
	    end= clock();
	    test= ((double)(end-start))/CLOCKS_PER_SEC;
	    printf("time    : %f\n", test);
	
	
	}
```
### Volatile varibale
- Khi compiler biên dịch chương trình, nó thấy các biến lặp lại giá trị qua các vòng lặp nó sẽ tự động tối ưu để tiết kiệm bộ nhớ.
	```c
	int a;
	while(1)
	{
	a=1;
	}
	```
 - Nhưng khi giá trị của biến thay đổi qua các vòng lặp, nó sẽ không hiểu được. Vì vậy khai báo biến sử dụng keyword volatile, nó sẽ thông báo cho compiler biết biến này có thể thay đổi giá trị bất cứ lúc nào sau các vòng lặp để tránh bị nó tối ưu.
	```c
	volatile int a; // ko toi uu
	while(1)
	{
	a= readUSB(); // tai moi vong lap a nhan gia tri khac nhau.
	}
	```
 - Ứng dụng: Interrupt, RTOS...


</details>
<details>
<summary>COMPILER</summary>

Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

- Giai đoàn tiền xử lý (Pre-processor)
- Giai đoạn dịch NNBC sang Asembly (Compiler)
- Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
- Giai đoạn liên kết (Linker)

![Compiler](https://media.geeksforgeeks.org/wp-content/uploads/20230404112946/Compilation-Process-in-C.png)

1. Giai đoạn tiền xử lý – Preprocessor
- Nhận mã nguồn
- Xóa bỏ tất cả chú thích, comments của chương trình
- Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý

Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.
```
main.i gcc -E main.c -o main.i
```

2. Công đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly(Compiler)
- Phân tích cú pháp (syntax) của mã nguồn NNBC
- Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.
- Assembly language cho phep can thieu truc tiep vao program counter
=> use in advance like RTOS
```
gcc main.i -S -o main.s
```
3. Công đoạn dịch Assembly(Assembler)
- Dich chương trình => Sang mã máy 0 và 1
- Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.
- Ca file multimedia se duoc dinh kem vao buoc nay
- Tao ma hexa `gcc -C main.s -o main.o`
4. Giai đoạn Linker
- Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
- Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
- Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
- Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.
```
gcc main.o -o main
./main
```
</details>
<details>
<summary>MACROS_INLINE_FUNCTION</summary>

### Inline function
- Được xử lý bởi compiler.
- Được khai báo với từ khóa inline.
- Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng.
### Normal Function
- Khi hàm được gọi, compiler sẽ phải luwu con trỏ chương trình PC(programm counter) hiện tại vào stac; chuyển PC tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí ban đầu trong stack trước khi gọi hàm và tiếp tục chương trình.
- Như vây, cách này khiến chương trình tốn thời gian hơn việc chỉ cần thay thế đoạn code đã được compile(inline function).
### Macros
- Được xử lý ở pre-processor
- The piece of code defined with the help of the #define directive. 
- Macros are very useful at multiple places to replace the picece of code with a single value of the macro.
### Phân loại:
#### 1. Kiểu object
```c
#define PI 3.14;
```
#### 2. Kiểu hàm
```c
#define AREA(r) 3.14*r*r;
```
#### 3. Kiểu dây chuyền 
```c
#define PI 3.14;
#define AREA(r) r*r*PI;
```
### Ứng dụng:
#### 1. Trong header file
- Khi lần đầu include thì macro sẽ được định nghĩa lần đầu.
- Sau đó chương trình gặp nó sẽ ko định nghĩa lại nữa.
```c
#define SIZE 20
#ifndef SIZE( if not defined)
... // neu da define roi thi doan code nay ko co hieu luc
#endif
```
#### 2. Khi thiết kế thư viện ta sẽ thiết kế cho nhiều MCU có thể dùng
```c
*lib.c
#define STM32F103 	0
#define ATMEGA		1
#define PIC16F887	2

#if MCU== STM32F103
void BlinkLed()
{
	DRC= !DRC;
	delay(1000);
}
#elif MCU==ATMEGA
...
#elif MCU==PIC16F887
...
#else
...
#endif		
======================================
*main.c
#include lib.c
#define MCU STM32F103
int main()
{
	BlinkLed();
}
```
#### 3. Để khi báo cho các hàm phức tạp, ta thêm `\` vào cuối dòng
```c
#define CREATE_FUNC(name, cmd) 		\
void name(){				\
	printf("%s", (char*)cmd);	\   
}			
CREATE_FUNC(test1, "This is test 1\n");
CREATE_FUNC(test2, "This is test 2\n");	
==========================================
// #cmd stand for "cmd" - 
// ## dung de noi chuoi - token pasting operator: Used to cocatenate two tokens during the preprocessor phase of the compilation process.

#define CREATE_VAR(name)			\
int var1__##name;				\
int var2__##name;				\
int var3__##name;
```
### Variadic macros ***
- Dùng khi chưa biết truyền tham số gi cụ thể vào. Ta để ... thay cho input parameter
- Trong phần khai báo hàm, Sử dụng keyword `__VA_ARGS__` để đại diện cho đoạn code sẽ truyền vào hàm.
```c
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
eprintf ("%s:%d: ", input_file, lineno)
     →  fprintf (stderr, "%s:%d: ", input_file, lineno)
```
- Ứng dụng: tạo các function phức tạp và có thể tái sử dụng nhiều lần. 


</details>
<details>
<summary>STRUCT & UNION</summary>
	
### STRUCT
- Là kiểu dữ liệu do người dùng rự định nghĩa( user defined type)
- Dùng để nhóm nhiều biến với kiểu dữ liệu khác nhau vào một nơi, các biến này gọi là member của struct.
- Mỗi member trong struct sẽ có địa chỉ riêng, và tùy vào thứ tự khai báo và kiến trúc xử lý mà kích thước sẽ khác nhau. Ta cần tìm hiểu thêm về `struct padding`.
#### Struct padding
- Tùy thuộc vào kiến trúc của OS mà mỗi lần quét bộ nhớ của struct có kích thước khác nhau. 32 bits thì quét 4 bytes một lần, 64 bits thì quét 8 bytes một lần.
- Riêng đối với gcc compiler, nó sẽ tối ưu hơn, kích thước của một lần quét chính là kích thước của member có kiểu dữ liệu lớn nhất.
- Sau mỗi lần quét, nếu sử dụng không hết tài nguyên sẽ dư ra phần bộ nhớ đệm, nếu đủ để chứa member tiếp theo thì member tiếp theo sẽ được khai báo ở vùn đệm đó để tận dụng tài nguyên.
```c
uint8_t a;   // quet 4 byte, nhung chiem 1 byte+3 byte bo nho dem
uint32_t b;	// 3 byte bo nho dem k du, nen dung them 4 byte
uint8_t c;	// lai dung 1 byte, thua 3 byte bo nho dem.
//==> struct chiếm 12 bytes.
//===for optimization===
uint8_t a;
uint8_t b;
uint32_t c; 
//==>tong chi su dung 8 bytes.
```
- Thêm một ví dụ:
```c
uint8_t var[5]; su dung 8 byte, dung 5 du 3
uint16_t var1[2]; dung 2 byte bo nhow dem va them 4 byte
uint32_t var2[2]; dung them 4*2 bytes
//=> tong su dung 4+4+4+4+4
```
### UNION
- Union về cơ bản cũng khá giống struct, chỉ khác là các member của nó share nhau cùng một địa chỉ.
- Sử dụng để khai báo kiểu dữ liệu gồm nhiều member mà tại một thời điểm chỉ được chọn một member duy nhất.
- Ứng dụng:
	- GPIo - tại một thời điểm chỉ đóng 1 vài trò duy nhất là input hoặc output
 	- Kết hợp với struct để truy xuất dữ liệu.
- Ví dụ:
```c
#include"stdio.h"
typedef union{
int arr1[5];
int arr2[3];
int arr3[2];
} unionArray;
int main()
{
  	unionArray arr;
	for(int i=0; i<5; i++)
		arr.arr1[i]= i*1;
	for(int i=0; i<3; i++)
		arr.arr2[i]= i*2;
	for(int i=0; i<2; i++)
		arr.arr3[i]=i*3;
	// Print arr1
  	for(int i=0; i<5; i++)
		printf("Arr1[%d]= %d\n", i, arr.arr1[i]);
}
// The result is 0, 3, 4, 3, 4 becuased of overwritten at the same address.
```
</details>
<details>
<summary>BIT-WISE & MASK</summary>

### BIT-WISE OPERATION
- Trong khoa học máy tính, bit-wise operation được thực hiện trên một hoặc nhiều chuỗi nhị phân tại cấp độ từng bit riêng biệt.
- Các phép toán này có ưu điểm là thực hiện nhanh, được hỗ trợ trực tiếp bởi vi xử lý.
- Ứng dung: Điều khiển các giá trị để so sánh, tính toán.
#### 1. AND(&) 
- Toán tử thao tác bit AND lấy 2 toán hạng nhị phân có chiều dài bằng nhau và thực hiện phép toán lý luận AND trên mỗi cặp bit tương ứng bằng cách nhân chúng lại với nhau.
- Nhờ đó, nếu cả hai bit ở vị trí được so sánh đều là 1, thì bit hiển thị ở dạng nhị phân sẽ là 1 (1 x 1 = 1); ngược lại thì kết quả sẽ là 0 (1 x 0 = 0).
- Ví dụ: ` 0b0101 | 0b1011 = 0b0001 `
#### 2. OR(|) 
- Phép toán trên thao tác bit OR lấy hai dãy bit có độ dài bằng nhau và thực hiện phép toán OR trên mỗi cặp bit tương ứng. Kết quả ở mỗi vị trí sẽ là 0 nếu cả hai bit là 0, ngược lại thì kết quả là 1.
- Ví dụ: ` 0b0101 | 0b1011 = 0b1111 `
#### 3. NOT(~)
- Toán tử thao tác bit NOT, hay còn gọi là còn được gọi là toán tử lấy phần bù (complement), là toán tử một ngôi thực hiện phủ định luận lý trên từng bit, tạo thành bù 1 (one’s complement) của giá trị nhị phân cho trước. Bit nào là 0 thì sẽ trở thành 1, và 1 sẽ trở thành 0.
- Ví dụ: ` NOT 0b0101 = 0b1010 `
#### 4. XOR(^) - Excludesive OR
- Phép toán thao tác bit XOR lấy hai dãy bit có cùng độ dài và thực hiện phép toán logic bao hàm XOR trên mỗi cặp bit tương ứng. Kết quả ở mỗi vị trí là 1 chỉ khi bit đầu tiên là 1 hoặc nếu chỉ khi bit thứ hai là 1, nhưng sẽ là 0 nếu cả hai là 0 hoặc cả hai là 1. Ở đây ta thực hiện phép so sánh hai bit, kết quả là 1 nếu hai bit khác nhau và là 0 nếu hai bit giống nhau.
- Ví dụ:  ` 0b0101 ^ 0b1011 = 0b1110 `
#### 5. Bit-Shift (Right-shift >> | Left-shift <<)
- Dùng để di chuyển cả chuỗi nhị phân sang trái hoặc phải so với vị trí ban đầu để thay đổi giá trị. Shif sang trái 1 đơn vị là nhân với 2, shift sang phải 1 đơn vị là chia cho 2.
- Ví dụ: `0b0001 0000 <<2 = 0b0100 0000 `

### BIT MASKING
- Bit Mask là dữ liệu được sử dụng cho các bit-wise operations. Sử dụng nó, một hoặc nhiều bit trong một byte/word có thể được bật tắt hoặc đảo tùy thuộc vào mục đích khác nhau.
- Ứng dụng: Tối ưu thuật toán, đặt lại giá trị có bit cần thiết thay vì đặt lại giá trị của cả byte/word gây xung đột chương trình.
- Ví dụ:
  - Tách lấy trạng thái thanh ghi PC0 thì PINC:
    ```c
    bool inp = PINC & 1<<0;
    ```
  - Set và clear bit trên thanh ghi, giả sử ta chỉ bật cổng nào đó lên trong 1 giây rồi tắt(cổng số 3)
    ```c
    PORTD |= 1<<3;
    delay(1000);
    PORTD & ~(1<<3);
    ```

</details>





