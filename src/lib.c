/**
\file lib.c
\brief Файл з реалізацією функцій

Цей файл, містить реалізацію функції mul_matrix.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/**
 
 Функція mul_matrix
 \param **matrix1 - масив першої матриці.
 \param **matrix2 - масив другої матриці.
 \param **result_mul_matrix - масив матриці у яку ми запишиме результат.
 \param links1 - кількість строк у матриці з результатом.
 \param colums2 - кількість стовпців у матриці з результатом.
 \param links2 - кількість стовпців першої матриці або кількість строк другої матриці.
 \return Повертає матрицю з результатами множення.
 
 
 Послідовність дій
 
- Створюємо 2 цикли що перебирають елемнти у матрицях які ми перемножуємо та задає адрес у результуючій матриці куди ми записуємо результат.

- Створюємо 3 цикл який задає адрес конкретного значення у матрицях matrix1 та matrix2.

- Помножуємо елемнти у матрицях, складаемо їх та записуємо у нашу результуючу матрицю.

- Повртаємо матрицю в якій знаходиться результат множення.  

*/

int CreateConst(char str[])
{	
	char word[1000];
	int number_letter;
	long int res = 0;
	
	if(str[0] != '\0')
		return 0;
	
	for(int i = 0, j = 0; str[i] != '\0';i++)    
	{		
		number_letter = 0;
		
		for(j = 0;str[i] != ' '; i++, j++)
		{	
			if( (str[i]>= 'a' && 'z' >= str[i]) || (str[i]>= 'A' && 'Z' >= str[i]) || (str[i]>= '0' && '9' >= str[i]) )
			
				word[j] = str[i];
				
			else if(strncmp(&str[i],"А", 2) >= 0 && strncmp(&str[i],"я", 2)  <= 0){
			
				word[j] = str[i];
				word[j + 1] = str[i + 1];
				number_letter++;
				j++;
				i++;
			}
			else if(strncmp(&str[i],"ї", 2) == 0 || strncmp(&str[i],"Ї", 2) == 0 || 
				strncmp(&str[i],"є", 2) == 0 || strncmp(&str[i],"Є", 2) == 0 || 
				strncmp(&str[i],"і", 2) == 0 || strncmp(&str[i],"І", 2) == 0 || 
				strncmp(&str[i],"ґ", 2) == 0 || strncmp(&str[i],"Ґ", 2) == 0){
			
				word[j] = str[i];
				word[j + 1] = str[i + 1];
				number_letter++;
				j++;
				i++;
			}
			else
				break;
			
												
		}
		
		number_letter = j - number_letter;
		printf("%s = %d\n", word,number_letter);
		memset(word,0,1000);
		
		if(number_letter >= 10)
		{
			res = (res * 100) + number_letter;
		}
		else
			res = (res * 10) + number_letter;
	}
	
	return res;
}











