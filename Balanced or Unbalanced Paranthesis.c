#include <stdio.h>
#include <stdlib.h>
#define b int


struct s {char data;struct s* next;};
void push(struct s** t, int new_data);
int pop(struct s** t);

b isMatchingPair(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else if (character1 == '[' && character2 == ']')
		return 1;
	else
		return 0;
}

b areBracketsBalanced(char exp[])
{	int i = 0;

	struct s* stack = NULL;

	while (exp[i])
	{
	if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
		push(&stack, exp[i]);
    if (exp[i] == '}' || exp[i] == ')'
			|| exp[i] == ']') {
	if (stack == NULL)
				return 0;
	else if (!isMatchingPair(pop(&stack), exp[i]))
				return 0;
			    
			}
	i++;
	}

	if (stack == NULL)
		return 1; 
	else
		return 0; 
}


int main()
{
	char exp[100] = "{()}[]";

	
	if (areBracketsBalanced(exp))
		printf("Balanced \n");
	else
		printf("Not Balanced \n");
	return 0;
}

void push(struct s** t, int new_data)
{
	
	struct s* n
		= (struct s*)malloc(sizeof(struct s));

	if (n == NULL) {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}
n->data = new_data;
n->next = (*t);
(*t) = n;
}
 
int pop(struct s** t)
{
	char r;
	struct s* top;

	if (*t == NULL) {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}
	else {
		top = *t;
		r = top->data;
		*t = top->next;
		free(top);
		return r;
	}

}

