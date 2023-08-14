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





